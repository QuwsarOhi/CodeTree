// Cut The Rope
// https://toph.co/p/cut-the-rope

#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define sf  scanf
#define pf  printf

using namespace std;
using namespace __gnu_pbds;

template<class T> using ordered_set = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

ordered_set<long long> sortedVal;
multiset<long long>Scale;


int main() {
    int t, q;
    long long x, n;
    char ch;
    sf("%d", &t);
    
    for(int Case = 1; Case <= t; ++Case) {
        pf("Case %d:\n", Case);
        sf("%lld %d", &n, &q);
        
        sortedVal.insert(n);
        Scale.insert(0), Scale.insert(n);
        
        while(q--) {
            sf(" %c %lld", &ch, &x);
            
            if(ch == 'C') {
                auto hi = Scale.upper_bound(x);
                auto low = hi;
                low--;
                auto pos = sortedVal.order_of_key(*hi-*low);
                sortedVal.erase(sortedVal.find_by_order(pos));
                
                sortedVal.insert(x-*low);
                sortedVal.insert(*hi-x);
                Scale.insert(x);
            }
            else
                pf("%lld\n", *sortedVal.find_by_order(x-1));
        }
        
        Scale.clear();
        sortedVal.clear();
    }
        
    return 0;
}
