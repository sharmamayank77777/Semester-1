#include<iostream>
#include<queue>
using namespace std;
void display(queue<int> q)
{
    while(q.front()!=q.back())
    {
        cout<<q.front()<<" ";
        q.pop();
    }
    cout<<q.front()<<endl;
}
void solve(queue<int>&q,int k)
{
    if(k==0) return;
    int num=q.front();
    q.pop();
    solve(q,k-1);
    q.push(num);
}
void reverse_queue(queue<int>& q,int k)
{
    solve(q,k);
    int s=q.size()-k;
    while(s-- > 0)
    {
        int num=q.front();
        q.pop();
        q.push(num);
    }
}
int main()
{
    queue<int> q;
    int k;
    cout<<"Enter value of k: ";
    cin>>k;
    for(int i=10;i<=100;i+=10)
    {
        q.push(i);
    }
    cout<<"Before reversing: ";
    display(q);
    reverse_queue(q,k);
    cout<<"After reversing: ";
    display(q);
    return 0;
}
