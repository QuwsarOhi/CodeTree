// Knuth Morris Pratt
// Complexity : O(String + Token)

//------------------------Genuine PrefixTable (Prefix-Suffix Length)------------
// Some Tricky Cases:	aaaaaa : 0 1 2 3 4 5		aaaabaa : 0 1 2 3 0 1 2		abcdabcd : 0 0 0 0 1 2 3 4
void prefixTable(int n, char pat[], int table[]) {
    int len = 0, i = 1;                     // length of the previous longest prefix suffix
    table[0] = 0;                           // table[0] is always 0
    while (i < n) {
        if (pat[i] == pat[len]) {
            len++;
            table[i] = len;
            i++;
        }
        else {                                                      // pat[i] != pat[len]
            if(len != 0)    len = table[len-1];                     // find previous match
            else            table[i] = 0, i++;                      // if (len == 0) and mismatch
}}}                                                                 // set table[i] = 0, and go to next index

void KMP(int strLen, int patLen, char str[], char pat[], int table[]) { 
    int i = 0, j = 0;						// i : string index, j : pattern index
    while (i < strLen) {
        if(str[i] == pat[j]) i++, j++;
        if(j == M) {
            printf("Found pattern at index %d n", i-j);
            j = table[j-1];					// Match found, try for next match
        }
        else if(i < strLen && str[i] != pat[j]) {	    // Match not found
            if(j != 0)  j = table[j-1];                 // if j != 0, then go to the prev match index
            else		i = i+1;					    // if j == 0, then we need to go to next index of str
}}}


// p is the pattern where table[] is the pre-made prefix table of pattern
// for any index idx the nxt[idx][j] returns the new index idx where the index
// should point next, this optimizes the kmp in linear time

void getState(string &p, int table[], int nxt[][27]) {
    for(int i = 0; i < p.size(); ++i) {
        for(int j = 0; j < 26; ++j) {
            if(p[i]-'a' == j)
                nxt[i][j] = i+1;
            else
                nxt[i][j] = i == 0 ? 0 : nxt[table[i-1]][j];
}}}

// check function using nxt[idx][j]
// idx is the index from which the string should start matching with the pattern
// by default idx = 0, also it refers the last index of the pattern to which
// the string matched

int match(string &s, int table[], int nxt[][27], int &idx) {
    int ans = 0;
    for(char c : s) {
        idx = nxt[idx][c-'a'];
        if(idx == p.size())
            ++ans, idx = table[idx-1];
    }
    return ans;
}

// --------------- 2D KMP ---------------

unordered_map<string, int>patt;             // Clear after each Kmp2D call
int flag = 0;                               // Set to zero before calling PrefixTable
// r : Pattern row, c : Pattern column      // table : prefix table (1D array)
// s : Pattern String (C++ string)          // Followed Felix-Halim KMP
vector<int> PrefixTable2D(int r, int c, int table[], string s[]) {
    vector<int>Row;                 // Contains Row mapped string index
    for(int i = 0; i < r; ++i) {
        if(patt.find(s[i]) == patt.end()) {
            patt[s[i]] = ++flag;
            Row.push_back(flag);
        }
        else Row.push_back(patt[s[i]]);
    }
    table[0] = -1;
    int i = 0, j = -1;
    while(i < r) {
        while(j >= 0 && Row[i] != Row[j])
            j = table[j];
        ++i, ++j;
        table[i] = j;
    }
    return Row;       // Returns Hashed index of each row in pattern string
}

// StrR StrC : String Row and Column       // PattR PattC : Pattern row and column
// Str : String (C++ String)               // Patt : Pattern (C++ String)      // table : Prefix table of pattern (1D array)
vector<pair<int, int> > Kmp2D(int StrR, int StrC, int PattR, int PattC, string Str[], string Patt[], int table[]) {
    int mat[StrR][StrC];
    int limC = StrC - PattC;
    vector<int>PattRow = PrefixTable2D(PattR, PattC, table, Patt);
    for(int i = 0; i < StrR; ++i)
        for(int j = 0; j <= limC; ++j) {
            string tmp = Str[i].substr(j, PattC);
            if(patt.find(tmp) == patt.end()) {          // Generating String Mapped using same mapping values
                patt[tmp] = ++flag;                     // Stored in matrix
                mat[i][j] = flag;
            }
            else mat[i][j] = patt[tmp];
        }
    vector<pair<int, int> >match;                       // This will contain the starting Row & Column of matched string
    for(int c = 0; c <= limC; ++c) {                    // Scan columnwise
        int i = 0, j = 0;
        while(i < StrR) {
            while(j >= 0 && mat[i][c] != PattRow[j])
                j = table[j];
            ++i, ++j;
            if(j == PattR) match.push_back(make_pair(i-j,c));
    }}
    return match;
}
