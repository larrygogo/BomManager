#ifndef BOM_MANAGER_TYPES_H
#define BOM_MANAGER_TYPES_H

/** 物料 */
typedef struct part {
    /* 物料编号 */
    char id[255];

    /* 物料名称 */
    char name[255];

    /* 已使用量 */
    int used;

    /* 剩余量 */
    int surplus;
} Part;

typedef struct partNode {
    Part data;
    struct partNode *next;
} PartNode;

/** 物料用量 */
typedef struct partCount {
    char id[255];
    Part part;
    int count;
} PartCount;

typedef struct partCountNode {
    PartCount data;
    struct partCountNode *next;
} PartCountNode;

/** 配方 */
typedef struct formula {
    char id[255];
    char name[255];
    PartCountNode *list;
} Formula;


typedef struct formulaNode {
    Formula data;
    struct formulaNode *next;
} FormulaNode;


/** 生产计划 */
typedef struct plan {
    /* 计划编号 */
    char id[255];

    /* 计划名称 */
    char name[255];

    /* 配方 */
    Formula formula;

    /* 已完成数 */
    int finishedCount;
} Plan;

typedef struct planNode {
    Plan data;
    struct planNode *next;
} PlanNode;


typedef struct globalContext {
    PartNode *partList;
    PlanNode *planList;
} Global;


#endif //BOM_MANAGER_TYPES_H
