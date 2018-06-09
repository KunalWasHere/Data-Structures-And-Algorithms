#include<bits/stdc++.h>
using namespace std;
int main()
{
    vector < pair<int,int> > v[10];
    vector < pair<int,int> > ::iterator it;
    int arr[10];
    int nodes,queries,a,b,dist,i,j,source;
    cin>>nodes>>queries>>source;
    for(i=0;i<queries;i++)
    {
        cin>>a>>b>>dist;
        v[a].push_back(make_pair(b,dist));
    }
    for(i=0;i<nodes;i++)
        arr[i]=INT_MAX;
    arr[source]=0;
    for(i=0;i<nodes-1;i++)
    {
        for(j=0;j<nodes;j++)
        {
            for(it=v[j].begin();it!=v[j].end();it++)
            {
                if(arr[j]!=INT_MAX &&(it->second + arr[j] < arr[it->first]))
                    arr[it->first]=it->second + arr[j];
            }
        }
    }
    cout<<"distances are :"<<endl;
    for(i=0;i<nodes;i++)
        cout<<arr[i]<<endl;

}
