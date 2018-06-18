// LightOJ
// 1242 - Similar Trees (II)

#include <bits/stdc++.h>
#define MAX 200
using namespace std;

bitset<MAX>vis;
int lft[MAX], rht[MAX];
vector<int>G1[MAX], G2[MAX];

int VertexCover(int u, vector<vector<int> >&G) {                    // Min Vertex Cover
	vis[u] = 1;
	for(int i = 0; i < (int)G[u].size(); ++i) {
		int v = G[u][i];
		if(vis[v])                          // If v is used earlier, skip
			continue;
		vis[v] = 1;
        
		if(lft[v] == -1) {                  // If there is no node present on left of v
			lft[v] = u, rht[u] = v;
			return 1;
		}
		else if(VertexCover(lft[v], G)) {       // If there is one node present on the left side of v (Let it be u')
			lft[v] = u, rht[u] = v;             // and if it is possible to match u' with another node (not v ofcourse!)
			return 1;                           // then we can match this u with v, and u' is matched with another node as well
    }}
	return 0;
}

int BPM(int n, vector<vector<int> >&G) {                            // Bipartite Matching
    int cnt = 0;
    memset(lft, -1, sizeof lft);
    memset(rht, -1, sizeof rht);
    
    for(int i = 0; i < n; ++i) {            // Nodes are numbered from 1 to n
        vis.reset();
        cnt += VertexCover(i, G);           // Check if there exists a match for node i
    }
    return cnt;
}


bool DoesMatch(int u1, int par1, int u2, int par2) {        // ReCURSE
    if((int)G1[u1].size()-1 == 0 && u1 != 1)
        return 1;
    
    int CNST = G1[u1].size()+2;
    vector<vector<int> >G(CNST+2);
    
    for(int i = 0; i < (int)G1[u1].size(); ++i) {
        int v1 = G1[u1][i];
        
        if(v1 == par1) continue;
        
        for(int j = 0; j < (int)G2[u2].size(); ++j) {
            int v2 = G2[u2][j];
            
            if(v2 == par2) continue;
            
            if(DoesMatch(v1, u1, v2, u2))
                G[i].push_back(CNST+j);
    }}
    
    int cnt = BPM(G1[u1].size(), G);
    return (cnt == (int)G1[u1].size() - (u1!=1));
}


int main() {
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);
    
    int t, u, v, n, m;
    scanf("%d", &t);
    
    for(int Case = 1; Case <= t; ++Case) {
        
        scanf("%d", &m);
        for(int i = 1; i < m; ++i) {        // Expanded Tree
            scanf("%d%d", &u, &v);
            G2[u].push_back(v);
            G2[v].push_back(u);
        }
        
        scanf("%d", &n);
        for(int i = 1; i < n; ++i) {        // Actual Tree
            scanf("%d%d", &u, &v);
            G1[u].push_back(v);
            G1[v].push_back(u);
        }
        
        printf("Case %d: %s\n", Case, DoesMatch(1, -1, 1, -1)?"Yes":"No");
        
        for(int i = 0; i < MAX; ++i)
            G1[i].clear();
        for(int i = 0; i < MAX; ++i)
            G2[i].clear();
    }
    return 0;
}



/*
Input:
11

10
1 2
1 3
3 4
3 5
3 6
2 7
7 8
7 9
9 10
9
1 3
1 2
2 7
3 4
3 5
3 6
4 8
4 9

10
1 2
1 3
3 4
3 5
3 6
2 7
4 8
4 9
9 10
9
1 3
1 2
2 7
3 4
3 5
3 6
4 8
4 9

4
1 2
2 3
2 4
3
1 2
1 3

3
1 2
1 3
4
1 2
2 3
2 4

3
1 2
1 3
3
1 2
1 3

4
1 2
2 3
2 4
3
1 2
1 3

4
1 2
2 3
2 4
4
1 2
1 3
3 1

4
1 2
2 4
1 3
3
1 3
3 2

5
1 2
2 4
1 3
3 5
4
1 3
1 2
1 4

2
1 2
2
1 2

4
1 2
2 3
3 4
2
1 2

Output:
Case 1: No
Case 2: Yes
Case 3: No
Case 4: No
Case 5: Yes
Case 6: No
Case 7: No
Case 8: Yes
Case 9: No
Case 10: Yes
Case 11: Yes
*/
