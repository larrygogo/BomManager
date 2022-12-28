#include <stdlib.h>
#include "utils.h"
#include "part.h"
#include "plan.h"
#include "formula.h"

Global *init() {
    Global *global = initGlobal();
    //TODO:: 从文件加载数据
    return global;
}

Global * initGlobal() {
    Global *global = NULL;
    global = (Global *) malloc(sizeof(Global));
    global->partList = createPartListHead();
    global->formulaList = createFormulaListHead();
    global->planList = createPlanListHead();
    if (NULL == global) {
        exit(0);
    }
    return global;
}