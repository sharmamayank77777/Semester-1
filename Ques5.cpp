/*[Find the modular node from the end:] Given a singly linked list, write a function to find the first from the end whose n%k==0,
where n is the number of elements in the list and k is an integer constant. If n=19 and k=3 then we should return 16th node.*/
#include<iostream>
#include<math.h>
using namespace std;
class list{
    struct node{
        int data;
        node* next;
    }*head;
    public:
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
    
    // to find root Nth element of list
    int ModularNodeFromEnd(int k)
    {
        node* ans=head;
        while(k)
        {
            if(head)
            head=head->next;
            else
            return -1;
            
            k--;
        }
        while(head!=NULL)
        {
            ans=ans->next;
            head=head->next;         
        }
        return ans->data;
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
    int k;
    ob.createList();
    ob.display();
    cout<<"Enter the value of k : ";
    cin>>k;
    cout<<"Modular node from end : "<<ob.ModularNodeFromEnd(k);
    return 0;
}