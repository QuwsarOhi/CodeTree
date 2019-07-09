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
}

vector<ll> f;

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

ll getVal(ll x) {
    cout << "1 " << x << endl;
    cout.flush();
    cin >> x;
    return x;
}

set<ll>s;

int main() {
    sieveGen(40000);
    string nxt;
    ll x, y, ans = 0;
    int t;
    cin >> t;

    
    while(t--) {
        x = 40000;

        s.clear();
        for(int i = 0; i < 2; ++i) {
            y = getVal(x);
            
            if(y == -1)
                return 0;

            f.clear();
            factor(x*x-y);

            if(i == 0) {
                for(auto it : f)
                    s.insert(it);
            }

            /*for(auto it : f)
                cout << it << " ";
            cout << endl;*/

            ll sum = 0;
            bool first = 1;
            for(int i = 0; i < f.size(); ++i) {
                if(f[i] > y and x + sum + f[i] < 1e9)
                    sum += f[i];
                if(f[i] > y and first)
                	first = 0, ans = f[i];
            }

            if(i != 0) {
                for(auto it : f)
                    if(s.count(it)) {
                        ans = it;
                        goto pass;
                    }
            }

            x += sum;
        }


        pass:;
        cout << "2 " << ans << endl;
        cout.flush();
        cin >> nxt;
        //if(nxt == "No")
        //    return 0;
    } 

    return 0;
}



/*
Primes:
999999929
999999937
*/