#include <bits/stdc++.h>
#define MAX 100009
#define MOD 1000000007
using namespace std;
typedef long long ll;
typedef vector<long long> vl;

bitset<1000009>isPrime;
vector<ll> primes;


void sieveGen(ll N) {                   // Faster, Will generate all primes <= N
    isPrime.set();
    isPrime[0] = isPrime[1] = 0;
    for(ll i = 3; i*i <= N; i+=2) {
        if(isPrime[i]) {
            for(ll j = i*i; j <= N; j += i)
                isPrime[j] = 0;
    }}

    primes.push_back(2);
    for(int i = 3; i <= N; i+=2)
        if(isPrime[i])
            primes.push_back(i);

    /*
    primes.push_back(1000037);
    primes.push_back(10000019);
    primes.push_back(10000079);
    primes.push_back(999999929);
    primes.push_back(999999937);
    primes.push_back(100000007);
    primes.push_back(100000039);
    primes.push_back(100000049);
    primes.push_back(100000073);
    */
}

vector<ll> f, ff;

void factor(ll n) {
    for(int i = 0; i < primes.size() and primes[i] <= n; ++i) {
        if(n%primes[i] == 0)
            f.push_back(primes[i]);
        while(n%primes[i] == 0)
            n /= primes[i];
    }
    if(n != 1)
        f.push_back(n);
}

vector<ll> tmp;


int itr = 0, ansp = 0;
string proc(string s) {
    stringstream ss(s);
    ll x, y;
    ss >> x;
    ss >> y;
    if(x == 1) {
        if(itr > 2) {
            cout << "Too many iterations\n";
            return string("-1");
        }

        if(y > 1e9) {
            cout << "Invalid Input\n";
            return string("-1");
        }

        ++itr;
        //cout << y << " -> " << y*y << " -> " << (y*y)%primes[ansp] << " : " << primes[ansp] << endl;
        return to_string((y*y)%primes[ansp]);
    }
    else {
        ansp++, itr = 0;
        if(y == primes[ansp-1]) {
            cout << "Guessed Correct " << primes[ansp-1] << endl;
            return string("Yes");
        }
        else {
            cout << "Guessed " << y << " Judge Expecting " << primes[ansp-1] << endl; 
            return string("No");
        }
    }
    return string("**");
}


string giveOut(ll x, ll y) {
    string s = to_string(x);
    s += " ";
    s += to_string(y);

    cout << "GIVING " << s << endl;
    return proc(s);
}


/*
string giveOut(ll x, ll y) {
    string s = to_string(x);
    s += " ";
    s += to_string(y);
    cout << s << "\n";
    cout.flush();
    cin >> s;
    return s;
}*/

set<ll>s;

ll getMOD(ll x, ll c, ll m) {
    ll m0 = (x*x)%m;
    ll m1 = (2*x*c)%m;
    ll m2 = (c*c)%m;

    return (((m0 - m1)%m + m)%m + m2)%m;
}

ll getAns(ll x, ll y, ll c, ll d) {
    if(c == 0)
        return x;

    f.clear();
    factor(x*x-c);

    cout << "PF : ";
    for(auto it : f)
        cout << it << " ";
    cout << endl;

    ff = f;
    f.clear();
    factor(y*y-d);

    cout << "PF : ";
    for(auto it : f)
        cout << it << " ";
    cout << endl;

    for(auto it : f) {
        
    }

    for(auto it0 : f)
        for(auto it1: ff)
            if(it0 == it1 and it0 > max(c, d) and (x*x)%it0 == c and (y*y)%it0 == d and getMOD(x, c, it0) == d)
                return it1;

    return -1;
}

int main() {
    sieveGen(1000000);
    string nxt;
    ll x, ans = 0;
    int t;
    cin >> t;

    //ansp = (int)primes.size() - 20;  
    while(t--) {
        x = 999999937;
 
        ll c = stoll(giveOut(1, x));
        ll y = x-c;
        ll d = stoll(giveOut(1, y));

        cout << c << " " << d << endl;

        nxt = giveOut(2, getAns(x, y, c, d));
        if(nxt == "No")
            return 0;
    } 

    //cout << "Passed All\n";
    return 0;
}



/*
Primes:
999999929
999999937
*/