// Binary Search
// Complexity : O(n Log n)

ll UpperBound(ll lo, ll hi, ll key) {               // Returns lowest position where v[i] > key
    ll mid, ans = -1;                               // 10 10 10 20 20 20 30 30
    while(lo <= hi) {                               //                   ^
        mid = (lo + hi)>>1;
        if(key >= v[mid])   ans = mid, lo = mid + 1;
        else                hi = mid - 1;
    }
    return ans+1;                               // Tweaking this line will return the last position of key
}

ll LowerBound(ll lo, ll hi, ll key) {           // Returns lowest position where v[i] == key (if value is present more than once)
    ll mid, ans = -1;                           // 10 10 10 20 20 20 30 30
    while(lo <= hi) {                           //          ^
        mid = (lo+hi)>>1;
        if(key <= v[mid])   ans = mid, hi = mid - 1;
        else                lo = mid + 1;
    }
    return ans;
}

// lo : lower value, hi : upper value, est : estimated output of the required result, delta : number of iteration in search
double bisection(double lo, double hi, double est, int delta) {
    double mid, ans = -1;
    for(int i = 0; i < delta; ++i) {
        mid = (lo+hi)/2.0;
        if(Equal(TestFunction(mid), est))           ans = mid, lo = mid;
        else if(Greater(TestFunction(mid), est))    hi = mid;
        else                                        lo = mid;
    }
    return ans;
}

// Full Functional Ternary Search
/* EMAXX ::
If f(x) takes integer parameter, the interval [l r] becomes discrete.
Since we did not impose any restrictions on the choice of points m1 and m2, the correctness of the algorithm is not affected. 
m1 and m2 can still be chosen to divide [l r] into 3 approximately equal parts.

The difference occurs in the stopping criterion of the algorithm. 
Ternary search will have to stop when (r−l) < 3, because in that case we can no longer select m1 and m2 to 
be different from each other as well as from ll and rr, and this can cause infinite iterating. 
Once (r−l) < 3, the remaining pool of candidate points (l,l+1,…,r) needs to be checked 
to find the point which produces the maximum value f(x).
*/

ll ternarySearch(ll low, ll high) {
    ll ret = -INF;
    while((high - low) > 2) {
        ll mid1 = low + (high - low) / 3;
        ll mid2 = high - (high - low) / 3;
        ll cost1 = f(mid1);
        ll cost2 = f(mid2);
        if(cost1 < cost2) {
            low = mid1;
            ret = max(cost2, ret);
        }
        else {
            high = mid2;
            ret = max(cost1, ret);
    }}
    for(int i = low; i <= high; ++i)
        ret = max(ret, f(i));
    return ret;
}
