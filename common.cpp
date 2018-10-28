#include "common.h"

int print_list_node(ListNode *head)
{
    int ret=0;
    while(head){
        ++ret;
        cout<<head->val<<" ";
        head=head->next;
    }
    cout<<endl;
    return ret;
}

ListNode *make_list(vector<int> v)
{
    ListNode dummy(-1),*cur=&dummy;
    for(auto i:v){
        ListNode* p=new ListNode(i);
        cur->next=p;
        cur=cur->next;
    }
    return dummy.next;
}
