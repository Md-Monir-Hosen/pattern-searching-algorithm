#include<bits/stdc++.h>
using namespace std;
#define d 256
void Search(char pat[],char text[],int q)
{
    int M=strlen(pat);
    int N=strlen(text);
    int i,j;
    int p=0;
    int t=0;
    int h=1;
    for(i=0;i<M-1;i++)
    {
        h=(h*d)%q;
    }
    for(i=0;i<M;i++)
    {
        p=(p*d+pat[i])%q;
         t=(p*d+text[i])%q;
    }
    for(i=0;i<N-M;i++)
    {
        if(p==t)
        {
            for(j=0;j<M;j++)
            {
                if(text[i+j]!=pat[j])
                {
                    break;
                }
            }
            if(j==M)
            {
                cout<<"Pattern found at index: "<<i<<"\n";
            }
        }
        if(i<N-M)
        {
            t=(d*(t-text[i]*h)+text[i+M])%q;
        }
        if(t<0)
        {
            t=(t+q);
        }
    }
}
int main()
{
     char txt[] = "GEEKS FOR GEEKS";
    char pat[] = "GEEK";
    int q = INT_MAX;
    Search(pat, txt, q);
    return 0;
}
