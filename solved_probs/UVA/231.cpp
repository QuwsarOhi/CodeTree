// UVa
// 231 - Testing the CATCHER

#include <bits/stdc++.h>
using namespace std;

vector<int>v, LIS;

int main() {
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);
    
    int x, Case = 1;
    
    while(1) {
        while(scanf("%d", &x) and x != -1)
            v.push_back(-x);
        if(v.empty())
            break;
        
        for(auto it : v) {
            auto pIT = upper_bound(LIS.begin(), LIS.end(), it);
            if(pIT == LIS.end())
                LIS.push_back(it);
            else
                *pIT = it;
        }
        if(Case != 1)
            printf("\n");
        printf("Test #%d:\n", Case++);
        printf("  maximum possible interceptions: %d\n", LIS.size());
        LIS.clear();
        v.clear();
    }
    
    return 0;
}

