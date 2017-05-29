//UVa
//  108 - Maximum Sum
// 2D matrix sum

#include <bits/stdc++.h>

using namespace std;



int main()
{
	register int n, i, j, k, l, maxsubrect, subrect;
	int A[110][110];
	while(scanf(" %d", &n) != EOF)
	{
		for(i = 0; i < n; i++)
			for(j = 0; j < n; j++)
			{
				scanf(" %d", &A[i][j]);
				if(i > 0) A[i][j] += A[i-1][j];
				if(j > 0) A[i][j] += A[i][j-1];
				if(i > 0 && j > 0) A[i][j] -= A[i-1][j-1];
			}
		maxsubrect = -127*100*100;
		for(i = 0; i < n; i++)
			for(j = 0; j < n; j++)
				for(k = i; k < n; k++)
					for(l = j; l < n; l++)
					{
						subrect = A[k][l];
						if(i > 0) subrect -= A[i-1][l];
						if(j > 0) subrect -= A[k][j-1];
						if(i > 0 && j > 0) subrect += A[i-1][j-1];
						//printf("%d\n", subrect);
						maxsubrect = max(maxsubrect, subrect);
					}
		printf("%d\n", maxsubrect);
	}
	return 0;
}
