#include <iostream>
#include <vector>

using namespace std;
const int N = 1e5+10;
vector<int> v1[N];

// A vector which contains connected comp id with vertex index
vector<int> connected_comp_id_vector(N,0);

// id
int connected_comp_id =1;

// using dfs 
void dfs(int vertex,vector<int> &temp){
    connected_comp_id_vector[vertex] = connected_comp_id;
    temp.push_back(vertex);
    for (auto child:v1[vertex])
    {
        if(connected_comp_id_vector[child]) continue;
        dfs(child,temp);
    }
}

int main(int argc, char const *argv[])
{
    int n,m;
    cin>>n>>m;
    for (int i = 0; i < m; i++)
    {
        int x,y;
        cin>>x>>y;
        v1[x].push_back(y);
        v1[y].push_back(x);
    }
    for (int i = 0; i < n; i++)
    {
        vector<int> temp;
        if(connected_comp_id_vector[i]) continue;
        dfs(i,temp);
        connected_comp_id++;
    }

    for (int i = 0; i < n; i++)
    {
        cout<<"Vertex: "<<i<<" ID:"<<connected_comp_id_vector[i]<<"\n";
    }
    
    return 0;
}
