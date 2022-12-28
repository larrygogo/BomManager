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

int addPartCountToFormulaById(FormulaNode *list, char *id, PartCount partCount);

int removePartCountFromFormulaById(FormulaNode *list, char *id, char *partCountId);

#endif //BOM_MANAGER_FORMULA_H
