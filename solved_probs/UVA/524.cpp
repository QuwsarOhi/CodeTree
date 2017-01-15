//UVa
//524 - Prime Ring Problem
#include<bits/stdc++.h>
using namespace std;
bitset<35>prime, mark;
vector<int>v;
int n;
void backtrack(int past_num)
{
    if(v.size() == n && prime[v.back()+1])
        for(int j = 0; j < v.size(); j++) {
            if(j == v.size()-1) printf("%d\n", v[j]);
            else printf("%d ", v[j]);
        }
    for(int i = 2 ; i <= n; i++)
        if(prime[past_num+i] && !mark[i]) {
            mark[past_num] = mark[i] = 1;
            if(v.empty()) v.push_back(past_num);
            v.push_back(i);
            backtrack(i);
            mark[i] = 0;
            v.pop_back();
        }
}

int main()
{
    register int t = 1;
    prime.reset();
    prime[2] = prime[3] = prime[5] = prime[7] = prime[11] = prime[13] = prime[17] = prime[19] = prime[23] = prime[29] = prime[31] = 1;
    while(scanf("%d", &n) != EOF) {
        if(t != 1) printf("\n");
        printf("Case %d:\n", t);
        mark.reset();
        backtrack(1);
        v.clear();
        t++;
    }
    return 0;
}
