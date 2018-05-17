int palindrom(int l, int r) {       // Find size of longest palindrome
    if(dp[l][r] != -1)
        return dp[l][r];
    else if(l == r)                 //if the middle point reached (odd length of a string)
        return dp[l][r] = 1;
    else if(l+1 == r) {             //if the two points are middle (even length of a string)
        if(S[l] == S[r])
            return dp[l][r] = 2;    //if matches, we can take them both
        else
            return dp[l][r] = 1;    //else we can take only one of them
    }
    else {
        if(S[l] == S[r])            //if the first and the last character is matched, then we can take them both and go deeper
            dp[l][r] = 2 + palindrom(l+1, r-1);
        else                        //else we will search for the best choice
            dp[l][r] = max(palindrom(l+1, r), palindrom(l, r-1));
    }
    return dp[l][r];
}

int recur(int p1, int p2) {         // make string s1 like s2, in minimum move
    if(dp[p1][p2] != INF)
        return dp[p1][p2];
    if(p1 == l1 or p2 == l2) {
        if(p1 < l1) return dp[p1][p2] = recur(p1+1, p2)+1;
        if(p2 < l2) return dp[p1][p2] = recur(p1, p2+1)+1;
        return dp[p1][p2] = 0;
    }
    if(s1[p1] == s2[p2])            // match found
        return dp[p1][p2] = recur(p1+1, p2+1);
    // change at position p1, delete position p1, insert at position p1
    return dp[p1][p2] = min(recur(p1+1, p2+1), min(recur(p1+1, p2), recur(p1, p2+1)))+1;    
}
