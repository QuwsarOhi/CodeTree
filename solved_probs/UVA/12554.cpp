//UVa
//12554 - A Special "Happy Birthday" Song!!!

#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n, loop;
	char pep[100][20];
	char song[][10] = {"Happy", "birthday", "to", "you", "Happy", "birthday", "to", "you", 
		"Happy", "birthday", "to", "Rujia", "Happy", "birthday", "to", "you"};
	scanf(" %d", &n);
	for(register int i = 0; i < n; i++)
		scanf("%s", pep[i]);
	if(n <= 16)
		loop = 16;
	else
		loop = (ceil(((long)n)/16.0))*16;
	int p = 0, s = 0;
	for(register int i = 0; i < loop; i++)
	{
		if(p == n)
			p = 0;
		if(s == 16)
			s = 0;
		printf("%s: %s\n", pep[p++], song[s++]);
	}
	return 0;
}
