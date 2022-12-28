#ifndef BOM_MANAGER_PART_COUNT_H
#define BOM_MANAGER_PART_COUNT_H
#include "types.h"

PartCountNode createPartCountListHead();

int createPartCount(PartCountNode *list, PartCount data);

int deletePartCountById(PartCountNode *list, char *id);

int updatePartCountById(PartCountNode *list, char *id, PartCount data);

void showPartCountList(PartCountNode *list);

#endif //BOM_MANAGER_PART_COUNT_H
