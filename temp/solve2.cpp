#include <bits/stdc++.h>
#define MAXVAL 5
using namespace std;


int cnt[10009][MAXVAL+2], n, v[10009], ans[10009];

void gen() {
    for(int i = 0; i < n; ++i) {
        cnt[i][v[i]]++;
        if(i != 0)
            for(int j = 0; j <= MAXVAL; ++j) {
                cnt[i][j] += cnt[i-1][j];
                //cerr << i << ", " << j << " = " << cnt[i][j] << endl;
            }
    }
    for(int i = 0; i < n; ++i) {
        for(int j = 1; j <= MAXVAL; ++j) {
            cnt[i][j] += cnt[i][j-1];
            //cerr << i << ", " << j << " == " << cnt[i][j] << endl;
        }
    }
}

int Bigger(int r, int val) {
    int ret = 0;
    if(r)
        ret = cnt[r-1][MAXVAL] - cnt[r-1][val];
    return ret;
}

int Smaller(int l, int val) {
    int ret = 0;
    if(val)
        ret = cnt[n-1][val-1] - cnt[l][val-1];
    return ret;
}

void genInversion() {
    for(int i = 0; i < n; ++i) {
        ans[i] = cnt[n-1][v[i]-1] - cnt[i][v[i]-1] + (i > 0 ? ans[i-1]:0);
        //cerr << cnt[n-1][v[i]-1] << " - " << cnt[i][v[i]-1] << " :: " << v[i] << " + " << (i > 0 ? ans[i-1]:0) << endl;
    }
}

int getAns(int pos) {
    return ans[pos] - (pos ? ans[pos-1]:0);
}

int swapQuery(int l, int r) {
    if(l == r or v[l] == v[r]) return ans[n-1];
    
    //cerr << "QUERY " << l << ", " << r << " :: " << v[l] << ", " << v[r] << endl; 
    int ret = ans[n-1] - getAns(l) - getAns(r);
    //cerr << ans[n-1] << " - " << getAns(l) << " - " << getAns(r) << " = " << ret;

    ret -= Bigger(l, v[l]);
    ret -= Bigger(r, v[r]);
    
    //cerr << " - (" << Bigger(l, v[l]) << " + " << Bigger(r, v[r]) << ") = " << ret;

    ret += Smaller(r, v[l]);
    ret += Bigger(r, v[l]);
    
    ret += Smaller(l, v[r]);
    ret += Bigger(l, v[r]);

    //cerr << " + " << Smaller(l, v[r]) << " + " << Bigger(l, v[r]) << " + " << Smaller(r, v[l]) << " + " << Bigger(r, v[l]) << " = " << ret << endl;

    return ret + 1;
}

int eraseQuery(int l, int r) {
    return -1;
    if(l > r) swap(l, r);
    int ret = ans[n-1] - (ans[r] - (l > 0 ? ans[l-1]:0));

    //cerr << "QUERY " << l << " " << r << " :: " << v[l] << "  " << v[r] << " ret " << ret << endl;

    int x = 0;
    for(int i = 0; i <= MAXVAL; ++i) {
        x = (cnt[r][i] - (l > 0 ? cnt[l-1][i]:0)) - (i > 0 ? (cnt[r][i-1] - (l > 0 ? cnt[l-1][-1]:0)):0);
        if(x > 0) {
            //cerr << i << " Bigger " << Bigger(l, i) << " * " << x << endl;
            //cerr << i << " Smaller " << Smaller(r, i) << " * " << x << endl;
            ret -= Bigger(l, i)*x;
            //ret -= Smaller(r, i)*x;
            //cerr << "MINUS " << Bigger(l, i)*x+Smaller(r, i)*x << endl;
        }
    }
    return ret;
}

int main() {
    scanf("%d", &n);
    for(int i = 0; i < n; ++i) scanf("%d", &v[i]);

    gen();
    genInversion();

    for(int i = 0; i < n; ++i)
        cerr << "* " << ans[i] << " " << Bigger(i, v[i]) << " " << Smaller(i, v[i]) << endl;
    cerr << ans[n-1] << endl;


    int q, l, r, typ;
    scanf("%d", &q);
    while(q--) {
        scanf("%d%d%d", &typ, &l, &r);
        if(typ == 0)
            printf("%d\n", swapQuery(l, r));
        else
            printf("%d\n", eraseQuery(l, r));
    }

    return 0;
}

/*

6
5 4 3 2 1 0
1
2 2 4

3
5 4 0
0

*/