#include<bits/stdc++.h>

#define pb push_back
using namespace std;
const int N = 1e6+10;
vector<int> graph_list[N],reversed_graph[N];
int visited[N];
bool values_of_nodes[N];

stack<int> s1;

void dfs1(int source){
    visited[source]=true;
    for(auto x:graph_list[source]){
        if(visited[x]) continue;
        dfs1(x);
    }
    s1.push(source);
}

void dfs2(int source,int cnt){
    visited[source] = cnt;
    for(auto x:reversed_graph[source]){
        if(visited[x]) continue;
        dfs2(x,cnt);
    }
}

int solver(int n){
    for (int i = 1; i <= n; i++){
        if(visited[i]) continue;
        dfs1(i);
    }

    for (int i = 1; i <=n; i++){
        visited[i] = false;
    }
    
    int counter =1;
    while(!s1.empty()){
        int crt = s1.top();
        s1.pop();
        if(visited[crt]) continue;
        dfs2(crt,counter);
        counter++;
    }
    int w = n/2;
    for (int i = 1; i <= w; i++)
    {
        if(visited[i]==visited[w+i]) return false;
        values_of_nodes[i] = visited[i]>visited[w+i];
    }
    return true;
}

int get_index(int a,bool sign_a,int n){
    if(!sign_a) return a+n;
    return a;
}
void add_edge(int a,int b,bool sign_a,bool sign_b,int n){
    int a1 = get_index(a,!sign_a,n);
    int a2 = get_index(b,sign_b,n);
    int b1 = get_index(b,!sign_b,n);
    int b2 = get_index(a,sign_a,n);
    graph_list[a1].pb(a2);
    graph_list[b1].pb(b2);

    reversed_graph[a2].pb(a1);
    reversed_graph[b2].pb(b1);
    return;
}

int main()
{
    int e,v;
    cin>>e>>v;
    for (int i = 0; i < e; i++)
    {
        int a,b;
        char s_a,s_b;
        cin>>s_a>>a>>s_b>>b;
        bool w = s_a=='+';
        bool e = s_b=='+';
        add_edge(a,b,w,e,v);
    }
    if(solver(2*v)){
        for(int i =1;i<=v;i++){
            if(values_of_nodes[i]) cout<<"+ ";
            else cout<<"- ";
        }
        cout<<"\n";
    }
    else{
        cout<<"IMPOSSIBLE\n";
    }
    return 0;
}
