#include <iostream>
#include <algorithm>
#include <queue>
#include <limits.h>
#include <vector>


using namespace std;
const int N = 1e6+10;
vector<pair<int,int> > Graph_list[N];
int top_sort[N];
int inDEG[N];

// topological sorting 

bool top_sort_alg(int n){
    queue<int> my_queue;
    for (int i = 1; i <= n; i++)
        if(inDEG[i]==0){
            my_queue.push(i);
        }
    int idx = 0;
    while(!my_queue.empty()){
        int crt = my_queue.front();
        my_queue.pop();
        top_sort[idx++]=crt;
        for(auto y: Graph_list[crt]){
            int x = y.first;
            inDEG[x] -=1;
            if(inDEG[x]==0){
                my_queue.push(x);
            }
        }
    }
    if(idx!=n){
        return false;
    }
    return true;
}

vector<int> min_distance(N,INT_MAX);
bool shortest_path(int u,int v,int n){
    int idx = n-1;
    while(idx>=0){
        if(top_sort[idx]==v) break;
        idx--;
    }
    min_distance[top_sort[idx--]]=0;
    while(idx>=0){
        for(auto x:Graph_list[top_sort[idx]]){
            if(min_distance[x.first]==INT_MAX) continue;
            min_distance[top_sort[idx]] = min(min_distance[top_sort[idx]],x.second+min_distance[x.first]);
        }
        if(top_sort[idx]==u) break;
        idx--;
    }
    return min_distance[top_sort[idx]]!=INT_MIN || u==v; // return true if shortest path is present 
}

vector<int> dis(N,INT_MIN);
bool longest_path(int u,int v,int n){
    int idx = n-1;
    while(idx>=0){
        if(top_sort[idx]==v) break;
        idx--;
    }
    dis[top_sort[idx--]]=0;
    while(idx>=0){
        for(auto x:Graph_list[top_sort[idx]]){
            if(dis[x.first]==INT_MIN) continue;
            dis[top_sort[idx]] = max(dis[top_sort[idx]],x.second+dis[x.first]);
        }
        if(top_sort[idx]==u) break;
        idx--;
    }
    return dis[top_sort[idx]]!=INT_MIN || u==v; // return true if longest path is present 
}

void dfs_print(int idx,int v){
    cout<<idx<<" ";
    if(idx==v) return;
    for(auto chld:Graph_list[idx]){
        if(dis[chld.first]+chld.second == dis[idx]){
            dfs_print(chld.first,v);
            break;
        }
    }
}

bool print_longest_path(int u,int v,int n){
    if(!longest_path(u,v,n)) return false;
    cout<<dis[u]+1<<"\n"; // for cses question 
    dfs_print(u,v);
    return true;
}

vector<int> result;
void store_longest_path(int u,int v){
    if(u==v){
        return;
    }
    for(auto chld:Graph_list[u]){
        if(dis[u]-chld.second == dis[chld.first]){
            result.push_back(u);
            store_longest_path(chld.first,v);
            break;
        }
    }
}

int no_of_path(int u,int v,int n){
    vector<int> store_no_of_path(n+1,0);

    int idx = n-1;
    while(idx>=0){
        if(top_sort[idx]==v) break;
        idx--;
    }
    store_no_of_path[top_sort[idx--]]=1;
    while(idx>=0){
        for(auto x:Graph_list[top_sort[idx]]){
            store_no_of_path[top_sort[idx]] += store_no_of_path[x.first];
            // store_no_of_path[top_sort[idx]] += store_no_of_path[x];   // for unweighted graph;
        }
        if(top_sort[idx]==u) break;
        idx--;
    }
    return store_no_of_path[top_sort[idx]];
}

// driver's code

int main(int argc, char const *argv[])
{
    int v,e;
    cin>>v>>e;
    for (int i = 0; i < e; i++)
    {
        // taking vertices from 1,2 ... v 
        int a,b,c=1;
        // cin>>a>>b>>c; // for weighted graph
        cin>>a>>b; // for unweighted graph
        Graph_list[a].push_back({b,c});
        inDEG[b]++;
    }

    if(!top_sort_alg(v)){
        cout<<"IMPOSSIBLE\n";
    }
    if(!print_longest_path(1,v,v)) cout<<"IMPOSSIBLE\n";
    return 0;
}
