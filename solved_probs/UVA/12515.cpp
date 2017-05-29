//UVa
//12515 - Movie Police
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

char data[1010][105], query[110];
int d_len[1010];

/*int max_hamming(int d, int data_len, int query_len)
{
    //d is the d'th data
    //int data_len = strlen(data[d]);
    //int query_len = strlen(quuery[q]);
    register int i, j, mx_ham, ham = 0;
    for(i = 0; i < query_len; i++) {
        if(data[d][i] == query[i])
            ham++;
    }
    mx_ham = ham;
    for(j = 0 ; i < data_len; i++, j++) {
        if(data[d][j] == query[j])
            ham--;
        if(data[d][i] == query[i])
            ham++;
        mx_ham = max(mx_ham, ham);
    }
    return mx_ham;
}*/

inline int max_hamming(int d, int data_len, int query_len)
{
    register int lim = data_len-query_len+1, tmp_ham, mx_ham = 0;
    //pf("runnign, query len %d\n", query_len);
    fr(i, 0, lim) {
        tmp_ham = 0;
        //pf("i is %d\n", i);
        for(register int j = 0, k = i; j < query_len; j++, k++) {
            if(data[d][k] == query[j]) {
                //pf("increasing\n");
                tmp_ham++;
            }
            //pf("%c != %c\n", data[d][k], query[j]);
        }
        mx_ham = max(tmp_ham, mx_ham);
    }
    return mx_ham;
}

int main()
{
    //frein;
    //freout;
    register int d, q, max_ham, ham, pos, q_len;
    sf("%d %d", &d, &q);
    fr(i, 0, d) {
        sf(" %[0-1]", data[i]);
        //pf(" data is %s\n", data[i]);
        d_len[i] = strlen(data[i]);
    }
    //pf("data recieved\n");
    fr(i, 0, q) {
        max_ham = 0;
        pos = 1;
        sf(" %[0-1]", query);
        //pf("query %d is %s\n", i+1, query);
        fr(j, 0, d) {
            q_len = strlen(query);
            ham = 0;
            if(d_len[j] >= q_len) {
                ham = max_hamming(j, d_len[j], q_len);
                //pf("in %d ham is %d\n", j, ham);
            }
            if(ham > max_ham) {
                pos = j+1;
                max_ham = ham;
                //pf("max_ham change %d\n", max_ham);
            }
        }
        pf("%d\n", pos);
    }
    return 0;
}
