#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "menu.h"
#include "part.h"
#include "formula.h"
#include "partCount.h"

void showMainMenu(Global *global) {
    printf("--------------��ӭʹ��--------------\n");
    printf("1. ���Ϲ���\n");
    printf("2. �䷽����\n");
    printf("3. �����ƻ�����\n");
    printf("0. �˳�ϵͳ\n");
    printf("-----------------------------------\n");
}

void checkMainMenuNumber(Global *global) {
    int num;
    while (1) {
        printf("�����ţ�");
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
                printf("����������\n");
        }
        checkMainMenuNumber(global);
    }
}

void showPartMenu(Global *global) {
    printf("--------------���Ϲ���--------------\n");
    printf("1. �����б�\n");
    printf("2. ��������\n");
    printf("3. ��������\n");
    printf("4. ɾ������\n");
    printf("0. �����ϼ�\n");
    printf("-1. �˳�\n");
    printf("-----------------------------------\n");
    checkPartMenuNumber(global);
}

void checkPartMenuNumber(Global *global) {
    int num;
    while (1) {
        printf("�����ţ�");
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
                printf("����������\n");
        }
        checkPartMenuNumber(global);
    }
}

void showCreatePartMenu(Global *global) {
    Part part;
    printf("--------------��������--------------\n");
    printf("����������ID��");
    scanf("%s", &part.id);
    printf("�������������ƣ�");
    scanf("%s", &part.name);
    printf("����������������");
    scanf("%d", &part.surplus);
    part.used = 0;
    createPart(global->partList, part);
    showPartList(global->partList);
}

void showDeletePartMenu(Global *global) {
    char id[255];
    int res;
    printf("������Ҫɾ��������ID��");
    scanf("%s", &id);
    res = deletePartById(global->partList, id);
    if(res == 0) {
        printf("����ID��%s ɾ���ɹ�\n", id);
    } else {
        printf("����ID��%s ɾ��ʧ��\n", id);
    }
    showPartList(global->partList);
}

void showUpdatePartMenu(Global *global) {
    char id[255], newId[255];
    char name[255];
    int used;
    int surplus;
    printf("������Ҫ���µ�����ID��");
    scanf("%s", &id);
    PartNode *node = findPartNodeById(global->partList, id);
    if(node == NULL) {
        printf("Not found id: %s\n", id);
    } else {
        printf("���������ϵ���ID��");
        scanf("%s", &newId);
        PartNode *newNode = findPartNodeById(global->partList, newId);
        if(newNode != NULL && strcmp(newId, id) != 0) {
            printf("id: %s already exists\n", id);
        } else {
            printf("���������ϵ������ƣ�");
            scanf("%s", &name);
            printf("���������ϵ�����ʹ������");
            scanf("%d", &used);
            printf("���������ϵ���������");
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
    printf("--------------�䷽����--------------\n");
    printf("1. �䷽�б�\n");
    printf("2. �����䷽\n");
    printf("3. �����䷽\n");
    printf("4. ɾ���䷽\n");
    printf("5. �鿴�䷽����\n");
    printf("0. �����ϼ�\n");
    printf("-1. �˳�\n");
    printf("-----------------------------------\n");
    checkFormulaMenuNumber(global);
}

void checkFormulaMenuNumber(Global *global) {
    int num;
    while (1) {
        printf("�����ţ�");
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
                printf("����������\n");
        }
        checkFormulaMenuNumber(global);
    }
}

void showCreateFormulaMenu(Global *global) {
    Formula formula;
    printf("--------------�����䷽--------------\n");
    printf("�������䷽ID��");
    scanf("%s", &formula.id);
    printf("�������䷽���ƣ�");
    scanf("%s", &formula.name);
    createFormula(global->formulaList, formula);
    showFormulaList(global->formulaList);
}

void showDeleteFormulaMenu(Global *global) {
    char id[255];
    int res;
    printf("������Ҫɾ�����䷽ID��");
    scanf("%s", &id);
    res = deleteFormulaById(global->formulaList, id);
    if(res == 0) {
        printf("�䷽ID��%s ɾ���ɹ�\n", id);
    } else {
        printf("�䷽ID��%s ɾ��ʧ��\n", id);
    }
    showFormulaList(global->formulaList);
}

void showUpdateFormulaMenu(Global *global) {
    char id[255], newId[255];
    char name[255];
    printf("������Ҫ���µ��䷽ID��");
    scanf("%s", &id);
    FormulaNode *node = findPartNodeById(global->formulaList, id);
    if(node == NULL) {
        printf("Not found id: %s\n", id);
    } else {
        printf("�������䷽����ID��");
        scanf("%s", &newId);
        FormulaNode *newNode = findFormulaNodeById(global->formulaList, newId);
        if(newNode != NULL && strcmp(newId, id) != 0) {
            printf("id: %s already exists\n", id);
        } else {
            printf("�������䷽�������ƣ�");
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
    printf("��������Ҫ�鿴������䷽ID��");
    scanf("%s", &id);
    FormulaNode *formulaNode = findFormulaNodeById(global->formulaList, id);
    if(NULL == formulaNode) {
        printf("Not found id: %s\n", id);
    } else {
        showPartCountMenu(global, formulaNode);
    }
}



void showPartCountMenu(Global *global, FormulaNode *formulaNode) {
    printf("��ǰ�䷽Id��%s\t�䷽���ƣ�%s\n", formulaNode->data.id, formulaNode->data.name);
    showPartCountList(formulaNode->data.partCountList);

    int num;
    printf("--------------�䷽�������--------------\n");
    printf("1. ������ϸ\n");
    printf("2. ɾ����ϸ\n");
    printf("0. �����ϼ�\n");
    printf("-1. �˳�\n");
    printf("-----------------------------------\n");
    printf("�����ţ�");
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
            printf("����������\n");
            showPartCountMenu(global, formulaNode);
    }
}

void showCreatePartCountMenu(Global *global, FormulaNode *formulaNode) {

}

void showDeletePartCountMenu(Global *global, FormulaNode *formulaNode) {

}
