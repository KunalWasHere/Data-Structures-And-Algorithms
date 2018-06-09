#include<bits/stdc++.h>
using namespace std;
int determinant(int a[][10],int n)
{
    //cout<<"detc"<<a[1][1]<<endl;
    int b[10][10];
    int ans=0,s=-1,i,m,p,j,q;
    if(n==1)
        return a[0][0];
    for(i=0;i<n;i++)
    {
        m=0;p=0;
        s=s*-1;
        for(q=1;q<n;q++)
        {
            for(j=0;j<i;j++)
            {
                b[m][p]=a[q][j];
                p++;

            }
            for(j=i+1;j<n;j++)
            {
                b[m][p]=a[q][j];
                /*if(p<n-2)
                    p++;
                else
                {
                   p=0;
                   m++;
                }*/
                p++;
            }
            m++;
            p=0;
        }
        //cout<<"detb"<<b[1][1];
        ans=ans+s*a[0][i]*determinant(b,n-1);
        //cout<<"check"<<n<<" "<<ans<<endl;
    }
    return ans;
}
int main()
{
    vector<int> v[10];
    int n,arr[10]={0},mat[10][10]={0},a[10][10],i,ar,b,j,ans,query;
    cin>>n>>query;
    for(i=0;i<query;i++)
    {
        cin>>ar>>b;
        v[ar].push_back(b);
        arr[ar]++;
        arr[b]++;
        mat[ar][b]=-1;
        mat[b][ar]=-1;
    }
    for(i=0;i<n;i++)
        mat[i][i]=arr[i];
    for(i=1;i<n;i++)
        for(j=1;j<n;j++)
            a[i-1][j-1]=mat[i][j];
    ans=determinant(a,n-1);
    cout<<"no of spanning trees :"<<ans;
}
