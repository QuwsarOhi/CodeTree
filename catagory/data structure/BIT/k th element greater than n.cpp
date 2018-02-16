// HackerRank
// Kth Number
// https://www.hackerrank.com/contests/morgan-stanley-2015/challenges/wet-shark-and-kth-largest-number

#include <bits/stdc++.h>
using namespace std;


struct node {
    int l, val, isQuery;
    
    node(int l, int val, int isQuery) {
        this->l = l;
        this->val = val;
        this->isQuery = isQuery;
    }
};


int tree[100010], val[100010], ans[100010], MaxVal = 100005;
vector<node>v;

bool cmp(node a, node b) {
    if(a.val != b.val)
        return a.val > b.val;
    else
        return a.isQuery < b.isQuery;
}

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

// Complexity : (logN)^2
int binarySearch(int lo, int hi, int cSum) {		// Returns the greater index if value is present more than once
	int pos = -1, mid;								// More trustworthy
	while(lo <= hi) {
		mid = (lo+hi)/2;
		if(read(mid) >= cSum) {
			pos = mid;
			hi = mid-1;
		}
		else
			lo = mid+1;
	}
	return pos;
}

void test(int n) {
    for(int i = 1; i <= n; ++i)
        cout << readSingle(i) << " ";
    cout << endl;
}

int main() {
    int n, q, l, k;
    
    scanf("%d%d", &n, &q);
    
    for(int i = 1; i <= n; ++i) {
        scanf("%d", &val[i]);
        v.push_back({i, val[i], 0});
    }
    
    for(int i = 1; i <= q; ++i) {
        scanf("%d%d", &l, &k);
        v.push_back({k, l, i});     // l, val, query
    }
    
    sort(v.begin(), v.end(), cmp);
    
    for(auto it : v) {
        if(!it.isQuery)
            update(it.l, 1);
        else 
            ans[it.isQuery] = val[binarySearch(1, n, it.l)];
    }
    
    for(int i = 1; i <= q; ++i)
        printf("%d\n", ans[i]);
    
    return 0;
}
