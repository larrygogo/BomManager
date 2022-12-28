#ifndef BOM_MANAGER_FORMULA_H
#define BOM_MANAGER_FORMULA_H
#include "types.h"

FormulaNode *createFormulaListHead();

int createFormula(FormulaNode *list, Formula data);

int deleteFormulaById(FormulaNode *list, char *id);

int updateFormulaById(FormulaNode *list, char *id, Formula data);

void showFormulaList(FormulaNode *list);

int addPartCountToFormulaById(FormulaNode *list, char *id, PartCount partCount);

int removePartCountFromFormulaById(FormulaNode *list, char *id, char *partCountId);

#endif //BOM_MANAGER_FORMULA_H
