// LightOJ
// 1112 - Curious Robin Hood
// Binary Indexed Tree

#include <bits/stdc++.h>
using namespace std;

long long tree[100010];
int MaxVal;

void update(int idx, int val) {
	while(idx <= MaxVal) {
		tree[idx] += val;
		idx += (idx & -idx);
	}
}

long long read(int idx) {
	long long sum = 0;
	while(idx > 0) {
		sum += tree[idx];
		idx -= (idx & -idx);
	}
	return sum;
}

long long readSingle(int idx) {
	long long sum = tree[idx];
	if(idx > 0) {
		int z = idx - (idx & -idx);
		--idx;
		while(idx != z) {
			sum -= tree[idx];
			idx -= (idx & -idx);
		}
	}
	return sum;
}


int main() {
	//freopen("in", "r", stdin);
	//freopen("out", "w", stdout);
	
	int t, q, idx, idx2, c;
	long long x;
	scanf("%d", &t);
	for(int Case = 1; Case <= t; ++Case) {
		scanf("%d %d", &MaxVal, &q);
		memset(tree, 0, sizeof(tree));
		
		for(int i = 1; i <= MaxVal; ++i) {
			scanf("%lld", &x);
			update(i, x);
		}
		printf("Case %d:\n", Case);
		while(q--) {	
			scanf("%d", &c);
			
			if(c == 1) {
				scanf("%d", &idx);
				x = readSingle(idx+1);
				update(idx+1, -x);
				printf("%lld\n", x);
			}
			else if(c == 2) {
				scanf("%d %lld", &idx, &x);
				update(idx+1, x);
			}
			else {
				scanf("%d %d", &idx, &idx2);
				x = read(idx2+1);
				x -= read(idx);
				printf("%lld\n", x);
			}
		}
	}
	return 0;
}
