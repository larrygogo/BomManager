#include "include/BOMTypes.h"
#include "include/BOMMenu.h"
#include "include/BOMUtils.h"

int main() {
    Global *global = init();
    showMainMenu(global);
    checkMainMenuNumber(global);
    return 0;
}
