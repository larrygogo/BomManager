#include <stdlib.h>
#include <string.h>
#include "utils.h"
#include "part.h"
#include "formula.h"

Global *init() {
    Global *global = initGlobal();
    return global;
}

Global * initGlobal() {
    Global *global = NULL;
    global = (Global *) malloc(sizeof(Global));
    loadPartFromFile(global);
    loadFormulaFromFile(global);
    if (NULL == global) {
        exit(0);
    }
    return global;
}
// 从csv文件加载Part
void loadPartFromFile(Global *global) {
    global->partList = createPartListHead();
}

void loadFormulaFromFile(Global *global) {
    global->formulaList = createFormulaListHead();
}