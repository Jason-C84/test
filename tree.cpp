#include <iostream>

using namespace std;

class Node{
public:
    Node():data(-1),parent(NULL),left(NULL),right(NULL){};
    Node(int val):data(val),parent(NULL),left(NULL),right(NULL){};
    int data;
    Node *parent;
    Node *left;
    Node *right;
};

class Tree{
public:
    Tree(int num[], int len);
    void insertNode(int data);
    void insertNode1(int data);
    Node *searchNode(int data);
    void deleteNode(int data);

    void InOrderTree();
    void PreOrderTree();
    void PostOrderTree();

private:
    void insertNode(Node* current, int data);
    void insertNode1(Node* current, int data);
    void deleteNode(Node* current);
    Node *searchNode(Node* current, int data);

    void InOrderTree(Node* current);
    void PreOrderTree(Node* current);
    void PostOrderTree(Node* current);

private:
    Node *root;
};

Tree::Tree(int num[], int len){
    root = new Node(num[0]);
    for (int i = 1; i < len; i++){
        insertNode(num[i]);
    }
}

void Tree::insertNode(int data){
    Node *node = new Node(data);
    Node *p = NULL;
    Node *q = NULL;

    p = q = root;

    while(p != NULL){
        q = p;
        if(p->data > node->data){
            p = p->left;
        }else if(p->data < node->data){
            p = p->right;
        }else{
            cout << "delete node" << endl;
            delete node;
            return;
        }
    }

    node->parent = q;
    if (node->data > q->data){
        q->right = node;
    }else{
        q->left = node;
    }
}

void Tree::insertNode1(int data){
    if(root != NULL){
        insertNode1(root, data);
    }else{
        cout << "root is null" << endl;
    }
}

void Tree::insertNode1(Node *current, int data){
    if(current->data > data){
        if(current->left == NULL){
            Node *node = new Node(data);
            current->left = node;
            current->left->parent = current;
        }else{
            insertNode1(current->left, data);
        }
    }else if(current->data < data){
        if(current->right == NULL){
            Node *node = new Node(data);
            current->right = node;
            current->right->parent = current;
        }else{
            insertNode1(current->right, data);
        }
    }
}

Node *Tree::searchNode(int data){
    Node *node = NULL;
    if (root != NULL){
        node = searchNode(root, data);
    }
    return node;
}

Node *Tree::searchNode(Node *current, int data){
    if(current->data > data){
        if(current->left == NULL){
            return NULL;
        }
        return searchNode(current->left, data);
    }else if(current->data < data){
        if(current->right == NULL){
            return NULL;
        }
        return searchNode(current->right, data);
    }else {
        return current;
    }
}

void Tree::deleteNode(int data){
    if(root != NULL){
        Node *node = searchNode(data);
        if(node != NULL)
        {
            deleteNode(node);
        }
    }
}

void Tree::deleteNode(Node*current){
    if(current->left != NULL){
        deleteNode(current->left);
    }
    if(current->right != NULL){
        deleteNode(current->right);
    }

    if(current->parent == NULL){
        delete current;
        root = NULL;
        return;
    }
    if(current->parent->data > current->data){
        current->parent->left = NULL;
    }else if(current->parent->data < current->data){
        current->parent->right = NULL;
        return;
    }

    delete current;
}

void Tree::InOrderTree(){
    if(root != NULL){
        InOrderTree(root);
    }
    return;
}

void Tree::PreOrderTree(){
    if(root != NULL){
        PreOrderTree(root);
    }
}

void Tree::PostOrderTree(){
    if(root != NULL){
        PostOrderTree(root);
    }
}

void Tree::InOrderTree(Node *current){
    if(current != NULL){
        InOrderTree(current->left);
        cout << current->data << endl;
        InOrderTree(current->right);
    }
}

void Tree::PreOrderTree(Node *current){
    if(current != NULL){
        cout << current->data << endl;
        PreOrderTree(current->left);
        PreOrderTree(current->right);
    }
}

void Tree::PostOrderTree(Node *current){
    if(current != NULL){
        PostOrderTree(current->left);
        PostOrderTree(current->right);
        cout << current->data << endl;
    }
}

int main(int argc, char *argv[]){
    int num[] = {5,3,7,2,4,6,8,1,9};
    cout << "before tree" << endl;
    Tree tree(num, 9);
    cout << "after tree"<<endl;
    cout << "InOrderTree:" << endl;
    tree.InOrderTree();
    cout << "PreOrderTree:" << endl;
    tree.PreOrderTree();
    cout << "PostOrderTree:" << endl;
    tree.PostOrderTree();

    return 0;
}
