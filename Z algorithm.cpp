#include<bits/stdc++.h>
using namespace std;
void getZarr(string str,int Z[])
{
    int n=str.length();
    int L,R,K;
    L=R=0;
    for(int i=1;i<n;i++)
    {
     if(i>R)
     {
         L=R=i;
         while(R<n && str[R-L]==str[R])
         {
             R++;
         }
         Z[i]=R-L;
         R--;
     }
     else
     {
         K=i-L;
         if(Z[K]<R-i+1)
         {
             Z[i]=Z[K];
         }
         else
         {
             L=i;
             while(R<n && str[R-L]==str[R])
             {
                 R++;
             }
             Z[i]=R-L;
             R--;
         }
     }
    }
}
void Search(string txt,string pat)
{
    string concat=pat+"$"+txt;
    int l=concat.length();
    int Z[l];
    getZarr(concat,Z);
    for(int i=0;i<l;i++)
    {
        if(Z[i]==pat.length())
        {
            cout<<"pattern is found at: "<<i-pat.length()-1<<"\n";
        }
    }
}
int main()
{
    string text = "GEEKS FOR GEEKS";
    string pattern = "GEEK";
    Search(text, pattern);
    return 0;
}
