#include <bits/stdc++.h>

using namespace std;

class disjoint_set
{
private:
    vector<int> prnt;
public:
    disjoint_set(int n)
    {
        prnt.resize(n,-1);
    }
    int disjoint_set::find_prnt(int n){
        if(prnt[n]<0) return n;
        return prnt[n]=find_prnt(prnt[n]);
    }
    void union_sets(int a,int b){
        a = find_prnt(a);
        b = find_prnt(b);
        if(a!=b){
            if(prnt[b]<prnt[a]) swap(a,b);
            prnt[a] += prnt[b];
            prnt[b]=a;
        }
        return;
    }
};

int main(int argc, char const *argv[])
{
    int n,m; 
    cin>>n>>m;
    disjoint_set ans(n);
    while(m--){
        string w;
        int a,b;
        cin>>w>>a>>b;
        a--,b--;
        if(w=="union"){
            ans.union_sets(a,b);
        }
        else{
            int w = ans.find_prnt(a);
            int v = ans.find_prnt(b);
            bool k = (w==v);
            cout<<((k)?"YES\n":"NO\n");
        }
    }
    return 0;
}
