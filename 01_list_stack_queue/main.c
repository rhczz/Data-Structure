#include <stdio.h>
#include "linked_list.h"

int main() {
    List L = MakeEmpty();
    Insert(1, L, Header(L));
    Insert(2, L, First(L));
    Insert(3, L, Advance(First(L)));

    // 测试链表
    Position current = First(L);
    while (current != NULL) {
        printf("%d\n", Retrieve(current));
        current = Advance(current);
    }

    Delete(2, L);
    DeleteList(L);

    return 0;
}