//UVa
//10646 - What is the Card?
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

int main()
{
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);
    string s;
    char a[10];
    register int x, y, v, i, t;
    sf("%d", &t);
    fr(c, 1, t+1)
    {
        stack<string>table;
        queue<string>hand;
        v = 52;
        wh(v--) {
            sf(" %s", &a);
            table.push(&a[0]);
        }
        v = 25;
        wh(v--) {
            hand.push(table.top());
            table.pop();
        }
        v = 3;
        y = 0;
        wh(v--) {
            s = table.top();
            if(isdigit(s[0])) x = s[0] - '0';
            else x = 10;
            //cout << "eliminating : " << s << endl;
            table.pop();
            y+=x;
            x = 10 - x;
            //cout << "erasing " << x << endl;
            wh(x-- && !table.empty()) table.pop();
        }
        wh(!table.empty()) {
            hand.push(table.top());
            table.pop();
        }
        v = hand.size() - y;
        wh(!hand.empty() && v--) {
            //cout << hand.front()<< endl;
            hand.pop();
        }
        cout << "Case " << c << ": " << hand.front() << "\n";
        //wh(!hand.empty()) {
            //cout << hand.front() <<endl;
            //hand.pop();
        //}
        //cout << y << endl;
    }
    return 0;
}
