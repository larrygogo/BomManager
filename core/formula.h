#ifndef BOM_MANAGER_FORMULA_H
#define BOM_MANAGER_FORMULA_H
#include "types.h"

FormulaNode *createFormulaListHead();

int createFormula(FormulaNode *list, Formula data);

FormulaNode *getFormulaNodeById(FormulaNode *list, char *id);

int deleteFormulaById(FormulaNode *list, char *id);

int updateFormulaById(FormulaNode *list, char *id, Formula data);

void showFormulaList(FormulaNode *list);

FormulaNode *findFormulaNodeById(FormulaNode *list, char *id);

int executeFormulaById(FormulaNode *list, PartNode *partList, char *id);
#endif //BOM_MANAGER_FORMULA_H
