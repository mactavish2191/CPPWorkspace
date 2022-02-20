#include <iostream>

struct simpleQueue {
    int front = -1;
    int rear = -1;
    int capacity = 0;
    int *array = nullptr;
};
//create function
simpleQueue* createQueue(int size)
{
    simpleQueue *Q = (simpleQueue*)malloc(sizeof(simpleQueue));
    if(Q == nullptr)
        return nullptr;
    Q->front = -1;
    Q->rear = -1;
    Q->capacity = size;
    Q->array = (int*)malloc(Q->capacity * sizeof(int));
    if(Q->array == nullptr)
        return nullptr;
    
    return Q;
}

//helper function
int isEmptyQueue(simpleQueue *Q){
    return (Q->front == -1);
}

int isFullQueue(simpleQueue *Q){
    return ((Q->rear+1) % Q->capacity == Q->front);
}

int queueSize(simpleQueue *Q){
    return (Q->capacity - Q->front + Q->rear +1) % Q->capacity;
}
// main queue operation
void enqueue(simpleQueue *Q, int data)
{
    if(isFullQueue(Q)){
        std::cout << "Queue is full.\n";
        return;
    }
    Q->rear = (Q->rear+1) % Q->capacity;
    Q->array[Q->rear] = data;
    if(Q->front == -1)
        Q->front = Q->rear;
}

//main queue operation
int dequeue(simpleQueue *Q)
{
    int data{0};
    if(isEmptyQueue(Q)){
        std::cout << "Queue is empty.\n";
        return 0;
    }
    else
    {
        data = Q->array[Q->front];
        if(Q->front == Q->rear)
            Q->front = Q->rear = -1;
        else
            Q->front = (Q->front+1) % Q->capacity;
    }
    return data;
}

void deleteQueue(simpleQueue *Q)
{
    if(Q){
        if(Q->array){
            free(Q->array);
        }
        free(Q);
    }
}

void printQueue(simpleQueue *Q)
{
    if(Q->front == -1){
        std::cout << "Empty queue.\n";
        return;
    }
    else
    {
        std::cout << "Queue :";
        for(int i=Q->front; i<= Q->rear; i++)
            std::cout << Q->array[i] << " ";
        
        std::cout <<"\n";
    }
}

int main() {
    simpleQueue *q = createQueue(5);
    enqueue(q, 1);
    enqueue(q, 2);
    enqueue(q, 3);
    printQueue(q);
    std::cout << queueSize(q) <<"\n";
    dequeue(q);
    printQueue(q);
    std::cout << queueSize(q) <<"\n";
    
    deleteQueue(q);
    return 0;
}
