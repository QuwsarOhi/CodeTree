//UVa
//11576 - Scrolling Sign

#include<bits/stdc++.h>
using namespace std;

char S[110], P[110];
int s_len, p_len, T[110];

void BuiltTable()
{
    int i = 0, j = -1;
    T[0] = -1;
    while(i < p_len) {
        while(j >= 0 && P[i] != P[j])
            j = T[j];
        i++, j++;
        T[i] = j;
    }
}

int KmpSearch()
{
    int i = 0, j = 0;
    while(i < s_len) {
        while(j >= 0 && S[i] != P[j])
            j = T[j];
        i++, j++;
        if(j == p_len) {
            if(i-j == 0)
                return s_len;
            j = T[j];
        }
    }
    return j;
}

int main()
{
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);
    int t;
    scanf("%d", &t);
    while(t--) {
        int k, w;
        scanf("%d %d", &k, &w);
        bool first = 1;
        int sum = 0;
        while(w--) {
            if(first) {
                scanf(" %s", S);
                s_len = strlen(S);
                sum += s_len;
                first = 0;
                continue;
            }
            scanf(" %s", P);
            p_len = strlen(P);
            sum += p_len;
            BuiltTable();
            sum -= KmpSearch();
            if(w) {
                for(int i = 0; i < p_len; i++)
                    S[i] = P[i];
                S[p_len] = '\0';
                s_len = p_len;
            }
        }
        printf("%d\n", sum);
    }
    return 0;
}
