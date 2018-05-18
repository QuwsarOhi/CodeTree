//-----------------------String DP-----------------------
int recur(int l, int r) {               // Building Palindrome in minimum move
    if(dp[l][r] != INF) return dp[l][r];
    if(l >= r)          return dp[l][r] = 0;
    if(l+1 == r)        return dp[l][r] = (s[l] != s[r]);
    if(s[l] == s[r])    return dp[l][r] = recur(l+1, r-1);
    return dp[l][r] = min(recur(l+1, r), recur(l, r-1))+1;      // Adding a alphabet on right, left
}

void dfs(int l, int r) {                // Palindrome printing, for above DP function
    if(l > r) return;
    if(s[l] == s[r]) {
        Palin.push_back(s[l]);
        dfs(l+1, r-1);
        if(l != r) Palin.push_back(s[l]);
        return;
    }
    int P = min(make_pair(dp[l+1][r], 1), make_pair(dp[l][r-1], 2)).second;
    if(P == 1) {
        Palin.push_back(s[l]);
        dfs(l+1, r);
        Palin.push_back(s[l]);
    }
    else {
        Palin.push_back(s[r]);
        dfs(l, r-1);
        Palin.push_back(s[r]);
}}

int recur(int p1, int p2) {         // make string s1 like s2, in minimum move
    if(dp[p1][p2] != INF)
        return dp[p1][p2];
    if(p1 == l1 or p2 == l2) {      // reached end of string s1 or s2
        if(p1 < l1) return dp[p1][p2] = recur(p1+1, p2)+1;
        if(p2 < l2) return dp[p1][p2] = recur(p1, p2+1)+1;
        return dp[p1][p2] = 0;
    }
    if(s1[p1] == s2[p2])            // match found
        return dp[p1][p2] = recur(p1+1, p2+1);
    // change at position p1, delete position p1, insert at position p1
    return dp[p1][p2] = min(recur(p1+1, p2+1), min(recur(p1+1, p2), recur(p1, p2+1)))+1;    
}

void dfs(int p1, int p2) {          // printing function for above dp
    if(dp[p1][p2] == 0)             // end point (value depends on topdown/bottomup)
        return;
    if(s1[p1] == s2[p2]) {          // match found, no operation
        dfs(p1+1, p2+1);
        return;
    }
    int P = min(mp(dp[p1+1][p2], 1), min(mp(dp[p1][p2+1], 2), mp(dp[p1+1][p2+1], 3))).second;
    if(P == 1)      dfs(p1+1, p2);              // delete s1[p1] from position p2 of s1 string
    else if(P == 2) dfs(p1, p2+1);              // insert s2[p2] on position p2 of s1 string
    else            dfs(p1+1, p2+1);            // change s1[p2] to s2[p2] on position p2 of string s1       
}

//-----------------------Digit DP-----------------------

// Complexity : O(10*idx*sum*tight)     : LightOJ 1068
// Tight contains if there is any restriction to number (Tight is initially 1)
// Initial Params: (MaxDigitSize-1, 0, 0, 1, modVal, allowed_digit_vector)

ll dp[15][100][100][2];
ll digitSum(int idx, int sum, ll value, bool tight, int mod, vector<int>&MaxDigit) {
    if (idx == -1)
        return ((value == 0) && (sum == 0));
    if (dp[idx][sum][value][tight] != -1)
        return dp[idx][sum][value][tight];
    ll ret = 0;
    int lim = (tight)? MaxDigit[idx] : 9;                           // Numbers are genereated in reverse order
    for (int i = 0; i <= lim; i++) {
        bool newTight = (MaxDigit[idx] == i)? tight : 0;            // caclulating newTight value for next state
        ll newValue = value ? ((value*10) % mod)+i : i;
        ret += digitSum(idx-1, (sum+i)%mod, newValue%mod, newTight, mod, MaxDigit);
    }
    return dp[idx][sum][value][tight] = ret;
}

// Bit DP (Almost same as Digit DP)    : LighOJ 1032
// Complexity O(2*pos*total_bits*tights*number_of_bits)
// Initial Params : (MostSignificantOnBitPos, N, 0, 0, 1)
// Call as : bitDP(SigOnBitPos, N, 0, 0, 1)   N is the Max Value, calculating [0 - N]
// Tight is initially on
// pairs are number of paired bits, prevOn shows if previous bit was on (it is for this problem)

#define isOn(x, i) (x & (1LL<<i))
#define On(x, i) (x | (1LL<<i))
#define Off(x, i) (x & ~(1LL<<i))
int N, lastBit;
long long dp[33][33][2][2];
ll bitDP(int pos, int mask, int pairs, bool prevOn, bool tight) {
    if(pos < 0)
        return pairs;
    if(dp[pos][pairs][prevOn][tight] != -1)
        return dp[pos][pairs][prevOn][tight];
    bool newTight = tight & !isOn(mask, pos);    // Turn off tight when we are turning off a bit which was initially on
    ll ans = bitDP(pos-1, Off(mask, pos), pairs, 0, newTight);
    if(On(mask, pos) <= N)
        ans += bitDP(pos-1, On(mask, pos), pairs + prevOn, 1, tight && isOn(mask, pos)); 
    return dp[pos][pairs][prevOn][tight] = ans;
}
