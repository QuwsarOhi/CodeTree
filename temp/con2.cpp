#include <bits/stdc++.h>
using namespace std;

struct seg{
	int height, width, area, l, r;
};

seg tree[120010];
int arr[30010];

seg segment_init(int pos, int L, int R) {
	
	if(L == R) {
		//printf("on pos %d area : %d\n", L, arr[L-1]);
		tree[pos].height = arr[L-1];
		tree[pos].width = 1;
		tree[pos].area = arr[L-1];
		tree[pos].l = tree[pos].r = L;
		return tree[pos];
	}
	
	int mid = (L+R)/2, lim = 2;
	
	seg com[3];
	com[0] = segment_init(pos*2, L, mid);
	com[1] = segment_init(pos*2 + 1, mid+1, R);
	
	if(com[0].r >= com[1].l - 1) {
		lim++;
		com[2].height = min(com[0].height, com[1].height);
		com[2].width = com[0].width + com[1].width;
		com[2].area = com[2].height * com[2].width;
		com[2].l = com[0].l;
		com[2].r = com[1].r;
	}
	
	int max_pos = 0, max_a = 0, max_w=0;
	for(int i = 0; i < lim; i++) {
		if(com[i].area > max_a) {
			max_pos = i;
			max_a = com[i].area;
			max_w = com[i].width;
		}
		else if(com[i].area == max_a) {
			if(com[i].width > max_w) {
				max_pos = i;
				max_w = com[i].width;
				max_a = com[i].area;
			}
		} 
	}
	
	tree[pos].area = com[max_pos].area;
	tree[pos].height = com[max_pos].height;
	tree[pos].width = com[max_pos].width;
	tree[pos].l = com[max_pos].l;
	tree[pos].r = com[max_pos].r;
	
	//printf("segment %d - %d (%d - %d) : max area : %d max height : %d max width : %d\n", L, R, tree[pos].l, tree[pos].r, tree[pos].area, tree[pos].height, tree[pos].width);
	
	return tree[pos];
}

int main() {
	freopen("in", "r", stdin);
	freopen("out", "w", stdout);
	
	int t;
	scanf("%d", &t);
	for(int Case = 1; Case <= t; Case++) {
		int n;
		scanf("%d", &n);
		for(int j = 0; j < n; j++) {
			scanf("%d", &arr[j]);
		}
		segment_init(1, 1, n);
		printf("Case %d: %d\n", Case, tree[1].area);
	}
}
