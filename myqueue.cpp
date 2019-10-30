#include <iostream>
#include <cstdlib>

using namespace std;

typedef struct Node{
    int data;
    Node *next;
};

typedef struct MyQueue{
    Node *front;
    Node *rear;
};

MyQueue *CreateQueue(){
    MyQueue *q = (MyQueue *)malloc(sizeof(MyQueue));
    if (q == NULL){
        cout << "create queue failed" << endl;
        return q;
    }
    q->front = NULL;
    q->rear = NULL;
    return q;
}

MyQueue *enqueue(MyQueue *q, int data){
    Node *pNode = (Node *)malloc(sizeof(Node));
    pNode->data = data;
    pNode->next = NULL;
    if (pNode == NULL){
        cout << "malloc failed" << endl;
        return q;
    }

    if(q->rear == NULL){
        q->rear = q->front = pNode;
    }else{
        q->rear->next = pNode;
        q->rear = pNode;
    }

    return q;
}

MyQueue *dequeue(MyQueue *q){
    Node *pNode = q->front;
    if (pNode == NULL){
        cout << "empty queue" << endl;
        return q;
    }
    q->front = q->front->next;
    if(q->front == NULL){
        q->rear = NULL;
    }
    free(pNode);
    return q;
}

int Getlen(MyQueue *q){
    Node *pNode = q->front;
    int length = 0;
    if(pNode == NULL){
        length = 0;
        return length;
    }
    if(pNode != NULL){
        length = 1;
    }
    while(pNode != q->rear){
        pNode = pNode->next;
        length++;
    }

    return length;
}

void printQueue(MyQueue *q){
    Node *pNode = q->front;
    if (pNode == NULL){
        cout << "empty queue" << endl;
        return;
    }
    while(pNode != q->rear){
        cout << "pNode->data = " << pNode->data << endl;
        pNode = pNode -> next;
    }
    cout << "pNode->data = " << pNode->data << endl;
}


int main(int argc, char *argv[]){
    MyQueue *mq = CreateQueue();
    enqueue(mq, 1);
    enqueue(mq, 2);
    enqueue(mq, 3);
    enqueue(mq, 4);
    int len = 0;
    len = Getlen(mq);
    cout << "len = " << len << endl;
    printQueue(mq);
    dequeue(mq);
    dequeue(mq);
    dequeue(mq);
    dequeue(mq);
    dequeue(mq);
    enqueue(mq, 4);
    enqueue(mq, 41);
    enqueue(mq, 42);
    len = Getlen(mq);
    cout << "len = " << len << endl;
    printQueue(mq);

    return 0;
}

