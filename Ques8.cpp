/*[Josephus circle:] N people decided to elect a leader by arranging themselves in a circle and eliminating every mth person around the circle,
closing ranks as each drops out. Find which person will be the last one remaining (with rank 1).*/

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
    int JosephusCircle()
    {
        int n;
        cout<<"\nHow many people are there in circle : ";
        cin>>n;
        node* temp=head;
        int i=1;
        while(i<=n)
        {
            node *newnode=new node;
            newnode->data=i;
            if(head==NULL)
            {
                head=temp=newnode;
                head->next=head;
            }
            else{
                temp->next=newnode;
                temp=newnode;
                newnode->next=head;
            }
            i++;
        }
        cout<<"People are : ";
        display();
        
        int m;
        cout<<"Enter the value of M : ";
        cin>>m;
        temp=head;
        for(i=1;i<n;i++)
        {
            node *temp2=NULL;
            for(int j=0;j<m;j++)
            {
                temp=temp->next;
            }
            temp->next=temp->next->next; // remove eliminated person
        }
        return temp->data;
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
        do
        {
            cout<<temp->data<<" ";
            temp=temp->next;
        }while(temp!=head);
        cout<<endl;

    }
};
int main()
{
    list ob1;
    int ans=ob1.JosephusCircle();
    cout<<"Last Remaining Person : "<<ans;
    
    return 0;
}