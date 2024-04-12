#include<bits/stdc++.h>
using namespace  std;
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>

namespace __gnu_pbds{
    typedef tree<long long,
            null_type,
            less_equal<long long>,
    rb_tree_tag,
    tree_order_statistics_node_update> ordered_set;
}


using namespace __gnu_pbds;


vector<vector<int>>graph;
vector<ordered_set>x;
vector<int>ans,values;

void dfs( int vertex,int parent,ordered_set &pathvalues)
{
    pathvalues.insert(values[vertex]);
    int n=pathvalues.size();
    ans[vertex]=*(pathvalues.find_by_order((n-1)/2));

    for(auto i:graph[vertex])
    {
        if(i!=parent)
        {
            dfs(i,vertex,pathvalues);
        }
    }
    pathvalues.erase(pathvalues.find_by_order(pathvalues.order_of_key(values[vertex])));

}

int main()
{
    int n;
    cin>>n;
    graph.assign(n,vector<int>());
    values.assign(n,0);
    ans.assign(n,0);
    int head;
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        if(x==-1) {
            head = i;
            graph[i].push_back(x);
            continue;
        }
        graph[i].push_back(x);
        graph[x].push_back(i);
    }
    for(int i=0;i<n;i++)
        cin>>values[i];

    ordered_set pathvalues;
    dfs(head,-1,pathvalues);

    for(auto i:ans)
        cout<<i<<" ";
    cout<<endl;
}
