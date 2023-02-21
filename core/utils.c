#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "utils.h"
#include "part.h"
#include "formula.h"

Global *init() {
    Global *global = initGlobal();
    return global;
}

Global * initGlobal() {
    Global *global = NULL;
    global = (Global *) malloc(sizeof(Global));
    loadPartFromFile(global);
    loadFormulaFromFile(global);
    if (NULL == global) {
        exit(0);
    }
    return global;
}

// 从csv文件加载Part
void loadPartFromFile(Global *global) {
    global->partList = createPartListHead();
    printf("loadPartFromFile\n");
    // 读取 part.csv 文件
    FILE *fp = fopen("../data/part.csv", "r");
    if (fp == NULL) {
        fprintf(stderr, "fopen() failed.\n");
        exit(EXIT_FAILURE);
    }
    Part part;
    char line[1024];
    while (fgets(line, 1024, fp)) {
        char *tmp = strdup(line);
        char *token = strtok(tmp, ",");
        part.id = token;
        token = strtok(NULL, ",");
        part.name = token;
        token = strtok(NULL, ",");
        part.total = atoi(token);
        token = strtok(NULL, ",");
        part.used = atoi(token);
        createPart(global->partList, part);
//        free(tmp);
    }

    fclose(fp);
}

void writePartToFile(Global *global) {
    FILE *fp = fopen("../data/part.csv", "w");
    if (fp == NULL) {
        fprintf(stderr, "fopen() failed.\n");
        exit(EXIT_FAILURE);
    }
    PartNode *head = global->partList->next;
    while (head) {
        fprintf(fp, "%s,%s,%d,%d", head->data.id, head->data.name, head->data.total, head->data.used);
        head = head->next;
    }
    fclose(fp);
}


void loadFormulaFromFile(Global *global) {
    global->formulaList = createFormulaListHead();
}