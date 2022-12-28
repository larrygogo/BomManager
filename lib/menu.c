#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "file.h"
#include "menu.h"
#include "part.h"

void showMainMenu(Global *global) {
    printf("--------------��ӭʹ��--------------\n");
    printf("1. ���Ϲ���\n");
    printf("2. �����ƻ�����\n");
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

                break;
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
    printf("5. �����ϼ�\n");
    printf("0. �˳�\n");
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
            case 5:
                showMainMenu(global);
                checkMainMenuNumber(global);
                break;
            case 0:
                exit(0);
            default:
                printf("����������\n");
        }
        checkPartMenuNumber(global);
    }
}

void showCreatePartMenu(Global *global) {
    char id[255], name[255];
    int surplus;
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
    int res = -1;
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