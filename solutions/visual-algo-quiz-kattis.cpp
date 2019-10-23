#include <iostream>
#include <vector>
#include <set>

#define pb push_back
using namespace std;

int main() {
    int n, m; cin >> n >> m;

    vector<int> best(n, 1e9 + 10);
    vector<int> ways(n, 0);
    vector<vector<pair<int,int>>> adj(n);
    for(int i = 0; i < m; i++) {
        int n1, n2, w; cin >> n1 >> n2 >> w;
        adj[n1].pb({n2,w});
    }

    int start, end; cin >> start >> end;

    set<pair<int,int>> q;
    q.insert({0, start});

    ways[start] = 1;
    best[start] = 0;
    while(!q.empty()) {
        pair<int,int> p = *q.begin();
        int curr = p.second;
        q.erase(p);

        for(auto edge : adj[curr]) {
            int next = edge.first;
            int w = edge.second;
            if(best[next] > best[curr] + w) {
                q.erase({best[next], next});
                ways[next] = ways[curr];
                best[next] = best[curr] + w;
                q.insert({best[next], next});
            }
            else if(best[next] == best[curr] + w) {
                ways[next] += ways[curr];
            }
        }
    }

    cout << ways[end] << endl;

    return 0;
}