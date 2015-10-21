/**
 * @author          johnsondu
 * @problem         3Sum Closest
 * @url             https://leetcode.com/problems/3sum-closest/
 * @timeComlexity   O(n^2)
 * @spaceComplexity O(1)
 * @strategy        Inserting each number nums[i] into a hash table,
 *                    and then for each index i and j, checking the minimm gap.
 * @status          Accepted, runtime beats 56.19% of cpp submissions. 12ms
 * @time            19:34, Oct 21 2015
 */

class Solution {
public:
    int Abs(int x) { return x < 0 ? -x : x; }

    int threeSumClosest(vector<int>& nums, int target) {
        int ans = nums[0] + nums[1] + nums[2];
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size() - 2; i ++) {
            if(i > 0 && nums[i] == nums[i-1]) continue;
            int a = nums[i];
            int lf = i + 1;
            int rt = nums.size() - 1;
            while(lf < rt) {
                int b = nums[lf];
                int c = nums[rt];
                if(a + b + c > target) rt --;
                else if(a + b + c < target) lf ++;
                else return target;
                if(Abs(a+b+c-target) < Abs(ans-target)) ans = a + b + c;
            }
        }
        return ans;
    }
};