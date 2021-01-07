#include<stdio.h>
#include<stdlib.h>

typedef struct {
    int *depth;
    int **parent;
    int max_depth;
    int n;
} TreeAncestor;

TreeAncestor *treeAncestorCreate(int n, int *parent, int parentSize)
{
    TreeAncestor *obj = malloc(sizeof(TreeAncestor));
    obj->parent = malloc(n * sizeof(int *));
    obj->n = n;
    obj->depth = malloc(n * sizeof(int));
    int max_depth = -1;
    memset(obj->depth, 0, n * sizeof(int));
    obj->parent[0] = malloc(sizeof(int));

    for (int i = 1; i < n; i++) {
        obj->depth[i] = obj->depth[parent[i]]+1;
        if(obj->depth[i] > max_depth)
            max_depth = obj->depth[i];
        int node_level = 32 - __builtin_clz(obj->depth[i]);
        obj->parent[i] = malloc(node_level * sizeof(int));
    }
    for (int i = 0; i < parentSize; i++)
        obj->parent[i][0] = parent[i];

    int bit_idx = 1;
    int max_bit = 32 - __builtin_clz(max_depth) + 1;
    while(bit_idx < max_bit){
        int start_idx = (1 << bit_idx);
        for(int j=start_idx;j<parentSize;j++){
            if(32 - __builtin_clz(obj->depth[j]) <= bit_idx)
                continue;
            obj->parent[j][bit_idx] = obj->parent[obj->parent[j][bit_idx - 1]][bit_idx - 1];
        }
        bit_idx++;
    }
    obj->max_depth = max_depth;
    return obj;
}

int treeAncestorGetKthAncestor(TreeAncestor *obj, int node, int k)
{
    int max_depth = obj->max_depth;
    if(obj->depth[node] < k)
        return -1;
    
    for (int i = 0; i < (32 - __builtin_clz(max_depth)) && node != -1; ++i){
        if ((k & (1 << i)))
            node = obj->parent[node][i];
    }
    return node;
}

void treeAncestorFree(TreeAncestor *obj)
{
    for (int i = 0; i < obj->n; i++)
        free(obj->parent[i]);
    free(obj->parent);
    free(obj->depth);
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

    for(int i=0;i<n;i++){
        int node_level = 32 - __builtin_clz(obj->depth[i]);
        for(int j=0;j<node_level;j++){
            printf("%d ", obj->parent[i][j]);
        }
        puts("\n");
    }



    int param_1 = treeAncestorGetKthAncestor(obj, 7, 4);
    printf("\nans: %d", param_1);
    treeAncestorFree(obj);
}

/**
 * Your TreeAncestor struct will be instantiated and called as such:
 * TreeAncestor* obj = treeAncestorCreate(n, parent, parentSize);
 * int param_1 = treeAncestorGetKthAncestor(obj, node, k);
 
 * treeAncestorFree(obj);
*/