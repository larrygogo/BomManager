#ifndef BOM_MANAGER_UTILS_H
#define BOM_MANAGER_UTILS_H
#include "types.h"
Global *init();
Global * initGlobal();
void loadPartFromFile(Global *global);
void loadFormulaFromFile(Global *global);

#endif //BOM_MANAGER_UTILS_H
