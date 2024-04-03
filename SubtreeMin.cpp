#include <bits/stdc++.h>
using namespace std;
using ll = long long int;

void dfs(int vertex, int parent, vector<vector<ll>> &graph, vector<ll> &values, vector<ll> &ans)
{
    ll curr = values[vertex];
    for (auto i : graph[vertex])
    {
        if (i != parent)
        {
            dfs(i, vertex, graph, values, ans);
            curr = min(ans[i],curr);
        }
    }
    curr =min(curr,values[vertex]);
    ans[vertex] = curr;
}

vector<vector<ll>> buildtree(vector<ll> parent)
{
    ll n = parent.size();
    vector<vector<ll>> tree(n);

    for (int i = 0; i < n; i++)
    {
        if(parent[i]!=-1)
            tree[parent[i]].push_back(i);
        tree[i].push_back(parent[i]);
    }
    return tree;
}

int main()
{
    ll n;
    cin >> n;
    vector<ll> parent(n);
    for (auto &i : parent)
        cin >> i;

    vector<ll> values(n);

    for (auto &i : values)
        cin >> i;

    vector<vector<ll>> tree;
    tree = buildtree(parent);
    vector<ll> ans(n);

    dfs(0, -1, tree, values, ans);

    for (auto i : ans)
        cout << i << " ";
    cout << endl;
}
