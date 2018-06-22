#include <bits/stdc++.h>
using namespace std;


void BottomUp(int TOT) {
    memset(dp, 0, sizeof dp);
    
    int state = 0;
    for(int i = 0; i < n; ++i) {
        state ^= 1;
        for(int sum = 0; sum <= TOT; ++sum) {
            int mx = 0;
            
