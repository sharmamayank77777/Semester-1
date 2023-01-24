/*Suppose there are two singly linked lists both of which intersect at some point and
become a singly list. The head or starting pointers for the both lists are known, but the
intersecting node is not known. Also the number of nodes in each of the lists before
they intersect is unknown and may be different in each list. List1 may have n nodes
before it reaches the intersection point, and list2 might have m nodes before it reaches
the intersection point where m and n may be m=n, m<n or m>n. write a program for
find a merging node.*/

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
    // to make a merged sll
    void mergeList(node* temp2)
    {
        node* temp;
        for(int i=100;i>70;i-=10)
        {
            node *newnode=new node;
            newnode->data=i;
            if(head==NULL)
            {
                head=temp=newnode;
            }
            else
            temp->next=newnode;
            temp=newnode;
        }
        temp->next=temp2->next->next->next;  
    }

    // to find length of list
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
    // to traverse if one list is greater than other
    node* traverse(node* temp,int k)
    {
        while(k>0)
        {
            temp=temp->next;
            k--;
        }
        return temp;
    }
    // to find the merging Node
    int findNode(node* head1,node* head2)
    {
        while(head1!=NULL)
        {
            if(head1==head2)
            {
                break;
            }
            else{
                head1=head1->next;
                head2=head2->next;
            }
        }
        return head1->data;
    }
    //to perform operation required to find mergingNode
    int findMergingNode(node* head1,node* head2)
    {
        int len1=length(head1);
        int len2=length(head2);
        if(len1>len2)
        {
            head1=traverse(head1,len1-len2);
        }
        else if(len2>len1)
        {
            head2=traverse(head2,len2-len1);
        }
        int ans=findNode(head1,head2);
        return ans;
    }

    // to display lists
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
    
    ob2.mergeList(ob1.head);
    cout<<"\nList2 : ";
    ob2.display();

    cout<<"Merging Node is : "<<ob1.findMergingNode(ob1.head,ob2.head);
    return 0;
}