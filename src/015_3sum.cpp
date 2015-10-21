/** 
 * @author          johnsondu 
 * @problem         3sum
 * @url             https://leetcode.com/problems/3sum/
 * @timeComlexity   O(n^2) 
 * @spaceComplexity O(1) 
 * @strategy        Inserting each number nums[i] into a hash table, 
 *                    and then for each index i and j, checking whether
 *                    the hash table contains the integer -(s[i] + s[j])
 * @status          Accepted, runtime beats 61.08% of cpp submissions 
 * @time            17:10, Oct 21 2015 
 */  
 
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        if(nums.size() < 3) return ans;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size() - 2; i ++) {
            // in case of duplicate solutions
            if(i > 0 && nums[i] == nums[i-1]) continue;
            int a = nums[i];
            int lf = i + 1;
            int rt = nums.size() - 1;
            while(lf < rt) {
                int b = nums[lf];
                int c = nums[rt];
                if(0 == a + b + c) {
                    ans.push_back(vector<int> {a, b, c});
                    // in case of duplicate solutions
                    while(lf < nums.size() && nums[lf] == b) lf ++;
                    // in case of duplicate solutions
                    while(rt >= 0 && nums[rt] == c) rt --;
                }
                else if(a + b + c > 0) rt --;
                else lf ++;
            }
        }
        return ans;
    }
};