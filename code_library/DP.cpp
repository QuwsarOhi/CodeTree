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

// FileName : 1141 - Brackets Sequence
// Given a bracket sequence of () and [] which can be non-accurate
// Have to make it accurate such as the accurate sequence length is minimum
int recur(int l, int r) {
    int &ret = dp[l][r];
    if(l > r)                   // No more placing required
        return ret = 0;
    if(l == r)                  // We need to place an extra bracket
        return ret = 2;
    if(ret != INF)
        return ret;
    ret = min(recur(l+1, r), recur(l, r-1))+2;  // First we assume that we
    char lft = s[l];                            // need to place brackets on first or on last
    if(lft == '(' or lft == '[')                // If this segment starts with opening bracket
        for(int i = l+1; i <= r; ++i)           // Then we try to slice the segment into two parts
            if((lft == '(' and s[i] == ')') or (lft == '[' and s[i] == ']'))
                ret = min(ret, recur(l+1, i-1)+recur(i+1, r)+2);    // +2 is the lenght of () or []
    return ret;
}

//-----------------------Digit DP-----------------------

// Complexity : O(10*idx*sum*tight)     : LightOJ 1068
// Tight contains if there is any restriction to number (Tight is initially 1)
// Initial Params: (MaxDigitSize-1, 0, 0, 1, modVal, allowed_digit_vector)
// MaxDigit contains values in reverse order, (123 will be stored as {3, 2, 1})

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

//-----------------------Sequence Dp-----------------------

// Finding number of subsequences for which mod of d is zero
// for any subsequence, the mod of d is zero iff the cumulative sum 
// of the subsequence is same as previously found cumulative sum
ll subSeqSum(ll v[], ll n, ll d) {
    ll ans = 0, sum = 0;
    memset(dp, 0, sizeof dp);
    dp[0] = 1;

    for(int i = 0; i < n; ++i) {
        sum = (sum + v[i])%d;
        ans += dp[sum]++;
    }
    return ans;
}

//-----------------------Double Bounded Digit Dp Technique-----------------------

vector<int>tt, mn = {0, 5, 4}, mx = {1, 3, 0};
int LIM;

void recur(int pos = 0, bool lower = 1, bool higher = 1) {
    if(pos == LIM) {
        for(auto it : tt) cout << it;
        cout << endl;
        return;
    }
    int lo = lower ? mn[pos]:0;
    int hi = higher ? mx[pos]:9;

    for(int d = lo; d <= hi; ++d) {
        bool newLower = (d == mn[pos]) ? lower:0;
        bool newHigher = (d == mx[pos]) ? higher:0;

        tt.push_back(d);
        recur(pos+1, newLower, newHigher);
        tt.pop_back();
}}


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

// Count Number of ways to go from (1, 1) to (r, c) if there exists n unassassable points (only eight and down is valid move)
ll CountNumberofWays(int r, int c, int n) {
    v[n] = {r, c};                                  // also add the last point as unaccessable point, to find how many
    sort(v.begin(), v.end());                       // ways we can come to this point, which is the answer
    for(int i = 0; i <= n; ++i) {
        dp[i] = CountWay(1, 1, v[i].first, v[i].second);               // Number of ways we can come from starting square
        for(int j = 0; j < i; ++j)
            if(v[j].first <= v[i].first and v[j].second <= v[i].second)
                dp[i] = (dp[i] - (dp[j] * CountWay(v[j].first, v[j].second, v[i].first, v[i].second))%MOD + MOD)%MOD;
    }                                               // Number of ways we can reach from (1, 1) to (r, c)
    return dp[n];                                   // The last state is always (r, c), which is the answer                   
}


// Travelling Salesman
// dist[u][v] = distance from u to v
// dp[u][bitmask] = dp[node][set_of_taken_nodes]  (saves the best(min/max) path)
// call with tsp(starting node, 1)
int n, x[11], y[11], dist[11][11], memo[11][1 << 11], dp[11][1 << 11];
int TSP(int u, int bitmask) {			    // startin node and bitmask of taken nodes
    if(bitmask == ((1 << (n)) - 1))	        // when it steps in this node, if all nodes are visited
        return dist[u][0];				    // then return to 0'th (starting) node [as the path is hamiltonian]
    // or use return dist[u][start]	if starting node is not 0
    if(dp[u][bitmask] != -1)			    // if we have previous value set up
        return dp[u][bitmask];			    // use that previous value
    int ans = 1e9;						    // set an infinite value
    for(int v = 0; v <= n; v++)					// for all the nodes
        if(u != v && !(bitmask & (1 << v)))		// if this node is not the same node, and if this node is not used yet(in bitmask)
            ans = min(ans, dist[u][v] + tsp(v, bitmask | (1 << v)));	// min(past_val, dist u->v + dist(v->all other untaken nodes))
    return dp[u][bitmask] = ans;				// save in dp and return
}

// [[SIMPLE CYCLE]] CF :: http://codeforces.com/contest/11/problem/D
// states : [contains nodes which can be visited from the first ON node][currently the node which I'm at]
// contains how many times I can come to each state
ull SimpleCycle() {
    for(int i = 0; i < V; ++i) dp[1<<i][i] = 1;             // Initial state (V = vertices)
    ull ans = 0, first;
    for(int mask = 1; mask < (1<<V); ++mask) {
        for(first = 0; first < V and not isOn(mask, first); ++first);       // Finding first node
        for(int from = first; from < V; ++from) {           // Finding all possible answers where
            if(not isOn(mask, from)) continue;              // we start from 'first' and come to 
            for(int to = first+1; to < V; ++to) {           // 'to' node visiting all other ON nodes
                if(not isOn(mask, to) or not G[from][to] or from == to) continue;
                dp[mask][to] += dp[mask^(1<<to)][from];
        }}
        // Double Counting occurs : 1-2-3-4-1 and 1-3-2-4-1 is considered same (As they are rings)
        for(int from = first+1; from < V; ++from)           // If we can go to the first node, this means
            if(isOn(mask, from) and G[from][first] and __builtin_popcount(mask) >= 3)   // we can traverse
                ans += dp[mask][from];                      //  all the nodes and go to the starting node
    }
    return ans/2;           // Every cycle is counted twice, converting to single count
}

// UVA 10605 - Mines For Diamonds
// all possible min cost graph traversal + path segment min summation 
int dp[1<<12][12], seg[1<<12], startDist[12], ans[1<<12];
int maskDP() {
    // dp[mask(the_position_which_i've_visited)][the_position_where_im_at_right_now]
    memset(dp, INF, sizeof dp);
    memset(seg, INF, sizeof seg);
    for(int i = 0; i < SIZE(point); ++i)
        dp[1<<i][i] = startDist[i];
    
    for(int mask = 1; mask < (1<< SIZE(point)); ++mask) {
        for(int from = 0; from < SIZE(point); ++from) {
            if(not (mask & (1<<from))) continue;
            for(int to = 0; to < SIZE(point); ++to) {
                if(not (mask & (1<<to))) continue;
                if(from == to) continue;
                int pastMask = mask^(1<<to);
                dp[mask][to] = min(dp[mask][to], dp[pastMask][from] + HamDist(from, to));
        }}
        for(int i = 0; i < SIZE(point); ++i)
            seg[mask] = min(seg[mask], dp[mask][i]);        // contains minimum of all states of mask
    }
    for(int mask1 = 1; mask1 < (1<<SIZE(point)); ++mask1) {     // slicing masked set to half and calculating the minimum
        for(int mask2 = 1; mask2 < mask1; ++mask2) {
            if(mask1 & mask2 == mask2)                          // mask2 is subset of mask1
                seg[mask1] = min(seg[mask1], seg[mask1 ^ mask2] + seg[mask2]);
    }}
    return seg[(1<<(SIZE(point)))-1];
}