#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int N = 1e5+10;
vector<int> adj[N];
bool vis[N];

//for unreachable vertices we have to put value -1
// so defining vector with default value -1
vector<int> distance_vector(N,-1);

// using bfs
void bfs(int source){
    queue<int> q;
    q.push(source);
    vis[source] =true;
    distance_vector[source]=0;

    while (!q.empty())
    {
        int crt_node = q.front();
        q.pop();
        for(int child:adj[source]){
            if(!vis[child]){
                q.push(child);
                vis[child]=true;
                distance_vector[child]=distance_vector[crt_node]+1;
            }
        }
    }
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
    bfs(0); // taking root node as 0


    // printing distances 
    for (int i = 0; i < v; i++)
    {
        cout<<"Vertex : "<<v<<" Distance: "<<distance_vector[v]<<"\n";
    }
    
    return 0;
}