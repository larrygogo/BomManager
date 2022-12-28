#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "plan.h"

PlanNode *createPlanListHead() {
    PlanNode *head = NULL;
    head = (PlanNode *) malloc(sizeof(PlanNode));
    if (NULL == head) {
        return NULL;
    }
    head->next = NULL;

    return head;
}

int createPlan(PlanNode *list, Plan data) {
    PlanNode *head = list;
    PlanNode *newNode = NULL;

    newNode = (PlanNode *) malloc(sizeof(PlanNode));
    if (NULL == newNode) {
        return -1;
    }
    newNode->data = data;

    while (head) {
        if(NULL != head->next && strcmp(head->next->data.id, data.id) == 0) {
            printf("id: %s already exists\n", data.id);
            free(newNode);
            return -1;
        }

        if (NULL == head->next) {
            newNode->next = head->next;
            head->next = newNode;
            return 0;
        }
        head = head->next;
    }
}

int deletePlanById(PlanNode *list, char *id) {
    PlanNode *head = list->next;
    PlanNode *deleteNode = head->next;
    if (NULL == head->next) {
        printf("Not found id: %s\n", id);
        return -1;
    }
    while (head) {
        if (strcmp(head->next->data.id, id) == 0) {
            head->next = deleteNode->next;
            deleteNode->next = NULL;
            free(deleteNode);
            return 0;
        }
        head = head->next;
        deleteNode = deleteNode->next;
    }
    printf("Not found id: %s\n", id);
    return -1;
}

int updatePlanById(PlanNode *list, char id[255], Plan data) {
    PlanNode *head = list->next;
    if (NULL == head->next) {
        printf("Not found id: %s\n", id);
        return -1;
    }
    while (head) {
        if (strcmp(head->data.id, id) == 0) {
            head->data = data;
            return 0;
        }
        head = head->next;
    }
    printf("Not found id: %s\n", id);
    return -1;
}

void showPlanList(PlanNode *list) {
    PlanNode *head = list;
    printf("-----------------------------------------------------------------------------------\n");
    printf("%-20s\t%-20s\t%-20s\t%-20s\t%-20s\n", "ID", "计划名称", "配方ID", "配方名称", "已完成次数");
    head = head->next;
    while (head != NULL) {
        printf("%-20s\t%-20s\t%-20s\t%-20s\t%-20s\n", head->data.id, head->data.name, head->data.formula.id, head->data.formula.name);
        head = head->next;
    }
    printf("-----------------------------------------------------------------------------------\n");
}

