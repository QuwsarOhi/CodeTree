#include <bits/stdc++.h>
using namespace std;

struct histogram{
	int a, l, r;
	histogram operator < (histogram o) {
		return (a < o.a);
}

int arr[100000];
int tree[400000];

int segment_init(int pos, int L, int R) {
	if(L == R) {
		printf("at %d : %d\n", L, arr[L-1]);
		return tree[pos].a = arr[L-1];
	}
	
	int mid = (L+R)/2;
	
	int l = segment_init(pos*2, L, mid);
	int r = segment_init(pos*2 + 1, mid+1, R);
	
	tree[pos].a = min(l, r);
	printf("at %d - %d : %d\n", L, R, tree[pos]);
	
	return tree[pos];
}

int query(int pos, int L, int R) {
	if(L == R){
		tree[pos].l = tree[pos].r = L;
		return tree[pos];
	}
	int mid = (L+R)/2;
	
	histogram l = query(pos*2, L, mid);
	histogram r = query(pos*2 + 1, mid+1, R);
	histogram mx;
	
	if(l < r)
		mx = r;
	else
		mx = l;
	
	if(l.r >= r.l) {	// if it is possible to combine left histogram and right histogram
		
	
	printf("at %d - %d : %d, %d\n", L, R, l, r);
	
	tree[pos] = max(l, r);
	return tree[pos];
}

int main() {
	freopen("in", "r", stdin);
	//freopen("out", "w", stdout);
	
	int t;
	scanf("%d", &t);
	for(int Case = 1; Case <= t; Case++) {
		int n;
		scanf("%d", &n);
		for(int j = 0; j < n; j++) {
			scanf("%d", &arr[j]);
		}
		segment_init(1, 1, n);
		printf("Segment iniit done\n");
		printf("Case %d: %d\n", Case, query(1, 1, n));
	}
}

