//LightOJ
//1082 - Array Queries
//Segment Tree - Range Minimum Query

#include <bits/stdc++.h>
#define INF 1e6
using namespace std;

int arr[100010], tree[400010];

// Builds Segment Tree, Saves minimum value of [L, R] in tree[pos]
// segment_init(1, 1, arr_len)
int segment_init(int pos, int L, int R) {
    //printf("at %d %d\n", L, R);

    if(L == R) {
        tree[pos] = arr[L-1];
        return tree[pos];
    }

    int left_max, right_max;
    int mid = (L+R)/2;

    left_max = segment_init(pos*2, L, mid);
    right_max = segment_init(pos*2 + 1, mid+1, R);

    tree[pos] = min(left_max, right_max);

    return tree[pos];
}

// Query for minimum value in range [l, r]
// query(1, 1, arr_len, l, r)
int query(int pos, int L, int R, int l, int r) {
    if(l <= L && R <= r)    //if [L, R] is in [l, r]
        return tree[pos];

    if(R < l || r < L)      //if [L, R] not in [l, r]
        return INF;

    int left_max, right_max;
    int mid = (L+R)/2;

    left_max = query(pos*2, L, mid, l, r);
    right_max = query(pos*2 + 1, mid+1, R, l, r);

    return min(left_max, right_max);
}


int main() {
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);

    int t;
    scanf("%d", &t);
    for(int Case = 1; Case <= t; Case++) {
        int n, q;
        scanf("%d %d", &n, &q);
        printf("Case %d:\n", Case);
        for(int i = 0; i < n; i++)
            scanf(" %d ", &arr[i]);
        segment_init(1, 1, n);
        //printf("build done\n");
        while(q--) {
            int l, r;
            scanf("%d %d", &l, &r);
            printf("%d\n", query(1, 1, n, l, r));
        }
    }
    return 0;
}
