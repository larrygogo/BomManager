#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "menu.h"
#include "part.h"
#include "formula.h"
#include "partCount.h"

void showMainMenu(Global *global) {
    printf("--------------Welcome--------------\n");
    printf("1. Part manage\n");
    printf("2. Formula manage\n");
//    printf("3. Plan manage\n");
    printf("0. Exit\n");
    printf("-----------------------------------\n");
}

void checkMainMenuNumber(Global *global) {
    int num;
    while (1) {
        printf("Please enter the number: ");
        scanf("%d", &num);
        switch (num) {
            case 1:
                showPartMenu(global);
                break;
            case 2:
                showFormulaMenu(global);
                break;
//            case 3:
//                showPlanMenu(global);
            case 0:
                exit(0);
            default:
                printf("Please enter the correct number!\n");
        }
        checkMainMenuNumber(global);
    }
}

void showPartMenu(Global *global) {
    printf("--------------Part manage--------------\n");
    printf("1. Create part\n");
    printf("2. Delete part\n");
    printf("3. Update part\n");
    printf("4. Show all parts\n");
    printf("0. Back\n");
    printf("-1. Exit\n");
    printf("-----------------------------------\n");
    checkPartMenuNumber(global);
}

void checkPartMenuNumber(Global *global) {
    int num;
    while (1) {
        printf("Please enter the number: ");
        scanf("%d", &num);
        switch (num) {
            case 1:
                showCreatePartMenu(global);
                break;
            case 2:
                showDeletePartMenu(global);
                break;
            case 3:
                showUpdatePartMenu(global);
                break;
            case 4:
                showPartList(global->partList);
                break;
            case 0:
                showMainMenu(global);
                checkMainMenuNumber(global);
                break;
            case -1:
                exit(0);
            default:
                printf("Please enter the correct number!\n");
        }
        showPartMenu(global);
        checkPartMenuNumber(global);
    }
}

void showCreatePartMenu(Global *global) {
    char *id = (char *) malloc(sizeof(char));
    char *name = (char *) malloc(sizeof(char));
    Part part;
    printf("--------------Create Part--------------\n");
    printf("Please enter the part id: ");
    scanf("%s", id);
    printf("Please enter the part name: ");
    scanf("%s", name);
    printf("Please enter the part total: ");
    scanf("%d", &part.total);
    part.id = id;
    part.name = name;
    part.used = 0;
    createPart(global->partList, part);
    showPartList(global->partList);

}

void showDeletePartMenu(Global *global) {
    char *id = (char *) malloc(sizeof(char));
    int res;
    printf("--------------Delete Part--------------\n");
    printf("Please enter the part id: ");
    scanf("%s", id);
    res = deletePartById(global->partList, id);
    if (res == 0) {
        printf("Delete part success!\n");
    } else {
        printf("Delete part failed!\n");
    }
    showPartList(global->partList);
}

void showUpdatePartMenu(Global *global) {
    char *id = (char *) malloc(sizeof(char));
    char *newId = (char *) malloc(sizeof(char));
    char *name = (char *) malloc(sizeof(char));
    int used;
    int total;
    printf("--------------Update Part--------------\n");
    printf("Please enter the part id: ");
    scanf("%s", id);
    PartNode *node = findPartNodeById(global->partList, id);
    if (node == NULL) {
        printf("Not found id: %s\n", id);
    } else {
        printf("Please enter the new part id: ");
        scanf("%s", newId);
        PartNode *newNode = findPartNodeById(global->partList, newId);
        if (newNode != NULL && strcmp(newId, id) != 0) {
            printf("id: %s already exists\n", id);
        } else {
            printf("Please enter the new part name: ");
            scanf("%s", name);
            printf("Please enter the new part used: ");
            scanf("%d", &used);
            printf("Please enter the new part total: ");
            scanf("%d", &total);
            Part part;
            part.id = newId;
            part.name = name;
            part.used = used;
            part.total = total;
            updatePartById(global->partList, id, part);
            showPartList(global->partList);
        }
    }
}

void showFormulaMenu(Global *global) {
    printf("--------------Formula manage--------------\n");
    printf("1. Create formula\n");
    printf("2. Delete formula\n");
    printf("3. Update formula\n");
    printf("4. Show all formulas\n");
    printf("5. Show formulas details\n");
    printf("6. Execute formula\n");
    printf("0. Back\n");
    printf("-1. Exit\n");
    printf("-----------------------------------\n");
    checkFormulaMenuNumber(global);
}

void checkFormulaMenuNumber(Global *global) {
    int num;
    while (1) {
        printf("Please enter the number: ");
        scanf("%d", &num);
        switch (num) {
            case 1:
                showCreateFormulaMenu(global);
                break;
            case 2:
                showDeleteFormulaMenu(global);
                break;
            case 3:
                showUpdateFormulaMenu(global);
                break;
            case 4:
                showFormulaList(global->formulaList);
                break;
            case 5:
                showFormulaDetailMenu(global);
                break;
            case 6:
                showExecuteFormulaMenu(global);
                break;
            case 0:
                showMainMenu(global);
                checkMainMenuNumber(global);
                break;
            case -1:
                exit(0);
            default:
                printf("Please enter the correct number!\n");
        }
        checkFormulaMenuNumber(global);
    }
}

void showCreateFormulaMenu(Global *global) {
    char *id = (char *) malloc(sizeof(char));
    char *name = (char *) malloc(sizeof(char));
    Formula formula;
    printf("--------------Create Formula--------------\n");
    printf("Please enter the formula id: ");
    scanf("%s", id);
    printf("Please enter the formula name: ");
    scanf("%s", name);
    formula.id = id;
    formula.name = name;
    formula.executeCount = 0;
    formula.partCountList = createPartCountListHead();
    createFormula(global->formulaList, formula);
    showFormulaList(global->formulaList);
}

void showDeleteFormulaMenu(Global *global) {
    char *id = (char *) malloc(sizeof(char));
    int res;
    printf("--------------Delete Formula--------------\n");
    printf("Please enter the formula id: ");
    scanf("%s", id);
    res = deleteFormulaById(global->formulaList, id);
    if (res == 0) {
        printf("Delete formula success!\n");
    } else {
        printf("Delete formula failed!\n");
    }
    showFormulaList(global->formulaList);
}

void showUpdateFormulaMenu(Global *global) {
    char *id = (char *) malloc(sizeof(char));
    char *newId = (char *) malloc(sizeof(char));
    char *name = (char *) malloc(sizeof(char));
    int executeCount;
    printf("--------------Update Formula--------------\n");
    printf("Please enter the formula id: ");
    scanf("%s", id);
    FormulaNode *node = findFormulaNodeById(global->formulaList, id);
    if (node == NULL) {
        printf("Not found id: %s\n", id);
    } else {
        printf("Please enter the new formula id: ");
        scanf("%s", newId);
        FormulaNode *newNode = findFormulaNodeById(global->formulaList, newId);
        if (newNode != NULL && strcmp(newId, id) != 0) {
            printf("id: %s already exists\n", id);
        } else {
            printf("Please enter the new formula name: ");
            scanf("%s", name);
            printf("Please enter the new formula execute count: ");
            scanf("%d", &executeCount);
            Formula formula;
            formula.id = newId;
            formula.name = name;
            formula.executeCount = executeCount;
            updateFormulaById(global->formulaList, id, formula);
            showFormulaList(global->formulaList);
        }
    }
}

void showFormulaDetailMenu(Global *global) {
    char *id = (char *) malloc(sizeof(char));
    showFormulaList(global->formulaList);
    printf("Please enter the formula id: ");
    scanf("%s", id);
    FormulaNode *formulaNode = findFormulaNodeById(global->formulaList, id);
    if (NULL == formulaNode) {
        printf("Not found id: %s\n", id);
    } else {
        showPartCountMenu(global, formulaNode);
    }
}

void showExecuteFormulaMenu(Global *global) {
    char *id = (char *) malloc(sizeof(char));
    showFormulaList(global->formulaList);
    printf("------------ Execute Formula -------------\n");
    printf("Please enter the formula id: ");
    scanf("%s", id);
    executeFormulaById(global->formulaList, global->partList, id);
}


void showPartCountMenu(Global *global, FormulaNode *formulaNode) {
    printf("Formula id: %s\tFormula name: %s\n", formulaNode->data.id, formulaNode->data.name);
    showPartCountList(formulaNode->data.partCountList);

    int num;
    printf("--------------Formula details manage--------------\n");
    printf("1. Add detail\n");
    printf("2. Delete detail\n");
    printf("3. Update detail\n");
    printf("0. Back\n");
    printf("-1. Exit\n");
    printf("-----------------------------------\n");
    printf("Please enter the number: ");
    scanf("%d", &num);
    switch (num) {
        case 1:
            showCreatePartCountMenu(global, formulaNode);
            break;
        case 2:
            showDeletePartCountMenu(global, formulaNode);
            break;
        case 3:
            showUpdatePartCountMenu(global, formulaNode);
            break;
        case 0:
            showFormulaMenu(global);
        case -1:
            exit(0);
        default:
            printf("Please enter the correct number!\n");
            showPartCountMenu(global, formulaNode);
    }
}

void showCreatePartCountMenu(Global *global, FormulaNode *formulaNode) {
    char *id = (char *) malloc(sizeof(char));
    printf("--------------Add formula detail--------------\n");
    PartCount partCount;
    printf("Please enter the part id: ");
    scanf("%s", id);
    PartNode *partNode = findPartNodeById(global->partList, id);
    if (partNode == NULL) {
        printf("Not found part id: %s\n", id);
        showPartCountMenu(global, formulaNode);
    } else {
        printf("Please enter the formula detail count: ");
        scanf("%d", &partCount.count);
        partCount.part = partNode->data;
        createPartCount(formulaNode->data.partCountList, partCount);
        showPartCountMenu(global, formulaNode);
    }
}

void showDeletePartCountMenu(Global *global, FormulaNode *formulaNode) {
    char *id = (char *) malloc(sizeof(char));
    int res;
    printf("--------------Delete formula detail--------------\n");
    printf("Please enter the formula detail part id: ");
    scanf("%s", id);
    res = deletePartCountById(formulaNode->data.partCountList, id);
    if (res == 0) {
        printf("Delete formula detail success!\n");
    } else {
        printf("Delete formula detail failed!\n");
    }
    showPartCountMenu(global, formulaNode);
}

void showUpdatePartCountMenu(Global *global, FormulaNode *formulaNode) {
    char *id = (char *) malloc(sizeof(char));
    int count;
    printf("--------------Update formula detail--------------\n");
    printf("Please enter the formula detail part id: ");
    scanf("%s", id);
    PartCountNode *node = findPartCountNodeById(formulaNode->data.partCountList, id);
    if (node == NULL) {
        printf("Not found id: %s\n", id);
    } else {
        printf("Please enter the new formula detail part count: ");
        scanf("%d", &count);
        PartCount partCount;
        partCount.part = node->data.part;
        partCount.count = count;
        updatePartCountById(formulaNode->data.partCountList, id, partCount);
        showPartCountMenu(global, formulaNode);
    }
}
