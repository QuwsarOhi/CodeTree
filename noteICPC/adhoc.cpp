Ad-hoc:
 * Longest Increasing Sequence
 * 1D Max Sum
 * 2D Max Sum
 * Ternary Search
 * Merge Sort

/* -------------------------- Longest Increasing/Decrasing Sequence --------------------------
   Non-Printable Version, Complexity : nLog_n */
int LIS(vi v) {                                              // v is the input array
    for(auto it : v) {                                       // Use -it for decrasing sequences
        auto pIT = upper_bound(LIS.begin(), LIS.end(), it);  // Longest Non-Decreasing Sequence
        if(pIT == LIS.end())    LIS.push_back(it);           // For Longest Increasing Sequence 
        else                    *pIT = it;                   // use lower_bound
    } return 0;
}
/* -------------------------Printable Version------------------------
   DP + BinarySearch (nLog_n)    INPUT ARRAY : {1, 1, 9, 3, 8, 11, 4, 5, 6, 6, 4, 19, 7, 1, 7}
   Incrasing : 1, 3, 4, 5, 6, 7                   NonDecreasing : 1, 1, 3, 4, 5, 6, 6, 7, 7 */
void findLIS(vi &v, vi &idx) {          // v contains input values and idx contains 
    if(v.empty()) return;               // index of the LIS values
    vector<int> dp(v.size());           // The memoization part, remembers what index is the 
	idx.push_back(0);                   // previous index if any value is inserted or modified 
    int l, r;                           // Carrys index of values
	for(int i = 1; i < (int)v.size(); i++) {
		if(v[idx.back()] <= v[i]) {         // Replace < with <= for non-decreasing subsequence
			dp[i] = idx.back(), idx.push_back(i);
			continue;                             // Binary search is done on idx (not in v)
		} for(l = 0, r = idx.size()-1; l < r; ) { // Binary search to find the smallest element 
			int mid = (l+r)/2;                    // referenced by idx which is just bigger
			if(v[idx[mid]] <= v[i])  l = mid+1;   // than v[i] (UpperBound(v[i]))
            else                    r = mid;      // replace <= with < if non-decreasing needed
		} if(v[i] < v[idx[l]]) {                  // Update idx if new value is smaller then 
            if(l > 0) dp[i] = idx[l-1];           // previously referenced value
			idx[l] = i;
	}} for(l = idx.size(), r = idx.back(); l--; r = dp[r])
        idx[l] = r;
}
/* --------------------------------------- 1D Max Sum ---------------------------------------
   Algorithm : Jay Kadane, Complexity : O(n) */
int maxSum1D(int A[], int len) {
    int sum = 0, ans = 0;
    for(int i = 0; i < len; i++) {
        sum += A[i];
        ans = max(sum, ans);                        // Always take the larger sum
        sum = max(sum, 0);                          // if sum is negative, reset it (greedy)
    } return ans;
}
/* --------------------------------------- 2D Max Sum ---------------------------------------
   Algorithm : DP, Inclusion Exclusion, Complexity : O(n^4) */
int maxSum2D(int A[][100], int n) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            scanf("%d", &A[i][j]);
            if(i > 0) A[i][j] += A[i-1][j];                     // Take from right
            if(j > 0) A[i][j] += A[i][j-1];                     // Take from left
            if(i > 0 && j > 0) A[i][j] -= A[i-1][j-1];          // Inclusion exclusion
    }} int maxSubRect = -1e7;
    for(int i = 0; i < n; i++) {                  // i & j are the start coordinate of sub-rect
        for(int j = 0; j < n; j++) {
            for(int k = i; k < n; k++) {         // k & l are the finish coordinate of sub-rect
                for(int l = j; l < n; l++) {
                    int subRect = A[k][l];
                    if(i > 0) subRect -= A[i-1][l];
                    if(j > 0) subRect -= A[k][j-1];
                    if(i > 0 && j > 0) subRect += A[i-1][j-1];           // Inclusion exclusion
                    maxSubRect = max(subRect, maxSubRect);
    }}}} return maxSubRect;
}
/* -------------------------------------- Ternary Search --------------------------------------
EMAXX : If f(x) takes integer parameter, the interval [l r] becomes discrete. Since we did not
impose any restrictions on the choice of points m1 and m2, the correctness of the algorithm is
not affected.  m1 and m2 can still be chosen to divide [l r] into 3 approximately equal parts.
The difference occurs in the stopping criterion of the algorithm.  Ternary search will have to 
stop when (r−l) < 3, because in that case we can no longer select m1 and m2 to be different 
from each other as well as from ll and rr, and this can cause infinite iterating. Once 
(r−l) < 3, the remaining pool of candidate points (l,l+1,…,r) needs to be checked to find the 
point which produces the maximum value f(x). */
ll ternarySearch(ll low, ll high) {
    ll ret = -INF;
    while((high - low) > 2) {
        ll mid1 = low + (high - low) / 3, mid2 = high - (high - low) / 3;
        ll cost1 = f(mid1), cost2 = f(mid2);
        if(cost1 < cost2)   { low = mid1, ret = max(cost2, ret); }
        else                { high = mid2, ret = max(cost1, ret);
    }} for(int i = low; i <= high; ++i)
        ret = max(ret, f(i));
    return ret;
}
/* ------------------------------------- Merge Sort -------------------------------------- */
void MergeSort(int arr[], int l, int mid, int r) {
    int lftArrSize = mid-l+1, rhtArrSize = r-mid, lftArr[lftArrSize+2], rhtArr[rhtArrSize+2];
    for(int i = l, j = 0; i <= mid; ++i, ++j)     lftArr[j] = arr[i];  
    for(int i = mid+1, j = 0; i <= r; ++i, ++j)   rhtArr[j] = arr[i];
    lftArr[lftArrSize] = rhtArr[rhtArrSize] = INF;                   // INF value in both array 
    int lPos = 0, rPos = 0;
    for(int i = l; i <= r; ++i) {
        if(lftArr[lPos] <= rhtArr[rPos]) arr[i] = lftArr[lPos++];
        else                             arr[i] = rhtArr[rPos++];
        //cnt += lftArrSize - lPos;                // Add in else if Min Number of Swaps needed
}} void Divide(int arr[], int l, int r) {                          // Call as Divide(v, 0, len)
    if(l == r || l > r) return;  
    int mid = (l+r)>>1;  
    Divide(arr, l, mid), Divide(arr, mid+1, r);  
    MergeSort(arr, l, mid, r);
}
