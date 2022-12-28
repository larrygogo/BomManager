#ifndef BOM_MANAGER_TYPES_H
#define BOM_MANAGER_TYPES_H

/** 物料 */
typedef struct part {
    /* 物料编号 */
    const char *id;

    /* 物料名称 */
    const char *name;

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
    char *id;
    Part part;
    int count;
} PartCount;

typedef struct partCountNode {
    PartCount data;
    struct partCountNode *next;
} PartCountNode;

/** 配方 */
typedef struct formula {
    char *id;
    char *name;
    PartCountNode *list;
} Formula;


typedef struct formulaNode {
    Formula data;
    struct formulaNode *next;
} FormulaNode;


/** 生产计划 */
typedef struct plan {
    /* 计划编号 */
    char *id;

    /* 计划名称 */
    char *name;

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
