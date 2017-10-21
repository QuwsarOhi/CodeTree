#include <bits/stdc++.h>
using namespace std;

int dy[] = {-1, 0, 0, 1}, dx[] = {0, -1, 1, 0};
bitset<100>Node;                    // Contains Numer of Unique Nodes
vector<int>G[410];
char mat[25][25];
map<pair<int, int>, bool>mp;       // To check unique connections

int NodeNumber(int r, int c, int n, int m) {
	return  m*r + c + 1;
}

void GridToList(int r, int c) {	            // r = total row, c = total column
	for(int i = 0; i < r; ++i) {
		for(int j = 0; j < c; ++j) {
			for(int k = 0; k < 4; ++k) {
				int x = i + dx[k];
				int y = j + dy[k];
				
				if(x < 0 || y < 0 || x >= r || y >= c)
					continue;
				
				int u = NodeNumber(i, j, r, c), v = NodeNumber(x, y, r, c);
				if(mat[i][j] == '*' && mat[x][y] == '*') {
					if(mp.find({u, v}) != mp.end())
						continue;
					G[u].push_back(v);
					G[v].push_back(u);
					Node[v] = Node[u] = 1;
					mp[{u, v}] = mp[{v, u}] = 1;
				}
				else if(mat[i][j] == '*')		// Only Single Point
					Node[u] = 1;
				else if(mat[x][y] == '*')
					Node[v] = 1;
			}
		}
	}
}


int main() {
    return 0;
}
