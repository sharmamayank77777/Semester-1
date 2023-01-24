/*Check whether the given linked list is either NULL-terminated or ends in cycle(cyclic).*/
#include<iostream>
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
        cout<<"\nHow many elements you want to enter : ";
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
   // to check whether cycle exist or not using Floyd's Algo 
    bool isCyclic()
    {
        if(head==NULL)
        return false;
        
        node* slow=head;
        node* fast=head;
        while(slow!=NULL && fast!=NULL)
        {
            fast=fast->next;
            if(fast!=NULL)
                fast=fast->next;
            slow=slow->next;
            if(slow==fast)
                return true;
        }
        return false;
    }
    
    // make list cyclic to test Floyd's algo
    void make_cyclic()
    {
        node* temp=head;
        while(temp->next=NULL)
        {
            temp=temp->next;
        }
        temp->next=head->next;
    }
    // to display listt
    void display()
    {
        if(head==NULL)
        {
            cout<<"list is empty!!";
            return;
        }
        
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
    list ob1,ob2;
    ob1.createList();
    cout<<"\nList1 : ";
    ob1.display();

    cout<<"Is List 1 Cyclic : "<<ob1.isCyclic()<<endl;

    ob2.createList();
    cout<<"\nList2 : ";
    ob2.display();
    cout<<"Is List 2 Cyclic : "<<ob2.isCyclic()<<endl;
    // making list2 cyclic
    ob2.make_cyclic();
    cout<<"(After making Cyclic)Is List 2 Cyclic : "<<ob2.isCyclic()<<endl;
    cout<<"Is List 1 Cyclic : "<<ob1.isCyclic()<<endl;
    return 0;
}