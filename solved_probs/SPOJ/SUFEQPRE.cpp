// SPOJ
// SUFEQPRE

#include <bits/stdc++.h>
#define MAX 1000100
using namespace std;
 
void prefixTable(int n, char pat[], int table[]) {
    int len = 0, i = 1;                     // length of the previous longest prefix suffix
    table[0] = 0;                           // table[0] is always 0
    while (i < n) {
        if (pat[i] == pat[len]) {
            len++;
            table[i] = len;
            i++;
        }
        else {                                                      // pat[i] != pat[len]
            if(len != 0)    len = table[len-1];                     // find previous match
            else            table[i] = 0, i++;                      // if (len == 0) and mismatch
}}}
 
char str[MAX];
int table[MAX];
 
int main() {
    int t;
    scanf("%d", &t);
 
    for(int Case = 1; Case <= t; ++Case) {
        scanf("%s", str);
        int len = strlen(str);
        prefixTable(len, str, table);
 
        int p = table[len-1], cnt = 0;
        while(p != 0) {
            p = table[p-1];
            ++cnt;
        }
        printf("Case %d: %d\n", Case, cnt);
    }
    return 0;
}
 
