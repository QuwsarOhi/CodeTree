#include <bits/stdc++.h>
#define MAX 509
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

int BPM(vector<int> &v, vector<vector<int> >&G) {                            // Bipartite Matching
    int cnt = 0;
    memset(lft, -1, sizeof lft);
    memset(rht, -1, sizeof rht);
    
    //for(auto it : v) {
    //    cout << it << " : ";
    //    for(auto it2 : G[it])
    //        cout << it2 << " ";
    //    cout << endl;
    //}
    for(int i = 0; i < (int)v.size(); ++i) {            // Nodes are numbered from 1 to n
        vis.reset();
        cnt += VertexCover(v[i], G);                    // Check if there exists a match for node i
    }
    return cnt;
}

bitset<MAX>vis1, vis2;
bool DoesMatch(int u1, int u2) {
    //cerr << "TRYING " << u1 << " & " << u2 << endl;
    //getchar();
    if((int)G1[u1].size()-1 == 0) {
        //cerr << u1 << " & " << u2 << " Matched\n";
        return 1;
    }
    
    vector<vector<int> >G(MAX);
    
    for(int i = 0; i < (int)G1[u1].size(); ++i) {
        int v1 = G1[u1][i];
        
        if(vis1[v1])
            continue;
        vis1[v1] = 1;
        
        for(int j = 0; j < (int)G2[u2].size(); ++j) {
            int v2 = G2[u2][j];
            
            if(vis2[v2])
                continue;
            vis2[v2] = 1;
                
            if(DoesMatch(v1, v2)) {
                //cerr << v1 << " & " << v2 << " Matched\n";
                G[v1].push_back(v2+100);
                G[v2+100].push_back(v1);
            }
            //else
                //cerr << v1 << " & " << v2 << " NOT MATCHED\n";
            vis2[v2] = 0;
        }
        vis1[v1] = 0;
    }
    
    //cerr << "BPM STARTED\n";
    int cnt = BPM(G1[u1], G);
    //cerr << "BPM ENDED " << cnt << " : " << G1[u1].size() << endl;
    //for(int i = 0; i < MAX; ++i)
    //    G[i].clear();
    //cerr << "CLEAR ENDED\n";
    return (cnt == (int)G1[u1].size() - (u1!=1));
}
    
int main() {
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
        
        vis1.reset(), vis2.reset();
        vis1[1] = vis2[1] = 1;
        printf("Case %d: %s\n", Case, DoesMatch(1, 1)?"Yes":"No");
        
        for(int i = 0; i <= n; ++i)
            G1[i].clear();
        for(int i = 0; i <= m; ++i)
            G2[i].clear();
    }
    return 0;
}




/*
1
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
NO*/
/*
1
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
YES*/

/*
1
4
1 2
2 3
2 4
3
1 2
1 3
NO*/
