//Codeabbey
//Url: http://www.codeabbey.com/index/task_view/neumanns-random-generator

#include <iostream>
#include <cmath>

using namespace std;

struct h{
	int range = 0;
	int values[30];
}mem[1000];

int store(int h, int val)
{
	if(mem[h].range == 0)
	{
		mem[h].values[mem[h].range] = val;
		mem[h].range++;
		return 0;
	}
	else
	{
		for(register int i = 0; i<= mem[h].range; i++)
		{
			if(mem[h].values[i] == val)
				return 1;
		}
		mem[h].values[++mem[h].range] = val;
	}
	return 0;
}

int hash(register int val)
{
	register long long h = 0, j = 1;
	for(register int i = 1; val != 0 ; i++)
	{
		h += (val%10) * pow(i, j++);
		//cout << "h : " << h << "\n";
		val /= 10;
		if(h > 997)
			h %= 997;
	}
	
	return ((int)h);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	register int t, in, csum, count;
	cin >> t;
	while(t--)
	{
		cin >> in;
		count = 0;
		csum = hash(in);
		store(csum, in);
		//cout << "hash : " << csum << "\n";
		while(1)
		{
			in *= in;
			in /= 100;
			in %= 10000;
			//cout << in << "\n";
			csum = hash(in);
			//cout << "hash : " << csum << "\n";
			count++;
			if(store(csum, in))
				break;
		}
		for(register int i = 0; i < 1000; i++)
			mem[i].range = 0;
		cout << count << " ";
	}
	return 0;
}
