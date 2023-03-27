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

Queue *create_queue()		//创建空队列 
{
    Queue *queue = (Queue *) malloc(sizeof(Queue));
    queue->front = NULL;
    queue->rear = NULL;
    return queue;
}

int is_empty(Queue *queue) {
    return (queue->front == NULL);
}

void enqueue(Queue *queue, void *data)	//将一个元素加入队列中，接受两个参数：指向队列的指针和要加入队列的元素的指针
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

void *dequeue(Queue *queue)	//从队列中取出一个元素，并返回其指针
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



