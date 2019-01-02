// UVa
// 10817 - Headmaster's Headache

#include <bits/stdc++.h>
#define isON(xx, jj)    (xx & (1 << jj))
#define ON(xx, jj)      (xx |= (1 << jj))
#define INF             0x3f3f3f3f
#define MAX             110
using namespace std;

vector<int>sub[MAX];
int cst[MAX], S, M, N;

void P(int x) {
    bitset<4>b(x);
    cout << b << endl;
}

int dp[101][(1 << 8) + 2][(1 << 8) + 2], vis[101][(1 << 8) + 2][(1 << 8) + 2], visCnt;


int recur(int pos, int mask0, int mask1) {
    if(mask0 == (1 << S)-1 and mask1 == (1 << S)-1)
        return 0;
    if(pos >= N)
        return INF;

    int &ret = dp[pos][mask0][mask1];

    if(vis[pos][mask0][mask1] == visCnt)
        return ret;
    vis[pos][mask0][mask1] = visCnt;

    ret = recur(pos+1, mask0, mask1);

    for(auto it : sub[pos]) {
        if(not isON(mask0, it))
            ON(mask0, it);
        else if(not isON(mask1, it))
            ON(mask1, it);
    }

    ret = min(ret, recur(pos+1, mask0, mask1)+cst[pos]);
    return ret;
}

int main() {
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);

    int x, mask0, mask1, totCost;
    string s;
    stringstream ss;

    while(1) {
        cin >> S >> M >> N;

        if(S == 0) break;
        mask0 = mask1 = totCost = 0;
        cin.ignore();

        for(int i = 0; i < M; ++i) {
            getline(cin, s);
            ss.clear();
            ss << s;

            ss >> x;
            totCost += x;

            while(ss >> x) {
                x--;
                if(not isON(mask0, x))
                    ON(mask0, x);
                else
                    ON(mask1, x);
            }
        }

        for(int i = 0; i < N; ++i) {
            getline(cin, s);
            ss.clear();
            ss << s;
            ss >> cst[i];

            sub[i].clear();
            while(ss >> x)
                sub[i].push_back(x-1);
        }

        //P(mask0), P(mask1);
        //cout << totCost << endl;
        visCnt++;
        cout << totCost+recur(0, mask0, mask1) << endl;
    }

    return 0;
}

