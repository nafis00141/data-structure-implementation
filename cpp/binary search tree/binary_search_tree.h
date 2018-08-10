#ifndef BINARY_SEARCH_TREE_H_INCLUDED
#define BINARY_SEARCH_TREE_H_INCLUDED
#include<bits/stdc++.h>
using namespace std;

class node{
    public:
        int val;
        node* left;
        node* right;
};

node* create_node(int x){
    node* temp = new node();
    temp->val = x;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

void print_inorder(node* head){

    if(head==NULL) return;
    print_inorder(head->left);
    cout<<head->val<<" ";
    print_inorder(head->right);

}

void print_preorder(node* head){

    if(head==NULL) return;
    cout<<head->val<<" ";
    print_preorder(head->left);
    print_preorder(head->right);

}

void print_levelorder(node* head){

    queue<node*>q;

    q.push(head);

    while(q.empty()==false){
        node* cur = q.front();
        q.pop();
        cout<<cur->val<<" ";
        if(cur->left!=NULL) q.push(cur->left);
        if(cur->right!=NULL) q.push(cur->right);

    }

}

node * tree_minimum(node* head){

    if(head->left==NULL) return head;
    return tree_minimum(head->left);

}

node * tree_maximum(node* head){

    if(head->right==NULL) return head;
    return tree_maximum(head->right);

}


void print_postorder(node* head){

    if(head==NULL) return;
    print_postorder(head->left);
    print_postorder(head->right);
    cout<<head->val<<" ";

}

node* search_bst(node* head,int x){



    if(head==NULL){
        return create_node(-1);
    }

    if(head->val==x) return head;
    else if(head->val>x) return search_bst(head->left,x);
    else return search_bst(head->right,x);

}

node* insert_node(node* head,int val){

    node* t = create_node(val);

    if(head==NULL){
        head = t;
    }
    else{
        node* temp = head;

        while(true){
            if(temp->val>t->val){
                if(temp->left==NULL){
                    temp->left = t;
                    break;
                }
                else{
                    temp = temp->left;
                }
            }
            else{
                if(temp->right==NULL){
                    temp->right = t;
                    break;
                }
                else{
                    temp = temp->right;
                }
            }
        }

    }

    return head;
}


#endif // BINARY_SEARCH_TREE_H_INCLUDED
