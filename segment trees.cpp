#include<bits/stdc++.h>
using namespace std;
int midof(int ss,int se)
{
    return ss+(se-ss)/2;
}
void update(int seg[],int index,int diff,int ss,int se,int si)
{
    if(index>=ss&&index<=se&&ss!=se)
    {
        seg[si]=seg[si]+diff;
        int mid=midof(ss,se);
        update(seg,index,diff,ss,mid,2*si+1);
        update(seg,index,diff,mid+1,se,2*si+2);
    }
    if(ss==se&&ss==index)
    {
        seg[si]=seg[si]+diff;
    }
    return;
}
int sum(int seg[],int ss,int se,int si,int l,int r)
{
    if(l<=ss&&r>=se)
        return seg[si];
    if(se<l||r<ss)
        return 0;
    int mid=midof(ss,se);
    return sum(seg,ss,mid,2*si+1,l,r)+ sum(seg,mid+1,se,2*si+2,l,r);
}

int buildseg(int arr[],int seg[],int ss,int se,int si)
{
    if(ss==se)
    {
        seg[si]=arr[ss];
        return arr[ss];
    }
    int mid=midof(ss,se);
    seg[si]=buildseg(arr,seg,ss,mid,2*si+1)+buildseg(arr,seg,mid+1,se,2*si+2);

}
int main()
{
    int arr[100],i,n,q,l,r,diff,index,value,check;
    cin>>n;
    for(i=0;i<n;i++)
        cin>>arr[i];
    int seg[202]={0};
    buildseg(arr,seg,0,n-1,0);
    cout<<endl<<"segment tree is :"<<endl;
    for(i=0;i<2*n+3;i++)
        cout<<seg[i]<<endl;
    cin>>q;
    while(q--)
    {
        cout<<endl<<"press 0 to update and 1 to get sum:"<<endl;
        cin>>check;
        if(check)
        {
            cin>>l>>r;
            cout<<endl<<"result of query is :"<<endl;
            cout<<sum(seg,0,n-1,0,l,r)<<endl;
        }
        else
        {
            cin>>index>>value;
            diff=value-arr[index];
            arr[index]=value;
            update(seg,index,diff,0,n-1,0);
        }
    }
}
