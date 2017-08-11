//UVa
//10503 - The dominoes solitaire
#include<bits/stdc++.h>
using namespace std;

vector<pair<int, int> >v;
bitset<40>used;
int space, piece, cnt;
bool found;

bool Match(int start_pos, int check_pos)
{
    if(used[check_pos])
        return 0;
    if(v[start_pos].second == v[check_pos].first)
        return 1;
    if(v[start_pos].second == v[check_pos].second) {
        swap(v[check_pos].first, v[check_pos].second);
        return 1;
    }
    return 0;
}
void backtrack(int start_pos)
{
    if(cnt > space)
        return;
    if(cnt == space) {
        if(v[start_pos].second == v[1].first)
            found = 1;
        /*if(found) {
            for(int i = 0; i < v2.size(); i++)
                printf("%d %d\n", v2[i].first, v2[i].second);
        }*/
    }
    for(int i = 2; i < v.size(); i++) {
        if(found) return;
        if(Match(start_pos, i)) {
            cnt++;
            used[i] = 1;
            //v2.push_back(v[i]);
            backtrack(i);
            used[i] = 0;
            //v2.pop_back();
            cnt--;
        }
    }
}

int main()
{
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);
    int x, y;
    while(scanf("%d", &space) && space) {
        scanf("%d", &piece);
        scanf("%d %d", &x, &y);
        v.push_back(make_pair(x, y));   //saving the starting point to 0 position
        scanf("%d %d", &x, &y);
        v.push_back(make_pair(x, y));   //saving the ending point to 1 position
        for(int i = 0; i < piece; i++) {
            scanf("%d %d", &x, &y);
            v.push_back(make_pair(x, y));
        }
        found = 0;
        cnt = 0;
        used.reset();
        backtrack(0);
        if(!found) {
            swap(v[0].first, v[0].second);
            used.reset();
            cnt = 0;
            backtrack(0);
        }
        if(found) printf("YES\n");
        else printf("NO\n");
        v.clear();
    }
    return 0;
}
