#include "bits/stdc++.h"  
using namespace std;  
  
#define ll            long long int  
#define endl          '\n'  
  
static const int maxn = 1e6 + 5;  
static const ll mod = 1e9 + 7;  
static const int Max = 1e6 + 7;  
  
int N;  
ll Tree[maxn];  
  
ll add(ll a, ll b)  
{  
      a = (a + b + mod) % mod;  
      return a;  
}  
  
void update(int pos, ll val)  
{  
      while (pos <= N)  
      {  
            Tree[pos] = add(Tree[pos], val);  
            pos += (pos & -pos);  
      }  
}  
  
void rangeUpdate(int l, int r, ll val)  
{  
      update(l, val);  
      update(r + 1, -val);  
}  
  
ll query(int pos)  
{  
      ll sum = 0;  
      while (pos > 0)  
      {  
            sum = add(sum, Tree[pos]);  
            pos -= (pos & -pos);  
      }  
      return sum;  
}  
  
struct state  
{  
      int len, link;  
      map <char, int> next;  
} st[Max * 2];  
  
int sz, last;  
  
void init()  
{  
      sz = last = 0;  
      st[0].len = 0;  
      st[0].link = -1;  
      st[0].next.clear();  
      for (int i = 1; i < Max * 2; i++)  
      {  
            st[i].len = 0;  
            st[i].link = 0;  
            st[i].next.clear();  
      }  
      ++sz;  
}  
  
void szExtend(char c)  
{  
      int l, r;  
      int cur = sz++;  
      st[cur].len = st[last].len + 1;  
      int p;  
      for (p = last; p != -1 && !st[p].next.count(c); p = st[p].link)  
      {  
            st[p].next[c] = cur;  
      }  
      if (p == -1)  
      {  
            st[cur].link = 0;  
      }  
      else  
      {  
            int q = st[p].next[c];  
            if (st[p].len + 1 == st[q].len)  
            {  
                  st[cur].link = q;  
            }  
            else  
            {  
                  int clone = sz++;  
                  st[clone].len = st[p].len + 1;  
                  st[clone].next = st[q].next;  
                  st[clone].link = st[q].link;  
                  for ( ; p != -1 && st[p].next[c] == q; p = st[p].link)  
                  {  
                        st[p].next[c] = clone;  
                  }  
                  l = st[ st[q].link ].len;  
                  r = st[q].len;  
                  assert(l+1 <= r);  
                  rangeUpdate(l+1, r, -1);  
                  st[q].link = st[cur].link = clone;  
                  l = st[ st[q].link ].len;  
                  r = st[q].len;  
                  assert(l+1 <= r);  
                  rangeUpdate(l+1, r, 1);  
                  l = st[ st[clone].link ].len;  
                  r = st[clone].len;  
                  assert(l+1 <= r);  
                  rangeUpdate(l+1, r, 1);  
            }  
      }  
      l = st[ st[cur].link ].len;  
      r = st[cur].len;  
      assert(l+1 <= r);  
      rangeUpdate(l+1, r, 1);  
      last = cur;  
}  
  
ll power[Max];  
ll powerSum[Max];  
ll sum[Max];  
ll cumsum[Max];  
  
int main()  
{  
      ios_base::sync_with_stdio(false);  
      cin.tie(nullptr);  
      cout.tie(nullptr);  
      cout << fixed << setprecision(12);  
  
//      #ifndef ONLINE_JUDGE  
//            freopen("in.txt", "r", stdin);  
//      #endif // ONLINE_JUDGE  
  
      power[0] = 1LL;  
      powerSum[0] = 0LL;  
      for (int i = 1; i < Max; i++)  
      {  
            power[i] = (power[i-1] * 26) % mod;  
            powerSum[i] = (powerSum[i-1] + power[i]) % mod;  
      }  
  
      int tc;  
      cin >> tc;  
      for (int tcase = 1; tcase <= tc; tcase++)  
      {  
            string s;  
            cin >> s;  
            int len = s.size();  
            N = len;  
            init();  
            for (char ch : s) szExtend(ch);  
            for (int i = 1; i <= len; i++)  
            {  
                  sum[i] = query(i);  
                  cumsum[i] = add(cumsum[i-1], sum[i]);  
            }  
            cout << "Case " << tcase << ":" << endl;  
            int q;  
            cin >> q;  
            while (q--)  
            {  
                  int l, r;  
                  cin >> l >> r;  
                  ll tsub = (powerSum[r] - powerSum[l-1] + mod) % mod;  
                  ll dsub = (cumsum[r] - cumsum[l-1] + mod) % mod;
                  cout << tsub << " " << dsub << endl;
                  ll ans = (tsub - dsub + mod) % mod;  
                  cout << ans << endl;  
            }  
            for (int i = 0; i <= N; i++) Tree[i] = 0;  
      }  
}  