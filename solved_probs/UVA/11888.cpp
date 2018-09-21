// UVa
// 11888	Abnormal 89's
// KMP / HASH

#include <bits/stdc++.h>
using namespace std;
#define MAX                 200010
#define EPS                 1e-9
#define INF                 1e7
#define pb                  push_back
#define mp                  make_pair
#define xx                  first
#define yy                  second
#define pi                  acos(-1)
#define sf                  scanf
#define pf                  printf
#define SIZE(a)             ((int)a.size())
#define All(S)              S.begin(), S.end()
#define Equal(a, b)         (abs(a-b) < EPS)
#define Greater(a, b)       (a >= (b+EPS))
#define GreaterEqual(a, b)  (a > (b-EPS))
#define fr(i, a, b)         for(register int i = (a); i < (int)(b); i++)
#define FastRead            ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define fileRead(S)         freopen(S, "r", stdin);
#define fileWrite(S)        freopen(S, "w", stdout);
#define Unique(X)           X.erase(unique(X.begin(), X.end()), X.end())

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

#include <ext/pb_ds/assoc_container.hpp>    // rb_tree_tag
#include <ext/pb_ds/tree_policy.hpp>        // tree_order_statistics_node_update
#define at(X)          find_by_order(X)
#define lessThan(X)    order_of_key(X)
using namespace std;
using namespace __gnu_pbds;
template<class T> using ordered_set = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

//int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};
//int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1}, dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};
//----------------------------------------------------------------------------------------------------------

void PrefixTable(int n, char str[], int table[]) {
	int i = 1, len = 0;
	table[0] = 0;
	while(i < n) {
		if(str[i] == str[len]) {
			len++;
			table[i++] = len;
		}
		else {
			if(len != 0) 	len = table[len-1];
			else			table[i++] = 0;
}}}

bool isAlindrome, isPalindrome;

void KMP(int strLen, int pattLen, char str[], char patt[], int table[]) {
	int i = 0, len = 0;
	//cerr << strLen << " " << pattLen << endl;
	while(i < strLen) {
		if(str[i] == patt[len]) ++i, ++len;
		if(len == pattLen) {
			//cerr << "AT " << i << endl;
			if(i > pattLen and i < strLen)
				isAlindrome = 1;
			else if(i == pattLen)
				isPalindrome = 1;
			len = table[len-1];
		}
		else if(i < strLen and str[i] != patt[len]) {
			if(len != 0)	len = table[len-1];
			else			++i;
}}}


char str[420000], patt[210000];
int table[420000];

int main() {
	//fileRead("in");
	//fileWrite("out");

	int t;
	sf("%d", &t);

	while(t--) {
		sf("%s", str);

		int len = strlen(str);
		for(int i = len, j = 0; j < len; ++i, ++j)
			str[i] = str[j];
		str[2*len] = '\0';
		for(int i = 0, j = len-1; i < len; ++i, --j)
			patt[j] = str[i];
		patt[len] = '\0';

		//cerr << str << " " << patt << endl;

		isAlindrome = isPalindrome = 0;
		PrefixTable(len, patt, table);
		KMP(len*2, len, str, patt, table);

		if(isAlindrome)
			pf("alindrome\n");
		else if(isPalindrome)
			pf("palindrome\n");
		else
			pf("simple\n");
	}

	return 0;
}