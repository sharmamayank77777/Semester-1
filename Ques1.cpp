/* Given an array of elements, replace every element with nearest greater element on the right of that element.*/

#include<iostream>
using namespace std;
void replaceWithNextGreater(int arr[],int n)
{
    for(int i=0;i<n-1;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(arr[j]>arr[i])
            {
                swap(arr[i],arr[j]);
                break;
            }
        }
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
    int arr[]={5,4,3,6,1,9,8,7};
    int n=sizeof(arr)/sizeof(arr[0]);
    
    cout<<"Original Array : ";
    display(arr,n);
    
    replaceWithNextGreater(arr,n);
    
    cout<<"Array after operation : ";
    display(arr,n);
    return 0;
}