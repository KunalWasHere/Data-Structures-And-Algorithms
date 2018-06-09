#include<bits/stdc++.h>
using namespace std;
int midof(int ss,int se)
{
    return ss+(se-ss)/2;
}
int min(int x,int y)
{
    if(x<y)
        return x;
    else
        return y;
}
int bracketleft(int seg[][2],int ss,int se,int si,int l)
{
    if(l<=ss&&r>=se)
        return seg
}
void build(char arr[],int seg[][2],int ss,int se,int si)
{
    if(ss==se)
    {
      if(arr[ss]=='(')
        seg[si][0]=1;
      if(arr[ss]==')')
        seg[si][1]=1;
      return;
    }
    int mid=midof(ss,se);
    build(arr,seg,ss,mid,2*si+1);
    build(arr,seg,mid+1,se,2*si+2);
    int newmatch=min(seg[2*si+1][0],seg[2*si+2][1]);
    seg[si][0]=seg[2*si+1][0]+seg[2*si+2][0]-newmatch;
    seg[si][1]=seg[2*si+1][1]+seg[2*si+2][1]-newmatch;

}
int main()
{
    int t,n,i,query,check;
    cin>>t;
    while(t--)
    {
        char arr[100];
        cin>>n;
        for(i=0;i<n;i++)
            cin>>arr[i];
        int seg[205][2]={0};
        build(arr,seg,0,n-1,0);
        cout<<endl<<"segment tree is :"<<endl;
        for(i=0;i<2*n+6;i++)
        {
            cout<<i<<":  "<<seg[i][0]<<"   "<<seg[i][1]<<endl;
        }
        cout<<"enter no of queries:";
        cin>>query;
        for(i=0;i<query;i++)
        {
            cin>>check;
            if(check)
            {
                cin>>l>>r;
                if(bracketleft(seg,0,n-1,0,l)&&bracketright(seg,0,n-1,0,r))
                    cout<<endl<<"YES";
                else
                    cout<<endl<<"NO";
            }
        }
    }

}
