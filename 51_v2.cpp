#include <stdbool.h> 
#include <string> 
#include <iostream> 
#include <vector> 
#include <algorithm>

using namespace std;
vector<vector<string> > solveNQueens(int n);

// driver program to test above function 
int main() { 
    solveNQueens(4);
	return 0; 
} 


bool isSafe(int* board, int row, int col, int n) { 
	int i, j; 

	/* Check this row on left side */
	if(board[row] > (1<<(n-col-1)))
		return false;

	// /* Check upper diagonal on left side */
	for (i = row, j = col; i >= 0 && j >= 0; i--, j--) 
		if(board[i] == 1<<(n-j-1))
			return false;

	// /* Check lower diagonal on left side */
	for (i = row, j = col; j >= 0 && i < n; i++, j--) 
		if(board[i] == 1<<(n-j-1))
			return false;

	return true; 
} 

/* A recursive utility function to solve n 
Queen problem */
bool solvenQUtil(int* board, int col, int n, vector<vector<string> >& ans) 
{ 
	/* base case: If all queens are placed 
	then return true */
	if (col >= n) {
		vector<string> sol;
		string dots = "";
		for (int i = 0; i < n; i++) 
			dots += '.';
		
		for (int i = 0; i < n; i++) { 
			string tmp = dots;
			tmp[__builtin_ffs(board[i])-1] = 'Q';
			sol.push_back(tmp);
		} 
		ans.push_back(sol);
		return true; 
	}

	/* Consider this column and try placing 
	this queen in all rows one by one */
	for (int i = 0; i < n; i++) { 
		/* Check if the queen can be placed on 
		board[i][col] */
		if (isSafe(board, i, col, n)) { 
			/* Place this queen in board[i][col] */
			board[i] = 1 << (n-col-1); 

			/* recur to place rest of the queens */
			solvenQUtil(board, col + 1, n, ans);

			/* If placing queen in board[i][col] 
			doesn't lead to a solution, then 
			remove queen from board[i][col] */
			board[i] = 0; // BACKTRACK 
		} 
	} 
	return false; 
} 

vector<vector<string> > solveNQueens(int n) {
	vector<vector<string> > ans;
	int board[n] = {0};
	for(int i=0;i<n;i++){
		board[i] = 0;
	}
	solvenQUtil(board, 0, n, ans);
	// for(int i=0;i<ans.size();i++){
    //     for(int j=0;j<ans[i].size();j++){
    //         for(int k=0;k<ans[i][j].size();k++){
    //             cout<<ans[i][j][k]<<" ";
    //         }
    //         puts("\n");
    //     }
    //         puts("\n-------------\n");
    // }

	return ans;
}

