#include <iostream>
#include <cstdlib>

using namespace std;

class Node{
public:
    Node():data(0), next(NULL){};
    Node(int val):data(val), next(NULL){};
    int data;
    Node *next;
};

class MyStack{
public:
    MyStack():top(NULL){};
    void push(Node node);
    void pop(Node &node);
    bool IsEmpty();
    Node *top;
};

class MyQueue{
public:
    void enqueue(Node node);
    void dequeue(Node &node);
    bool IsEmpty();
private:
    MyStack s1;
    MyStack s2;
};

bool MyStack::IsEmpty(){
    return (top == NULL);
}

void MyStack::push(Node node){
    Node *pNode = new Node(node.data);
    pNode->next = top;
    top = pNode;
}

void MyStack::pop(Node &node){
    Node *pNode = NULL;
    if(IsEmpty() == true){
        cout << "empty stack" << endl;
    }else{
        pNode = top;
        node.data = top->data;
        top = top->next;
        delete pNode;
    }
}

bool MyQueue::IsEmpty(){
    return (s1.top == NULL && s2.top == NULL);
}

void MyQueue::enqueue(Node node){
    s1.push(node);
}

void MyQueue::dequeue(Node &node){
    Node temp(0);
    if(IsEmpty() == true){
        cout << "empty queue" << endl;
        return;
    }
    if(s2.IsEmpty() == true){
        while(s1.IsEmpty() != true){
            s1.pop(temp);
            s2.push(temp);
        }
    }
    if(s2.IsEmpty() != true){
        s2.pop(node);
    }

}

int main(int argc, char *argv[]){
    MyQueue q;
    Node node(0);

    q.enqueue(Node(1));
    q.enqueue(Node(2));
    q.enqueue(Node(3));

    q.dequeue(node);
    cout << "dequeue:" << node.data << endl;
    q.dequeue(node);
    cout << "dequeue:" << node.data << endl;
    q.dequeue(node);
    cout << "dequeue:" << node.data << endl;

    return 0;
}
