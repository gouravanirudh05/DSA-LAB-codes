#include<bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>

using namespace std;

namespace __gnu_pbds{
    typedef tree<long long,
                 null_type,
                 less_equal<long long>,
                 rb_tree_tag,
                 tree_order_statistics_node_update> ordered_set;
}
using namespace __gnu_pbds; //'pbds' stands for Policy-Based Data Structure. 

vector<vector<int>> edge;
vector<ordered_set> parent;
vector<int> main_array,ans;

void dfs(int c,int p){
    parent[c].insert(main_array[c]);
    for(auto i: edge[c]){
        if(i != p){
            dfs(i,c);
            if(parent[c].size() < parent[i].size()){
                parent[c].swap(parent[i]);
            }
            for(auto j:parent[i]){
                parent[c].insert(j);
            }
        }
    }
    int size = parent[c].size();
    ans[c] = *(parent[c].find_by_order((size-1)/2));
}
int main(){
    int n;
    cout<<"Enter the value of n: ";
    cin>>n;
    edge.assign(n, vector<int>());
    main_array.assign(n,0);
    parent.resize(n);
    ans.assign(n,0);
    cout<<"Enter the values of parent array: ";
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        if(x==-1) continue;
        edge[i].push_back(x);
        edge[x].push_back(i);
    }
    /*
    The loop iterates over each vertex of the tree, represented by the index i.
    For each vertex i, it reads an integer x from the input.
    If x is -1, it means that vertex i is the root of the tree, so there's no need to add any edge for it. The continue statement skips further processing for this vertex.
    If x is not -1, it means that x is the parent of vertex i.
    So, the edge between x and i is added to the edge vector. This is done by pushing i into the adjacency list of x, indicating that i is a child of x.
    Additionally, since this is an undirected tree, we also need to add the edge from i to x. Hence, we push x into the adjacency list of i.
    Let's illustrate this with an example:

    Suppose we have a tree with n = 5 vertices, and the parent array is: -1 0 1 2 3 

    For vertex 0, x is -1, so it's the root of the tree. We skip adding any edges for it.
    For vertex 1, x is 0. So, we add the edge (0, 1) and (1, 0) (since it's undirected).
    For vertex 2, x is also 0. So, we add the edge (1, 2) and (2, 1).
    For vertex 3, x is 1. So, we add the edge (2, 3) and (3, 2).
    For vertex 4, x is 1. So, we add the edge (3, 4) and (4, 3).

    And "edge" vector will look like :
    edge[0]: [1]
    edge[1]: [0, 2]
    edge[2]: [1, 3]
    edge[3]: [2, 4]
    edge[4]: [3]

    Explanation:
    edge[0]: Vertex 0 is the root, and its only child is vertex 1.
    edge[1]: Vertex 1 is a child of vertex 0, and its child is vertex 2.
    edge[2]: Vertex 2 is a child of vertex 1, and its child is vertex 3.
    edge[3]: Vertex 3 is a child of vertex 2, and its child is vertex 4.
    edge[4]: Vertex 4 is a child of vertex 3.


    */
    cout<<"Enter the values of main array: ";
    for(int i=0;i<n;i++){
        cin>>main_array[i];
    }
    dfs(0,-1);
    for(auto i:ans){
        cout<<i<<" ";
    }
    cout<<endl;

}
