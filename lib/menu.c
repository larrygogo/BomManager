#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "file.h"
#include "menu.h"
#include "part.h"

void showMainMenu(Global *global) {
    printf("--------------欢迎使用--------------\n");
    printf("1. 物料管理\n");
    printf("2. 生产计划管理\n");
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

                break;
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
    printf("5. 返回上级\n");
    printf("0. 退出\n");
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
            case 5:
                showMainMenu(global);
                checkMainMenuNumber(global);
                break;
            case 0:
                exit(0);
            default:
                printf("编号输入错误\n");
        }
        checkPartMenuNumber(global);
    }
}

void showCreatePartMenu(Global *global) {
    char id[255], name[255];
    int surplus;
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
    int res = -1;
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