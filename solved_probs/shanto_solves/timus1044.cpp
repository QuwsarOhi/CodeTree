// Timus
// 1044. Lucky Tickets. Easy!

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    int p = 1;
    for(int i = 0; i < n/2; ++i)
        p *= 10;
    int cnt[60] = {0};

    for(int i = 0; i < p; ++i) {
        int sum = 0, x = i;
        while(x) {
            sum += x%10;
            x/=10;
        }
        cnt[sum]++;
    }

    int ans=  0;
    for(int i = 0; i < 55; ++i)
        ans += cnt[i] * cnt[i];

    printf("%d\n",  ans);
    return 0;
}
