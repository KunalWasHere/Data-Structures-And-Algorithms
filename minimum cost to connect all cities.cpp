#include<bits/stdc++.h>
using namespace std;
int findmin(int arr[],int n)
{
    int min=arr[0];
    int index=0;
    for(int i=0;i<n;i++)
    {
        if(arr[i]<min)
        {
            min=arr[i];
            index=i;
        }
    }
    return index;
}
int main()
{
    int n,i,j,ans=0,index,temp=0,val[100][100];
    cin>>n;
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            cin>>val[i][j];
    int arr[100],x[100];
    arr[0]=0;
    for(i=1;i<n;i++)
        arr[i]=INT_MAX;
    while(temp<n){
    index=findmin(arr,n);
    ans=ans+arr[index];
    temp++;
    //temp=arr[0];
    //arr[0]=arr[index];
    //arr[index]=arr[0];
    for(i=0;i<n;i++)
        val[i][index]=-1;
    for(i=0;i<n;i++)
    {
        if(val[index][i]==-1)
            arr[i]=INT_MAX;
        else if(val[index][i]==0&&arr[i]!=0)
            arr[i]=arr[i];
        else if(val[index][i]==0&&arr[i]==0)
            arr[i]=INT_MAX;
        else if(val[index][i]<arr[i])
            arr[i]=val[index][i];
    }
    }
    cout<<"ans is :"<<ans;

}
