// UVa
// 542 - France '98

#include <bits/stdc++.h>
using namespace std;
#define MAX                 20000
#define EPS                 1e-9
#define INF                 1e7
#define MOD                 1000000007
#define pb                  push_back
#define mp                  make_pair
#define x                  first
#define y                  second
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

int p[20][20];
double win[20][10];
char name[17][100];

vi play[18][5] = { {},
    {{2}, {3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12, 13, 14, 15, 16}},           // team 1
    {{1}, {3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12, 13, 14, 15, 16}},           // team 2
    {{4}, {1, 2}, {5, 6, 7, 8}, {9, 10, 11, 12, 13, 14, 15, 16}},           // team 3
    {{3}, {1, 2}, {5, 6, 7, 8}, {9, 10, 11, 12, 13, 14, 15, 16}},           // team 4
    {{6}, {7, 8}, {1, 2, 3, 4}, {9, 10, 11, 12, 13, 14, 15, 16}},           // team 5
    {{5}, {7, 8}, {1, 2, 3, 4}, {9, 10, 11, 12, 13, 14, 15, 16}},           // team 6
    {{8}, {5, 6}, {1, 2, 3, 4}, {9, 10, 11, 12, 13, 14, 15, 16}},           // team 7
    {{7}, {5, 6}, {1, 2, 3, 4}, {9, 10, 11, 12, 13, 14, 15, 16}},           // team 8
    {{10}, {11, 12}, {13, 14, 15, 16}, {1, 2, 3, 4, 5, 6, 7, 8}},           // team 9
    {{9}, {11, 12}, {13, 14, 15, 16}, {1, 2, 3, 4, 5, 6, 7, 8}},            // team 10
    {{12}, {9, 10}, {13, 14, 15, 16}, {1, 2, 3, 4, 5, 6, 7, 8}},            // team 11
    {{11}, {9, 10}, {13, 14, 15, 16}, {1, 2, 3, 4, 5, 6, 7, 8}},            // team 12
    {{14}, {15, 16}, {9, 10, 11, 12}, {1, 2, 3, 4, 5, 6, 7, 8}},            // team 13
    {{13}, {15, 16}, {9, 10, 11, 12}, {1, 2, 3, 4, 5, 6, 7, 8}},            // team 14
    {{16}, {13, 14}, {9, 10, 11, 12}, {1, 2, 3, 4, 5, 6, 7, 8}},            // team 15
    {{15}, {13, 14}, {9, 10, 11, 12}, {1, 2, 3, 4, 5, 6, 7, 8}},            // team 16
    };

int main() {
    //fileWrite("out");
    
    for(int i = 1; i <= 16; ++i)
        sf("%s", name[i]);
    
    for(int i = 1; i <= 16; ++i)
        for(int j = 1; j <= 16; ++j)
            sf("%d", &p[i][j]);
    
    
    memset(win, 0, sizeof win);
    
    for(int level = 0; level <4; ++level)
        for(int i = 1; i <= 16; ++i)
            for(auto j : play[i][level]) {
                win[i][level] += (p[i][j] * (level-1 >= 0 ? win[j][level-1]:1) * (level-1 >= 0 ? win[i][level-1]:1)) / 100.0;
                //cerr << i << " + " << j << " lvl " << level << " : " << fixed << setprecision(3) << win[i][level] << endl;
            }
    
    // probability that team i will win a match vs j
    // W(i, j) : probability of i reaching this level tournament * probability of j reaching this tournament * probability of i will win vs j
    
    for(int i = 1; i <= 16; ++i)
        pf("%-10s p=%.2f%%\n", name[i], win[i][3]*100);
    
    return 0;
}
