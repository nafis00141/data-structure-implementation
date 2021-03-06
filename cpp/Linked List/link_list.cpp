#include<bits/stdc++.h>
#include "LinkList.h"
using namespace std;

int main(){

    node* head = NULL;

    cout<<"list size: "<<get_size(&head)<<"\n";


    for(int i=5;i<=10;i++){
        insert_end(&head,i);
    }

    cout<<"inserted end\n";

    print_list(&head);

    cout<<"list size: "<<get_size(&head)<<"\n";

    for(int i=1;i<=4;i++){
        insert_front(&head,i);
    }

    cout<<"inserted front\n";

    print_list(&head);

    cout<<"list size: "<<get_size(&head)<<"\n";

    inset_node_nth_position(&head,11,6);

    cout<<"inserted at 6th position\n";

    print_list(&head);

    cout<<"list size: "<<get_size(&head)<<"\n";

    delete_from_front(&head);

    cout<<"delete from front\n";

    print_list(&head);

    cout<<"list size: "<<get_size(&head)<<"\n";

    delete_from_end(&head);

    cout<<"delete from end\n";

    print_list(&head);

    cout<<"list size: "<<get_size(&head)<<"\n";

    delete_node_nth_position(&head,5);

    cout<<"delete at 5th position\n";

    print_list(&head);

    cout<<"list size: "<<get_size(&head)<<"\n";

    cout<<"reverse list: ";

    node* reverseList = reverse_list(head);

    print_list(&reverseList);

    cout<<"reverse list size: "<<get_size(&reverseList)<<"\n";

    cout<<"list size: "<<get_size(&head)<<"\n";

    head = partition_list(head, 3);

    print_list(&head);

    cout<<"partition list size: "<<get_size(&head)<<"\n";

    head = removeNthFromEnd(head,3);

    print_list(&head);

    cout<<"Remove Nth Node From End of List size: "<<get_size(&head)<<"\n";

    cout<<"clear list\n";

    clear_list(&head);

    cout<<"list size: "<<get_size(&head)<<"\n";

}
