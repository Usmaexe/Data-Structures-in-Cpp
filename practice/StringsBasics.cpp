
#include<stdio.h>
int main()
{
    char a[]="decimal";
    char b[]="mediacl";
    int h[26]={0},c=0;
    for(int i=0;a[i]!='\0';i++)
        h[a[i]-97]+=1;
    for(int i=0;b[i]!='\0';i++)
        h[b[i]-97]-=1;
    for(int i=0;i<26;i++)
    {
        if(h[i]==0)
            c++;
    }
    if(c==26)
        printf("Anagram");
    else
        printf("not Anagram");
    return 0;
}