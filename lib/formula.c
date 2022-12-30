#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "part.h"
#include "formula.h"

FormulaNode *createFormulaListHead() {
    FormulaNode *head = NULL;
    head = (FormulaNode *) malloc(sizeof(FormulaNode));
    if (NULL == head) {
        return NULL;
    }
    head->next = NULL;

    return head;
}

int createFormula(FormulaNode *list, Formula data) {
    FormulaNode *head = list;
    FormulaNode *newNode = NULL;

    newNode = (FormulaNode *) malloc(sizeof(FormulaNode));
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

int deleteFormulaById(FormulaNode *list, char id[255]) {
    FormulaNode *head = list->next;
    FormulaNode *deleteNode = head->next;
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

int updateFormulaById(FormulaNode *list, char id[255], Formula data) {
    FormulaNode *head = list->next;
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

int executeFormulaById(FormulaNode *list, PartNode *partList, char *id) {
    FormulaNode *head = list->next;
    while (head) {
        if (strcmp(head->data.id, id) == 0) {
            PartCountNode *partCountHead = head->data.partCountList->next;
            while (partCountHead) {
                PartCount partCount = partCountHead->data;
                PartNode *partNode = findPartNodeById(partList, partCount.part.id);
                if (NULL == partNode) {
                    printf("Not found part id: %s\n", partCount.part.id);
                    return -1;
                } else if(partNode->data.used + partCount.count > partNode->data.total) {
                    printf("Not enough part id: %s\n", partCount.part.id);
                    return -1;
                }
                partCountHead = partCountHead->next;
            }
            printf("----------------------------------------------\n");
            printf("Execute formula id: %s success\n", id);
            partCountHead = head->data.partCountList->next;
            while (partCountHead) {
                PartCount partCount = partCountHead->data;
                PartNode *partNode = findPartNodeById(partList, partCount.part.id);
                printf("Part: [%s]%s, before used: %d,  after used: %d, total: %d\n", partNode->data.id, partNode->data.name, partNode->data.used, partNode->data.used + partCount.count, partNode->data.total);
                partNode->data.used += partCount.count;
                partCountHead = partCountHead->next;
            }
            head->data.executeCount++;
            return 0;
        }
        head = head->next;
    }
    printf("Not found id: %s\n", id);
    return -1;
}

void showFormulaList(FormulaNode *list) {
    FormulaNode *head = list;
    printf("-----------------------------------------------------------------------------------\n");
    printf("%-20s\t%-20s\t%-20s\n", "ID", "Formula Name", "Execute Count");
    head = head->next;
    while (head != NULL) {
        printf("%-20s\t%-20s\t%-20d\n", head->data.id, head->data.name, head->data.executeCount);
        head = head->next;
    }
    printf("-----------------------------------------------------------------------------------\n");
}

FormulaNode *findFormulaNodeById(FormulaNode *list, char id[255]) {
    FormulaNode *head = list->next;
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