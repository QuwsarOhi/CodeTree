// Longest Increasing/Decrasing Sequence
// Complexity : nLog_n

// -----------------------Non Printable Version--------------------

int main() {
    // vector v contains the sequence
    for(auto it : v) {                                          // Use -it for decrasing sequences
        auto pIT = upper_bound(LIS.begin(), LIS.end(), it);     // Longest Non-Decreasing Sequence
        if(pIT == LIS.end())                                    // For Longest Increasing Sequence use lower_bound
            LIS.push_back(it);
        else
            *pIT = it;
    }
    return 0;
}

// -------------------------Printable Version------------------------
// DP + BinarySearch (nLog_n)
// {1, 1, 9, 3, 8, 11, 4, 5, 6, 6, 4, 19, 7, 1, 7}
// Incrasing     : 1, 3, 4, 5, 6, 7
// NonDecreasing : 1, 1, 3, 4, 5, 6, 6, 7, 7

void findLIS(vector<int> &v, vector<int> &idx) {    // v is the input values and idx vector contains index of the LIS values
    if(v.empty()) return;
    vector<int> dp(v.size());               // The memoization part, remembers what index is the previous index if any value is inserted or modified
	idx.push_back(0);                       // Carrys index of values
    int l, r;
    
	for(int i = 1; i < (int)v.size(); i++) {
		if(v[idx.back()] <= v[i]) {         // **Replace < with <= if non-decreasing subsequence required
			dp[i] = idx.back();             // If next element v[i] is greater than last element of
			idx.push_back(i);               // current longest subsequence v[idx.back()], just push it at back of "idx" and continue
			continue;
		}
        // Binary search to find the smallest element referenced by idx which is just bigger than v[i] (UpperBound(v[i]))
        // Note : Binary search is performed on idx (and not v)
		for(l = 0, r = idx.size()-1; l < r; ) {
			int mid = (l+r)/2;
			if(v[idx[mid]] <= v[i])  l = mid+1;      // **Replace < with <= if non-decreasing subsequence required
            else                    r = mid;
		}
		if(v[i] < v[idx[l]]) {                      // Update idx if new value is smaller then previously referenced value
            if(l > 0) dp[i] = idx[l-1];
			idx[l] = i;
		}
    }
	for(l = idx.size(), r = idx.back(); l--; r = dp[r])
        idx[l] = r;
}
