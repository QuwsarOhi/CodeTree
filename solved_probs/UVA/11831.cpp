//UVa
//11831 Sticker Collector Robots
#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define PI acos(-1)
#define fr(i, a, b) for(register int i = a; i < b; i++)
#define f1(i, b) for(register int i = 1; i <= b; i++)
#define ss stringstream
#define mimx(a, b) if(a > b)swap(a, b)
#define msi map<string, int>
#define mii map<int, int>
#define vec vector<int>
#define fio ios_base::sync_with_stdio(false); cin.tie(NULL);
#define sf scanf
#define pf printf
#define wh while
#define inf std::numeric_limits<int>::max()
#define ll long long
#define ui unsigned int
#define vi vector<int>
#define ii pair<int, int>
#define vii vector<pair<int, int> >
#define ull unsigned long long
#define N 500000
#define EPS 1e-9
#define frein freopen("in", "r", stdin);
#define freout freopen("out", "w", stdout);

using namespace std;

int direction, posr, posc, R, C, command, g[110][110], cnt;
char cmd;

void change_direct(char x) {
    if(x == 'N') direction = 1; //NORTH
    else if(x == 'L') direction = 2; //EAST
    else if(x == 'S') direction = 3; //SOUTH
    else if(x == 'O') direction = 4; //WEST
    else if(x == 'D') ++direction; //RIGHT
    else if(x == 'E') --direction; //LEFT
    if(direction > 4) direction = 1;
    if(direction < 1) direction = 4;
}

void sticker() {
    if(g[posr][posc] == '*') {
        ++cnt;
        g[posr][posc] = '.';
}}

void walk() {
    if(direction == 1 && g[posr-1][posc] != '#' && posr-1 >= 0) --posr, sticker();
    if(direction == 2 && g[posr][posc+1] != '#' && posc+1 < C) ++posc, sticker();
    if(direction == 3 && g[posr+1][posc] != '#' && posr+1 < R) ++posr, sticker();
    if(direction == 4 && g[posr][posc-1] != '#' && posc-1 >= 0) --posc, sticker();
}

int main()
{
    //frein;
    //freout;
    wh(sf("%d %d %d", &R, &C, &command) && (R || C || command)) {
        cnt = 0;
        //pf("%d %d %d\n", R, C, command);
        memset(g, 0, sizeof(g));
        fr(i, 0, R) fr(j, 0, C) {
            sf(" %c", &g[i][j]);
            if(g[i][j] == 'N' || g[i][j] == 'S' || g[i][j] == 'L' || g[i][j] == 'O') {
                change_direct(g[i][j]);
                posr = i;
                posc = j;
            }
        }
        fr(i, 0, command) {
            sf(" %c", &cmd);
            if(cmd == 'F') walk();
            else change_direct(cmd);
        }
        pf("%d\n", cnt);
    }
        return 0;
}
