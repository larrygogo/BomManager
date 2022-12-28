#include <stdio.h>
#include "lib/types.h"
#include "lib/part.h"

int main() {
    PartNode *head = createPartListHead();
    Part part1 = {"0001", "0001", 0, 10};
    createPart(head, part1);
    Part part2 = {"0002", "0002", 0, 10};
    createPart(head, part2);
    Part part3 = {"0003", "0003", 0, 10};
    createPart(head, part3);
    Part part4 = {"0004", "0004", 0, 10};
    updatePartById(head, "0003", part4);
    deletePartById(head, "0002");
    showPartList(head);
    return 0;
}
