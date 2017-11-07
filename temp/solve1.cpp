#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<pair<ll, ll>>tree;
string s;

void init(int L, int R, int pos) {
    if(L == R) {
        tree[pos].first = s[L]-'0';
        tree[pos].second = -1;
        return;
    }
    
    int mid = (L+R)>>1;
    
    init(L, mid, pos<<1);
    init(mid+1, R, pos<<1|1);
    
    tree[pos].first = tree[pos<<1].first + tree[pos<<1|1].first;
    tree[pos].second = -1;
}

void updateOn(int L, int R, int l, int r, int pos) {
    if(R < l || r < L)
        return;
    
    cout << L << " " << R << endl;
    
    if(l <= L && R <= r) {
        tree[pos].first = (R-L+1);
        tree[pos].second = 1;
        return;
    }
    
    int mid = (L+R)>>1;
    
    updateOn(L, mid, l, r, pos<<1);
    updateOn(mid+1, R, l, r, pos<<1|1);
    
    tree[pos].first = tree[pos<<1].second == 1 ? (mid-L+1) : (tree[pos<<1].second == 0 ? 0 : tree[pos<<1].first);
    tree[pos].first += tree[pos<<1|1].second == 1 ? (R-mid) : (tree[pos<<1|1].second == 0 ? 0 : tree[pos<<1|1].first);
    tree[pos].second = -1;
}

void updateOff(int L, int R, int l, int r, int pos) {
    if(R < l || r < L)
        return;
    
    if(l <= L && R <= r) {
        tree[pos].first = 0;
        tree[pos].second = 0;
        return;
    }
    
    int mid = (L+R)>>1;
    
    updateOff(L, mid, l, r, pos<<1);
    updateOff(mid+1, R, l, r, pos<<1|1);
    
    tree[pos].first = tree[pos<<1].second == 0 ? 0 : (tree[pos<<1].second == 1 ? (mid-L+1) : tree[pos<<1].first);
    tree[pos].first += tree[pos<<1|1].second == 0 ? 0 : (tree[pos<<1|1].second == 1 ? (R-mid) : tree[pos<<1|1].first);
    tree[pos].second = -1;
}

void updateFlip(int L, int R, int l, int r, int pos, int prop) {
    if(R < l || r < L)
        return;
    
    cout << L << " " << R << " " << prop << endl;
    
    if(L == R) {
        if(prop == 1)
            tree[pos].first = 0;
        else if(prop == 0)
            tree[pos].first = 1;
        else
            tree[pos].first = tree[pos].first == 1 ? 0:1;
        tree[pos].second = -1;
        return;
    }
    
    int mid = (L+R)>>1;
    
    updateFlip(L, mid, l, r, pos<<1, tree[pos].second);
    updateFlip(mid+1, R, l, r, pos<<1|1, tree[pos].second);
    
    //tree[pos].first = tree[pos].second == -1 ? tree[pos<<1].first : (tree[pos].second == 0 ? 0 : 1);
    //tree[pos].first += tree[pos].second == -1 ? tree[pos<<1|1].first : (tree[pos].second == 0 ? 0 : 1);
    //tree[pos].second = -1;
    tree[pos].first = tree[pos<<1].first + tree[pos<<1|1].first;
    tree[pos].second = -1;
}

int queryOn(int L, int R, int l, int r, int pos) {
    if(R < l || r < L || L > R)
        return 0;
    
    if(L==R)
        return tree[pos].first;
    
    if(l <= L && R <= r) {
        //cout << "on " << L << " " << R << " - " << tree[pos].second << endl; 
        if(tree[pos].second != -1)
            return (R-L+1)*tree[pos].second;
        else
            return queryOn(L, (L+R)/2, l, r, pos<<1) + queryOn(((L+R)/2)+1, R, l, r, pos<<1|1);
    }
    
    int mid = (L+R)>>1;
    
    int lft = queryOn(L, mid, l, r, pos<<1);
    int rht = queryOn(mid+1, R, l, r, pos<<1|1);
    
    return lft+rht;
}

void printer(int node) {
    cout << "NODES" << endl;
    for(int i = 1; i <= node; ++i) {
        cout << i << " :: " << tree[i].first << " - " << tree[i].second << endl;
    }
}

int main() {
    //freopen("in", "r", stdin);
    
    int t, l, r, x, y, q;
    char s1[60], c;
    
    scanf("%d", &t);
    
    for(int Case = 1; Case <= t; ++Case) {
        scanf("%d", &x);
        s = " ";
        while(x--) {
            scanf("%d", &y);
            scanf(" %s", s1);
            while(y--)
                s += string(s1);
        }
        tree.resize(s.size()*4);
        init(1, (int)s.size(), 1);
        printf("Case %d:\n", Case);
        scanf("%d", &q);
        int Query = 1;
        cout << "1 to " << s.size() << endl;
        while(q--) {
            scanf(" %c %d %d", &c, &l, &r);
            ++l, ++r;
            if(c == 'F')
                updateOn(1, (int)s.size()-1, l, r, 1);
            else if(c == 'E')
                updateOff(1, (int)s.size()-1, l, r, 1);
            else if(c == 'I')
                updateFlip(1, (int)s.size()-1, l, r, 1, tree[1].second);
            else {
                printf("Q%d: ", Query++);
                printf("%d\n", queryOn(1, (int)s.size()-1, l, r, 1));
            }
            printer(12);
        }
    }
    
    return 0;
}

/*
1
1
3
10
100
*/
