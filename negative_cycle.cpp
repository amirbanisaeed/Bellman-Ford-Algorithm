#include <iostream>
#include <vector>
using namespace std;
using std::vector;

int negative_cycle(vector<vector<int> >& adj, vector<vector<int> >& cost) {
    //write your code here
    vector<long long> dist(adj.size());

    for (size_t i = 0; i < dist.size(); i++)
    {
        dist[i] = INT32_MAX;
    }

    dist[0] = 0;

    long long  v;

    for (size_t i = 0; i <= dist.size(); i++)
    {

        if (i == dist.size() - 1)
        {
            //cout << "Hey";
            for (size_t u = 0; u < adj.size(); u++)
            {
                for (size_t j = 0; j < adj[u].size(); j++)
                {
                    v = adj[u][j];
                    if (dist[v] > dist[u] + cost[u][j])
                    {
                        return 1;
                        dist[v] = dist[u] + cost[u][j];
                    }
                }
            }
        }

        else
        {
            //cout << "i " << i;

            for (size_t u = 0; u < adj.size(); u++)
            {
                for (size_t j = 0; j < adj[u].size(); j++)
                {
                    v = adj[u][j];
                    if (dist[v] > dist[u] + cost[u][j])
                    {
                        dist[v] = dist[u] + cost[u][j];
                        // cout << "u: " << u <<" v: " << v << " Dist v: " << dist[v] << "Cost " << cost[u][j]<<endl;
                    }
                }

            }

        }




    }

    // cout << "OOOOOPS";
   /*
     for (size_t i = 0; i < dist.size(); i++)
     {
       cout << dist[i] << endl;
     }

   */
    return 0;
}

int main() {
    int n, m;
    std::cin >> n >> m;
    vector<vector<int> > adj(n, vector<int>());
    vector<vector<int> > cost(n, vector<int>());
    for (int i = 0; i < m; i++) {
        int x, y, w;
        std::cin >> x >> y >> w;
        adj[x - 1].push_back(y - 1);
        cost[x - 1].push_back(w);
    }
    std::cout << negative_cycle(adj, cost);
}
