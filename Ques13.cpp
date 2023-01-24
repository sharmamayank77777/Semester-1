/*How do we implement two stacks using only one array?
Our stack routines should not indicate an exception unless every slot in the array is used.*/

#include<iostream>
#define MAX 10
using namespace std;

int arr[MAX];
int top1=-1;
int top2=MAX;
void push1()
{
    if(top2-top1>1)
    {
        int val;
        cout<<"Enter data to push in stack 1 : ";
        cin>>val;
        arr[++top1]=val;
    }
    else{
        cout<<"Stack1 overflow"<<endl;
    }
}
void push2()
{
    if(top2-top1>1)
    {
        int val;
        cout<<"Enter data to push in stack 2 : ";
        cin>>val;
        arr[--top2]=val;
    }
    else{
        cout<<"Stack2 overflow"<<endl;
    }
}
void pop1()
{
    if(top1<0)
    cout<<"Stack1 underflow"<<endl;
    else
    cout<<"Popped item from stack1 is : "<<arr[top1--]<<endl;

}
void pop2()
{
    if(top2==MAX)
    cout<<"Stack2 underflow"<<endl;
    else
    cout<<"Popped item from stack2 is : "<<arr[top2++]<<endl;
}
int main()
{
    char ch;
    do{
        int n;
        cout<<"Choice to perform operation :"<<endl
            <<"1.Push element in Stack 1"<<endl
            <<"2.Push element in Stack 2"<<endl
            <<"3.Pop element from Stack1"<<endl
            <<"4.Pop element from Stack2"<<endl
            <<"Enter your choice : ";
        cin>>n;
        switch(n)
        {
            case 1:     push1();
                        break;
            case 2:     push2();
                        break;
            case 3:     pop1();
                        break;
            case 4:     pop2();
                        break;
            default:    cout<<"Wrong Choice!!"<<endl;   
        }
        cout<<"Do you want to continue(y/n) : ";
        cin>>ch;
    }while(ch=='y' || ch=='Y');
    
    return 0;
}