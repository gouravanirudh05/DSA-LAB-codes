#include<bits/stdc++.h>
using namespace std;
//You can change combine function according to the ST you want to make
int combine(const int &a,const int &b)
{
	return a+b;
}
//Building Segment Tree Recursively
void build(const vector<int> &a, int tl, int tr, int idx, vector<int> &stree)
{
	if(tl == tr)
		stree.at(idx) = a.at(tl);
	else
	{
		int tm = tl + (tr-tl)/2;
		build(a,tl,tm,2*idx,stree);
		build(a,tm+1,tr,2*idx+1,stree);
		stree.at(idx) = combine(stree.at(2*idx),stree.at(2*idx+1));
	}
}
//Point Update
void update(int tl, int tr, int idx, int pos, int val, vector<int> &stree)
{
	if(tl == tr)
		stree.at(idx) = val;
	else
	{
		int tm = tl + (tr-tl)/2;
		if(pos<=tm)
			update(tl,tm,2*idx,pos,val,stree);
		else
			update(tm+1,tr,2*idx+1,pos,val,stree);
		stree.at(idx) = combine(stree.at(2*idx),stree.at(2*idx+1));
	}
}
//Range Query
int query(int tl, int tr, int idx, int l, int r, vector<int> &stree)
{
	if(l>r)
		return 0;// change acc to question
	else if(tl == l && tr == r)
		return stree.at(idx);
	int tm = tl + (tr-tl)/2;
	return combine(query(tl,tm,2*idx,l , min(r,tm),stree) , query( tm+1,tr,2*idx+1,max(l,tm+1),r,stree));
}
int main()
{
	int n,q;
	cin>>n>>q;
	vector<int> v(n),stree(4*n);
	for(int i = 0 ;i<n;i++)
		cin>>v.at(i);
	//Build Segment Tree
	build(v,0,n-1,1,stree);
	vector<pair<int,int>> queries(q);
	for(int i = 0;i<q;i++)
		cin>>queries.at(i).first>>queries.at(i).second;
	for(const auto &p:queries)
	{
		cout<<query(0,n-1,1,p.first-1,p.second-1,stree)<<endl;
	}
	return 0;
}
