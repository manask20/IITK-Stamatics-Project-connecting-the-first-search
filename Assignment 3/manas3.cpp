#include <bits/stdc++.h>

using namespace std;

class disjoint_set
{
private:
    vector<int> par;
public:
    disjoint_set(int n);
    int findpar(int);
    void union_sets(int,int);
};

disjoint_set::disjoint_set(int n)
{
    par.resize(n,-1);
}

int disjoint_set::findpar(int n){
    if(par[n]<0) return n;
    return par[n]=findpar(par[n]);
}

void disjoint_set::union_sets(int a,int b){
    a = findpar(a);
    b = findpar(b);
    if(a!=b){
        if(par[b]<par[a]) swap(a,b);
        par[a] += par[b];
        par[b]=a;
    }
    return;
}

int main(int argc, char const *argv[])
{
    int n,m;
    cin>>n>>m;
    disjoint_set result(n);
    vector<pair<int,pair<int,int> > >edg;
    for (int i = 0; i < m; i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        edg.push_back({w,{u,v}});
    }
    sort(edg.begin(),edg.end());

    int min_cost =0;
    for(auto x:edg){
        int wt = x.first;
        int u = x.second.first;
        int v = x.second.second;
        u--,v--;
        if(result.findpar(u)==result.findpar(v)) continue;
        result.union_sets(u,v);
        min_cost += x.first;
    }
    cout<<min_cost<<"\n";
}
