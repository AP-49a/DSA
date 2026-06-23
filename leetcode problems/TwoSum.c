#include <stdlib.h>

int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    // Simple hash table: we'll use a basic approach since C has no built-in map.
    // Use a hash table sized to handle reasonable input ranges.
    
    // Open-addressing hash map: key = value, val = index
    int capacity = 1;
    while (capacity < numsSize * 2) capacity <<= 1; // power of 2, load factor ~0.5
    
    int* keys = malloc(capacity * sizeof(int));
    int* vals = malloc(capacity * sizeof(int));
    char* used = calloc(capacity, sizeof(char));
    
    for (int i = 0; i < numsSize; i++) {
        long long complement = (long long)target - nums[i];
        
        // Look up complement in hash table
        unsigned int h = ((unsigned int)complement) & (capacity - 1);
        while (used[h]) {
            if (keys[h] == complement) {
                int* result = malloc(2 * sizeof(int));
                result[0] = vals[h];
                result[1] = i;
                *returnSize = 2;
                free(keys);
                free(vals);
                free(used);
                return result;
            }
            h = (h + 1) & (capacity - 1);
        }
        
        // Insert nums[i] into hash table
        unsigned int ih = ((unsigned int)nums[i]) & (capacity - 1);
        while (used[ih]) {
            ih = (ih + 1) & (capacity - 1);
        }
        keys[ih] = nums[i];
        vals[ih] = i;
        used[ih] = 1;
    }
    
    free(keys);
    free(vals);
    free(used);
    *returnSize = 0;
    return NULL; // no solution found
}