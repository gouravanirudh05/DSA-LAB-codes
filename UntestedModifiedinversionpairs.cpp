//
// Created by GOURAV ANIRUDH B J on 12-04-2024.
//
#include<bits/stdc++.h>
using namespace  std;
using ll=long long int;


ll prefix(vector<ll>&BIT,ll pos)
{
    ll sum=0;
    while(pos>0)
    {
        sum+=BIT[pos];
        pos-=pos&(-pos);
    }
    return sum;
}

ll findsum(vector<ll>&BIT,ll start,ll end)
{
    return prefix(BIT,end)-prefix(BIT,start-1);
}

void update(vector<ll>&BIT,ll pos,ll x)
{
    while(pos<BIT.size())
    {
        BIT[pos]+=x;
        pos+=(pos&(-pos));
    }
}


vector<ll>transform(vector<ll>&a,ll mult,ll add)
{
    vector<ll>ans;
    for(ll i:a)
        ans.push_back(i*mult+add);
    return ans;
}

ll findpairs(vector<ll>&a,ll leftmult,ll leftadd,ll rightmult,ll rightadd)
{
    vector<ll>b= transform(a,leftmult,leftadd);
    vector<ll>bcopy(b);
    vector<ll>c= transform(a,rightmult,rightadd);
    vector<ll>ccopy(c);
    sort(bcopy.begin(),bcopy.end());
    sort(ccopy.begin(),ccopy.end());
    vector<ll>leftsum;
    vector<ll>BIT(b.size()+1,0);
    ll total=0;
    for(int i=0;i<b.size();i++) {
        ll index = lower_bound(bcopy.begin(), bcopy.end(), a[i]) - bcopy.begin() - 1;

        if (index != -1) {
            leftsum.push_back(findsum(BIT, 1, index + 1));
        }
        update(BIT, lower_bound(bcopy.begin(), bcopy.end(), b[i] - bcopy.begin() + 1), 1);
    }
        BIT=vector<ll>(c.size()+1,0);

    for(ll i= c.size()-1;i>=0;i--)
    {
        ll index= lower_bound(ccopy.begin(),ccopy.end(),a[i])-ccopy.begin();
        if(index !=ccopy.size())
        {
            total+=leftsum[i]*(findsum(BIT,index+1,BIT.size()-1));
            update(BIT, lower_bound(ccopy.begin(),ccopy.end(),c[i])-ccopy.begin(),1);
        }
    }
    return total;
}

int main()
{
    ll t;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        vector<ll>a(n);
        for(auto &i:a)
            cin>>i;
        ll leftmult, leftadd, rightmult, rightadd;
        cin >> leftmult >> leftadd >> rightmult >> rightadd;

        ll result = findpairs(a, leftmult, leftadd, rightmult, rightadd);
        cout << result << endl;

    }
}
