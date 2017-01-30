//UVa
//10950 - Bad Code
#include <bits/stdc++.h>
using namespace std;

int len, missmatch, t, cnt;
char input_char[20], track_char[20];

void printer(int pos, int track_mismatch)
{
	if(track_mismatch > missmatch)			//missmatch must be equal or less
		return;
	//if(track_mismatch != missmatch && pos >= len)
		//return;
	if(pos >= len) {
		track_char[pos] = 0;				//end of string
		printf("%s\n", track_char);
		return;
	}
	track_char[pos] = 'A';
	printer(pos+1, track_mismatch+(track_char[pos] != input_char[pos]));
	track_char[pos] = 'C';
	printer(pos+1, track_mismatch+(track_char[pos] != input_char[pos]));
	track_char[pos] = 'G';
	printer(pos+1, track_mismatch+(track_char[pos] != input_char[pos]));
	track_char[pos] = 'T';
	printer(pos+1, track_mismatch+(track_char[pos] != input_char[pos]));
}

void counter(int pos, int track_mismatch)
{
	if(track_mismatch > missmatch)
		return;
	//if(track_mismatch != missmatch && pos >= len)
		//return;
	if(pos >= len) {
		cnt++;
		return;
	}
	track_char[pos] = 'A';
	counter(pos+1, track_mismatch+(track_char[pos] != input_char[pos]));
	track_char[pos] = 'C';
	counter(pos+1, track_mismatch+(track_char[pos] != input_char[pos]));
	track_char[pos] = 'G';
	counter(pos+1, track_mismatch+(track_char[pos] != input_char[pos]));
	track_char[pos] = 'T';
	counter(pos+1, track_mismatch+(track_char[pos] != input_char[pos]));
}

int main()
{
	freopen("in", "r", stdin);
	freopen("out", "w", stdout);
	scanf("%d", &t);
	while(t--) {
		scanf("%d %d", &len, &missmatch);
		scanf(" %s", input_char);
		cnt = 0;
		counter(0, 0);
		printf("%d\n", cnt);
		//printf("%s\n", input_char);
		printer(0, 0);
	}
	return 0;
}
