// SOPJ
// FILRTEST - File Recover Testing

#include <bits/stdc++.h>
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
        else {                              // pat[i] != pat[len]
            if (len != 0)                   // find previous match
                len = table[len-1];
            else                            // if (len == 0) and mismatch
                table[i] = 0, i++;          // set table[i] = 0, and go to next index
        }
    }
}


int main() {
    int k, len, table[1000100];
    char s[1000100];
    
    while(1) {
        scanf("%d %s", &k, s);
        if(k == -1)
            break;
        len = strlen(s);
        prefixTable(len, s, table);
        if(k < len)
            printf("0\n");
        else if(table[len-1] == 0) 
            printf("%d\n", k/len);
        else {
            int add = len-table[len-1];
            int cnt = 1 + (k-len)/add;
            printf("%d\n", cnt);
        }
    }
    return 0;
}
