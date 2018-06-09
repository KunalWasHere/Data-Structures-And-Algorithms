#include<bits/stdc++.h>
using namespace std;
stack<int> st;
vector< pair<int,int> > tree[6];
int visited[6]={0};
int dist[6];
void topologicalsort(int index)
{
    visited[index]=1;
    vector< pair<int,int> > :: iterator it;
    for(it=tree[index].begin();it!=tree[index].end();++it)
    {
        if(!visited[(it->first)])
            topologicalsort(it->first);
    }
    st.push(index);

}
int main()
{
    int t,i,a,b,wt,source;
    cin>>t;
    while(t--)
    {
        cin>>a>>b>>wt;
        tree[a].push_back(make_pair(b,wt));
    }
    for(i=0;i<6;i++)
    {
        dist[i]=INT_MIN;
        if(!visited[i])
            topologicalsort(i);
    }
    cout<<endl<<"enter source :";
    cin>>source;
    dist[source]=0;
    while(st.top()!=source)
        st.pop();
    vector< pair<int,int> > :: iterator it;
    while(!st.empty())
    {
        for(it=tree[st.top()].begin();it!=tree[st.top()].end();++it)
        {
            if(dist[it->first]<(dist[st.top()]+(it->second)))
                dist[it->first]=dist[st.top()]+(it->second);
            //cout<<"check"<<it->first<<it->second;
        }
        st.pop();
    }
    cout<<endl<<"final distances from source to every node is :"<<endl;
    for(i=0;i<6;i++)
        cout<<"distance from source "<<source<<" to node "<<i<<" is :"<<dist[i]<<endl;

}
