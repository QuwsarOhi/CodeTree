//UVa
//10338 - Mischievous Children
#include<bits/stdc++.h>
using namespace std;

int main()
{
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);
    int t;
    scanf("%d", &t);
    for(int Case = 1; Case <= t; Case++) {
        char a[60];
        map<char, int>mp;
        scanf(" %s", a);
        int len = strlen(a);
        long long ans = 1;
        for(int i = 0; i < len; i++) {
            mp[a[i]]++;
            ans *= i+1;
        }
        for(map<char, int> :: iterator it = mp.begin(); it != mp.end(); it++)
            if(it->second > 1) {
                int tmp = it->second;
                while(tmp > 1) {
                    ans /= tmp;
                    tmp--;
                }
            }
        printf("Data set %d: %lld\n", Case, ans);
    }
}
