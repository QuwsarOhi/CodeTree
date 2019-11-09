DP:
 * Building Palindrome in minimum move and printing the answer palindrome
 * Matching two strings by insert, erase, and changing characters
 * String reduction                                     [AXDOODOO -> AX(DO^2)^2] 
 * Merging multiple strings into shortest string        [TAC + ACT + CTA = ACTAC]
 * Making balanced bracket sequqnce from imbalanced bracket sequence
 * Digit DP : Decimal DP, Bit DP, Double bonded Decimal DP
 * Memory Optimized Dp : Building two subsets of equal sum from a single set of values
 * Travelling Salesman

/* ----------------------- Dynamic Programming ----------------------- */
// String DP
int Palindrome(int l, int r) {                          // Building Palindrome in minimum move
    if(dp[l][r] != INF) return dp[l][r];
    if(l >= r)          return dp[l][r] = 0;
    if(l+1 == r)        return dp[l][r] = (s[l] != s[r]);
    if(s[l] == s[r])    return dp[l][r] = Palindrome(l+1, r-1);
    return dp[l][r] =   min(Palindrome(l+1, r), Palindrome(l, r-1))+1;  // Adding a alphabet 
}                                                                       // on left and right
// String Printer function of above DP
void dfs(int l, int r) {                // Palindrome printing, for above DP function
    if(l > r) return;
    if(s[l] == s[r]) {
        Palin.push_back(s[l]);
        dfs(l+1, r-1);
        if(l != r) Palin.push_back(s[l]);
        return;
    } int P = min(make_pair(dp[l+1][r], 1), make_pair(dp[l][r-1], 2)).second;
    if(P == 1) {
        Palin.push_back(s[l]);
        dfs(l+1, r);
        Palin.push_back(s[l]);
    } else {
        Palin.push_back(s[r]);
        dfs(l, r-1);
        Palin.push_back(s[r]);
}}
// Checks if substring l-r is palindrome
bool isPalindrome(int l, int r) {       
    if(l == r || l > r)     return 1;
    if(dp[l][r] != -1)      return dp[l][r];
    if(s[l] == s[r])        return dp[l][r] = isPalindrome(l+1, r-1);
    return 0;
}
// Given two string s1 and s2, match the two strings by performing the following operations:
// delete chars, insert chars, and change chars at any position on any string
int recur(int p1, int p2) {         // make string s1 like s2, in minimum move
    if(dp[p1][p2] != INF)
        return dp[p1][p2];
    if(p1 == l1 or p2 == l2) {      // reached end of string s1 or s2
        if(p1 < l1) return dp[p1][p2] = recur(p1+1, p2)+1;
        if(p2 < l2) return dp[p1][p2] = recur(p1, p2+1)+1;
        return dp[p1][p2] = 0;
    } if(s1[p1] == s2[p2])            // match found
        return dp[p1][p2] = recur(p1+1, p2+1);
    // change at position p1, delete position p1, insert at position p1
    return dp[p1][p2] = min(recur(p1+1, p2+1), min(recur(p1+1, p2), recur(p1, p2+1)))+1;    
}
// Printing the string of above dp function
void dfs(int p1, int p2) {          // printing function for above dp
    if(dp[p1][p2] == 0)             // end point (value depends on topdown/bottomup)
        return;
    if(s1[p1] == s2[p2]) {          // match found, no operation
        dfs(p1+1, p2+1); 
        return;
    } int P = min(mp(dp[p1+1][p2], 1), min(mp(dp[p1][p2+1], 2), mp(dp[p1+1][p2+1], 3))).second;
    if(P == 1)      dfs(p1+1, p2);               // delete s1[p1] from position p2 of s1 string
    else if(P == 2) dfs(p1, p2+1);                 // insert s2[p2] on position p2 of s1 string
    else            dfs(p1+1, p2+1);     // change s1[p2] to s2[p2] on position p2 of string s1       
}
// Reduce string AXDOODOO (len : 8) to AX(DO^2)^2 (len : 4)
int reduce(int l, int r) {              
    if(l > r)           return INF;
    if(l == r)          return 1;
    if(dp[l][r] != -1)  return dp[l][r];
    int ret = r-l+1, len = r-l+1;
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
    } return dp[l][r] = ret;
}
// Light OJ 1073 - DNA Sequence
// FIND and PRINT shortest string after merging multiple string together
// TAC + ACT + CTA = ACTAC
int matchDP[20][20];                    
int TryMatch(int x, int y) {            // Finds overlap of two strings if placed as x + y
    if(matchDP[x][y] != -1)             // ABAAB + AAB : Match at index 2
        return matchDP[x][y];
    for(size_t i = 0; i < v[x].size(); ++i) {
        for(size_t j = i, k = 0; j < v[x].size() && k < v[y].size(); ++j, ++k)
            if(v[x][j] != v[y][k])
                goto pass;
        return matchDP[x][y] = i;
        pass:;
    } return matchDP[x][y] = v[x].size(); 
} int dp[16][(1<<15)+100];
int recur(int mask, int last) {                 // Final match patterns of strings
    if(dp[last][mask] != -1)             return dp[last][mask];
    if(mask == (1<<n)-1)                 return dp[last][mask] = v[last].size();
    int ret = INF, cost;
    for(int i = 0; i < n; ++i) {
        if(isOn(mask, i))   continue;
        int mPos = TryMatch(last, i);
        if(mPos < (int)v[last].size())
            cost = (int)v[last].size() - ((int)v[last].size() - mPos);
        else
            cost = v[last].size();
        ret = min(ret, recur(mask | (1 << i), i) + cost);
    } return dp[last][mask] = ret; 
} string ans;
void dfs(int mask, int last, string ret) {      // Printing the final string
    if(!ret.empty() && ans < ret) return;
    if(mask == (1<<n)-1) {
        ret += v[last];
        if(ret < ans)
            ans = ret;
        return; }
    for(int i = 0; i < n; ++i) {
        if(isOn(mask, i))
            continue;
        int mPos = TryMatch(last, i), cost;
        if(mPos < (int)v[last].size())
            cost = (int)v[last].size() - ((int)v[last].size() - mPos);
        else
            cost = v[last].size();
        if(dp[last][mask] - cost == dp[i][mask | (1<<i)])
            dfs(mask | (1<<i), i, ret + v[last].substr(0, cost));
}}
// FileName : 1141 - Brackets Sequence
// Given a bracket sequence of () and [] which can be non-accurate have to make it accurate 
// such as the accurate sequence length is minimum and lexicographically smallest
int recur(int l, int r) {
    int &ret = dp[l][r];
    if(l > r)                    return ret = 0;
    if(l == r)                   return ret = 2;           // We need to place an extra bracket
    if(ret != INF)               return ret;
    ret = min(recur(l+1, r), recur(l, r-1))+2;     // First we assume that we
    char lft = s[l];                              // need to place brackets on first or on last
    if(lft == '(' or lft == '[') {               // If this segment starts with opening bracket
      for(int i = l+1; i <= r; ++i) {        // Then we try to slice the segment into two parts
        if((lft == '(' and s[i] == ')') or (lft == '[' and s[i] == ']'))
          ret = min(ret, recur(l+1, i-1)+recur(i+1, r)+2);      // +2 is the lenght of () or []
return ret; }

/* -----------------------Digit DP-----------------------
Complexity : O(10*idx*sum*tight)     : LightOJ 1068
Tight contains if there is any restriction to number (Tight is initially 1)
Initial Params: (MaxDigitSize-1, 0, 0, 1, modVal, allowed_digit_vector)
MaxDigit contains values in reverse order, (123 will be stored as {3, 2, 1}) */
ll dp[15][100][100][2];
ll digitSum(int idx, int sum, ll value, bool tight, int mod, vector<int>&MaxDigit) {
    if (idx == -1)                              return ((value == 0) && (sum == 0));
    if (dp[idx][sum][value][tight] != -1)       return dp[idx][sum][value][tight];
    ll ret = 0, lim = (tight)? MaxDigit[idx] : 9;
    for(int i = 0; i <= lim; i++) {
        bool newTight = (MaxDigit[idx] == i)? tight:0;                  // caclulating newTight  
        ll newValue = value ? ((value*10) % mod)+i : i;                 // value for next state
        ret += digitSum(idx-1, (sum+i)%mod, newValue%mod, newTight, mod, MaxDigit);
    } return dp[idx][sum][value][tight] = ret; 
}
/* Bit DP (Almost same as Digit DP)    : LighOJ 1032
Complexity O(2*pos*total_bits*tights*number_of_bits)
Initial Params : (MostSignificantOnBitPos, N, 0, 0, 1)
Call as : bitDP(SigOnBitPos, N, 0, 0, 1)   N is the Max Value, calculating in range [0 - N]
pairs are number of paired bits, prevOn shows if previous bit was on (it is for this problem)*/
ll dp[33][33][2][2], N, lastBit;
ll bitDP(int pos, int mask, int pairs, bool prevOn, bool tight) {
    if(pos < 0)                                 return pairs;
    if(dp[pos][pairs][prevOn][tight] != -1)     return dp[pos][pairs][prevOn][tight];
    bool newTight = tight & !isOn(mask, pos);
    ll ans = bitDP(pos-1, Off(mask, pos), pairs, 0, newTight);
    if(On(mask, pos) <= N)
        ans += bitDP(pos-1, On(mask, pos), pairs + prevOn, 1, tight && isOn(mask, pos)); 
return dp[pos][pairs][prevOn][tight] = ans; }

/* ----------------------- Double Bounded Digit Dp Technique -----------------------
mn, mx contains the digits from MSB to LSB and both of them must be of same length */
vector<int>tt, mn = {0, 5, 4}, mx = {1, 3, 0};              // mn = 54, mx = 130, mn is resized
void recur(int pos = 0, bool lower = 1, bool higher = 1) {                  // A dummy function
    if(pos == LEN) {
        for(auto it : tt) cout << it;
        cout << endl;
        return;
    } int lo = lower ? mn[pos]:0, hi = higher ? mx[pos]:9;
    for(int d = lo; d <= hi; ++d) {
        bool newLower = (d == mn[pos]) ? lower:0, newHigher = (d == mx[pos]) ? higher:0;
        tt.push_back(d);
        recur(pos+1, newLower, newHigher);
        tt.pop_back();
}}
/* Memory Optimized DP + Bottom Up solution (LOJ : 1126 - Building Twin Towers)
 Given array v of n elements, make two value x1 and x2 where x1 == x2, output maximum of it */
int dp[2][500010], n;                                   // present dp table and past dp table
int BottomUp(int TOT) {                                 // TOT = (Cumulative Sum of v)/2
    memset(dp, -1, sizeof dp);             // DP[iteration_state][sum_difference] = maximum sum
    dp[0][0] = 0;
    bool present = 0, past = 1;
    for(int i = 0; i < n; ++i) {
      present ^= 1, past ^= 1;                        // Swapping present and past dp table
      for(int diff = 0; diff <= TOT; ++diff) {
        if(dp[past][diff] != -1) {
          int moreDiff = diff + v[i], lessDiff = abs(diff - v[i]);
          dp[present][diff] = max(dp[present][diff], dp[past][diff]);
          dp[present][lessDiff] = max(dp[present][lessDiff], 
                                            max(dp[past][lessDiff], dp[past][diff] + v[i]));
          dp[present][moreDiff] = max(dp[present][moreDiff], 
                                            max(dp[past][moreDiff], dp[past][diff] + v[i]));
    }}} return (max(dp[0][0], dp[1][0]))/2;              // Returns the maximum possible answer
}
/* Travelling Salesman
 dist[u][v] = distance from u to v
 dp[u][bitmask] = dp[node][set_of_taken_nodes]  (saves the best(min/max) path) */
int n, x[11], y[11], dist[11][11], memo[11][1 << 11], dp[11][1 << 11];
int TSP(int u, int bitmask) {               // TSP(startin_node, bitmask_of_visited_node)
    if(bitmask == ((1 << (n)) - 1))         return dist[u][0];
    if(dp[u][bitmask] != -1)                return dp[u][bitmask];             
    int ans = INF;
    for(int v = 0; v <= n; v++)                 // Traverse all nodes from u
        if(u != v && !(bitmask & (1 << v)))     
            ans = min(ans, dist[u][v] + tsp(v, bitmask | (1 << v)));
    return dp[u][bitmask] = ans; 
}