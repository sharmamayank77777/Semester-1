/*Show how to implement one queue efficiently using two stacks. Analyse the running time of queue operations.*/

#include<iostream>
#define MAX 10
using namespace std;
int arr1[MAX],arr2[MAX];
int top1=-1,top2=-1;

void push1(int data)
{
    arr1[++top1]=data;
}
void push2()
{
    while(top1!=0)
    {
        arr2[++top2]=arr1[top1--];
    }
}

//push element in queue
void enqueue()
{
    
    if(top1==MAX-1)
    {
        cout<<"Queue Overflow!!"<<endl;
    }
    else{
        int n;
        cout<<"Enter element : ";
        cin>>n;
        push1(n);
    }

}
void pop2()
{
    while(top2!=-1)
    {
        push1(arr2[top2--]);
    }
}
int pop1()
{
    push2();
    int n=arr1[top1--];
    pop2();
    return n;

}

// pop element from queue
void dequeue()
{
    if(top1==-1)
    {
        cout<<"Queue Underflow!!";
    }
    else{
        cout<<"Popped element is : "<<pop1();
    }
}
int main()
{
    char ch;
    do{
        int n;
        cout<<"***  Queue operation  ***"<<endl
            <<"1.Push element in Queue"<<endl
            <<"2.Pop element from Queue"<<endl
            <<"Enter your choice : ";
        cin>>n;
        switch(n)
        {
            case 1:     enqueue();
                        break;
            case 2:     dequeue();
                        break;
            default:    cout<<"Wrong Choice!!"<<endl;   
        }
        cout<<"\nDo you want to continue(y/n) : ";
        cin>>ch;
    }while(ch=='y' || ch=='Y');
    return 0;
}