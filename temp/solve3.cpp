#include <bits/stdc++.h>
using namespace std;

vector<int>Set[100002];
bitset<100002>isPresent;

int UpperBound(int lo, int hi, int key, int x) {               // Returns lowest position where v[i] > key
    int mid, ans = -1;                               // 10 10 10 20 20 20 30 30
    while(lo <= hi) {                               //                   ^
        mid = (lo + hi)>>1;
        if(key >= Set[x][mid]) {
            ans = mid;
            lo = mid + 1;
        }
        else
            hi = mid - 1;
    }
    return ans;                               // Tweaking this line will return the last position of key
}

int main() {
    freopen("in", "r", stdin);
    
    int n, t, x, q, l, r, pos;
    scanf("%d", &t);
    
    for(int Case = 1; Case <= t; ++Case) {
        scanf("%d %d", &n, &q);
        isPresent.reset();
        for(int i = 1; i <= n; ++i) {
            scanf("%d", &x);
            Set[x].push_back(i);
            isPresent[x] = 1;
        }
    
        while(q--) {
            pos = -1;
            scanf("%d %d %d", &l, &r, &x);
            if(isPresent[x])
            pos = UpperBound(0, (int)Set[x].size()-1, r, x);
            while(pos > 0 && pos < (int)Set[x].size() && Set[x][pos] > r) pos--;
            cout << "pos " << pos  << "  " << Set[x][pos]<< endl;
            if(pos > l)
                printf("%d\n", Set[x][pos]);
            else
                printf("-1\n");
        }
        
        for(int i = 0; i <= 100000; ++i)
            Set[i].clear();
    }
        
    return 0;
}