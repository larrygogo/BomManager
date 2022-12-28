#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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

int deleteFormulaById(FormulaNode *list, char *id) {
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

int updateFormulaById(FormulaNode *list, char *id, Formula data) {
    FormulaNode *head = list->next;
    while (head) {
        if (strcmp(head->data.id, id) == 0) {
            head->data = data;
            return 0;
        }
        head = head->next;
    }
    return -1;
}

void showFormulaList(FormulaNode *list) {
    FormulaNode *head = list;
    printf("-----------------------------------------------------------------------------------\n");
    printf("%-20s\t%-20s\n", "ID", "Name");
    head = head->next;
    while (head != NULL) {
        printf("%-20s\t%-20s\n", head->data.id, head->data.name);
        head = head->next;
    }
    printf("-----------------------------------------------------------------------------------\n");
}