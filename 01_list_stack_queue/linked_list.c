#include <stddef.h>
#include <stdlib.h>
#include "linked_list.h"

struct Node {
    int element;
    struct Node *next;
};

// 创建一个空列表，包含一个头节点
List MakeEmpty(void) {
    List L = malloc(sizeof(struct Node));
    L->next = NULL; // 头节点的next指针初始化为NULL
    return L;
}

// 判断列表是否为空
int IsEmpty(List L) {
    return L->next == NULL; // 检查头节点的next是否为NULL
}

// 判断位置P是否为列表L的最后一个元素
int IsLast(Position P, List L) {
    return P->next == NULL;
}

// 在列表L中查找元素X，返回指向该元素的指针
Position Find(int X, List L) {
    Position P = L->next; // 从头节点的next开始查找
    while (P != NULL && P->element != X) {
        P = P->next;
    }
    return P;
}

// 删除列表L中的元素X
void Delete(int X, List L) {
    Position P = L; // 从头节点开始
    while (P->next != NULL && P->next->element != X) {
        P = P->next;
    }
    if (P->next != NULL) {
        Position Temp = P->next;
        P->next = Temp->next;
        free(Temp);
    }
}

// 查找元素X前一个位置
Position FindPrevious(int X, List L) {
    Position P = L; // 从头节点开始
    while (P->next != NULL && P->next->element != X) {
        P = P->next;
    }
    return P;
}

// 在位置P后插入元素X到列表L中
void Insert(int X, List L, Position P) {
    Position NewNode = malloc(sizeof(struct Node));
    NewNode->element = X;
    NewNode->next = P->next;
    P->next = NewNode;
}

// 删除整个列表L
void DeleteList(List L) {
    while (L->next != NULL) {
        Position Temp = L->next;
        L->next = Temp->next;
        free(Temp);
    }
    free(L); // 释放头节点
}

// 返回列表L的头部节点
Position Header(List L) {
    return L;
}

// 返回列表L的第一个元素的位置
Position First(List L) {
    return L->next;
}

// 将位置P移动到下一个元素
Position Advance(Position P) {
    return P->next;
}

// 返回位置P的元素值
int Retrieve(Position P) {
    return P->element;
}
