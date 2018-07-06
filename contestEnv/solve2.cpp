#include <bits/stdc++.h>
using namespace std;
#define MAX                 100100
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


//int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};
//int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1}, dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};
//----------------------------------------------------------------------------------------------------------


static int numPalindrome(int num)
{
    int numLength = 0;
    int palLength = 0;
    int palPrefix = 0;
    int temp      = 0;
    int i         = 0;

    // Example 1: num = 12345678
    // Example 2: num = 123456789

    // Find the length of the number, in digits.  Examples: 8 and 9
    for (numLength=0, temp = num; temp != 0; temp /= 10)
        numLength++;

    // Find the palindrome prefix, which is the front half of the number,
    // rounding up the length.
    //
    // Examples: palLength = 4    and 5
    //           palPrefix = 1234 and 12345
    palLength = (numLength+1) / 2;
    palPrefix = num;
    for (i=0; i < numLength - palLength; i++)
        palPrefix /= 10;

    // Check whether the palindrome formed by palPrefix is greater than num.
    // If it is, we subtract one from palPrefix because the last palindrome
    // is not usable.
    //
    // Example 1: Is 12344321  greater than 12345678?
    // Example 2: Is 123454321 greater than 123456789?
    if (constructPalindrome(palPrefix, numLength) > num)
        palPrefix--;

    // So right now, we have palPrefix being 1234 and 12345 for the two
    // examples.  The number of palindromes less than num is close to
    // palPrefix*2.  The reason is, for each number from 1..palPrefix, you can
    // can construct two palindromes, one of odd length where the last digit
    // is not repeated, and one of even length where all digits are repeated.
    //
    // 25  -> 252    2552
    // 256 -> 25652  256652
    //
    // Starting with all these, palindromes, we adjust the count depending
    // on whether the original number had an even or odd number of digits.
    //
    // For even numLength, we are missing some palindromes, for example:
    //
    // num       = 12345678
    // palPrefix = 1234
    //
    // We can create a palindrome with prefix higher than 1234 that is still
    // less than num.  For example, choose 2345:
    //
    // 2345 -> 2345432
    //
    // So for each number from 1235..9999, we should add one to the count.
    // In other words, add 10^prefixLength - 1 - palPrefix to the count.
    //
    // For odd numLength, we have too many palindromes.  Some of the
    // palindromes already created are not usable.  For example:
    //
    // num       = 12345678
    // palPrefix = 12345
    //
    // 12345 -> 1234554321 (too big, 10 digits)
    //
    // So for all the max digit prefixes, we can only use 1 of the 2
    // palindromes.  So we should subtract some from the count.  The number we
    // need to subtract in this case is: (12345 - 9999).  In other words,
    // subtract palPrefix - (10^(prefixLength-1) - 1) prefixes.
    palPrefix *= 2;
    if (numLength & 1) {
        // Subtract off adjustment for odd length.
        int adjustment = 1;
        for (i=1;i<palLength;i++)
            adjustment *= 10;
        palPrefix -= (palPrefix/2 - adjustment + 1);
    } else {
        // Add adjustment for even length.
        int adjustment = 1;
        for (i=0;i<palLength;i++)
            adjustment *= 10;
        palPrefix += (adjustment - 1 - palPrefix/2);
    }
    return palPrefix;
}


int main() {
    cout << numPalindrome(2) << endl;
    return 0;
}
