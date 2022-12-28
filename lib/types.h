#ifndef BOM_MANAGER_TYPES_H
#define BOM_MANAGER_TYPES_H

/** ���� */
typedef struct part {
    /* ���ϱ�� */
    char id[255];

    /* �������� */
    char name[255];

    /* ��ʹ���� */
    int used;

    /* ʣ���� */
    int surplus;
} Part;

typedef struct partNode {
    Part data;
    struct partNode *next;
} PartNode;

/** �������� */
typedef struct partCount {
    char id[255];
    Part part;
    int count;
} PartCount;

typedef struct partCountNode {
    PartCount data;
    struct partCountNode *next;
} PartCountNode;

/** �䷽ */
typedef struct formula {
    char id[255];
    char name[255];
    PartCountNode *list;
} Formula;


typedef struct formulaNode {
    Formula data;
    struct formulaNode *next;
} FormulaNode;


/** �����ƻ� */
typedef struct plan {
    /* �ƻ���� */
    char id[255];

    /* �ƻ����� */
    char name[255];

    /* �䷽ */
    Formula formula;

    /* ������� */
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
