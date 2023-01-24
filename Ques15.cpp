/*Show how to implement one stack efficiently using two queues. Analyse the running time of stack operations.*/
/*Show how to implement one queue efficiently using two stacks. Analyse the running time of queue operations.*/

#include<iostream>
#define MAX 10
using namespace std;
int arr1[MAX],arr2[MAX];
int front1=-1,rear1=-1;
int front2=-1,rear2=-1;

void enqueue1(int data)
{
    if(front1==-1)
    {
        front1=rear1=0;
    }
    else{
        rear1++;
    }
    arr1[rear1]=data;
}
void enqueue2()
{
    while(front1!=rear1)
    {
        if(front2==-1)
        {
            front2=rear2=0;
        }
        else{
            rear2++;
        }
        arr2[rear2]=arr1[front1];
        front1++;
    }
}
void display(int arr[])
{
    cout<<"\nQueue is : "<<endl;
    for(int i=front1;i<=rear1;i++)
    cout<<arr1[i]<<" ";
    cout<<endl;
}
//push element in queue
void push()
{
    
    if(rear1==MAX-1)
    {
        cout<<"Stack Overflow!!"<<endl;
    }
    else{
        int n;
        cout<<"Enter element : ";
        cin>>n;
        enqueue1(n);
    }

}
void dequeue2()
{
    cout<<"Inside dequeue 2 ";
    cout<<"front2 : "<<front2<<" rear2 : "<<rear2<<endl;
    display(arr2);
    while(front2<=rear2)
    {
        enqueue1(arr2[front2++]);
    }
    front2=rear2=-1;
}
int dequeue1()
{
    enqueue2();
    int n=arr1[front1];
    front1=rear1=-1;
    display(arr1);
    cout<<"front1 : "<<front1<<" rear1 : "<<rear1<<endl;
    dequeue2();
    display(arr1);
    cout<<"front1 : "<<front1<<" rear1 : "<<rear1<<endl;
    return n;
}

// pop element from queue
void pop()
{
    if(front1==-1)
    {
        cout<<"Stack Underflow!!";
    }
    else{
        cout<<"Popped element is: "<<dequeue1();
    }
}
int main()
{
    char ch;
    do{
        int n;
        cout<<"***  Stack operation  ***"<<endl
            <<"1.Push element in Stack"<<endl
            <<"2.Pop element from Stack"<<endl
            <<"Enter your choice : ";
        cin>>n;
        switch(n)
        {
            case 1:     push();
                        break;
            case 2:     pop();
                        break;
            default:    cout<<"Wrong Choice!!"<<endl;   
        }
        cout<<"\nDo you want to continue(y/n) : ";
        cin>>ch;
    }while(ch=='y' || ch=='Y');
    return 0;
}