//1D Max Sum
//Algorithm : Jay Kadane
//Complexity : O(n)

int main() {
    int n;
    scanf("%d", &n);
    int A[n+1];
    for(int i = 0; i < n; i++)
        scanf("%d", &A[i]);

    //Main part of the code
    int sum = 0, ans = 0;
    for(int i = 0; i < 9; i++) {
        sum += A[i];
        ans = max(sum, ans);                //always take the larger sum
        if(sum < 0)
            sum = 0;                        //if sum is negative, reset it (greedy)
    }
    printf("1D Max Sum : %d\n", ans);
    return 0;
}

//2D Max Sum
//Algorithm : DP, Inclusion Exclusion
//Complexity : O(n^4)

int main() {
    int row_column, A[100][100];             //A square matrix
    scanf("%d", &row_column);

    for(int i = 0; i < row_column; i++)         //input of the matrix/2D array
        for(int j = 0; j < row_column; j++) {
            scanf("%d", &A[i][j]);
            if(i > 0) A[i][j] += A[i-1][j];                     //take from right
            if(j > 0) A[i][j] += A[i][j-1];                     //take from left
            if(i > 0 && j > 0) A[i][j] -= A[i-1][j-1];         //inclusion exclusion
        }

    int maxSubRect = -1e7;
    for(int i = 0; i < row_column; i++)                 //i & j are the starting coordinate of sub-rectangle
        for(int j = 0; j < row_column; j++)
            for(int k = i; k < row_column; k++)         //k & l are the finishing coordinate of sub-rectangle
                for(int l = j; l < row_column; l++) {
                    int subRect = A[k][l];
                    if(i > 0) subRect -= A[i-1][l];
                    if(j > 0) subRect -= A[k][j-1];
                    if(i > 0 && j > 0) subRect += A[i-1][j-1];         //due to inclusion exclusion
                    maxSubRect = max(subRect, maxSubRect);
                }
    printf("2D Max Sum : %d\n", maxSubRect);
    return 0;
}
