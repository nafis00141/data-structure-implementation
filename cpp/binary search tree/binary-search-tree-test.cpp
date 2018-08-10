#include<bits/stdc++.h>
#include "binary_search_tree.h"
using namespace std;

int main(){
    node* head = NULL;

    int t,a;

    cin>>t;

    while(t--){
        cin>>a;
        head = insert_node(head,a);
    }

    cout<<"inorder traversal\n";
    print_inorder(head);
    cout<<"\n";
    cout<<"preorder traversal\n";
    print_preorder(head);
    cout<<"\n";
    cout<<"postorder traversal\n";
    print_postorder(head);
    cout<<"\n";
    cout<<"levelorder traversal\n";
    print_levelorder(head);
    cout<<"\n";
    cout<<"tree minimum\n";
    cout<<tree_minimum(head)->val;
    cout<<"\n";
    cout<<"tree maximum\n";
    cout<<tree_maximum(head)->val;
    cout<<"\n";
    cin>>a;
    cout<<"search BST\n";
    cout<<search_bst(head,a)->val;
    cout<<"\n";
    cin>>a;
    cout<<"search BST\n";
    cout<<search_bst(head,a)->val;
    cout<<"\n";

}


/*
7
30 20 40 10 25 35 45
25
43
*/
