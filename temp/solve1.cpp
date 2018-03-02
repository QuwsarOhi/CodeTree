#include <bits/stdc++.h>
using namespace std;
#define MAX                 1000
#define EPS                 1e-9
#define INF                 1e7
#define MOD                 1000000007
#define pb                  push_back
#define mp                  make_pair
#define fi                  first
#define se                  second
#define pi                  acos(-1)
#define sf                  scanf
#define pf                  printf
#define SIZE(a)             ((int)a.size())
#define All(S)              S.begin(), S.end()              
#define Equal(a, b)         (abs(a-b) < EPS)
#define Greater(a, b)       (a >= (b+EPS))
#define GreaterEqual(a, b)  (a > (b-EPS))
#define fr(i, a, b)         for(register int i = (a); i < (int)(b); i++)
#define FastRead            ios_base::sync_with_stdio(false); cin.tie(NULL);
#define fileRead(S)         freopen(S, "r", stdin);
#define fileWrite(S)        freopen(S, "w", stdout);
#define Unique(X)           X.erase(unique(X.begin(), X.end()), X.end())
#define error(args...)      { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }

#define isOn(S, j)          (S & (1 << j))
#define setBit(S, j)        (S |= (1 << j))
#define clearBit(S, j)      (S &= ~(1 << j))
#define toggleBit(S, j)     (S ^= (1 << j))
#define lowBit(S)           (S & (-S))
#define setAll(S, n)        (S = (1 << n) - 1)

typedef unsigned long long ull;
typedef long long ll;
typedef map<int, int> mii;
typedef map<ll, ll>mll;
typedef map<string, int> msi;
typedef vector<int> vi;
typedef vector<long long>vl;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<pair<int, int> > vii;
typedef vector<pair<ll, ll> >vll;

void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {                                                  // Debugger error(a, b, ....)
	cerr << *it << " = " << a << "\n";
	err(++it, args...);
}

//const int dx[4][2] = {{0,1}, {0,-1}, {1,0}, {-1,0}};                                                      // Four side 
//const int dxx[8][2] = {{0,1}, {0,-1}, {1,0}, {-1,0}, {1,1}, {1,-1}, {-1,1}, {-1,-1}};                     // Eight side
//----------------------------------------------------------------------------------------------------------

struct node {
	int start, end;
	int length;
	int edge[26];
	int suffixEdg;
};


struct PalinTree {
    int currNode;
    string s;                           // Contains the string
    int ptr, mxLen;
    node root1, root2, tree[MAX];
    
    PalinTree() {
        s.clear();
        root1.length = -1;
        root1.suffixEdg = 1;
        root2.length = 0;
        root2.suffixEdg = 1;

        tree[1] = root1;
        tree[2] = root2;
        ptr = 2;
        currNode = 1;
        mxLen = 0;
    }
    
    void insert(int idx) {
        int tmp = currNode;
        while(1) {
            int curLength = tree[tmp].length;
            if(idx - curLength >= 1 && s[idx] == s[idx-curLength-1])
                break;
            tmp = tree[tmp].suffixEdg;
        }
    
        if(tree[tmp].edge[s[idx]-'a'] != 0) {
            currNode = tree[tmp].edge[s[idx]-'a'];
            return;
        }
    
        ptr++;
        tree[tmp].edge[s[idx]-'a'] = ptr;
        tree[ptr].length = tree[tmp].length + 2;
        tree[ptr].end = idx;
        tree[ptr].start = idx - tree[ptr].length + 1;
        tmp = tree[tmp].suffixEdg;
        currNode = ptr;
        
        if(tree[currNode].length == 1) {
            tree[currNode].suffixEdg = 2;
            return;
        }
    
        while(1) {
            int curLength = tree[tmp].length;
            if(idx-curLength >= 1 && s[idx] == s[idx-curLength-1])
                break;
            tmp = tree[tmp].suffixEdg;
        }
    
        tree[currNode].suffixEdg = tree[tmp].edge[s[idx]-'a'];
    }
    
    void buildTree() {          // Builds Palindrome Tree of string s
        for(int i = 0; i < (int)s.length(); ++i)
            insert(i);
    }
    
    void CalMaxLen() {
        for(int i = 3; i <= ptr; ++i)
            mxLen = max(mxLen, tree[i].end - tree[i].start);
    }
    
    string MaxLenPalin() {
        string mxstr;
        //CalMaxLen();
        
        bool isFirst = 1;
        
        for(int i = 3; i <= ptr; ++i)
            if(mxLen == tree[i].end - tree[i].start) {
                for(int j = tree[i].start, k = 0; j <= tree[i].end; ++j, ++k) {
                    bool isSmall = 0;
                    if(isFirst)
                        mxstr.push_back(s[j]);
                    else {
                        if(isSmall)
                            mxstr[k] = s[j];
                        else if(mxstr[k] > s[j]) {
                            mxstr[k] = s[j];
                            isSmall = 1;
                        }
                    }
                }
                isFirst = 0;
            }
        return mxstr;
    }
    
};


int main() {
    FastRead;
    PalinTree pt;
    
	cin >> pt.s;
    pt.buildTree();
    

	/*cout << "All distinct palindromic substring for "
		<< pt.s << " : \n";
	for(int i=3; i<=pt.ptr; i++) {
		cout << i-2 << ") ";
		for (int j=pt.tree[i].start; j<=pt.tree[i].end; j++)
			cout << pt.s[j];
		cout << endl;
	}*/
    
    int mxLen = 1e8;
    for(int i = 3; i <= pt.ptr; ++i) {
        int len = pt.tree[i].end - pt.tree[i].start;
        if(len >= 1)
            mxLen = min(mxLen, pt.tree[i].end - pt.tree[i].start);
    }
    
    if(mxLen == 0 || mxLen == 1e8) {
        cout << "-1\n";
        return 0;
    }
    
    string mnstr;
    for(int i = 3; i <= pt.ptr; ++i) {
        if(mxLen == pt.tree[i].end - pt.tree[i].start) {
            string tmp;
            for(int j = pt.tree[i].start; j <= pt.tree[i].end; ++j)
                tmp.push_back(pt.s[j]);
            if(mnstr.empty() || mnstr > tmp)
                mnstr = tmp;
        }
    }
    
    cout << mnstr << endl;

	return 0;
}
