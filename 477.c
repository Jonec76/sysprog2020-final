#include<stdio.h>
int totalHammingDistance(int* nums, int numsSize);

/**
 * Count bit 0 and bit 1 numbers in each iteration, and multiply these two values
 */ 

int main(){
    int data[] = {8, 7};
    printf("%d", totalHammingDistance(data, (sizeof(data) / sizeof(data[0]))));
}

int totalHammingDistance(int* nums, int numsSize){
    int total_ham_distance = 0;
    size_t bit_1_ctr=0; 
    char has_number = 0;
    
    do{
        has_number = 0;
        bit_1_ctr=0; 
        for(size_t i=0;i<numsSize;i++){
            bit_1_ctr+=(nums[i] & 1);
            has_number |= nums[i];
            nums[i] >>= 1;
        }
        total_ham_distance += (numsSize - bit_1_ctr)*bit_1_ctr;
    }while(has_number);

    return total_ham_distance;
}