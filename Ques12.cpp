/*Given an array of characters formed with a’s and b’s. The string is marked with special character X which represents the middle of the list
(for example:ababa...ababXbabab....baaaa). Check whether the string is palindrome.*/

#include<iostream>
#include<vector>
using namespace std;
bool palindrome(vector<char> v)
{
    int i=0;
    int j=v.size()-1;
    while(v[i]!='X')
    {
        if(v[i]!=v[j])
        {
            return false;
        }
        i++;j--;
    }
    return true;
}
int main()
{
    vector<char> v{'a','b','a','a','a','b','b','b','b','X','b','b','b','b','a','a','a','b','a'};
    bool ans=palindrome(v);
    if(ans)
    cout<<"Palindrome";
    else
    cout<<"Not Palindrome";
    return 0;
}