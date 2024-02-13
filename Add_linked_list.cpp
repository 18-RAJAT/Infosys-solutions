#include<bits/stdc++.h>
using namespace std;
#define int long long
struct listNode
{
    int val;
    listNode* next;
    //Constructor
    listNode(int x):val(x),next(nullptr){}
};
void sol()
{
    /*
        Approach:
        1. Reverse the linked list because we have to add 1 to the number represented by the linked list.
        2. Add 1 to the number represented by the linked list.
        3. Reverse the linked list again.
    */
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
    function<listNode*(listNode*)>addOneToList=[&](listNode* head)->listNode*
    {
        head=reverse_list(head);
        listNode* current=head;
        int carry=1;
        while(current!=nullptr)
        {
            current->val+=carry;
            carry=current->val/10;
            current->val%=10;
            // If carry is 0 then we don't need to add 1 to the number represented by the linked list.
            if(carry==0)
            {
                break;
            }
            if(current->next==nullptr)
            {
                current->next=new listNode(0);
            }
            // else if(current->next!=nullptr)
            // {
            //     current=current->next;
            // }
            current=current->next;
        }
        head=reverse_list(head);
        return head;
    };
    int n;
    cin>>n;
    listNode* head=nullptr;
    listNode* tail=nullptr;
    auto print_list=[&](listNode* head)
    {
        listNode* current=head;
        while(current!=nullptr)
        {
            cout<<current->val<<" ";
            current=current->next;
        }
    };
    for(int i=0;i<n;++i)
    {
        int x;
        cin>>x;
        if(head==nullptr)
        {
            head=new listNode(x);
            tail=head;
        }
        else
        {
            tail->next=new listNode(x);
            tail=tail->next;
        }
    }
    head=addOneToList(head);//Add 1 to the number represented by the linked list.
    print_list(head);
    cout<<endl;
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