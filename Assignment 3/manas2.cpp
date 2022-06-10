#include <bits/stdc++.h>

using namespace std;

class disjoint_set
{
private:
    vector<int> prnt;
public:
    disjoint_set(int n);
    int findpar(int);
    void union_sets(int,int);
};

disjoint_set::disjoint_set(int n)
{
    prnt.resize(n,-1);
}

int disjoint_set::findpar(int n){
    if(prnt[n]<0) return n;
    return prnt[n]=findpar(prnt[n]);
}

void disjoint_set::union_sets(int a,int b){
    a = findpar(a);
    b = findpar(b);
    if(a!=b){
        if(prnt[b]<prnt[a]) swap(a,b);
        prnt[a] += prnt[b];
        prnt[b]=a;
    }
    return;
}


int main(int argc, char const *argv[])
{
    int n,m,k;
    cin>>n>>m>>k;
    disjoint_set ans(n);
    int a,b;
    for (int i = 0; i < m; i++)
    {
        cin>>a>>b;
    }
    stack<vector<int> > q2;
    for (int i = 0; i < k; i++)
    {
        string p;
        cin>>p>>a>>b;
        a--,b--;
        if(p=="ask"){
            q2.push({1,a,b});
        }
        else{
            q2.push({0,a,b});
        }
    }
    vector<string> res;
    while(!q2.empty()){
        auto x = q2.top();
        q2.pop();
        if(x[0]){
            res.push_back((ans.findpar(x[1])==ans.findpar(x[2]))?"YES\n":"NO\n");
        }
        else{
            ans.union_sets(x[1],x[2]);
        }
    }
    for(auto it=res.rbegin();it!=res.rend();it++){
        cout<<*it;
    }
}
