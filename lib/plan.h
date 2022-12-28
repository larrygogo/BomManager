#ifndef BOM_MANAGER_PLAN_H
#define BOM_MANAGER_PLAN_H

#include "types.h"

/**
 * 创建头结点
 */
PlanNode *createPlanListHead();

/**
 * 新建物料
 */
int createPlan(PlanNode *list, Plan data);

/**
 * 删除物料
 */
int deletePlanById(PlanNode *list, char *id);

/**
 * 修改物料信息
 */
int updatePlanById(PlanNode *list, char *id, Plan data);

/** 显示物料列表 */
void showPlanList(PlanNode *list);

#endif //BOM_MANAGER_PLAN_H
