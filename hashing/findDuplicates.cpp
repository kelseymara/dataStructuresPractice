/* Find All Duplicates in an Array

Given an integer array nums of length n where all the integers of nums are in the range [1, n] and each integer appears once or twice, return an array of all the integers that appears twice.

From https://leetcode.com/problems/find-all-duplicates-in-an-array/description/

*/

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> res;
        unordered_map<int, int> m; // key and value , 
        for (int n : nums) {
            // if the interger already appears in the
            // hashmap once, push it back
            if(m[n]) 
            res.push_back(n);
            else if(m[n]>=2)
            continue;
            m[n]++;
        }
        return res;
    }
};
