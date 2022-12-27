#ifndef BOM_MANAGER_TYPES_H
#define BOM_MANAGER_TYPES_H

/** 物料 */
struct Part {
    /* 物料编号 */
    char *id;

    /* 物料名称 */
    char *name;

    /* 已使用量 */
    int used;

    /* 剩余量 */
    int surplus;
};

/** 生产计划 */
struct Plan {
    /* 计划编号 */
    char *id;

    /* 计划名称 */
    char *name;

    /* 使用配方 */
    char *formulaId;

    /* 已完成数 */
    int finishedCount;
};

/** 配方物料使用量 */
struct FormulaPartDetail {
    /* 所需物料 */
    struct Part part;

    /* 所需数量 */
    int count;
};

/** 配方 */
struct Formula {
    /* 配方名称 */
    char *name;

    /* 使用物料列表 */
    struct FormulaPartDetail *details;
};


#endif //BOM_MANAGER_TYPES_H
