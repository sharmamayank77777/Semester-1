/*16. Given a stack of integers, how do you check whether each successive pair of members
in the stack is consecutive or not. The pairs can be increasing or decreasing, and if the
stack has an odd number of elements, the element at the top is left out of pair. For
example, if stack of elements are [4, 5, -2, -3, 11, 10, 5, 6, 20], then the output should
be true because each of the pairs (4,5), (-2,-3), (11,10) and (5,6) consists of
consecutive numbers.*/

#include<iostream>
#include<stack>
#include<queue>
using namespace std;
bool solve(stack<int> s)
{
   queue<int> q;
   bool isOrder=true;
   while(!s.empty())
   {
        q.push(s.top());
        s.pop();
   }
   while(!q.empty())
   {
        s.push(q.front());
        q.pop();
   }
   while(!s.empty())
   {
        int n=s.top();
        s.pop();
        q.push(n);
        if(!s.empty())
        {
            int m=s.top();
            s.pop();
            q.push(m);
            if(abs(n-m)!=1)
            {
                isOrder=false;
            }
        }
   }
   while(!q.empty())
   {
        s.push(q.front());
        q.pop();
   }
   return isOrder;

}
int main()
{
    stack<int> s;
    s.push(4);
    s.push(5);
    s.push(-2);
    s.push(-3);
    s.push(11);
    s.push(10);
    s.push(5);
    s.push(6);
    s.push(20);
    cout<<"Answer is : "<<solve(s);
    return 0;
}