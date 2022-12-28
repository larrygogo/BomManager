#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "menu.h"
#include "part.h"
#include "formula.h"
#include "partCount.h"

void showMainMenu(Global *global) {
    printf("--------------欢迎使用--------------\n");
    printf("1. 物料管理\n");
    printf("2. 配方管理\n");
    printf("3. 生产计划管理\n");
    printf("0. 退出系统\n");
    printf("-----------------------------------\n");
}

void checkMainMenuNumber(Global *global) {
    int num;
    while (1) {
        printf("输入编号：");
        scanf("%d", &num);
        switch (num) {
            case 1:
                showPartMenu(global);
                break;
            case 2:
                showFormulaMenu(global);
                break;
            case 3:
//                showPlanMenu(global);
            case 0:
                exit(0);
            default:
                printf("编号输入错误\n");
        }
        checkMainMenuNumber(global);
    }
}

void showPartMenu(Global *global) {
    printf("--------------物料管理--------------\n");
    printf("1. 物料列表\n");
    printf("2. 创建物料\n");
    printf("3. 更新物料\n");
    printf("4. 删除物料\n");
    printf("0. 返回上级\n");
    printf("-1. 退出\n");
    printf("-----------------------------------\n");
    checkPartMenuNumber(global);
}

void checkPartMenuNumber(Global *global) {
    int num;
    while (1) {
        printf("输入编号：");
        scanf("%d", &num);
        switch (num) {
            case 1:
                showPartList(global->partList);
                break;
            case 2:
                showCreatePartMenu(global);
                break;
            case 3:
                showUpdatePartMenu(global);
                break;
            case 4:
                showDeletePartMenu(global);
                break;
            case 0:
                showMainMenu(global);
                checkMainMenuNumber(global);
                break;
            case -1:
                exit(0);
            default:
                printf("编号输入错误\n");
        }
        checkPartMenuNumber(global);
    }
}

void showCreatePartMenu(Global *global) {
    Part part;
    printf("--------------创建物料--------------\n");
    printf("请输入物料ID：");
    scanf("%s", &part.id);
    printf("请输入物料名称：");
    scanf("%s", &part.name);
    printf("请输入物料数量：");
    scanf("%d", &part.surplus);
    part.used = 0;
    createPart(global->partList, part);
    showPartList(global->partList);
}

void showDeletePartMenu(Global *global) {
    char id[255];
    int res;
    printf("请输入要删除的物料ID：");
    scanf("%s", &id);
    res = deletePartById(global->partList, id);
    if(res == 0) {
        printf("物料ID：%s 删除成功\n", id);
    } else {
        printf("物料ID：%s 删除失败\n", id);
    }
    showPartList(global->partList);
}

void showUpdatePartMenu(Global *global) {
    char id[255], newId[255];
    char name[255];
    int used;
    int surplus;
    printf("请输入要更新的物料ID：");
    scanf("%s", &id);
    PartNode *node = findPartNodeById(global->partList, id);
    if(node == NULL) {
        printf("Not found id: %s\n", id);
    } else {
        printf("请输入物料的新ID：");
        scanf("%s", &newId);
        PartNode *newNode = findPartNodeById(global->partList, newId);
        if(newNode != NULL && strcmp(newId, id) != 0) {
            printf("id: %s already exists\n", id);
        } else {
            printf("请输入物料的新名称：");
            scanf("%s", &name);
            printf("请输入物料的新已使用量：");
            scanf("%d", &used);
            printf("请输入物料的新总量：");
            scanf("%d", &surplus);
            Part part;
            part.id[0] = *newId;
            part.name[0] = *name;
            part.used = used;
            part.surplus = surplus;
            updatePartById(global->partList, id, part);
            showPartList(global->partList);
        }
    }
}

void showFormulaMenu(Global *global) {
    printf("--------------配方管理--------------\n");
    printf("1. 配方列表\n");
    printf("2. 创建配方\n");
    printf("3. 更新配方\n");
    printf("4. 删除配方\n");
    printf("5. 查看配方详情\n");
    printf("0. 返回上级\n");
    printf("-1. 退出\n");
    printf("-----------------------------------\n");
    checkFormulaMenuNumber(global);
}

void checkFormulaMenuNumber(Global *global) {
    int num;
    while (1) {
        printf("输入编号：");
        scanf("%d", &num);
        switch (num) {
            case 1:
                showFormulaList(global->formulaList);
                break;
            case 2:
                showCreateFormulaMenu(global);
                break;
            case 3:
                showUpdateFormulaMenu(global);
                break;
            case 4:
                showDeleteFormulaMenu(global);
                break;
            case 5:
                showFormulaDetailMenu(global);
            case 0:
                showMainMenu(global);
                checkMainMenuNumber(global);
                break;
            case -1:
                exit(0);
            default:
                printf("编号输入错误\n");
        }
        checkFormulaMenuNumber(global);
    }
}

void showCreateFormulaMenu(Global *global) {
    Formula formula;
    printf("--------------创建配方--------------\n");
    printf("请输入配方ID：");
    scanf("%s", &formula.id);
    printf("请输入配方名称：");
    scanf("%s", &formula.name);
    createFormula(global->formulaList, formula);
    showFormulaList(global->formulaList);
}

void showDeleteFormulaMenu(Global *global) {
    char id[255];
    int res;
    printf("请输入要删除的配方ID：");
    scanf("%s", &id);
    res = deleteFormulaById(global->formulaList, id);
    if(res == 0) {
        printf("配方ID：%s 删除成功\n", id);
    } else {
        printf("配方ID：%s 删除失败\n", id);
    }
    showFormulaList(global->formulaList);
}

void showUpdateFormulaMenu(Global *global) {
    char id[255], newId[255];
    char name[255];
    printf("请输入要更新的配方ID：");
    scanf("%s", &id);
    FormulaNode *node = findPartNodeById(global->formulaList, id);
    if(node == NULL) {
        printf("Not found id: %s\n", id);
    } else {
        printf("请输入配方的新ID：");
        scanf("%s", &newId);
        FormulaNode *newNode = findFormulaNodeById(global->formulaList, newId);
        if(newNode != NULL && strcmp(newId, id) != 0) {
            printf("id: %s already exists\n", id);
        } else {
            printf("请输入配方的新名称：");
            scanf("%s", &name);
            Formula formula;
            formula.id[0] = *newId;
            formula.name[0] = *name;
            updateFormulaById(global->formulaList, id, formula);
            showFormulaList(global->formulaList);
        }
    }
}

void showFormulaDetailMenu(Global *global) {
    char id[255];
    showFormulaList(global->formulaList);
    printf("请输入需要查看详情的配方ID：");
    scanf("%s", &id);
    FormulaNode *formulaNode = findFormulaNodeById(global->formulaList, id);
    if(NULL == formulaNode) {
        printf("Not found id: %s\n", id);
    } else {
        showPartCountMenu(global, formulaNode);
    }
}



void showPartCountMenu(Global *global, FormulaNode *formulaNode) {
    printf("当前配方Id：%s\t配方名称：%s\n", formulaNode->data.id, formulaNode->data.name);
    showPartCountList(formulaNode->data.partCountList);

    int num;
    printf("--------------配方详情管理--------------\n");
    printf("1. 新增明细\n");
    printf("2. 删除明细\n");
    printf("0. 返回上级\n");
    printf("-1. 退出\n");
    printf("-----------------------------------\n");
    printf("输入编号：");
    scanf("%d", &num);
    switch (num) {
        case 1:
            showCreatePartCountMenu(global, formulaNode);
            break;
        case 2:
            showDeletePartCountMenu(global, formulaNode);
            break;
        case 0:
            showFormulaMenu(global);
        case -1:
            exit(0);
        default:
            printf("编号输入错误\n");
            showPartCountMenu(global, formulaNode);
    }
}

void showCreatePartCountMenu(Global *global, FormulaNode *formulaNode) {

}

void showDeletePartCountMenu(Global *global, FormulaNode *formulaNode) {

}
