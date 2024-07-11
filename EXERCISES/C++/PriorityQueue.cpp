#include<iostream>

#define MAX 100

typedef struct{
    int value;
    int priority;
}Queue;

Queue pqueue[MAX];
int size =0;

void enqueue(int value, int priority){
    if(size==MAX){
        std::cout<<"Priority queue overflow\n";
    }else{
        Queue newQueue = {value, priority};
        pqueue[size++]= newQueue;
        std::cout<<"the Value: "<<value<<" Of priority "<<priority<<" is inserted to the queue\n";
    }
}

int dequeue(){
    if (size==0){
        std::cout<<"Priority queue underflow\n";
        return -1;
    } else{
        int highestPriority = pqueue[0].priority;
        int index =0;

        for(int i=1;i<size;i++){
            if(pqueue[i].priority> highestPriority){
                highestPriority = pqueue[i].priority;
                index=i;
            }
        }
        int value = pqueue[index].value;
        for(int i=index;i<size-1;i++){
            pqueue[i]=pqueue[i+1];
        }
        size--;
        return value;
    }

}
int main(){
    enqueue(10, 1);
    enqueue(20, 2);
    enqueue(30, 3);
    std::cout<<"Dequeued element with highest priority:" << dequeue()<<"\n";
    std::cout<<"Dequeued element with highest priority:" << dequeue()<<"\n";
    return 0;

}