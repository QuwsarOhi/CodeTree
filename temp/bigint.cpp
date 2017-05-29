//4 no
#include <bits/stdc++.h>
using namespace std;

int MaxVal = 100005, tree[100010];

bool cmp(int x, int y) {
	return x > y;
}

int read(int idx) {
	int sum = 0;
	while(idx > 0) {
		sum += tree[idx];
		idx -= (idx & -idx);
	}
	return sum;
}

void update(int idx, int val) {
	while(idx <= MaxVal) {
		tree[idx] += val;
		idx += (idx & -idx);
	}
}

int main() {
	//freopen("in", "r", stdin);
	//freopen("out", "w", stdout);
	int t, n, q, x;
	scanf("%d", &t);
	while(t--) {
		scanf("%d %d", &n, &q);
		vector<int>V;
		//map<int, int>mp;
		while(n--) {
			scanf(" %d", &x);
			V.push_back(x);
		}
		sort(V.begin(), V.end(), cmp);
		//printf("sorteed\n");
		memset(tree, 0, sizeof tree);
		bool first = 1;
		int past = -1;
		for(int i = V.size()-1; i >= 0; --i) {
			if(!first) {
				if(past > V[i]) {
					++past;
					update(100005 - past, 1);
					//I think i have to do something in this point
					/*if(abs(past-V[i]) > 1) {
						update(100005 - past - 1, -1);
						update(100005 - V[i], 1);
					}*/
					//printf("entered in size %d\n", past);
					V[i] = past;
				}
				else
					update(100005 - (++V[i]), 1);
				//printf("update on %d\n", 100005 - (V[i] + 1));
				past = V[i];
			}
			else {
				update(100005 - V[i], 1);
				//printf("*update on %d\n", 100005 - V[i]);
				first = 0;
			}
		}
		//printf("V[0] = %d\n", V[0]);
		while(q--) {
			scanf("%d", &x);
			if(x <= V[0]) {
				//printf("x is %d\n", x);
				printf("%d\n", read(100005-x));
			}
			else
				printf("0\n");
		}
		V.clear();
	}
	return 0;
}

/*Test case :
5
5 2
21 9 5 8 10
10
15
5 1
1 2 3 4 5
100
4 4
1 1 1 1
4
3
2
1
4 4
1 2 1 1
4
3
2		//This one gives Wrong Ans
1
4 4
1 2 3 1
4
3
2
1
*/
