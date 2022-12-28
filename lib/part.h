#ifndef BOM_MANAGER_PART_H
#define BOM_MANAGER_PART_H

#include "types.h"

/**
 * 创建头结点
 */
PartNode *createPartListHead();

/**
 * 新建物料
 */
int createPart(PartNode *list, Part data);

/**
 * 删除物料
 */
int deletePartById(PartNode *list, char id[255]);

/**
 * 修改物料信息
 */
int updatePartById(PartNode *list, char id[255], Part data);

/**
 * 根据ID查找物料
 */
PartNode *findPartNodeById(PartNode *list, char id[255]);

/** 显示物料列表 */
void showPartList(PartNode *list);

#endif //BOM_MANAGER_PART_H
