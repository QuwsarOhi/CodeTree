// Codeforces
// http://codeforces.com/contest/762/problem/E

// E. Radio stations

// Range Search

#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>    // rb_tree_tag
#include <ext/pb_ds/tree_policy.hpp>        // tree_order_statistics_node_update

using namespace std;
using namespace __gnu_pbds;


template<class T> using ordered_set = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

struct station {
    int x, r, f;
};

bool cmp(station a, station b) {
    return a.r > b.r;
}

ordered_set<int> SET[100100];
vector<station>st;

int main() {
    int n, k, x, r, f;
    cin >> n >> k;
    
    for(int i = 0; i < n; ++i) {
        cin >> x >> r >> f;
        st.push_back({x, r, f});
    }
    
    sort(st.begin(), st.end(), cmp);            // min(ri, rj) >= |xi - xj|
    
    // for every position i, it's sure that this ri is less than all previous r
    // so we'r sorting increasing order
    
    long long ans = 0;
    for(auto stat : st) {
        //cout << stat.x << " " << stat.r << " " << stat.f << endl;
        for(int freq = max(stat.f-k, 1); freq <= stat.f+k; ++freq) {
            ans += SET[freq].order_of_key(stat.x+stat.r+1) - SET[freq].order_of_key(stat.x-stat.r);
            //for(int i = SET[freq].order_of_key(stat.x-stat.r); i < (int)SET[freq].order_of_key(stat.x+stat.r); ++i)
            //    cout << "freq " << freq << " " << *SET[freq].find_by_order(i) << " for " << stat.r << endl;
            //cout << "ANS " << ans << endl;
        }
        SET[stat.f].insert(stat.x);         // As pair (i, j) == pair (j, i), we add every station after searching it, this way will eliminate same pairs
    }
    
    cout << ans << endl;
    return 0;
}
