//UVa
//195 - Anagram
#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define pi acos(-1)
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
#define N 1000000

using namespace std;

bool cmp(string x, string y)
{
	//return  1 if x goes first
	
	if(x.size() < y.size())
		return 1;
	else if(x.size() == y.size())
	{
		for(size_t i = 0; i < x.size(); i++)
		{
			char a = x[i], b = y[i];
			if(tolower(a) < tolower(b))
				return 1;
			else if(tolower(a) > tolower(b))
				return 0;
			else if(tolower(a) == tolower(b))
			{
				if(isupper(a) && islower(b))
					return 1;
				else if(islower(a) && isupper(b))
					return 0;
			}
		}
	}
	return 0;
	
}

int main()
{
	int n;
	char arr[100];
	vector<string>v;
	map<string, bool>mp;
	sf("%d", &n);
	wh(n--)
	{
		sf(" %s", arr);
		if(mp[&arr[0]]++ == 0)
		{
			int len = strlen(arr);
			sort(arr, arr+len);
			do
			{
				v.pb(&arr[0]);
			}while(next_permutation(arr, arr+len));
			sort(v.begin(), v.end(), cmp);
			for(vector<string>:: iterator it = v.begin(); it != v.end(); it++)
				cout << *it << "\n";
			v.clear();
		}
	}
	return 0;
}
