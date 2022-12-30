#include "lib/types.h"
#include "lib/menu.h"
#include "lib/utils.h"

int main() {
    Global *global = init();
    showMainMenu(global);
    checkMainMenuNumber(global);
    return 0;
}
