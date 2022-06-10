#include <bits/stdc++.h>
#define ll long long int 

using namespace std;

class fnwk_tree
{
private:
    vector<ll> tree;
    int n;
public:
    fnwk_tree(int n){
        this->n = n;
        tree.resize(n+1,0);
    }

    ll sum(int idx){
        ll ans =0;
        while(idx>0){
            ans += tree[idx];
            idx -= idx&(-idx);
        }
        return ans;
    }

    ll sum(int l,int r){
        ll w = sum(r);
        ll e = sum(l-1);
        return w-e;
    }

    void add(int i,ll w){
        for (; i <= n; i+= i&(-i))
        {
            tree[i] += w;
        }
    }

    void add_range(int l,int r,ll val){
        add(l,val);
        add(r+1,-val);
    }

};

int main(int argc, char const *argv[])
{
    int n,m;
    cin>>n>>m;
    fnwk_tree answer(n);
    vector<int> vec(n+1,0);
    for (int i = 1; i <= n; i++)
    {
        cin>>vec[i];
    }
    while(m--){
        int w;
        cin>>w;
        if(w==1){
            int a,b,c;
            cin>>a>>b>>c;
            answer.add_range(a,b,c);
        }
        else if(w==2){
            int a;
            cin>>a;
            cout<<answer.sum(a)+vec[a]<<"\n";
        }
    }
    return 0;
}