#include<bits/stdc++.h>
using namespace std;
struct suffix
{
    int index;
    char *suff;
};
int cmp(struct suffix a,struct suffix b)
{
    return strcmp(a.suff,b.suff)<0 ? 1:0;
}
int *buildSuffixArray(char *txt,int n)
{
    struct suffix suffixes[n];
    for(int i=0;i<n;i++)
    {
        suffixes[i].index=i;
        suffixes[i].suff=(txt+i);
    }
    sort(suffixes,suffixes+n,cmp);
    int *suffixArr=new int[n];
    for(int i=0;i<n;i++)
    {
        suffixArr=suffixes[i].index;
    }
    return suffixArr;
}
void printArr(int arr[],int n)
{
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<"\n";
}
int main()
{
     char txt[] = "banana";
    int n = strlen(txt);
    int *suffixArr = buildSuffixArray(txt,  n);
    cout << "Following is suffix array for " << txt << endl;
    printArr(suffixArr, n);
    return 0;
}
