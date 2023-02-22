#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "../include/BOMUtils.h"
#include "../include/BOMPart.h"
#include "../include/BOMFormula.h"
#include "../include/BOMPartCount.h"
Global *init() {
    Global *global = initGlobal();
    return global;
}

Global * initGlobal() {
    Global *global = NULL;
    global = (Global *) malloc(sizeof(Global));
    readPartFromFile(global);
    readFormulaFromFile(global);
    if (NULL == global) {
        exit(0);
    }
    return global;
}

// 从csv文件加载Part
void readPartFromFile(Global *global) {
    global->partList = createPartListHead();
    FILE *fp = fopen("../data/Part.csv", "r");
    if (fp == NULL) {
        // 创建文件
        fp = fopen("../data/Part.csv", "w");
        if (fp == NULL) {
            fprintf(stderr, "fopen() failed.\n");
            exit(EXIT_FAILURE);
        }
    }
    Part part;
    char line[1024];
    while (fgets(line, 1024, fp)) {
        char *tmp = strdup(line);
        char *token = strtok(tmp, ",");
        part.id = (char *) malloc(sizeof(char) * (strlen(token) + 1));
        strcpy(part.id, token);
        token = strtok(NULL, ",");
        part.name = (char *) malloc(sizeof(char) * (strlen(token) + 1));
        strcpy(part.name, token);
        token = strtok(NULL, ",");
        part.total = atoi(token);
        token = strtok(NULL, ",");
        part.used = atoi(token);
        createPart(global->partList, part);
        free(tmp);
    }

    fclose(fp);
}

void writePartToFile(Global *global) {
    FILE *fp = fopen("../data/Part.csv", "w");
    if (fp == NULL) {
        fprintf(stderr, "fopen() failed.\n");
        exit(EXIT_FAILURE);
    }
    PartNode *head = global->partList->next;
    while (head) {
        fprintf(fp, "%s,%s,%d,%d\n", head->data.id, head->data.name, head->data.total, head->data.used);
        head = head->next;
    }
    fclose(fp);
}

// 从csv文件加载Formula
void readFormulaFromFile(Global *global) {
    global->formulaList = createFormulaListHead();
    FILE *fp = fopen("../data/Formula.csv", "r");
    if (fp == NULL) {
        fclose(fp);
        // 创建文件
        fp = fopen("../data/Formula.csv", "w");
        writePartToFile(global);
        fclose(fp);
        fp = fopen("../data/Formula.csv", "r");
        if (fp == NULL) {
            fprintf(stderr, "fopen() failed.\n");
            exit(EXIT_FAILURE);
        }
    }
    Formula formula;
    char line[1024];
    int lineCount = 1;
    while (fgets(line, 1024, fp)) {
        char *tmp = strdup(line);
        char *token = strtok(tmp, ",");
        formula.id = malloc(sizeof(char) * (strlen(token) + 1));
        strcpy(formula.id, token);
        token = strtok(NULL, ",");
        formula.name = malloc(sizeof(char) * (strlen(token) + 1));
        strcpy(formula.name, token);
        token = strtok(NULL, ",");
        formula.executeCount = atoi(token);
        token = strtok(NULL, ",");
        PartCountNode *partCountList = createPartCountListHead();
        formula.partCountList = partCountList;

        while (token != NULL) {
            PartCount partCount;
            char *id = token;
            token = strtok(NULL, ",");
            int count = atoi(token);
            token = strtok(NULL, ",");

            PartNode *partNode = findPartNodeById(global->partList, id);

            if (partNode != NULL) {
                partCount.part = partNode->data;
                partCount.count = count;

                createPartCount(formula.partCountList, partCount);
            } else {
                printf("warning: line %d partId %s not found in partList", lineCount, id);
            }
        }

        createFormula(global->formulaList, formula);
        free(tmp);
    }
    fclose(fp);
}

void writeFormulaToFile(Global *global) {
    FILE *fp = fopen("../data/Formula.csv", "w");
    if (fp == NULL) {
        fprintf(stderr, "fopen() failed.\n");
        exit(EXIT_FAILURE);
    }
    FormulaNode *head = global->formulaList->next;
    while (head) {
        fprintf(fp, "%s,%s,%d", head->data.id, head->data.name, head->data.executeCount);
        PartCountNode *partCountNode = head->data.partCountList->next;
        while (partCountNode) {
            fprintf(fp, ",%s,%d", partCountNode->data.part.id, partCountNode->data.count);
            partCountNode = partCountNode->next;
        }
        fprintf(fp, "\n");

        head = head->next;
    }
    fclose(fp);
}

