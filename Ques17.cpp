/*Given array[] with sliding window of size w which is moving from the very left of the
array to very right. Assume that we can only see the w numbers in the window. Each
time the sliding window moves right forwards by on position. For example: The array
is [1 3 -1 -3 5 3 6 7], and w is 3.*/

#include<iostream>
using namespace std;
void maxOfWindow(int arr[],int n,int k)
{
    int max_ele=INT_MIN;
  
    for(int i=0;i<k;i++)
    {
        if(arr[i]>max_ele)
        max_ele=arr[i];
    }
    cout<<"Max : "<<max_ele<<endl;
    for(int i=k;i<n;i++)
    {
        max_ele=max(max_ele,arr[i]);
        cout<<"Max : "<<max_ele<<endl;
    }
    
}
int main()
{
    int arr[]={1,3,-1,-3,5,3,6,7};
    int n=sizeof(arr)/sizeof(arr[0]);
    int k; 
    cout<<"Enter window size(k) : ";
    cin>>k;
    maxOfWindow(arr,n,k);
    return 0;
}