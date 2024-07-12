//Implement queue and its operations like enqueue, dequeue, traverse, search.


#include<stdio.h>

#define MAX 100

typedef struct{
    int front, rear;
    int values[MAX];
}Queue;

void initQueue(Queue *s){
    s->front=-1;
    s->rear=-1;
}

int isFull(Queue *s){
    return (s->rear == MAX - 1);
}

int isEmpty(Queue *s){
    return (s->front == -1 || s->front > s->rear);
}

void enqueue(Queue *s, int value){
    if(isFull(s)){
        printf("Queue is full\n");
        return;
    } else{
        if(s->front == -1) s->front =0;
        s->rear = ++(s->rear);
        s->values[s->rear] = value;
        printf("%d is enqueued to the queue\n",value);
    }
}
int dequeue(Queue *s){
    if(isEmpty(s)){
        printf("Queue is empty\n");
        return -1;
    } else{
        int item = s->values[(s->front)++];
        if (s->front > s->rear) {
            s->front = s->rear = -1;
        }
        printf("%d dequeued from queue\n", item);
        return item;
    }
}



int main(){
    Queue s;
    initQueue(&s);

    enqueue(&s, 1);
    enqueue(&s, 2);
    enqueue(&s, 3);
    
    printf("\n");

    dequeue(&s);
    dequeue(&s);
    dequeue(&s);
    dequeue(&s);

    return 0;
}