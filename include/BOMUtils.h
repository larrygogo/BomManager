#ifndef BOM_MANAGER_UTILS_H
#define BOM_MANAGER_UTILS_H
#include "BOMTypes.h"
Global *init();
Global * initGlobal();
void readPartFromFile(Global *global);
void readFormulaFromFile(Global *global);
void writePartToFile(Global *global);
void writeFormulaToFile(Global *global);

#endif //BOM_MANAGER_UTILS_H
