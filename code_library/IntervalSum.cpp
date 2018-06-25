// Interval Sum
// Complexity: query*log(query)
// http://codeforces.com/contest/915/problem/E

struct Interval { 
    set<pair<ll, ll> >Set;                      // Contains Segment Endpoints {r, l}
    map<pair<ll, ll>, ll>Val;                   // Contains Segment Values    {l, r} = k
    int TOTlen;                                 // Contains Total Segment Covered Length
    
    void init(int sz = -1) {
        Set.clear(), Val.clear(), TOTlen = 0;
        if(sz > 0)                              // Will be initialized if size declared (NOT needed)
            Set.insert(make_pair(sz, 1)), Val[make_pair(1, sz)] = 0;
    }
    
    void Insert(ll l, ll r, ll val) {
        set<pair<ll, ll> > :: iterator it = Set.lower_bound(make_pair(l, 0LL));
        while(it != Set.end() && it->second <= r) {
            ll segL = it->second, segR = it->first;             // Overlapped segment
            Set.erase(it++);                                    // Erase and point to the next segment
            ll L = max(segL, l), R = min(segR, r);              // Erased segment's partial L and R
            TOTlen -= R-L+1;
            if(segL < l) {
                Set.insert({l-1, segL});
                Val[make_pair(segL, l-1)] = Val[make_pair(segL, segR)];
            }              
            if(segR > r) {
                Set.insert({segR, r+1});
                Val[make_pair(r+1, segR)] = Val[make_pair(segL, segR)];
            }
            Val.erase(make_pair(segL, segR));
        }
        TOTlen += r-l+1;
        Set.insert(make_pair(r, l));
        Val[make_pair(l, r)] = val;
    }
    
    ll getSum(ll l, ll r) {
        ll sum = 0;
        set<pair<ll, ll> > :: iterator it = Set.lower_bound(make_pair(l, 0LL));
        while(it != Set.end() && it->second <= r) {
            ll segL = it->second, segR = it->first;                 // Overlapped segment
            ll V = Val[make_pair(segL, segR)];
            sum += (segR-segL+1) * V;
            if(segL < l) sum -= (l-segL)*V;
            if(segR > r) sum -= (segR-r)*V;
            ++it;
        }
        return sum;
}};
