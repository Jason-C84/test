#include <iostream>
#include <cstdlib>

using namespace std;

typedef struct Node{
    int data;
    Node *right;
    Node *left;
};

Node *CreateNode(int data){
    Node *NewNode = (Node*)malloc(sizeof(Node));
    if (NewNode == NULL){
        cout << "malloc fail" << endl;
        return NULL;
    }
    NewNode->data = data;
    NewNode->right = NewNode->left = NULL;
    return NewNode;
}

Node *CreateList(int headval){
    Node *Newlist = CreateNode(headval);
    return Newlist;
}

Node *AppendNode(Node *head, int data){
    Node *NewNode = CreateNode(data);
    if (NewNode == NULL){
        cout << "malloc failed" << endl;
        return NULL;
    }
    Node *p = NULL;
    Node *q = NULL;
    p = head;

    while(p != NULL){
        q = p;
        p = p->right;
    }

    q->right = NewNode;
    NewNode->left = q;

    return head;
}

void PrintList(Node *Nodelist){
    if (Nodelist == NULL){
        cout << "empty list" << endl;
        return;
    }
    Node *p = Nodelist;
    while(p != NULL){
        cout << "p->data = " << p->data << endl;
        p = p->right;
    }
}

Node *findNode(Node *head, int data){
    if (head == NULL){
        cout << "empty list" << endl;
        return NULL;
    }
    Node *p = head;
    while(p != NULL){
        if(p->data == data){
            cout << "find it!" << endl;
            return p;
        }
        p = p->right;
    }
    cout << "not find" << endl;
    return NULL;
}

Node *InsertNode(Node *head, int data){
    Node *NewNode = CreateNode(data);
    if (NewNode == NULL){
        cout << "malloc failed insert" << endl;
        return head;
    }
    if (head->right == NULL){
        head->right = NewNode;
        NewNode->left = head;
        return head;
    }
    if(head->right->data > NewNode->data){
        NewNode->right = head->right;
        head->right->left = NewNode;
        head->right = NewNode;
        NewNode->left = head;
        return head;
    }
    Node *pHead = head->right;
    Node *preHead;
    while(pHead->data < NewNode->data && pHead != NULL){
        preHead = pHead;
        pHead = pHead->right;
    }
    if (pHead == NULL){
        preHead->right = NewNode;
        NewNode->left = preHead;
        return head;
    }else{
       NewNode->right = pHead;
       pHead->left = NewNode;
       preHead -> right = NewNode;
       NewNode->left = preHead;
       return head;
    }
}


Node *deleteNode(Node *head, int data){
    Node *p = findNode(head, data);
    if(p == NULL){
        cout << "not found" << endl;
        return head;
    }
    Node *pHead = NULL;
    if(p->left->left == NULL){
        p->left->right = p->right;
        p->right->left = p->left;
    }
    if(p->right == NULL){
        p->left->right = NULL;
    }else{
        p->left->right = p->right;
        p->right->left = p->left;
    }
    free(p);
    return head;
}

int main(int argc,char *argv[]){
    Node *head = CreateList(-1);
    if (head == NULL){
        cout << "create list failed" << endl;
        return -1;
    }
    Node *pHead = head;

    for(int i = 0; i < 10; i++){
        head = AppendNode(head, 3*i+1);
    }

    PrintList(head->right);
    Node *pfind = findNode(head->right, 10);
    cout << "find:" << pfind->data << endl;
    cout << "=======InsertNode==========" << endl;
    Node *insNd = InsertNode(head, 14);
    PrintList(insNd);
    cout << "=======deleteNode==========" << endl;
    Node *delNd = deleteNode(head, 25);
    PrintList(delNd);

    return 0;
}

