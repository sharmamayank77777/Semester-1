/*Given an array of n numbers, create an algorithm which displays all pairs whose sum is S.*/

#include<iostream>
#include<vector>
using namespace std;
void pairSum(vector<int> arr,int S)
{
    for(int i=0;i<arr.size();i++)
    {
        for(int j=i+1;j<arr.size();j++)
        {
            if(arr[i]+arr[j]==S)
            {
                cout<<"("<<arr[i]<<","<<arr[j]<<")"<<" ";
            }
        }
    }
}
int main()
{
    vector<int> v{1,2,3,4,5,6,7,8};
    pairSum(v,9);
    return 0;
}