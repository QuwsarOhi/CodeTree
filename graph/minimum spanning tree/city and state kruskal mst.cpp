//UVa
//11228 - Transportation system.
//Minimum Spanning Tree (kruskal)


#include<bits/stdc++.h>
using namespace std;

vector<int> u_list, u_set;
vector<pair<int, int> > points;
vector<pair<double, pair<int, int> > > Edge;

void unionInit(int n)
{
    u_list.resize(n+5, 1);
    u_set.resize(n+5);
    for(int i = 0; i <= n; i++)
        u_set[i] = i;
}

int unionRoot(int n)
{
    if(u_set[n] == n)
        return n;
    return u_set[n] = unionRoot(u_set[n]);
}

void makeUnion(int a, int b)
{
    int x = unionRoot(a);
    int y = unionRoot(b);

    if(x == y)
        return;
    else if(u_list[x] > u_list[y]) {
        u_set[y] = x;
        u_list[x] += u_list[y];
        return;
    }
    else {
        u_set[x] = y;
        u_list[y] += u_list[x];
        return;
    }
}

bool isSameUnion(int a, int b)
{
    if(unionRoot(a) == unionRoot(b))
        return 1;
    return 0;
}

int main()
{
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);

    int u, v, V, E, t, r;

    scanf("%d", &t);
    for(int Case = 1; Case <= t; Case++) {
        scanf("%d %d", &V, &r);
        for(int i = 0; i < V; i++) {
            scanf("%d %d", &u, &v);
            points.push_back(make_pair(u, v));
        }
        //printf("input taken\n");
        for(int i = 0; i < points.size(); i++)
            for(int j = i+1; j < points.size(); j++) {
                int x = points[i].first - points[j].first;
                int y = points[i].second - points[j].second;
                double w = (x*x) + (y*y);
                w = sqrt(w);
                Edge.push_back(make_pair(w, make_pair(i, j)));
            }
        sort(Edge.begin(), Edge.end());
        //printf("Edgelist made\n");
        unionInit(V);
        double mst_city = 0, mst_state = 0;
        int cities = 1;

        for(int i = 0; i < Edge.size(); i++) {
            double w = Edge[i].first;
            u = Edge[i].second.first;
            v = Edge[i].second.second;

            if(!isSameUnion(u, v)) {

                if(w > r) {
                    cities++;
                    mst_city += w;
                    makeUnion(u, v);
                }
                else {
                    mst_state += w;
                    makeUnion(u, v);
                }
            }
        }

        printf("Case #%d: %d %.0lf %.0lf\n", Case, cities, mst_state, mst_city);
        Edge.clear();
        points.clear();
    }
    return 0;
}
