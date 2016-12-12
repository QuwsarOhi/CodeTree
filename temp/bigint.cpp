
#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define pi acos(-1)
#define fr(i, a, b) for(register int i = a; i < b; i++)
#define f1(i, b) for(register int i = 1; i <= b; i++)
#define ss stringstream
#define mimx(a, b) if(a > b)swap(a, b)
#define msi map<string, int>
#define mii map<int, int>
#define vec vector<int>
#define fio ios_base::sync_with_stdio(false); cin.tie(NULL);
#define sf scanf
#define pf printf
#define wh while
#define inf std::numeric_limits<int>::max()
#define ll long long
#define N 9876543210
#define frein freopen("in", "r", stdin);
#define freout freopen("out", "w", stdout);

using namespace std;

int main()
{
    int lim = 7, cnt = 0, roll = 0;
    fr(i, 1, lim)
        fr(j, 1, lim) {
            if(j == i) continue; //pf("i: %d j: %d\n", i, j);
            fr(k, 1, lim) {
                if(k ==i || k == j) continue; //pf("k: %d\n", k);
                fr(l, 1, lim) {
                    if(l == i || l ==j || l == k) continue; //pf("l: %d\n", l);
                    fr(m, 1, lim) {
                        if(m == i || m == j || m ==k || m == l) continue; //pf("i: %d j: %d k: %d l: %d m: %d\n", i, j, k, l, m);
                        fr(n, 1, lim) {
                            if(n == i || n ==j || n == k || n ==l || n == m) continue;
                            if(i+n == 7 && j+m == 7 && k+l ==7) {
                            pf("%d %d %d %d %d %d\n", i, j, k, l, m, n);
                            roll++;
                            }
                            cnt++;
                        }
                    }
                }
            }
        }
    pf("%d iterations, %d dice rolls\n", cnt, roll);
    return 0;
}
