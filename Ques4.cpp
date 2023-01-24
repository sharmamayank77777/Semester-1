/*Given a singly linked list, write a function to find root(n)th element, where n is the number of elements in the list.
Assume value of n is not known in advance.*/

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
    int rootNthElement()
    {
        node* ans=NULL;
        int i=1,j=1;
        while(head!=NULL)
        {
            if(i==j*j)
            {
                if(ans==NULL)
                {
                    ans=head;
                }
                else
                ans=ans->next;
                
                j++;
            }
            i++;  
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
    ob.createList();
    ob.display();
    cout<<"Root Nth element : "<<ob.rootNthElement();
    return 0;
}