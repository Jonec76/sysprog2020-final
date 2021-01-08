#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;


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
void permute(int *a, int l, int r, vector<vector<string> >& ans){
    int i;
    if (l == r){
        bool skip = false;
        for(int i=l-1;i<l+1;i++){
            for(int j=1;j<i+1;j++){
                // printf("%d %d j:%d\n", a[i], a[i-j], j);
                if(((a[i] - a[i-j]) == j)||((a[i] - a[i-j]) == -j)){
                    skip = true;
                    break;
                }
            }
        }
        if(skip)
            return;

        string tmp = "", dots="";
        for(int j=0;j<l+1;j++)
            tmp += '.';

        vector<string> sol;
        for(int j=0;j<l+1;j++){
            cout<<a[j]<<" ";
            dots = tmp;
            dots[a[j]] = 'Q';
            sol.push_back(dots);
        }
        cout<<"\n";
        ans.push_back(sol);
    }else{
        for (i = l; i <= r; i++){
            bool skip = false;
            if(l>1){
                for(int j=1;j<l;j++)
                    if(((a[l-1] - a[l-1-j]) == j)||((a[l-1] - a[l-1-j]) == -j))
                        skip = true;
            }
            if(skip)
                continue;
            swap((a+l), (a+i));
            permute(a, l+1, r, ans);
            swap((a+l), (a+i)); //backtrack
        }
    }
}


vector<vector<string> > solveNQueens(int n) {
    vector<vector<string> > ans;
    int* nums = (int*)malloc(n * sizeof(int));
    for(int i=0;i<n;i++)
        nums[i] = i;
    permute(nums, 0, n-1, ans);

    for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans[i].size();j++){
            for(int k=0;k<ans[i][j].size();k++){
                cout<<ans[i][j][k]<<" ";
            }
            puts("\n");
        }
            puts("\n-------------\n");
    }

    return ans;
}

int main(){
    solveNQueens(6);
}
