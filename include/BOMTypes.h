#ifndef BOM_MANAGER_TYPES_H
#define BOM_MANAGER_TYPES_H

typedef struct part {
    char *id;

    char *name;

    int used;

    int total;
} Part;

typedef struct partNode {
    Part data;
    struct partNode *next;
} PartNode;

typedef struct partCount {
    Part part;
    int count;
} PartCount;

typedef struct partCountNode {
    PartCount data;
    struct partCountNode *next;
} PartCountNode;

typedef struct formula {
    char *id;
    char *name;
    int executeCount;
    PartCountNode *partCountList;
} Formula;


typedef struct formulaNode {
    Formula data;
    struct formulaNode *next;
} FormulaNode;


typedef struct globalContext {
    PartNode *partList;
    FormulaNode *formulaList;
} Global;


#endif //BOM_MANAGER_TYPES_H
