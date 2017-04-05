#include<bits/stdc++.h>
#define MAX 100
#define INF 1e6

using namespace std;

vector<int>dist, G[MAX], W[MAX];

void dikjstra(int u, int nodes)
{
    //dist[v] contains the distance from u to v
    dist.resize(nodes+1, INF);
    dist[u] = 0;
    //pq is sorted in ascending order according to weight and edge
    priority_queue<pair<int, int> > pq;
    pq.push(make_pair(0, -u));

    while(!pq.empty()) {
        int u = -pq.top().second;
        int wu = -pq.top().first();
        pq.pop();

        //skipping the longer edges, if we have found shorter edge earlier
        if(wu > dist[u])
            continue;

        for(int i = 0; i < G[u].size(); i++) {
            int v = G[u][i];
            int wv = W[u][i];

            //path relax
            if(wu + wv < dist[v]) {
                dist[v] = wu + wv;
                pq.push(make_pair(-dist[v], -v);
            }
        }
    }
}

int main()
{

}
