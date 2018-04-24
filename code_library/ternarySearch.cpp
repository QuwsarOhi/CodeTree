#include <bits/stdc++.h>
using namespace std;


// Might need 200 - 300 iterations
// Complexity : nLog_n

// EMAXX
// Finds the Highest peak
double ternary_search(double l, double r) {         // works on integer also
    double eps = 1e-9;                              // set the error limit here
    while (r - l > eps) {                           // if the answer set is not in double, then use r - l > 2 insted
        double m1 = l + (r - l) / 3;
        double m2 = r - (r - l) / 3;
        double f1 = f(m1);                          //evaluates the function at m1
        double f2 = f(m2);                          //evaluates the function at m2
        if (f1 < f2)
            l = m1;
        else
            r = m2;
    }
    return l;                                    //return the maximum of f(x) in [l, r]
}

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

// GeeksForGeeks
// Finds Minimum value (TESTED!)

ll ternarySearch(ll low, ll high) {             // low must be lowest possible value and hi must be heighest possible value (otherwise this may fall)
    while ((high - low) > 2) {
        // mid1 and mid2 are representative array
        // equal values of search space
        int mid1 = low + (high - low) / 3;
        int mid2 = high - (high - low) / 3;
 
        int cost1 = f(mid1);
        int cost2 = f(mid2);
 
        // if mid2 point gives more total cost,
        // skip third part
        if (cost1 < cost2)
            high = mid2;
 
        // if mid1 point gives more total cost,
        // skip first part
        else
            low = mid1;
    }
 
    // computeCost gets optimum cost by sending
    // average of low and high as X
    return f((low + high)/2);
}


// Full Functional Ternary Search

ll ternarySearch(ll low, ll high) {
    ll ret = -INF;
    
    while ((high - low) > 2) {
        ll mid1 = low + (high - low) / 3;
        ll mid2 = high - (high - low) / 3;
 
        ll cost1 = f(mid1);
        ll cost2 = f(mid2);
                
        if (cost1 < cost2) {
            low = mid1;
            ret = max(cost2, ret);
        }
        else {
            high = mid2;
            ret = max(cost1, ret);
        }
    }

    for(int i = low; i <= high; ++i)
        ret = max(ret, f(i));
    
    return ret;
}


int main() {
	return 0;
}
