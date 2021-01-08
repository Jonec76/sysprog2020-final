/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
#include<stdlib.h>
#include<stdio.h>

char *** solveNQueens(int n);

int main(){

    // char** a;
    // char b[3][4];
    // a = (char**)malloc(3*sizeof(char*));
    // memcpy(a, b, 3*4*sizeof(char));
    int *returnSize;
    int **returnColumnSizes;
    solveNQueens(5);
}

void swap(int *x, int *y){
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

/* Function to print permutations of string
   This function takes three parameters:
   1. String
   2. Starting index of the string
   3. Ending index of the string. */
void permute(int *a, int l, int r, char ****ans, int* returnSize){
    int i;
    if (l == r){
        for(int j=0;j<l+1;j++){
            int diff = 1;
            for(int k=j+1;k<l+1;k++){
                if((a[j] - a[k]) == diff || (a[j] - a[k]) == -diff)
                    return; 
                diff++;
            }
        }
        (*returnSize)++;
        (*ans) = realloc((*ans), (*returnSize)*sizeof(char*));
        char tmp[l+1][l+1] ;
        for(int j=0;j<l+1;j++){
            memset(tmp[j], '.', (l+1)*sizeof(char));
            tmp[j][a[j]] = 'Q';
        }
        (*ans)[(*returnSize)-1] = (char**)malloc((l+1) * sizeof(char*));
        for (i=0; i<l+1; i++) 
            (*ans)[(*returnSize)-1][i] = (int *)malloc((l+1) * sizeof(int)); 

        for(int j=0;j<l+1;j++){
            for(int k=0;k<l+1;k++){
                (*ans)[(*returnSize)-1][j][k] = tmp[j][k];
            }
        }
    }
    else
    {
        for (i = l; i <= r; i++)
        {
            swap((a+l), (a+i));
            permute(a, l+1, r, ans, returnSize);
            swap((a+l), (a+i)); //backtrack
        }
    }
}

char *** solveNQueens(int n){
    int* nums = (int*)malloc(n * sizeof(int));
    int returnSize = 0;
    char ***ans;
    for(int i=0;i<n;i++)
        nums[i] = i;
    permute(nums, 0, n-1, &ans, &returnSize);
    return ans;
}

// [["Q....","..Q..","....Q",".Q...","...Q."],["Q....","...Q.",".Q...","....Q","..Q.."],[],[".Q...","....Q","..Q..","Q....","...Q."],["..Q..","Q....","...Q.",".Q...","....Q"],["..Q..","....Q",".Q...","...Q.","Q...."],["...Q.","Q....","..Q..","....Q",".Q..."],["...Q.",".Q...","....Q","..Q..","Q...."],["....Q",".Q...","...Q.","Q....","..Q.."],["....Q","..Q..","Q....","...Q.",".Q..."]]


// 13042
// ".Q...",
// "...Q.",
// "Q....",
// "....Q"
// "..Q..",