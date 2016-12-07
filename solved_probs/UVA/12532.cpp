//UVa
//12532 - Interval Product
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
#define N 100050
#define frein freopen("in", "r", stdin);
#define freout freopen("out", "w", stdout);

using namespace std;

int arr[N], tree[4*N];

void segment_build(int pos, int L, int R)
{
    tree[pos] = 0;
    if(L==R) {
        tree[pos] = arr[L];
        return;
    }
    int mid = (L+R)/2;
    segment_build(pos*2, L, mid);
    segment_build(pos*2+1, mid+1, R);
    tree[pos] = tree[pos*2] * tree[pos*2+1];
}

void segment_update(int pos, int L, int R, int i, int val)
{
    if(L==R) {
        tree[pos] = val;
        return;
    }
    int mid = (L+R)/2;
    if(i <= mid) segment_update(pos*2, L, mid, i, val);
    else segment_update(pos*2+1, mid+1, R, i, val);
    tree[pos] = tree[pos*2] * tree[pos*2+1];
}

int segment_query(int pos, int L, int R, int l, int r)
{
    if(R < l || r < L) return 1;
    if(l <= L && R <= r) return tree[pos];
    int mid = (L+R)/2;
    int x = segment_query(pos*2, L, mid, l, r);
    int y = segment_query(pos*2+1, mid+1, R, l, r);
    //pf("pos %d x: %d y: %d\n", pos, x, y);
    return x*y;
}

void printer(int x)
{
    if(x > 0) pf("+");
    else if(x < 0) pf("-");
    else pf("0");
}

int main()
{
    //frein;
    //freout;
    int n, q, l, r, j, val;
    char c;
    //bool first = 1;
    memset(arr, 0, sizeof(arr));
    memset(tree, 0, sizeof(tree));
    wh(sf(" %d %d", &n, &q) != EOF) {
        //first = 0;
        fr(i, 1, n+1) {
            sf(" %d", &val);
            if(val > 0) val = 1;
            else if(val == 0) val = 0;
            else val = -1;
            //pf("st %d\n", val);
            arr[i] = val;
        }
        segment_build(1, 1, n);
        wh(q--) {
            sf(" %c", &c);
            if(tolower(c) == 'c') {
                sf(" %d %d", &j, &val);
                if(val > 0) val = 1;
                else if(val == 0) val = 0;
                else val = -1;
                //pf("sg val %d\n", val);
                segment_update(1, 1, n, j, val);
            }
            else {
                sf(" %d %d", &l, &r);
                //pf("l: %d r: %d\n", l, r);
                printer(segment_query(1, 1, n, l, r));
            }
        }
        pf("\n");
    }
    return 0;
}
