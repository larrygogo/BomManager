#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "part.h"

PartNode *createPartListHead() {
    PartNode *head = NULL;
    head = (PartNode *) malloc(sizeof(PartNode));
    if (NULL == head) {
        return NULL;
    }
    head->next = NULL;

    return head;
}

int createPart(PartNode *list, Part data) {
    PartNode *head = list;
    PartNode *newNode = NULL;

    newNode = (PartNode *) malloc(sizeof(PartNode));
    if (NULL == newNode) {
        return -1;
    }
    newNode->data = data;
    newNode->next = NULL;

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
    return -1;
}

int deletePartById(PartNode *list, char id[255]) {
    PartNode *head = list;
    PartNode *deleteNode = head->next;
    if (NULL == list->next) {
        printf("Not found id: %s\n", id);
        return -1;
    }
    while (head) {
        if (strcmp(deleteNode->data.id, id) == 0) {
            head->next = deleteNode->next;
            deleteNode->next = NULL;
            return 0;
        }
        head = head->next;
        deleteNode = deleteNode->next;
    }
    printf("Not found id: %s\n", id);
    return -1;
}

int updatePartById(PartNode *list, char id[255], Part data) {
    PartNode *head = list->next;
    if (NULL == list->next) {
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

void showPartList(PartNode *list) {
    PartNode *head = list;
    printf("-------------------------------------------------------------------------\n");
    printf("%-20s %-20s %-20s %-20s\n", "ID", "名称", "已使用量", "总量");
    head = head->next;
    while (head != NULL) {
        printf("%-20s %-20s %-20d %-20d\n", head->data.id, head->data.name, head->data.used, head->data.surplus);
        head = head->next;
    }
    printf("--------------------------------------------------------------------------\n");
}

PartNode *findPartNodeById(PartNode *list, char id[255]) {
    PartNode *head = list->next;
    if (NULL == list->next) {
        return NULL;
    }
    while (head) {
        if (strcmp(head->data.id, id) == 0) {
            return head;
        }
        head = head->next;
    }
    return NULL;
}