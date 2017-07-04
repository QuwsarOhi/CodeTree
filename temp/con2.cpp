#include <bits/stdc++.h>
 
// Binary search (note boundaries in the caller)
int CeilIndex(std::vector<int> &v, int l, int r, int key) {
    while (r-l > 1) {
		int m = l + (r-l)/2;
		if (v[m] >= key)
			r = m;
		else
			l = m;
    }
 
    return r;
}

int lowerBound(std::vector<int>&v, int low, int hi, int key) {				// Less than-equal to the key
	while(low < hi) {
		int m = (r+l)/2;
		if(v[m] >= key)
			hi = m;
		else
			low = m;
	}
	return hi;
}
 
void printer(std::vector<int> &x) {
	for(int i = 0; i < x.size(); ++i)
		printf("%d ", x[i]);
	printf("\n");
}

int LongestIncreasingSubsequenceLength(std::vector<int> &v) {
    if (v.size() == 0)
        return 0;
 
    std::vector<int> tail(v.size(), 0);
    int length = 1; // always points empty slot in tail
 
    tail[0] = v[0];
    for (size_t i = 1; i < v.size(); i++) {
		printf("val : %d\n", v[i]);
		printf("Before : \n");
		printer(tail);
        if (v[i] < tail[0]) {
            // new smallest value
            tail[0] = v[i];
		}
        else if (v[i] > tail[length-1]) {
            // v[i] extends largest subsequence
            tail[length++] = v[i];
		}
        else {
            // v[i] will become end candidate of an existing subsequence or
            // Throw away larger elements in all LIS, to make room for upcoming grater elements than v[i]
            // (and also, v[i] would have already appeared in one of LIS, identify the location and replace it)
            int x = CeilIndex(tail, 0, length-1, v[i]);
            int y = lowerBound(tail, 0, length-1, v[i]);
            printf("%d ---------------- %d -------------- %d\n", x, y);
            tail[CeilIndex(tail, 0, length-1, v[i])] = v[i];
		}
		printf("After : \n");
		printer(tail);
    }
    for(int i = 0; i < length; i++)
		std::cout << tail[i] << " ";
	std::cout << "\n";
    return length;
}
 
int main() {
    std::vector<int> v{0, 8, 4, 12, 2, 10, 6, 14, 1, 9, 5, 13, 3, 11, 7, 15};
    std::cout << "Length of Longest Increasing Subsequence is " << LongestIncreasingSubsequenceLength(v) << '\n';
   return 0;
}
