#include <iostream>
#include <vector>
#include <queue>

using namespace std;
const int N = 1e5 + 10;
vector<int> graph_list[N];
int inDEG[N]; // answer

vector<int> kahn_bfs(int n)
{
    vector<int> ordered(n, 0);
    queue<int> my_queue; // maintain a queue
    for (int i = 1; i <= n; i++)
        if (inDEG[i] == 0)
            my_queue.push(i);

    int idx = 0;
    while (!my_queue.empty())
    {
        auto crt = my_queue.front();
        my_queue.pop();
        ordered[idx++] = crt;
        for (auto child : graph_list[crt])
        {
            inDEG[child] = inDEG[child] - 1;
            if (inDEG[child] == 0)
            {
                my_queue.push(child);
            }
        }
    }
    if (idx != n)
    {
        return {}; // graph contains cycles
    }
    return ordered;
}

// driver code
int main()
{
    int v, e;
    cin >> v >> e;
    for (int i = 0; i < e; i++)
    {
        int a, b;
        cin >> a >> b;
        graph_list[a].push_back(b);
        inDEG[b]++;
    }
    vector<int> b = kahn_bfs(v);
    
    for (auto x : b)
    {
        cout << x << " ";
    }

    if (b.empty())
        cout << "IMPOSSIBLE";
    cout << "\n";

    return 0;
}