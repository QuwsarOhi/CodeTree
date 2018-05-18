#include <bits/stdc++.h>
using namespace std;

long long len;
char s[30];

bool isPalindrome(long long mask) {
    for(int l = 0, r = len-1; l < r; ) {
        if(!(mask & (1LL << l))) {
            ++l;
            continue;
        }
        if(!(mask & (1LL << r))) {
            --r;
            continue;
        }
        if(s[l] != s[r])
            return 0;
        
        ++l, --r;
    }
    return 1;
}


long long recur(int l, long long mask) {
    long long ret = isPalindrome(mask);
    for(int i = l; i < len; ++i)
        if(mask & (1LL << i)) 
            ret += recur(i, mask ^ (1LL << i));
    return ret;
}


int main() {
    scanf("%s", s);
    len = strlen(s);
    printf("%lld\n", recur(0, (1LL << len)-1)-1);
    return 0;
}
