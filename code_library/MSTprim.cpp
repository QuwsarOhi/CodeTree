//Minimum Spanning Tree
//Prim's Algorithm
//Complexity : O(E logV)

vector<int> G[MAX], W[MAX];
priority_queue<pair<int, int> >pq;
bitset<MAX>taken;

void process(int u) {
    taken[u] = 1;
    for(int i = 0; i < (int)G[u].size(); i++) {
        int v = G[u][i];
        int w = W[u][i];
        if(!taken[v])
            pq.push(make_pair(-w, -v));
    }
}

int main() {
    taken.reset();
    process(0);    //taking 0 node as default
    int mst_cost = 0;
    while(!pq.empty()) {
        w = -pq.top().first;
        v = -pq.top().second;
        pq.pop();
        //if the node is not taken, then use this node
        //as it contains the minimum edge
        if(!taken[v])
            mst_cost += w, process(v);
    }
    printf("Prim's MST cost : %d\n", mst_cost);
    return 0;
}
