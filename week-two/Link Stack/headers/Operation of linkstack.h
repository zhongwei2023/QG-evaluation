#include <stdio.h>
#include <stdlib.h>


struct Node {
    int data;
    struct Node* next;
};

// 新建空栈
struct Node* createStack() {
    return NULL;
}

// 判断链栈是否为空
int isEmpty(struct Node* top) {
    return top == NULL;
}

// 入栈操作
struct Node* push(struct Node* top, int data) {
    // 创建新节点
    struct Node *temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    // 将新节点插入链表头
    temp->next = top;
    top = temp;
    return top;
}

// 出栈操作
struct Node* pop(struct Node* top) {
    if (!isEmpty(top)) {
        // 保存当前栈顶节点
        struct Node* temp = top;
        // 栈顶指针指向下一个节点
        top = top->next;
        // 释放当前栈顶节点
        free(temp);
    } else {
        printf("Stack is empty!");
    }
    return top;
}

// 取栈顶元素
int getTop(struct Node* top) {
    if (!isEmpty(top)) {
        return top->data;  // 返回栈顶元素
    } else {
        printf("Stack is empty!");
        return -1;
    }
}

//遍历栈
void walk(struct Node* top){
    if(top==NULL){
        printf("Stack is empty!");
    }
    struct Node *curNode=top;
    printf("==Start to traverse Link-Stack==");
    while(curNode){
        printf("the data of curent Stack:%d",curNode->data);
        curNode=curNode->next;
    }
    printf("==Over==");
}


