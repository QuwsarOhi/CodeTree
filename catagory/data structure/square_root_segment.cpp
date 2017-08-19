#include <iostream>
#include <cstdio>

//
//Union for p[Find(b)] = a;
//
//    1st      2nd
//    ___      __
//(5)/(1)\ (4)/  \
//   1---2---5---4
//       \___/
//         ?
//        3rd
//
// Find;
//
// (1)-->(5)-->(4) {end as p[4]==4}
// (2)-->(1)-->(4) {end as p[4]==4}
//
//Union for p[Find(b)] = Find(a);
//
//
//it also finds the actual value for a (as, 5(a), 2(b); a's actual value is 4)
//
//    1st      2nd
//    ___      __
//(4)/(1)\ (4)/  \
//   1---2---5---4
//       \___/
//         ?
//        3rd
//
///////////////////////////////////////////////////


using namespace std;

int p[100];

int Find(int x)
{
	printf("*%d", x);
	if(p[x] == x)
		return x;
	printf("*");
	return p[x] = Find(p[x]);
}

void Union(int a, int b)
{
	p[Find(b)] = a; //or Find(a);
}

int main()
{
	for(int i = 0; i < 101; i++)
		p[i] = i;
		
	Union(1, 2);
	printf("%d\n", p[1]);
	printf("%d\n", p[2]);
	printf("----------\n");
	Union(4, 5);
	printf("%d\n", p[4]);
	printf("%d\n", p[5]);
	printf("----------\n");
	Union(5, 2);
	printf("++\n");
	printf("%d\n", p[2]);
	printf("%d\n", p[5]);
	printf("%d\n", p[1]);
	printf("++");
	printf("%d\n", p[5]);
	printf("%d\n", p[2]);
	printf("----------\n");
	Union(6, 3);
	printf("%d\n", p[3]);
	printf("%d\n", p[6]);
	printf("----------\n");
	//Union(3, 6);
	
	printf("----------------------\n");
	for(int i = 1; i < 8; i++)
		printf("%d\n", Find(i));
	
	return 0;
}
