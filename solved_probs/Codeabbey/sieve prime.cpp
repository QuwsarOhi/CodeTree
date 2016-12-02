//Codeabbey
//url: http://www.codeabbey.com/index/task_view/prime-numbers-generation
#include <iostream>

using namespace std;

int siv[5000000];

void sieve()
{
	for(register int i = 0; i <= 5000000; i++)
		siv[i] = 1; //initialize;
	for(register int i = 4; i <= 5000000; i+=2)
		siv[i] = 0;  //setting non prime to 0
	for(register int i = 3; i < 2238; i+=2)
		for(register int j = i*i; j < 5000000; j += i)
			siv[j] = 0;
	siv[1] = 0;
}
		
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	sieve();
	register int t, i;
	cin >> t;
	while(t--)
	{
		i = 0;
		int in;
		cin >> in;
		for(i = 1; in; i++)
			if(siv[i])
			{
				//cout << "i : " << i << "num : " << siv[i] << "\n";
				in--;
			}
		cout << i-1 << " ";
	}
	return 0;
}
