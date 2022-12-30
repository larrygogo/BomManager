#ifndef BOM_MANAGER_MENU_H
#define BOM_MANAGER_MENU_H
#include "utils.h"

// 展示菜单
void showMainMenu(Global *global);
void checkMainMenuNumber(Global *global);

void showPartMenu(Global *global);
void checkPartMenuNumber(Global *global);
void showCreatePartMenu(Global *global);
void showDeletePartMenu(Global *global);
void showUpdatePartMenu(Global *global);

void showFormulaMenu(Global *global);
void checkFormulaMenuNumber(Global *global);
void showCreateFormulaMenu(Global *global);
void showDeleteFormulaMenu(Global *global);
void showUpdateFormulaMenu(Global *global);
void showFormulaDetailMenu(Global *global);
void showExecuteFormulaMenu(Global *global);

void showPartCountMenu(Global *global, FormulaNode *formulaNode);
void showCreatePartCountMenu(Global *global, FormulaNode *formulaNode);
void showDeletePartCountMenu(Global *global, FormulaNode *formulaNode);
void showUpdatePartCountMenu(Global *global, FormulaNode *formulaNode);

#endif
