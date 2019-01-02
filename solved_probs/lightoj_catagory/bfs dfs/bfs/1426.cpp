// LightOJ
// 1426 - Blind Escape

#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
typedef vector<pii> vii;

int dx[] = {0, -1, 1, 0}, dy[] = {1, 0, 0, -1};
char dir[] = {'E', 'N', 'S', 'W'};

char G[15][15];
int n, m;

// Returns True if the point is insize the maze
bool isInside(pii x) {
	if(x.first >= 0 and x.second >= 0 and x.first < n and x.second < m)
		return 1;
	return 0;
}


// The problem states that, if the hero goes to any direction, he will keep walking until 
// he hits by any obstacle or he is out of the maze
//
// Contains the point, where the hero will stand if he made a move in d direction
pii nextPoint[15][15][4];
pii NextPointGenerator(int x, int y, int d) {
	pii &ret = nextPoint[x][y][d];

	if(ret.first != -1)
		return ret;

	int xx = x + dx[d];
	int yy = y + dy[d];

	if(not isInside(pii(xx, yy)))
		return ret = pii(xx, yy);
	
	if(G[xx][yy] == '#')
		return ret = pii(x, y);
	
	return ret = NextPointGenerator(xx, yy, d);
}


// dfs to check if the hero can actually get out from 
// the maze if he starts from any of the dots

int vis[15][15], mark = 0;
bool canGetOut(int x, int y) {
	if(not isInside(pii(x, y)))
		return 1;
	if(vis[x][y] == mark)
		return 0;
	vis[x][y] = mark;

	for(int d = 0; d < 4; ++d) {
		if(canGetOut(nextPoint[x][y][d].first, nextPoint[x][y][d].second))
			return 1;
	}

	return 0;
}

bool isPossible(const vii &points) {
	for(int i = 0; i < points.size(); ++i) {
		++mark;
		if(not canGetOut(points[i].first, points[i].second))
			return 0;
	}
	return 1;
}

// BFS to find the lexicographically smallest answer

map<vii, string>step;
string bfs(vii &uPoints) {
	queue<vii> q;
	q.push(uPoints);
	
	step.clear();
	step[uPoints] = "";
	
	vii vPoints;
	string prevStep;

	while(not q.empty()) {
		uPoints = q.front();
		prevStep = step[uPoints];
		q.pop();

		if(uPoints.empty())
			return prevStep;

		for(int d = 0; d < 4; ++d) {
			vPoints.clear();

			for(int i = 0; i < uPoints.size(); ++i) {
				int xx = nextPoint[uPoints[i].first][uPoints[i].second][d].first;
				int yy = nextPoint[uPoints[i].first][uPoints[i].second][d].second;

				if(not isInside(pii(xx, yy)))
					continue;

				vPoints.push_back(pii(xx, yy));
			}

			sort(vPoints.begin(), vPoints.end());
            vPoints.erase(unique(vPoints.begin(), vPoints.end()), vPoints.end());

			if(step.find(vPoints) != step.end())
				continue;
			
			step[vPoints] = prevStep + dir[d];
			q.push(vPoints);
		}
	}

	return "";
}

int main() {
	int t;
	vii startPoints;
	scanf("%d", &t);

	for(int Case = 1; Case <= t; ++Case) {
		scanf("%d%d", &n, &m);
		startPoints.clear();

		for(int i = 0; i < n; ++i) {
			scanf("%s", &G[i]);
			for(int j = 0; j < m; ++j)
				if(G[i][j] == '.')
					startPoints.push_back(pii(i, j));
		}


		for(int i = 0; i <= n; ++i)
			for(int j = 0; j <= m; ++j)
				for(int d = 0; d < 4; ++d)
					nextPoint[i][j][d] = pii(-1, -1);


		for(int i = 0; i < startPoints.size(); ++i)
			if(G[startPoints[i].first][startPoints[i].second] == '.')
				for(int d = 0; d < 4; ++d)
					if(nextPoint[startPoints[i].first][startPoints[i].second][d].first == -1)
						nextPoint[startPoints[i].first][startPoints[i].second][d] = NextPointGenerator(startPoints[i].first, startPoints[i].second, d);

		printf("Case %d: ", Case);
		if(not isPossible(startPoints))
			printf("Impossible\n");
		else
			printf("%s\n", bfs(startPoints).c_str());
	}

	return 0;
}