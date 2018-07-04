//-----------------------String DP-----------------------
int Palindrome(int l, int r) {               // Building Palindrome in minimum move
    if(dp[l][r] != INF) return dp[l][r];
    if(l >= r)          return dp[l][r] = 0;
    if(l+1 == r)        return dp[l][r] = (s[l] != s[r]);
    if(s[l] == s[r])    return dp[l][r] = Palindrome(l+1, r-1);
    return dp[l][r] =   min(Palindrome(l+1, r), Palindrome(l, r-1))+1;      // Adding a alphabet on right, left
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

bool isPalindrome(int l, int r) {       // Checks if substring l-r is palindrome
    if(l == r || l > r)     return 1;
    if(dp[l][r] != -1)      return dp[l][r];
    if(s[l] == s[r])        return dp[l][r] = isPalindrome(l+1, r-1);
    return 0;
}

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

int reduce(int l, int r) {              // Reduce string AXDOODOO (len : 8) to AX(DO^2)^2 (len : 4)
    if(l > r)           return INF;
    if(l == r)          return 1;
    if(dp[l][r] != -1)  return dp[l][r];
    int ret = r-l+1;
    int len = ret;
    for(int i = l; i < r; ++i)          // A B D O O D O O   remove A X substring
        ret = min(ret, reduce(l, i)+reduce(i+1, r));
    for(int d = 1; d < len; ++d) {      // D O O D O O  to check all divisable length substring
        if(len%d != 0)  continue;
        for(int i = l+d; i <= r; i += d)
            for(int k = 0; k < d; ++k)
                if(s[l+k] != s[i+k])
                    goto pass;
        ret = min(ret, reduce(l, l+d-1));
        pass:;
    }
    return dp[l][r] = ret;
}

// Light OJ 1073 - DNA Sequence
// FIND and PRINT shortest string after merging multiple string together 

int matchDP[20][20];                    
int TryMatch(int x, int y) {            // Finds First overlap of two string
    if(matchDP[x][y] != -1)             // ABAAB + AAB : Match at 2
        return matchDP[x][y];
    for(size_t i = 0; i < v[x].size(); ++i) {
        for(size_t j = i, k = 0; j < v[x].size() && k < v[y].size(); ++j, ++k)
            if(v[x][j] != v[y][k])
                goto pass;
        return matchDP[x][y] = i;
        pass:;
    }
    return matchDP[x][y] = v[x].size();
}

int dp[16][(1<<15)+100];
int recur(int mask, int last) {                 // DP part of LIGHT OJ
    if(dp[last][mask] != -1)                    // eleminate all substrings from n string first in main function!
        return dp[last][mask];                  // it's not handeled here
    if(mask == (1<<n)-1)
        return dp[last][mask] = v[last].size();
    int ret = INF, cost;
    for(int i = 0; i < n; ++i) {
        if(isOn(mask, i))
            continue;
        int mPos = TryMatch(last, i);
        if(mPos < (int)v[last].size())
            cost = (int)v[last].size() - ((int)v[last].size() - mPos);
        else
            cost = v[last].size();
        ret = min(ret, recur(mask | (1 << i), i) + cost);
    }
    return dp[last][mask] = ret;
}

string ans;
void dfs(int mask, int last, string ret) {          // PRINTING part of LIGHT OJ   
    if(!ret.empty() && ans < ret)
        return;
    if(mask == (1<<n)-1) {
        ret += v[last];
        if(ret < ans)
            ans = ret;
        return;
    }
    for(int i = 0; i < n; ++i) {
        if(isOn(mask, i))
            continue;
        int mPos = TryMatch(last, i);
        int cost;
        if(mPos < (int)v[last].size())
            cost = (int)v[last].size() - ((int)v[last].size() - mPos);
        else
            cost = v[last].size();
        if(dp[last][mask] - cost == dp[i][mask | (1<<i)])
            dfs(mask | (1<<i), i, ret + v[last].substr(0, cost));
}}

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

// Memory Optimized DP + Bottom Up solution (LOJ : 1126 - Building Twin Towers)
// given array v of n elements, make two value x1 and x2 where x1 == x2, output maximum of it 
 
int dp[2][500010], n;                                   // present dp table and past dp table
int BottomUp(int TOT) {                                 // TOT = (Cumulative Sum of v)/2
    memset(dp, -1, sizeof dp);
    dp[0][0] = 0;
    bool present = 0, past = 1;
    for(int i = 0; i < n; ++i) {
        present ^= 1, past ^= 1;                        // Swapping present and past dp table
        for(int diff = 0; diff <= TOT; ++diff)
            if(dp[past][diff] != -1) {
                int moreDiff = diff + v[i], lessDiff = abs(diff - v[i]);
                dp[present][diff] = max(dp[present][diff], dp[past][diff]);
                dp[present][lessDiff] = max(dp[present][lessDiff], max(dp[past][lessDiff], dp[past][diff] + v[i]));
                dp[present][moreDiff] = max(dp[present][moreDiff], max(dp[past][moreDiff], dp[past][diff] + v[i]));
    }}
    return (max(dp[0][0], dp[1][0]))/2;                 // Returns the maximum possible answer
}
