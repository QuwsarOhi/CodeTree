//UVa
//11747 - Heavy Cycle Edges

#include <bits/stdc++.h>
#define MAX 1000

using namespace std;

vector<pair<int, pair<int, int> > > Edge;
vector<int>u_list, u_set, ans;

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

	int V, E, u, v, w;
	while(scanf("%d %d", &V, &E) && (V || E)) {
        for(int i = 0; i < E; i++) {
            scanf("%d %d %d", &u, &v, &w);
            Edge.push_back(make_pair(w, make_pair(u, v)));
        }
        sort(Edge.begin(), Edge.end());

        unionInit(V);

        for(int i = 0; i < E; i++) {
            u = Edge[i].second.first;
            v = Edge[i].second.second;
            w = Edge[i].first;

            if(!isSameSet(u, v)) {
                makeUnion(u, v);
            }
            else
                ans.push_back(w);
        }
        if(ans.empty())
            printf("forest\n");
        else {
            printf("%d", ans[0]);
            for(int i = 1; i < ans.size(); i++)
                printf(" %d", ans[i]);
            printf("\n");
        }
        Edge.clear();
        ans.clear();
	}
	return 0;
}
