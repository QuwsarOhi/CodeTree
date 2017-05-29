//UVa
//156 - Ananagrams
#include <bits/stdc++.h>
#define pb push_back
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

using namespace std;
char a[1000], b[1000];
void lower()
{
    int lim = sizeof(a);
    memset(b, 0, sizeof(b));
    for(int i = 0; i < lim ; i++)
        b[i] = tolower(a[i]);
}

bool cmp(string x, string y)
{
    if(lexicographical_compare(x.begin(), x.end(), y.begin(), y.end()))
        return 1;
    else
        return 0;
}

bool alp(string x, string y)
{
    if(x[0] > y[0])
        return 0;
    else
        return 1;
}

int main()
{
    char a[1000];
    map<string, int>m1;
    map<string, string>m2;
    string p , q, r;
    vector<string>v;
    bool b = 0;
    wh(!getline(cin, p).eof()) {
        ss s;
        s << p;
        wh(s >> p) {
            if(p[0] == '#') {
                b = 1;
                break;
            }
            q = p;
            transform(q.begin(), q.end(), q.begin(), ::tolower);
            sort(q.begin(), q.end());
            m1[q]++;
            m2[q] = p;
            //cout << p << " " << q << endl;
        }
        if(b) break;
    }
    //cout << "map1 size " <<m1.size() << endl;
    //cout << "map2 size " <<m2.size() << endl;
        for(map<string, int>:: iterator it = m1.begin(); it != m1.end(); it++) {
            if(it->second == 1)
                v.pb(m2[it->first]);
           // cout << it->first << " : " << it->second << "\n";
        }
        sort(v.begin(), v.end(), cmp);
        for(int i = 0; i < v.size(); i++)
            cout << v[i] << "\n";
        //cout << v.size() << endl;
    return 0;
}
