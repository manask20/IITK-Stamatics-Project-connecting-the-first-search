#include <bits/stdc++.h>
#define ll long long int  
using namespace std;

class fw_tree
{
private:
    vector<ll> tree;
    int n;
public:
    fw_tree(int n){
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
};

int main(int argc, char const *argv[])
{
    int n,m;
    cin>>n>>m;
    fw_tree answer(n);
    for (int i = 1; i <= n; i++)
    {
        int a;
        cin>>a;
        answer.add(i,a);
    }
    while(m--){
        int w,a,b;
        cin>>w>>a>>b;
        if(w==1){
            ll w = answer.sum(a,a);
            answer.add(a,b-w);
        }
        else if(w==2){
            cout<<answer.sum(a,b)<<"\n";
        }
    }
    return 0;
}