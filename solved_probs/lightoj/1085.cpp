// LightOJ
// 1085 - All Possible Increasing Subsequences
// BIT, Sortring & Indexing

# include <bits/stdc++.h>
# define MOD 1000000007
using namespace std;

long long tree[100010];
int MaxVal, val[100010], sortedVal[100010];

long long read(int idx) {				// Cumulative Frequency in idx
	long long sum = 0;
	while(idx > 0) {
		sum += tree[idx];
		if(sum >= MOD)
			sum %= MOD;
		idx -= (idx & -idx);
	}
	return sum%MOD;
}

void update(int idx, long long val) {	// Add frequency in idx
	while(idx <= MaxVal) {
		tree[idx] += val;
		if(tree[idx] >= MOD)
			tree[idx] %= MOD;
		idx += (idx & -idx);
	}
}


int main() {
	//freopen("in", "r", stdin);
	
	int t;
	scanf("%d", &t);
	map<int, int>Index;
	for(int Case = 1; Case <= t; ++Case) {
		scanf("%d", &MaxVal);
		Index.clear();
		memset(tree, 0, sizeof(tree));
		for(int i = 1; i <= MaxVal; ++i) {
			scanf("%d", &val[i]);
			sortedVal[i] = val[i];
		}
	
		int indxCnt = 0;
			
		sort(sortedVal+1, sortedVal+MaxVal+1);
		
		for(int i = 1; i <= MaxVal; ++i) {
			if(Index.find(sortedVal[i]) == Index.end())
				Index[sortedVal[i]] = ++indxCnt;
		}
		
		long long idx, subSequence;
		for(int i = 1; i <= MaxVal; ++i) {
			idx = Index[val[i]];
			subSequence = read(idx-1) + 1;
			//printf("%d %lld %lld\n", val[i], subSequence, idx);
			update(idx, subSequence);
		}
		
		printf("Case %d: %lld\n", Case, read(Index[sortedVal[MaxVal]]));
	}
	return 0;
}
