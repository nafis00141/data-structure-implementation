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

void print_levelorder_in_level(node* head){

    queue<node*>q;
    queue<int>qi;

    q.push(head);
    qi.push(0);
    int last_level = 0;
    node* n = NULL;
    int l = 0;

    while(q.empty()==false){

        n = q.front();
        q.pop();

        l = qi.front();
        qi.pop();

        if(last_level!=l){
            cout<<"\n";
            last_level = l;
        }

        cout<<n->val<<" ";

        if(n->left!=NULL){
            q.push(n->left);
            qi.push(l+1);
        }
        if(n->right!=NULL){
            q.push(n->right);
            qi.push(l+1);
        }


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


node* reconstruct_bst_from_postorder(vector<int>v,int st,int en){

    node* temp = create_node(v[en]);

    if(st==en) return temp;

    int t = en-1;

    while(v[t]>v[en] && t>st){
        t--;
    }

    node* l = NULL;

    node* r = NULL;

    if(t==st && v[t]>v[en]){
        //no left subtree
        r = reconstruct_bst_from_postorder(v,st,en-1);
    }
    else if(t==en-1 && v[t]<v[en]){
        //no right subtree
        l = reconstruct_bst_from_postorder(v,st,en-1);
    }
    else{
        //has both subtree
        l = reconstruct_bst_from_postorder(v,st,t);
        r = reconstruct_bst_from_postorder(v,t+1,en-1);
    }

    temp->left = l;

    temp->right = r;

    return temp;

}


#endif // BINARY_SEARCH_TREE_H_INCLUDED
