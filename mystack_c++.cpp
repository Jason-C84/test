#include <iostream>

using namespace std;

class Node{
public:
    Node():data(0), next(NULL){};
    Node(int n):data(n), next(NULL){};
    int data;
    Node *next;
};

class MyStack{
public:
    MyStack():top(NULL){};
    void push(Node node);
    void pop(Node *node);
    bool IsEmpty();
    Node *top;
};

bool MyStack::IsEmpty(){
    return (top == NULL);
}

void MyStack::push(Node node){
    Node *pNode = new Node(node.data);
    pNode->next = top;
    top = pNode;
}

void MyStack::pop(Node *data){
    if(IsEmpty()==true){
        return ;
    }
    data->data = top->data;
    Node *p = top;
    top = top->next;
    delete p;
}

int main(int argc, char *argv[]){
    Node data(0);
    MyStack s;
    s.push(Node(1));
    s.push(Node(2));
    s.push(Node(3));

    s.pop(&data);
    cout << "data.data = " << data.data << endl;
    s.pop(&data);
    cout << "data.data = " << data.data << endl;
    s.pop(&data);
    cout << "data.data = " << data.data << endl;
    s.push(Node(4));
    s.pop(&data);
    cout << "data.data = " << data.data << endl;
    cout << "IsEmpty = " << s.IsEmpty() <<endl;
}
