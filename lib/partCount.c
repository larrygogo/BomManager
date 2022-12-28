#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "partCount.h"

PartCountNode *creatPartCountListHead() {
    PartCountNode *head = NULL;
    head = (PartCountNode *) malloc(sizeof(PartCountNode));
    if (NULL == head) {
        return NULL;
    }
    head->next = NULL;

    return head;
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

int deletePartCountById(PartCountNode *list, char *id) {
    PartCountNode *head = list->next;
    PartCountNode *deleteNode = head->next;
    if (NULL == head->next) {
        printf("Not found id: %s", id);
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
    return -1;
}

int updatePartCountById(PartCountNode *list, char *id, PartCount data) {
    PartCountNode *head = list->next;
    while (head) {
        if (strcmp(head->data.id, id) == 0) {
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
    printf("%-20s\t%-20s\t%-20s\t%-20s\n", "ID", "Part ID", "Part Name", "Count");
    head = head->next;
    while (head != NULL) {
        printf("%-20s\t%-20s\t%-20d\t%-20d\n", head->data.id, head->data.part.id, head->data.part.name, head->data.count);
        head = head->next;
    }
    printf("-----------------------------------------------------------------------------------\n");
}