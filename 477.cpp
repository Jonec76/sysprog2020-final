#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int totalHammingDistance(vector<int>& nums);

/**
 * Count bit 0 and bit 1 numbers in each iteration, and multiply these two values
 */ 

int main(){
    int data[] = {1, 4};
    vector<int> nums;
    for (size_t i = 0; i < (sizeof(data) / sizeof(data[0])); i++) {
        nums.push_back(data[i]);
    }
    totalHammingDistance(nums);
}

int totalHammingDistance(vector<int>& nums) {
    int total_ham_distance = 0;
    size_t bit_0_ctr=0, bit_1_ctr=0; 
    bool has_number = 0;
    
    do{
        has_number = 0;
        bit_0_ctr=0;
        bit_1_ctr=0; 
        for(size_t i=0;i<nums.size();i++){
            if(nums[i] & 1)
                bit_1_ctr++;
            else
                bit_0_ctr++;
            has_number |= nums[i];
            nums[i] >>= 1;
        }
        total_ham_distance += bit_0_ctr*bit_1_ctr;
    }while(has_number);

    return total_ham_distance;
}
