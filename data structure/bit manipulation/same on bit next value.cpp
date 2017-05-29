//LightOJ
//1042 - Secret Origins
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t, n;
    scanf("%d", &t);
    for(int Case = 1; Case <= t; Case++) {
        scanf("%d", &n);
        vector<int>v;
        while(n >= 2) {
            v.push_back(n % 2);
            n /= 2;
        }
        v.push_back(n);
        v.push_back(0);
        reverse(v.begin(), v.end());
        next_permutation(v.begin(), v.end());
        int ans = 0, pos = 0;
        for(int i = v.size()-1; i >= 0; i--) {
            if(v[i])
                ans |= (1 << pos);
            pos++;
        }
        printf("Case %d: %d\n", Case, ans);
    }
    return 0;
}
