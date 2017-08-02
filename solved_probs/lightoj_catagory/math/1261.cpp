// LightOJ
// 1261 - K-SAT Problem
// SubSet Problem

// In this problem there are two sets for every person take an element or not to take an element
// we get the positions and bitmask it for each person
// for the query (query says to take only) we make another bitmask of taken element
// now test if the new bitmask is a subset of one persons take list or the left element(off bits in bitset) is subset of the not to take bitmask
// if it is a valid subset of any of the two above (for every person ofcourse!)
// then this solution is correct

#include <bits/stdc++.h>
#define SET(x, i)  x |= (1<<i)

using namespace std;

int take[35], not_take[35];


// A useful function to debug
void bitprint(int x) {
	
	for(int i = 10; i >= 0; --i)
		printf("%d", (x & (1<<i)) >= 1 ? 1 : 0);
		
	printf("\n");
}

int main() {	
	//freopen("in", "r", stdin);
	//freopen("out", "w", stdout);
	
	int t, n, m, k, x;
	
	scanf("%d", &t);
	
	for(int Case = 1; Case <= t; ++Case) {
		memset(take, 0, sizeof(take));
		memset(not_take, 0, sizeof(take));
		
		scanf("%d%d%d", &n, &m, &k);
		
		for(int i = 0; i < n; ++i) {
			for(int j = 0; j < k; ++j) {
				scanf("%d", &x);
				if(x < 0) {
					x *= -1;
					SET(not_take[i], --x);
				}
				else
					SET(take[i], --x);
			}
			//printf("%d : \n", i);
			//bitprint(take[i]);
			//bitprint(not_take[i]);
		}
		
		scanf("%d", &k);
		int tmpTake = 0;
		for(int i = 0; i < k; ++i) {
			scanf("%d", &x);
			SET(tmpTake, --x);
		}
		
		
		
		bool yes = 1;
		for(int i = 0; i < n && yes; ++i) {
			if(((tmpTake & take[i]) == 0) && (not_take[i] & (~tmpTake)) == 0) {
				/*printf("on %d\n", i);
				bitprint(tmpTake);
				bitprint(take[i]);
				bitprint(not_take[i]);
				bitprint((~tmpTake));*/
				yes = 0;
			}
		}
		
		printf("Case %d: ", Case);
		
		if(yes)
			printf("Yes\n");
			
		else
			printf("No\n");
		
	}
	
	
	return 0;
}
