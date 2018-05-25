// UVa
// 167 - The Sultan's Successors

#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int> >places;
vector<vector<pair<int, int> > >patt;

int mat[8][8];

int col[8];
bool place(int r, int c) {
    for(int prev = 0; prev < r; ++prev)
        if(col[prev] == c or abs(col[prev] - c) == (r-prev))
            return 0;
    return 1;
}

void genQueen(int r) {
    if(r == 8) {
        patt.push_back(places);
        return;
    }
    
    for(int c = 0; c < 8; ++c)
        if(place(r, c)) {
            places.push_back({r, c});
            col[r] = c;
            genQueen(r+1);
            places.pop_back();
        }
}

int TryAll() {
    int ans = -1, sum;
    for(int i = 0; i < (int)patt.size(); ++i) {
        sum = 0;
        for(int j = 0; j < (int)patt[i].size(); ++j)
            sum += mat[patt[i][j].first][patt[i][j].second];
        ans = max(ans, sum);
    }
    return ans;
}

int main() {
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);
    
    int n;
    genQueen(0);
    //cout << "DONE with " << patt.size() << endl;
    
    while(scanf("%d", &n) == 1) {
        while(n--) {
            for(int i = 0; i < 8; ++i)
                for(int j = 0; j < 8; ++j)
                    scanf("%d", &mat[i][j]);
            printf("%5d\n", TryAll());
        }
    }
    return 0;
}
