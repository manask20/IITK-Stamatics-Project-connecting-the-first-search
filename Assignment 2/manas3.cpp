#include<bits/stdc++.h>

#define pb push_back
using namespace std;
const int N = 1e5+10;
vector<int> graph_list[N],reversed_graph[N];
int visited[N];


// using kosaraju algorithm 
stack<int> mystack;

void dfs1(int v){
    visited[v] = true;
    for(auto x:graph_list[v]){
        if(visited[x]) continue;
        dfs1(x);
    }
    mystack.push(v);
}

void dfs2(int v,int count){
    visited[v] = count;
    for(auto x:reversed_graph[v]){
        if(visited[x]) continue;
        dfs2(x,count);
    }
}

int find_strongy_con_comp(int n){
    for(int i = 1; i <=n; i++){
        if(!visited[i])
            dfs1(i);
    }

    for (int i =1; i <= n; i++)
    {
        visited[i] = false;
    }
    
    int counter = 1;
    while(!mystack.empty()){
        int crt = mystack.top();
        mystack.pop();
        if(visited[crt]) continue;
        dfs2(crt,counter);
        counter++;
    }
    return counter-1;
}
// driver code
int main()
{
    int v,e;
    cin>>v>>e;
    for (int i = 0; i < e; i++)
    {
        int a,b;
        cin>>a>>b;
        graph_list[a].pb(b);
        reversed_graph[b].pb(a); // making reversed_graphersed graph 
    }
    cout<<find_strongy_con_comp(v)<<endl;
    for (int i = 1; i <= v; i++)
    {
        cout<<visited[i]<<" ";
    }
    cout<<"\n";
    return 0;
}
