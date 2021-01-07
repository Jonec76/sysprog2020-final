#include<stdio.h>
#include<stdlib.h>

typedef struct {
    int **parent;
    int max_level;
    int n;
} TreeAncestor;

TreeAncestor *treeAncestorCreate(int n, int *parent, int parentSize)
{
    TreeAncestor *obj = malloc(sizeof(TreeAncestor));
    obj->parent = malloc(n * sizeof(int *));
    obj->n = n;
    int max_level = 32 - __builtin_clz(n);

    obj->parent[0] = malloc(sizeof(int));

    for (int i = 1; i < n; i++) {
        int node_level = 32 - __builtin_clz(i);
        obj->parent[i] = malloc(node_level * sizeof(int));
        for (int j = 0; j < node_level; j++)
            obj->parent[i][j] = -1;
    }
    for (int i = 0; i < parentSize; i++)
        obj->parent[i][0] = parent[i];

    int level_counter = 1;
    while(level_counter < max_level){
        int start_idx = (1 << level_counter);
        for(int j=start_idx;j<parentSize;j++){
            int parent_level = (obj->parent[j][level_counter - 1] == 0)? 1
                            :32 - __builtin_clz(obj->parent[j][level_counter - 1]);
            if((level_counter > parent_level) || (obj->parent[j][level_counter - 1]==-1))
                obj->parent[j][level_counter] = -1;
            else
                obj->parent[j][level_counter] = obj->parent[obj->parent[j][level_counter - 1]][level_counter - 1];
        }
        level_counter++;
    }
    obj->max_level = max_level;
    return obj;
}

int treeAncestorGetKthAncestor(TreeAncestor *obj, int node, int k)
{
    if(node < k)
        return -1;
    int max_level = obj->max_level;
    for (int i = 0; i < max_level && node != -1; ++i){
        int parent_level = (node == 0)? 1
                            :32 - __builtin_clz(node);

        if ((k & (1 << i))){
            if(parent_level <= i)
                return -1;
            node = obj->parent[node][i];

        }
    }
    return node;
}

void treeAncestorFree(TreeAncestor *obj)
{
    for (int i = 0; i < obj->n; i++)
        free(obj->parent[i]);
    free(obj->parent);
    free(obj);
}


/**
 * Your TreeAncestor struct will be instantiated and called as such:
 * TreeAncestor* obj = treeAncestorCreate(n, parent, parentSize);
 * int param_1 = treeAncestorGetKthAncestor(obj, node, k);
 
 * treeAncestorFree(obj);
*/

/**
 * Your TreeAncestor struct will be instantiated and called as such:
 * TreeAncestor* obj = treeAncestorCreate(n, parent, parentSize);
 * int param_1 = treeAncestorGetKthAncestor(obj, node, k);
 
 * treeAncestorFree(obj);
*/

int main(){
    int n=10, parentSize=n;
    int parent[] = {-1,0,0,1,2,0,1,3,6,1};
    TreeAncestor* obj = treeAncestorCreate(n, parent, parentSize);
    int param_1 = treeAncestorGetKthAncestor(obj, 9, 7);
    printf("\nans: %d", param_1);
    treeAncestorFree(obj);
}

/**
 * Your TreeAncestor struct will be instantiated and called as such:
 * TreeAncestor* obj = treeAncestorCreate(n, parent, parentSize);
 * int param_1 = treeAncestorGetKthAncestor(obj, node, k);
 
 * treeAncestorFree(obj);
*/