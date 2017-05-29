//UVa
//10945 - Mother bear
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
#define N 20000000

using namespace std;

int main()
{
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);
    char a[100000], b[100000], c[100000], d[] = "DONE";
    int len, low, i, up;
    wh(sf(" %[^\n]", a)) {
        //pf("%s\n", a);
        if(strcmp(a, d) == 0)
            break;
        len = strlen(a);
        low = len-1;
        c[len] = 0;
        up = 0;
        memset(b, 0, sizeof(b));
        memset(c, 0, sizeof(c));
        for(i = 0; i < len; i++) {
            if(isalpha(a[i])) {
                b[up] = c[up] = tolower(a[i]);
                up++;
            }
        }
        reverse(b, b+up);
        //pf("string1: %s\nstring2: %s\n", b, c);
        if(strcmp(c, b)== 0)
            pf("You won't be eaten!\n");
        else
            pf("Uh oh..\n");
    }
    return 0;
}
