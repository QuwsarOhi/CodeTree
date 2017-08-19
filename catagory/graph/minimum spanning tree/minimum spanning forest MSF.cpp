//10369 - Arctic Network
//Minimum Spanning Forest
//Kruskal's Algorithm

#include <bits/stdc++.h>
#define MAX 1000

using namespace std;

vector<pair<double, pair<int, int> > > Edge;
vector<int>u_list, u_set;
vector<pair<int, int> >points;


//u_list[x] contains the size of a set x
//u_set[x] contains the root of x

int unionRoot(int n)
{
    if(u_set[n] == n)
        return n;
    else
        return u_set[n] = unionRoot(u_set[n]);
}

int makeUnion(int a, int b)
{
    int x = unionRoot(a);
    int y = unionRoot(b);

    if(x == y)
        return x;
    else if(u_list[x] > u_list[y]) {
        u_set[y] = x;
        u_list[x] += u_list[y];
        return x;
    }
    else {
        u_set[x] = y;
        u_list[y] += u_list[x];
        return y;
    }
}

void unionInit(int len)
{
    u_list.resize(len+5, 1);
    u_set.resize(len+5);

    for(int i = 0; i <= len; i++)
        u_set[i] = i;
}

bool isSameSet(int a, int b)
{
    if(unionRoot(a) == unionRoot(b))
        return 1;
    return 0;
}


int main()
{
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);

    int t;
    scanf("%d", &t);
    while(t--) {
        int V, E, u, v, S, x, y;
        double w;
        scanf("%d %d", &S, &V);
        for(int i = 0; i < V; i++) {
            scanf("%d %d", &x, &y);
            points.push_back(make_pair(x, y));
        }

        for(int i = 0; i < V; i++)
            for(int j = i + 1; j < V; j++) {
                x = points[i].first - points[j].first;
                y = points[i].second - points[j].second;
                double dist = x * x + y * y;
                dist = sqrt(dist);
                Edge.push_back(make_pair(dist, make_pair(i, j)));
            }

        sort(Edge.begin(), Edge.end());
        priority_queue<double>pq;
        double mst_cost = 0, selected_edge = 0;
        unionInit(V);

        //V - S is due to Minimum Spanning Forest, ignoring S nodes
        for(int i = 0; i < Edge.size() && selected_edge < V - S; i++) {
            u = Edge[i].second.first;
            v = Edge[i].second.second;
            w = Edge[i].first;

            if(!isSameSet(u, v)) {
                selected_edge++;
                pq.push(w);
                mst_cost = max(w, mst_cost);
                makeUnion(u, v);
            }
        }

        printf("%.2lf\n", mst_cost);
        Edge.clear();
        points.clear();
    }
	return 0;
}
