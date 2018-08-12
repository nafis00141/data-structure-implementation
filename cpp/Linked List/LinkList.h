#ifndef LINKLIST_H_INCLUDED
#define LINKLIST_H_INCLUDED
#include<bits/stdc++.h>
using namespace std;

struct node{
    int val;
    node* next;

    node(int x){
        val = x;
        next = NULL;
    }
};


node* copyNode(node* n){

    return new node(n->val);

}


void print_list(node** head){

    node* temp = *head;

    while(temp!=NULL){
        cout<<temp->val<<" ";
        temp = temp->next;
    }
    cout<<"\n";

    delete(temp);
}


void insert_front(node** head,int x){

    node* temp = new node(x);

    temp->next = *head;

    *head = temp;

}

void insert_end(node** head,int x){

    node* temp = new node(x);

    node* ite = *head;

    if(ite==NULL){
        insert_front(head,x);
        return;
    }

    while(ite->next!=NULL){
        ite = ite->next;
    }

    ite->next = temp;

}

void inset_node_nth_position(node** head,int x,int position){

    node* ite = *head;

    if(ite==NULL){
        insert_front(head,x);
        return;
    }

    node* temp = new node(x);

    int i = 1;

    node* pre = NULL;

    while(ite!=NULL){
        if(i==position){
            temp->next = pre->next;
            pre->next = temp;
            break;
        }
        pre = ite;
        ite = ite->next;
        i++;
    }


}

void delete_from_front(node** head){

    *head = (*head)->next;

}

void delete_from_end(node** head){

    node* ite = *head;

    node* pre = NULL;

    while(ite->next!=NULL){
        pre = ite;
        ite = ite->next;
    }

    pre->next = NULL;

}


void delete_node_nth_position(node** head,int position){

    node* ite = *head;

    int i = 1;

    node* pre = NULL;

    while(ite!=NULL){
        if(i==position){
            pre->next = ite->next;
            break;
        }
        pre = ite;
        ite = ite->next;
        i++;
    }


}

int get_size(node** head){

    node* ite = *head;

    int i = 0;

    if(ite==NULL){
        return i;
    }
    else i++;

    while(ite->next!=NULL){
        ite = ite->next;
        i++;
    }

    return i;

}

void clear_list(node** head){

    node* ite = *head;

    *head = NULL;

    while(ite!=NULL){
        node* pre = ite;
        ite = ite->next;
        delete(pre);
    }

}

node* reverse_list(node* head){

    if(head==NULL) return head;

    node* ite = head;
    node* rev = NULL;

    while(ite!=NULL){
        node* temp = copyNode(ite);
        ite = ite->next;
        temp->next = rev;
        rev = temp;
    }

    return rev;

}


/*

Given a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.

Input: head = 1->4->3->2->5->2, x = 3
Output: 1->2->2->4->3->5

*/

node* partition_list(node* head, int x) {

    if(head==NULL) return head;

    node* insertPosition = head;
    node* preTemp = NULL;
    node* temp = head;

    while(temp!=NULL){
        if(temp->val>=x) break;
        insertPosition = temp;
        preTemp = temp;
        temp = temp->next;
    }

    //cout<<insertPosition->val<<"\n";
    //if(preTemp!=NULL)cout<<preTemp->val<<"\n";


    bool flag = true;
    if(insertPosition==head && head->val>=x){
        flag = false; ///insert in head
    }


    while(temp!=NULL){

        if(temp->val<x){
            node* t = temp;
            if(preTemp!=NULL)preTemp->next = temp->next;
            temp = preTemp->next;

            if(flag==false){
                t->next = insertPosition;
                insertPosition = head = t;
                flag = true;
            }
            else{
                t->next = insertPosition->next;
                insertPosition->next = t;
                insertPosition = insertPosition->next;
            }

        }
        else{
            preTemp = temp;
            temp = temp->next;
        }

    }

    return head;

}


#endif // LINKLIST_H_INCLUDED
