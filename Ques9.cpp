/*For a given k value (k>0) reverse blocks of nodes in the list.*/
#include<iostream>
#include<math.h>
using namespace std;
class list{
    public:
    struct node{
        int data;
        node* next;
    }*head;
    list()
    {
        head=NULL;
    }
    // to enter linked list
    void createList()
    {
        int n;
        cout<<"How many elements you want to enter : ";
        cin>>n;
        node* temp=head;
        cout<<"Enter element of list : ";
        while(n>0)
        {
            int val;
            cin>>val;
            node *newnode=new node;
            newnode->data=val;
            newnode->next=NULL;
            if(head==NULL)
            {
                head=temp=newnode;
            }
            else
            temp->next=newnode;
            temp=newnode;
            
            n--;
        }
    }
    // to find number of elements in list
    int length(node* temp)
    {
        int count=0;
        while(temp!=NULL)
        {
            count++;
            temp=temp->next;
        }
        return count;
    }
    // to reverse list in group of k
    node* reverseKGroup(node* head, int k) {
        if(head==NULL)
        {
            return head;
        }
        node* forward=NULL;
        node* cur=head;
        node* prev=NULL;
        int cnt=0;
        while(cnt<k && cur!=NULL)
        {
            forward=cur->next;
            cur->next=prev;
            prev=cur;
            cur=forward;
            cnt++;
        }
        if(length(forward)>=k)
        {
            head->next=reverseKGroup(forward,k);
        }
        else{
            head->next=forward;
        }
        return prev;
    }
    // to display entered list
    void display()
    {
        if(head==NULL)
        {
            cout<<"list is empty!!";
            return;
        }
        cout<<"Your list is : ";
        node* temp=head;
        while(temp!=NULL)
        {
            cout<<temp->data<<" ";
            temp=temp->next;
        }
        cout<<endl;
    }
};
int main()
{
    list ob;
    ob.createList();
    ob.display();
    ob.head=ob.reverseKGroup(ob.head,4);
    ob.display();
    return 0;
}
//1 2 3 4 5 6 7 8 9 10