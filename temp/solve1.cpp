#include <bits/stdc++.h>
#define MAX 1000
using namespace std;
typedef long long ll;

ll tree[320][MAX];
int val[MAX], BlockSize, MaxVal;
int pre[320][320], suff[320][320];

void update(ll *tree, int idx, ll val, int MxVal) {
    for( ; idx <= MxVal; idx += idx & -idx)
        tree[idx] += val;
}


ll read(ll *tree, int idx) {
    ll sum = 0;
    for( ; idx >= 1; idx -= idx & -idx)
        sum += tree[idx];
    return sum;
}

ll readSingle(ll *tree, int idx) {             // Point read in log(n)
    ll sum = tree[idx];
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


void Build(int n) {
    BlockSize = sqrt(n)+1;
    for(register int i = 1; i <= n; ++i)
        update(tree[i/BlockSize], i%BlockSize+1, val[i], 200000);
}

void updateBlocks(int l, int r) {
    int p = l;
    while(l%BlockSize != 0 and l < r) {
        int updateIdx = val[i]+

int main() {
    return 0;
}
