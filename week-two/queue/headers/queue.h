#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    void *data;
    struct node *next;
} Node;

typedef struct queue {
    Node *front;
    Node *rear;
} Queue;

Queue *create_queue()		//�����ն��� 
{
    Queue *queue = (Queue *) malloc(sizeof(Queue));
    queue->front = NULL;
    queue->rear = NULL;
    return queue;
}

int is_empty(Queue *queue) {
    return (queue->front == NULL);
}

void enqueue(Queue *queue, void *data)	//��һ��Ԫ�ؼ�������У���������������ָ����е�ָ���Ҫ������е�Ԫ�ص�ָ��
{
    Node *new_node = (Node *) malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = NULL;
    if (is_empty(queue)) {
        queue->front = new_node;
    } else {
        queue->rear->next = new_node;
    }
    queue->rear = new_node;
}

void *dequeue(Queue *queue)	//�Ӷ�����ȡ��һ��Ԫ�أ���������ָ��
{
    if (is_empty(queue)) {
        printf("Error: Queue is empty");
        return NULL;
    }
    Node *temp = queue->front;
    void *data = temp->data;
    queue->front = temp->next;
    if (queue->front == NULL) {
        queue->rear = NULL;
    }
    free(temp);
    return data;
}



