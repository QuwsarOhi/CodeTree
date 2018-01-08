#include <bits/stdc++.h>
using namespace std;
#define MAX                 1e6
#define EPS                 1e-9
#define INF                 1e9+10
#define MOD                 1000000007
#define pb                  push_back
#define mp                  make_pair
#define fi                  first
#define se                  second
#define pi                  acos(-1)
#define sf                  scanf
#define pf                  printf
#define SIZE(a)             ((int)a.size())
#define Equal(a, b)         (abs(a-b) < EPS)
#define Greater(a, b)       (a >= (b+EPS))
#define GreaterEqual(a, b)  (a > (b-EPS)) 
#define fr(i, a, b)         for(register int i = (a); i < (int)(b); i++)
#define FastRead            ios_base::sync_with_stdio(false); cin.tie(NULL);
#define dbug(vari)          cerr << #vari << " = " << (vari) <<endl
#define isOn(S, j)          (S & (1 << j))
#define setBit(S, j)        (S |= (1 << j))
#define clearBit(S, j)      (S &= ~(1 << j))
#define toggleBit(S, j)     (S ^= (1 << j))
#define lowBit(S)           (S & (-S))
#define setAll(S, n)        (S = (1 << n) - 1)
#define fileRead(S)         freopen(S, "r", stdin);
#define fileWrite(S)        freopen(S, "w", stdout);
#define Unique(X)           X.erase(unique(X.begin(), X.end()), X.end())

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

vi DecimalVal(int a, int b) {           // Calculate Decimal values (after .) of a/b
    vi v;
    a %= b;
    if(a == 0) {
        v.pb(0);
        return v;
    }
    bool first = 1;
    while(SIZE(v) <= 200) {             // Define the Maximum Length of decimal values 
        if(a == 0)
            return v;                   // If any Zero divisor is found (then, rest all will be Zero) return values
        else if(a < b && !first) {      // If we need to add another zero (add zero after first time)
            a*=10;
            v.pb(0);
        }
        else if(a < b && first) {       // If we need to add a extra zero (adding zero first time)
            first = 0;
            a *= 10;
            continue;
        }
        else {
            v.pb(a/b);
            a%=b;
            first = 1;
        }
    }
    return v;
}

// Repetation (PunoPonik) is also calculated

vi dec1, dec2;                              // Before . (decimal), after . (decimal)
int DecimalRepeated(int a, int b) {         // Calculate Decimal values (after .) of a/b
    unordered_map<int, int>mp;
    int k = 0, point = -1;
    bool divisable = 0;
    
    if(a >= b) {                            // Before Decimal Calculation
        dec1.push_back(a/b);
        a %= b;
    }
    if(dec1.size() == 0)
        dec1.push_back(0);
		
    while(a != 0) {
        if(mp.find(a) != mp.end()) {        // if the remainder is found again, there exists a loop
            point = mp[a];
            break;
        }
        if(a%b == 0) {
            dec2.push_back(a/b);
            break;
        }
        mp[a] = k++;
        int cnt = 0;
        while(a < b) {
            a *= 10;
            if(cnt != 0) {
                dec2.push_back(0);
                k++;
            }
            ++cnt;
        }
        if(cnt != 0 && mp.find(a) != mp.end()) {
            point = mp[a];
            break;
        }
        if(cnt == 1)
            mp[a] = (k-1);
        dec2.push_back(a/b);
        a %= b;
        if(a == 0) {
            divisable = 1;
            break;
        }
    }
    
    return divisable == 1 ? 1:((int)dec2.size()-point);
}
        

        
int main() {
    //fileRead("in");
    //fileWrite("out");
    
    int a, b;
    cin >> a >> b;
    vi v = DecimalVal(a, b);
    
    for(auto it : v)
        cout << it;
    cout << endl;
    
    
    cout << "\n\n";
    
    
    int Cycle = DecimalRepeated(a, b);
    for(auto it : dec1)
        cout << it;
    cout << ".";
    for(auto it : dec2)
        cout << it;
    cout << "\n\n";
    cout << "Last Repeating Cycle " << Cycle << endl;
    return 0;
}
