// SubsetSum

#include <bits/stdc++.h>
using namespace std;

// SubSetSum : Complexity O(element * maxSum)

bool isSubsetSum(int set[], int n, int sum) {       // ifSubSetSum(value_array, num_of_values, sum) == 1, sum exists
    bool subset[n+1][sum+1];
  
    for (int i = 0; i <= n; i++)                    // If sum is 0, then answer is true
      subset[i][0] = true;
  
    for (int i = 1; i <= sum; i++)                  // If sum is not 0 and set is empty, then answer is false
      subset[0][i] = false;
  
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= sum; j++) {
            if(j < set[i-1])
                subset[i][j] = subset[i-1][j];
            if (j >= set[i-1])
                subset[i][j] = subset[i-1][j] || subset[i - 1][j-set[i-1]];
       }
    
    /*for(int i = 0; i <= n; i++) {                //uncomment this code to print table
        for (int j = 0; j <= sum; j++)
            printf ("%4d", subset[i][j]);
        printf("\n");
     }*/
  
     return subset[n][sum];
}


// SubSetSum : Complexity O(element * maxSum)

bool isSubsetSum(int set[], int pos, int sum) {
    if(sum == 0)                   // Base Cases
        return 1;
    if(pos == 0 && sum != 0)
        return 0;
    
    //add dp state dp[n][sum]
    
    if(set[pos-1] > sum)           // if the value is greater than sum ignore it
        return isSubsetSum(set, pos-1, sum);

    return isSubsetSum(set, pos-1, sum) || isSubsetSum(set, pos-1, sum-set[pos-1]);        // ignore this element, include this element
}



int main() {

    // Solution in bitmask with DP Complexity: O(2^n)
    // Without dp the complexity was O(n * 2^n)
    sum[0] = 0;
    // num[i] contains the values
    for (int i = 0; i < n; i++) {
        for(int mask = (1<<i); mask < (1 << (i+1)); ++mask) {
            sum[mask] = sum[mask ^ (1<<i)] + num[i];
            // Update answer, one part is
            // sum[mask], another total-sum[mask]
        }
    }
    return 0;
}
