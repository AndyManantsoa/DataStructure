#include<iostream>

#define MAX 100

typedef struct{
    int value;
    int priority;
}Queue;

Queue queue[MAX];
int size =0;

void enqueue(int value, int priority){
    if(size==MAX){
        std::cout<<"Priority queue overflow\n";
    }else{
        Queue newQueue = {value, priority};
        // Queue *newQueue;
        // newQueue->value=value;
        // newQueue->priority=priority;
        queue[size++]= newQueue;
        std::cout<<"the Value: "<<value<<" Of priority "<<priority<<" is inserted to the queue\n";
    }
}

int dequeue(){
    if (size==0){
        std::cout<<"Priority queue underflow\n";
    }
}
int main(){

}