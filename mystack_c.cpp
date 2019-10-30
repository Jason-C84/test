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

void push(MyStack *s, int data){
    Node *pNode = (Node*)malloc(sizeof(Node));
    pNode->data = data;
    pNode->next = NULL;

    pNode->next = s->top;
    s->top = pNode;
}

bool isEmpty(MyStack *s){
    return (s->top == NULL);
}

Node *pop(MyStack *s){
    Node *pNode = NULL;
    if (isEmpty(s) == true){
        cout << "empty stack" << endl;
    }else{
        pNode = s->top;
        s->top = s->top->next;
    }

    return pNode;
}



int main(int argc, char *argv[]){
    MyStack *s = CreateStack();
    if (s == NULL){
        cout << "create stack fail" << endl;
        return -1;
    }
    push(s, 1);
    push(s, 2);
    push(s, 3);

    Node *top = NULL;
    top = pop(s);
    if(top != NULL){
       cout << "top->data = " << top->data << endl;
       free(top);
    }
    top = pop(s);
    if(top != NULL){
       cout << "top->data = " << top->data << endl;
       free(top);
    }
    top = pop(s);
    if(top != NULL){
       cout << "top->data = " << top->data << endl;
       free(top);
    }
    top = pop(s);
    if(top != NULL){
       cout << "top->data = " << top->data << endl;
    }




    return 0;
}
