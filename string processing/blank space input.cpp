//UVa
//10252 - Common Permutation
#include <bits/stdc++.h>
using namespace std;

int main()
{
    char a[1010], b[1010];
    map<char, int>amap, bmap;
    int alen, blen, t = 1005;
    while(fgets(a, 1005, stdin)) {      //fgets is used to get the \n line, as scanf skips \n
        fgets(b, 1005, stdin);
        alen = strlen(a);
        blen = strlen(b);
        for(int i = 0; i < alen; i++)
            if(isalpha(a[i]))           //this is used to ignore the blank line (\n)
                amap[a[i]]++;
        for(int i = 0; i < blen; i++)
            if(isalpha(b[i]))
                bmap[b[i]]++;
        for(map<char, int> ::iterator it = amap.begin(); it != amap.end(); it++) {
            if(bmap[it->first] != 0) {
                //printf("got %c\n", it->first);
                int lim = min(it->second, bmap[it->first]);
                for(int i = 0; i < lim; i++)
                    printf("%c", it->first);
            }
        }
        printf("\n");
        amap.clear();
        bmap.clear();
    }
    return 0;
}
