#ifndef BOM_MANAGER_PART_H
#define BOM_MANAGER_PART_H

#include "types.h"

/** 全局物料信息 */
extern struct Part *parts;

/** 从文件读取物料信息 */
void readPartsFromFile();

/** 保存物料信息到文件 */
void writePartsToFile();

/** 显示物料列表 */
void showPartList();

/**
 * 新建物料
 * @param id 物料编号
 * @param name 物料名称
 * @param count 物料数量
 */
void createPart(char *id, char *name, int count);

/**
 * 删除物料
 * @param id 物料编号
 */
void deletePartById(char *id);

#endif //BOM_MANAGER_PART_H
