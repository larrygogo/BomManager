#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "partCount.h"

PartCountNode *createPartCountListHead() {
    PartCountNode *head = NULL;
    head = (PartCountNode *) malloc(sizeof(PartCountNode));
    if (NULL == head) {
        return NULL;
    }
    head->next = NULL;

    return head;
}

PartCountNode *findPartCountNodeById(PartCountNode *list, char *id) {
    PartCountNode *head = list->next;
    while (head) {
        if (strcmp(head->data.part.id, id) == 0) {
            return head;
        }
        head = head->next;
    }
    return NULL;
}

int createPartCount(PartCountNode *list, PartCount data) {
    PartCountNode *head = list;
    PartCountNode *newNode = NULL;

    newNode = (PartCountNode *) malloc(sizeof(PartCountNode));
    if (NULL == newNode) {
        return -1;
    }
    newNode->data = data;

    while (head) {
        if(NULL != head->next && strcmp(head->next->data.part.id, data.part.id) == 0) {
            printf("id: %s already exists\n", data.part.id);
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

int deletePartCountById(PartCountNode *list, char *id) {
    PartCountNode *head = list;
    PartCountNode *deleteNode = head->next;
    if (NULL == head->next) {
        printf("Not found id: %s", id);
        return -1;
    }
    while (head) {
        if (strcmp(head->next->data.part.id, id) == 0) {
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

int updatePartCountById(PartCountNode *list, char *id, PartCount data) {
    PartCountNode *head = list->next;
    while (head) {
        if (strcmp(head->data.part.id, id) == 0) {
            head->data = data;
            return 0;
        }
        head = head->next;
    }
    return -1;
}

void showPartCountList(PartCountNode *list) {
    PartCountNode *head = list;
    printf("-----------------------------------------------------------------------------------\n");
    printf("%-20s\t%-20s\t%-20s\n", "Part ID", "Part Name", "Count");
    head = head->next;
    while (head != NULL) {
        printf("%-20s\t%-20s\t%-20d\n",head->data.part.id, head->data.part.name, head->data.count);
        head = head->next;
    }
    printf("-----------------------------------------------------------------------------------\n");
}