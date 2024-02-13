#include<bits/stdc++.h>
using namespace std;
#define int long long
struct listNode
{
    int val;
    listNode* next;
    listNode(int x):val(x),next(nullptr){}
};
void sol()
{
    function<listNode*(listNode*)>reverse_list=[&](listNode* head)->listNode*
    {
        listNode* previous=nullptr;
        listNode* current=head;
        while(current!=nullptr)
        {
            listNode* tmp=current->next;
            current->next=previous;
            previous=current;
            current=tmp;
        }
        return previous;
    };
    /*
        Approach of zip_linked_list function:
        1. Find the middle of the linked list.
        2. Reverse the second half of the linked list.
        3. Merge the first half and the second half of the linked list.
    */
    function<listNode*(listNode*)>zip_linked_list=[&](listNode* head)->listNode*
    {
        if(head==nullptr||head->next==nullptr)
        {
            return head;
        }
        listNode* slow=head;
        listNode* fast=head;
        while(fast->next!=nullptr&&fast->next->next!=nullptr)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        /*
            slow is the middle of the linked list.
        */
        listNode* second_half=slow->next;
        slow->next=nullptr;
        second_half=reverse_list(second_half);
        listNode* first_ptr=head;
        listNode* second_ptr=second_half;
        /*
            Merge the first half and the second half of the linked list.
        */
        while(second_ptr!=nullptr)
        {
            listNode* tmp1=first_ptr->next;
            listNode* tmp2=second_ptr->next;
            first_ptr->next=second_ptr;
            second_ptr->next=tmp1;
            first_ptr=tmp1;
            second_ptr=tmp2;
        }
        return head;
    };
    function<void(listNode*)>print_list=[&](listNode* head)
    {
        while(head!=nullptr)
        {
            cout<<head->val<<" ";
            head=head->next;
        }
        cout<<endl;
    };
    int k;
    cin>>k;
    listNode* head=nullptr;
    listNode* tail=nullptr;
    for(int i=0;i<k;++i)
    {
        int val;
        cin>>val;
        if(head==nullptr)
        {
            head=new listNode(val);
            tail=head;
        }
        else
        {
            tail->next=new listNode(val);
            tail=tail->next;
        }
    }
    head=zip_linked_list(head);
    print_list(head);
}
signed main()
{
    int t;
    cin>>t;
    while(t--)
    {
        sol();
    }
    return 0;
}