// LightOJ
// 1097 - Lucky Number
// Binary Indexed Tree / Segment Tree / Binary Search Tree
// Large deletation

#include <bits/stdc++.h>
#define MAX 1429431
using namespace std;

vector<int>v;
int tree[1500000], MaxVal = MAX, highBitMaxVal;


void setHighBit() {
	highBitMaxVal = MaxVal;
	while(1) {
		if(highBitMaxVal - (highBitMaxVal & -highBitMaxVal) > 0)
			highBitMaxVal -= (highBitMaxVal & -highBitMaxVal);
		else
			break;
	}
} 

int read(int idx){
    int sum = 0;
    while (idx > 0){
        sum += tree[idx];
        idx -= (idx & -idx);
    }
    return sum;
}

int readSingle(int idx){
	int sum = tree[idx]; 			// sum will be decreased
	if (idx > 0){ 					// special case
		int z = idx - (idx & -idx); // make z first
		idx--; 						// idx is no important any more, so instead y, you can use idx
		while (idx != z) { 			// at some iteration idx (y) will become z
			sum -= tree[idx]; 		// substruct tree frequency which is between y and "the same path"
			idx -= (idx & -idx);
		}
	}
	return sum;
}

int BITsize() {
	return read(MaxVal);
}

int binarySearch(int k) {
	int low = 0, high = MaxVal, mid;
	while(high - low > 1) {
		mid = (low + high) >> 1;
		if(read(mid) >= k) 
			high = mid;
		else
			low = mid;
	}
	return high;
}

void update(int idx, int val) {
	while(idx <= MaxVal) {
		tree[idx] += val;
		idx += (idx & -idx);
	}
}


void build() {
	int lim;
	for(int i = 1; i <= MaxVal; ++i) {						// Adding all numbers in BIT
		update(i, 1);
	for(int i = 2; i <= BITsize(); i+=2)					// Marking all even numbers
		v.push_back(i);
	for(int i = 0; i < (int)v.size(); ++i)					// Deleting all even numbers
		update(v[i], -1);
	for(int i = 2; i <= (lim = BITsize()); ++i) {			// Starting from 2nd index
		v.clear();
		int pos = binarySearch(i);
		if(pos > lim)
			break;
		for(int j = pos; j <= lim; j += pos)		 		// Marking 
			v.push_back(binarySearch(j));
		for(int j = 0; j < (int)v.size(); ++j)				// Deleting
			update(v[j], -1);
	}
}


int main() {
	//freopen("in", "r", stdin);
	//freopen("out", "w", stdout);
	int t, x;
	memset(tree, 0, sizeof(tree));
	build();
	scanf("%d", &t);
	for(int Case = 1; Case <= t; ++Case) {
		scanf("%d", &x);
		printf("Case %d: %d\n", Case, binarySearch(x));
	}
	return 0;
}
