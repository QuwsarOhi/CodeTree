#include <bits/stdc++.h>
using namespace std;
#define MAX                 200010
#define EPS                 1e-9
#define INF                 1e7
#define MOD                 1000000007
#define pb                  push_back
#define mp                  make_pair
#define fi                  first
#define se                  second
#define pi                  acos(-1)
#define sf                  scanf
#define pf                  printf
#define SIZE(a)             ((int)a.size())
#define All(S)              S.begin(), S.end()              
#define Equal(a, b)         (abs(a-b) < EPS)
#define Greater(a, b)       (a >= (b+EPS))
#define GreaterEqual(a, b)  (a > (b-EPS))
#define fr(i, a, b)         for(register int i = (a); i < (int)(b); i++)
#define FastRead            ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define fileRead(S)         freopen(S, "r", stdin);
#define fileWrite(S)        freopen(S, "w", stdout);
#define Unique(X)           X.erase(unique(X.begin(), X.end()), X.end())

#define isOn(S, j)          (S & (1 << j))
#define setBit(S, j)        (S |= (1 << j))
#define clearBit(S, j)      (S &= ~(1 << j))
#define toggleBit(S, j)     (S ^= (1 << j))
#define lowBit(S)           (S & (-S))
#define setAll(S, n)        (S = (1 << n) - 1)

typedef unsigned long long ull;
typedef long long ll;
typedef map<int, int> mii;
typedef map<ll, ll>mll;
typedef map<string, int> msi;
typedef vector<int> vi;
typedef vector<long long>vl;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<pair<int, int> > vii;
typedef vector<pair<ll, ll> >vll;


//int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};
//int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1}, dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};
//----------------------------------------------------------------------------------------------------------


// --------------- 2D KMP ---------------

unordered_map<string, int>patt;             // Clear after each Kmp2D call
int flag = 0;                               // Set to zero before calling PrefixTable
// r : Pattern row, c : Pattern column      // table : prefix table (1D array)
// s : Pattern String (C++ string)          // Followed Felix-Halim KMP

vector<int> PrefixTable2D(int r, int c, int table[], string s[]) {
    vector<int>Row;                         // Contains Row mapped string index
    for(int i = 0; i < r; ++i) {
        if(patt.find(s[i]) == patt.end()) {
            patt[s[i]] = ++flag;
            Row.push_back(flag);
        }
        else Row.push_back(patt[s[i]]);
    }
    int len = 0, i = 1;
    table[0] = 0;
    while(i < r) {
        if(Row[i] == Row[len]) {
            ++len;
            table[i] = len;
            ++i;
        }
        else {
            if(len != 0)    len = table[i-1];
            else            table[i++] = 0;
    }}
    return Row;       // Returns Hashed index of each row in pattern string
}

// StrR StrC : String Row and Column       // PattR PattC : Pattern row and column
// Str : String (C++ String)               // Patt : Pattern (C++ String)      // table : Prefix table of pattern (1D array)
int Kmp2D(int StrR, int StrC, int PattR, int PattC, string Str[], string Patt[], int table[]) {
    int mat[StrR][StrC];
    int limC = StrC - PattC;
    
    patt.clear(), flag = 0;

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
    //vector<pair<int, int> >match;                       // This will contain the starting Row & Column of matched string
    /*for(int c = 0; c <= limC; ++c) {                    // Scan columnwise
        int i = 0, j = 0;
        while(i < StrR) {
            while(j >= 0 && mat[i][c] != PattRow[j])
                j = table[j];
            ++i, ++j;
            if(j == PattR) match.push_back(make_pair(i-j,c));
    }}*/
    int cnt = 0;
    for(int c = 0; c <= limC; ++c) {
        int i = 0, j = 0;
        while(i < StrR) {
            if(mat[i][c] == PattRow[j])     ++i, ++j;
            if(j == PattR) {
                //match.push_back({i-j, c});          // Match Found
                ++cnt;
                j = table[j-1];
            }
            else if(i < StrR and mat[i][c] != PattRow[j]) {
                if(j != 0)  j = table[j-1];
                else        i++;
            }
        }
    }
    return cnt;
}

string str[1010], Patt[110];
int table[1010];

int main() {
    //fileRead("in");
    //fileWrite("out");
    FastRead;

    int t, n, m, x, y;
    cin >> t;

    while(t--) {
        cin >> n >> m;


        for(int i = 0; i < n; ++i) {
            cin >> str[i];
            //cerr << "GOT " << str[i] << endl;
        }

        cin >> x >> y;
        for(int i = 0; i < x; ++i) {
            cin >> Patt[i];
            //cerr << "GOT " << Patt[i] << endl;
        }

        cout << Kmp2D(n, m, x, y, str, Patt, table) << "\n";
    }
    return 0;
}