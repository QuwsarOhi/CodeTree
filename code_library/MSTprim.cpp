//Minimum Spanning Tree
//Prim's Algorithm
//Complexity : O(E logV)

#include<bits/stdc++.h>
#define MAX 100
using namespace std;

vector<int> G[MAX], W[MAX];
priority_queue<pair<int, int> >pq;
bitset<MAX>taken;

void process(int u)
{
    //mark this node as taken
    taken[u] = 1;
    //get all the edges of this node on a priority queue
    for(int i = 0; i < G[u].size(); i++) {
        int v = G[u][i];
        int w = W[u][i];
        if(!taken[v])
            pq.push(make_pair(-w, -v));
    }
    //priority queue returns the minimum node first, if tie, then the first node
}

int main()
{
    freopen("in", "r", stdin);
    //freopen("out", "w", stdout);

    int V, E, u, v, w;
    scanf("%d %d", &V, &E);
    while(E--) {
        scanf("%d %d %d", &u, &v, &w);
        G[u].push_back(v);
        W[u].push_back(w);
        G[v].push_back(u);
        W[v].push_back(w);
    }

    //Main Prim's MST code

    taken.reset();

    //taking 0 node as default
    process(0);
    int mst_cost = 0;

    while(!pq.empty()) {
        w = -pq.top().first;
        v = -pq.top().second;
        pq.pop();

        //if the node is not taken, then use this node
        //as it contains the minimum edge
        if(!taken[v]) {
            mst_cost += w;
            process(v);
        }
    }



    printf("Prim's MST cost : %d\n", mst_cost);

    return 0;
}


    /*
    //Sample input
    //Ans is 18
    5 7
    0 1 4
    0 2 4
    0 3 6
    0 4 6
    1 2 2
    2 3 8
    3 4 9
    */
