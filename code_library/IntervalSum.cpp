// Interval Sum
// Complexity: query*log(query)
// http://codeforces.com/contest/915/problem/E

int main() {
    ll lim, q, l, r, k, sum = 0;
    set<pll>Set;
    sf("%lld %lld", &lim, &q);
    while(q--) {
        sf("%lld %lld %lld", &l, &r, &k);         // k is the set or remove segment command
        // first remove the overlapping segments;
        // set contains : r', l'
        // Search boundary : l, r
        // because we need to find l' and r' such that l <= r'
        // also checking l' <= r
        
        auto it = Set.lower_bound(make_pair(l, 0LL));
        while(it != Set.end() && it->second <= r) {
            ll segL = it->second;
            ll segR = it->first;
            it = Set.erase(it);                    // Erase and point to the next segment
            
            ll L = max(segL, l);
            ll R = min(segR, r);
            sum -= (R-L+1);
      
            if(segL < l)                          // l'----l-----r----r'  or  l'----l-----r'---r
                Set.insert({l-1, segL});
            if(segR > r)                          // l'----l-----r----r'  or  l----l'----r-----r'
                Set.insert({segR, r+1});
        }
        
        if(k == 1) {                // Insertion
            sum += (r-l+1);
            Set.insert({r, l});     // inserting r' as first pair element because lower_bound will return first l <= r'
        }
        pf("%lld\n", lim - sum);
    }
    return 0;
}
