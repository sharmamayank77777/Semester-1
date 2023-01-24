/*Recursively remove all adjacent duplicates: Given a string of characters, recursively remove adjacent duplicate characters from the string.
The output string should not have any adjacent duplicates.*/

#include<iostream>
#include<string.h>
#include<map>
using namespace std;
string unique_character(char* s)
{
    int skip=-1;
    int i=0;
    while(s[i]!='\0')
    {
        if(skip==-1 || s[skip]!=s[i])
        {
            skip++;
            s[skip]=s[i];
            i++;
        }
        else{
            while(s[i]!='\0' && s[skip]==s[i])
            {
                i++;
            }
            skip--;
        }
    }
    s[skip+1]='\0';
    return s;
}
int main()
{
    char s[]="Mississippi";
    cout<<"Unique string : "<<unique_character(s);
    return 0;
}
