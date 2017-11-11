// 2D KMP

#include <bits/stdc++.h>
using namespace std;

unordered_map<string, int>patt;     // Clear after each Kmp2D call
int flag = 0;                       // Set to zero before calling PrefixTable

// r : Pattern row
// c : Pattern column
// table : prefix table (1D array)
// s : Pattern String (C++ string)

vector<int> PrefixTable2D(int r, int c, int table[], string s[]) {
    vector<int>Row;                 // Contains Row mapped string index
    
    for(int i = 0; i < r; ++i) {
        if(patt.find(s[i]) == patt.end()) {
            patt[s[i]] = ++flag;
            Row.push_back(flag);
        }
        else
            Row.push_back(patt[s[i]]);
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

// StrR StrC : String Row and Column
// PattR PattC : Pattern row and column
// Str : String (C++ String)
// Patt : Pattern (C++ String)
// table : Prefix table of pattern (1D array)

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
            else
                mat[i][j] = patt[tmp];
        }
    
    vector<pair<int, int> >match;                       // This will contain the starting Row & Column of matched string
    for(int c = 0; c <= limC; ++c) {                    // Scan columnwise
        int i = 0, j = 0;
        while(i < StrR) {
            while(j >= 0 && mat[i][c] != PattRow[j])
                j = table[j];
            ++i, ++j;
            if(j == PattR)
                match.push_back(make_pair(i-j,c));
        }
    }
    return match;
}


