// LightOJ
// 1087 - Diablo
// Binary Indexed Tree

// Use BIT to determine new position of the army
// add 1 in every position in BIT
// len contains the length of the army
// increase len if new group added
// if a group is deleted, update the index with -1
// tree contains the cumulative frequency of BIT which indecates the index of army
// ex : tree[12] = 6, means the 6'th army data is in val[12]

#include <bits/stdc++.h>
using namespace std;

int MaxVal, tree[200010], val[200010], highBitMaxVal;

void setHighBit() {
	highBitMaxVal = MaxVal;
	while(1) {
		if(highBitMaxVal - (highBitMaxVal & -highBitMaxVal) > 0)
			highBitMaxVal -= (highBitMaxVal & -highBitMaxVal);
		else
			break;
	}
} 

void update(int idx, int val) {
	while(idx <= MaxVal) {
		tree[idx] += val;
		idx += (idx & -idx);
	}
}

int read(int idx) {
	int sum = 0;
	while(idx > 0) {
		sum += tree[idx];
		idx -= (idx & -idx);
	}
	return sum;
}


int binarySearch(int cSum) {					// Binary search for the cumulative sum
	int idx = 0, tIdx;							// Returns the greater index if value is present more than once
	int bitmask = highBitMaxVal;
	
	while(bitmask != 0 && idx < MaxVal) {
		tIdx = idx + bitmask;
		if(cSum == tree[tIdx])
			return tIdx;
		if(cSum > tree[tIdx]) {
			idx = tIdx;
			cSum -= tree[tIdx];
		}
		//printf("CumFre : %d idx : %d tree : %lld,  %d, %d\n", cSum, idx, tree[idx], bitmask, tdx);
		bitmask >>= 1;
	}
	if(cSum != 0) 
		return -1;
	else
		return idx;
}

int minVal(int cSum) {							// Helper function of binarySearch
	int pos = binarySearch(cSum);				// Returns the smallest index of cumulative sum if value is present more than once
	if(pos == -1)
		return pos;
	while(pos && val[pos] == -1) --pos;
	return pos;
}


int main() {
	//freopen("in", "r", stdin);
	//freopen("out", "w", stdout);
	
	int t, x, len, q;
	char c;
	scanf("%d", &t);
	for(int Case = 1; Case <= t; ++Case) {
		scanf("%d %d", &len, &q);
		MaxVal = len + q;
		setHighBit();
		memset(tree, 0, sizeof(tree));
		memset(val, -1, sizeof(val));
		printf("Case %d:\n", Case);
		
		for(int i = 1; i <= len; ++i) {
			scanf("%d", &x);
			val[i] = x;
			update(i, 1);
		}
		
		while(q--) {
			scanf(" %c", &c);
			if(c == 'a') {
				scanf("%d", &x);
				val[++len] = x;
				update(len, 1);
			}
			else {
				scanf("%d", &x);
				int pos = minVal(x);
				if(pos == -1)
					printf("none\n");
				else {
					printf("%d\n", val[pos]);
					val[pos] = -1;
					update(pos, -1);
				}
			}
		}
	}
	return 0;
}
