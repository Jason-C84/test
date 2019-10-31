#include <iostream>
#include <cstdlib>

using namespace std;

typedef struct Node{
    int data;
    Node *next;
};

typedef struct MyStack{
    Node *top;
};

MyStack *CreateStack(){
    MyStack *s = (MyStack *)malloc(sizeof(MyStack));
    s->top = NULL;
    return s;
}

void Push(MyStack *s, int data){
    Node *pNode = (Node *)malloc(sizeof(Node));
    pNode->data = data;
    pNode->next = s->top;
    s->top = pNode;
}

bool IsEmpty(MyStack *s){
    return (s->top == NULL);
}

void *Pop(MyStack *s, Node **node){
    Node *pNode = s->top;
    if (pNode == NULL){
        cout << "empty stack" << endl;
    }else {
        (*node)->data = pNode->data;
        s->top = s->top->next;
        free(pNode);
    }

}


int main(){
    MyStack *s = CreateStack();
    if (s == NULL){
        cout << "create stack failed" << endl;
        return -1;
    }

    Push(s, 1);
    Push(s, 2);
    Push(s, 3);
    Push(s, 4);

    Node *node = (Node*)malloc(sizeof(Node));
    Pop(s, &node);
    cout << "node->data = " << node->data << endl;
    Pop(s, &node);
    cout << "node->data = " << node->data << endl;
    Pop(s, &node);
    cout << "node->data = " << node->data << endl;
    Pop(s, &node);
    cout << "node->data = " << node->data << endl;
    Pop(s, &node);
    cout << "node->data = " << node->data << endl;

    cout << "IsEmpty = " << ((IsEmpty(s) == true)?1:0) << endl;
    free(node);
    return 0;

}
