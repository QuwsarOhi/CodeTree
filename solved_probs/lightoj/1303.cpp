// LightOJ
// 1303 - Ferris Wheel

#include <bits/stdc++.h>
using namespace std;
#define MAX                 200100
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
 
int n, m, Time, seat[50];
vi person;
bool visited[50][50];
 
bool checkAll() {
    for(int i = 0; i < m; ++i) {
        for(int j = 0; j < n; ++j) {
            if(!visited[i][j])
                return 0;
        }
    }
    return 1;
}
 
void simulate() {
    for(int i = 0; ; i++) {
        i %= m;
        bool isSeated = 0;
        vector<int>::iterator it = person.begin();
        //cout << " AT " << i << "\n\n";
        for(; it != person.end(); ++it) {
            if(!visited[i][*it]) {          // someone not seated yet
                int per = seat[i];
                int x = *it;
                if(per != -1)
                    person.pb(per);         // if seat is not empty, add the seated person to the queue
                seat[i] = x;              // new person from queue sits on the seat
                person.erase(it);           // remove the person from queue
                visited[i][x] = 1;        // this person has visited the i'th seat
                isSeated = 1;               // one has seated
 
              //  cout << x << " seated " << per << " got off" << endl;
                break;
            }
        }
        if(!isSeated) {                      // if none is seated
            if(seat[i] != -1)                 // if there is someone in the seat
                person.pb(seat[i]);           // add him to queue
            //cout << "seat set to empty got off " << seat[i] << endl;
            seat[i] = -1;                   // make the seat empty
 
        }
        Time += 5;
 
        //cout << "At time " << Time << " queue " << SIZE(person) << endl;
        //for(auto it : person)
        //    cout << it << " ";
        //cout << endl;
 
        if(SIZE(person) == n && checkAll())                      // check if all of the persons have visited all the seats
            return;
    }
}
 
int main() {
    //fileRead("in.txt");
    //fileWrite("out.txt")
    int t;
    cin >> t;
    for(int Case = 1; Case <= t; ++Case) {
        cin >> n >> m;
        cout << "Case " << Case << ": ";
        Time = 0;
        memset(visited, 0, sizeof visited);
        memset(seat, -1, sizeof seat);
        person.clear();
        for(int i = 0; i < n; ++i)
            person.pb(i);
        simulate();
        cout << Time << endl;
    }
    return 0;
}
