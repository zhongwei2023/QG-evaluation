#include <stdio.h>
#include <stdlib.h>


struct Node {
    int data;
    struct Node* next;
};

// �½���ջ
struct Node* createStack() {
    return NULL;
}

// �ж���ջ�Ƿ�Ϊ��
int isEmpty(struct Node* top) {
    return top == NULL;
}

// ��ջ����
struct Node* push(struct Node* top, int data) {
    // �����½ڵ�
    struct Node *temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    // ���½ڵ��������ͷ
    temp->next = top;
    top = temp;
    return top;
}

// ��ջ����
struct Node* pop(struct Node* top) {
    if (!isEmpty(top)) {
        // ���浱ǰջ���ڵ�
        struct Node* temp = top;
        // ջ��ָ��ָ����һ���ڵ�
        top = top->next;
        // �ͷŵ�ǰջ���ڵ�
        free(temp);
    } else {
        printf("Stack is empty!");
    }
    return top;
}

// ȡջ��Ԫ��
int getTop(struct Node* top) {
    if (!isEmpty(top)) {
        return top->data;  // ����ջ��Ԫ��
    } else {
        printf("Stack is empty!");
        return -1;
    }
}

//����ջ
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


