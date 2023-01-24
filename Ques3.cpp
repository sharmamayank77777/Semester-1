/*Given a list, List1={A1,A2,A3,........An-1, An} with data, reorder it to {A1, An, A2, An-1, .....} without using any extra space.*/

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

    // reverese list
    node* reverse(node* head)
    {
        if(head==NULL)
        return head;

        node* cur=head;
        node* forward=NULL;
        node* prev=NULL;
        while(cur!=NULL)
        {
            forward=cur->next;
            cur->next=prev;
            prev=cur;
            cur=forward;
        }
        return prev;
    }

    // to get the middle of list
    node* getMiddle(node* head)
    {
        if(head==NULL || head->next==NULL)
        return head;

        node* slow=head;
        node* fast=head;
        while(fast!=NULL && fast->next!=NULL)
        {
            fast=fast->next->next;
            slow=slow->next;
        }
        return slow;
    }

    //operation to shuffle elements
    void shuffleElements()
    {
        if(head==NULL ||head->next==NULL ||head->next->next==NULL)
        return;

        //finding middle of list
        node* middle=getMiddle(head);
        
        //reversing list from middle
        node* head2=reverse(middle->next);
        
        //detaching first list till middle of original list
        middle->next=NULL;
        
        node* cur=head;
        node* forward=NULL;
        node* forward2=NULL;
        while(head2!=NULL)
        {
            forward=cur->next;
            cur->next=head2;
            forward2=head2->next;
            head2->next=forward;

            cur=forward;
            head2=forward2;
        }
    }
    
    // to display list
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
    list ob;
    ob.createList();
    cout<<"\n Original List : ";
    ob.display();
    
    ob.shuffleElements();
    cout<<"After Shuffling elements of List : ";
    ob.display();

    return 0;
}

/*
#include<iostream>
using namespace std;
void reorder(int arr[],int n)
{
    int i=1;
    while(i<n)
    {
        int ch=arr[n-1];
        for(int j=n-1;j>i;j--)
        {
            arr[j]=arr[j-1];
        }
        arr[i]=ch;
        i+=2;    
    }
}
void display(int arr[],int n)
{
    for(int i=0;i<n;i++)
    cout<<arr[i]<<" ";
    cout<<endl;
}
int main()
{
    int arr[]={1,2,3,4,5,6,7,8};
    int n=sizeof(arr)/sizeof(arr[0]);
    
    cout<<"Original Array : ";
    display(arr,n);
    
    reorder(arr,n);
    
    cout<<"Array after operation : ";
    display(arr,n);
    return 0;
}
 1 2 3 4 5 6 7 8 9 10*/