#include <iostream>
#include <vector>

using namespace std;

const int N = 1e5+10;
// declaration of adj_list and visited array 
vector<int> adj[N];
bool vis[N];

int time_in[N];     // in time array 
int time_out[N];    // out time array 

int currt_time=0; // timer 
// dfs function 
void dfs(int source){
    time_in[source] = currt_time;
    currt_time++;
    vis[source] = true; // maintaining visited array
    for (int child:adj[source])
    {
        // iterating all child which are not visited
        if(!vis[child]){
            dfs(child);
        }
    }
    time_out[source] = currt_time;
    currt_time++;
}

bool is_ancestor(int start,int end){
    // for ancestor start time of ancestor >= time_in of its descendants and out_time of ancestor is greater than
    // its descendants 
    return time_in[start]<time_in[end] && time_out[start]>time_out[end];
}

bool is_tree_edge(int start,int end){
    return is_ancestor(start,end);
}

int main(int argc, char const *argv[])
{
    int v,e;
    cin>>v>>e; // input no of vertices and edges
    
    vector<pair<int,int> > edges;
    for (int i = 0; i < e; i++)
    {
        int x,y;
        cin>>x>>y;
        edges.push_back({x,y});
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    dfs(0); // taking root node as 0 
    for (int i = 0; i < v; i++)
    {
        cout<<"Vertice : "<<i<<" In time: "<<time_in[i]<<" Out time: "<<time_out[i]<<"\n";    
    }
    for (auto edge:edges)
    {
        if(is_tree_edge(edge.first,edge.second)){
            cout<<"("<<edge.first<<","<<edge.second<<")"<<" -> tree edge\n";
        }
        else{
            cout<<"("<<edge.first<<","<<edge.second<<")"<<" -> back edge\n";
        }
    }
    return 0;
}
