#include <stdio.h>
#include <stdlib.h>
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
    printf("3. 删除物料\n");
    printf("4. 返回上级\n");
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
                break;
            case 4:
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
    Part *part;
    part = (Part *) malloc(sizeof (Part));
    if (NULL == part) {
        printf("内存不足，创建失败");
    }
    printf("--------------创建物料--------------\n");
    printf("请输入物料ID：");
    scanf("%s", part->id);
    printf("请输入物料名称：");
    scanf("%s", part->name);
    printf("请输入物料数量：");
    scanf("%d", &part->surplus);
    part->used = 0;
    createPart(global->partList, *part);
    showPartList(global->partList);
}