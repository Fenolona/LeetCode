/** 
 * @author          johnsondu 
 * @problem         Two Sum 
 * @url             https://leetcode.com/problems/two-sum/ 
 * @timeComlexity   O(n) 
 * @spaceComplexity O(n) 
 * @strategy        Use map to contain the answer 
 * @status          Accepted, 40ms,  runtime beats 5.20% of cpp submissions 
 * @time            14:30, Oct 21 2015 
 */  
   
class Solution {  
public:  
    vector<int> twoSum(vector<int>& nums, int target) {  
        map<int, int> mp;  
        vector<int> vec;  
        for(int i = 0; i < nums.size(); i ++)  
            mp[nums[i]] = i + 1;  
        for(int i = 0; i < nums.size(); i ++) {  
            if(mp[target-nums[i]]){  
                if(i+1 == mp[target-nums[i]]) continue;  
                if(mp[target-nums[i]] != 0) {  
                    vec.push_back(i+1);  
                    vec.push_back(mp[target-nums[i]]);  
                    break;  
                }  
            }  
        }  
        sort(vec.begin(), vec.end());  
        return vec;  
    }  
};  


/** 
 * @author          johnsondu 
 * @problem         Two Sum 
 * @url             https://leetcode.com/problems/two-sum/ 
 * @timeComlexity   O(nlog(n)) 
 * @spaceComplexity O(1) 
 * @strategy        copy -> binary search -> find index -> swap index if not suit 
 * @status          Accepted, 12ms,  runtime beats 89.81% of cpp submissions 
 * @time            14:55, Oct 21 2015 
 */  
class Solution {  
public:  
    vector<int> twoSum(vector<int>& nums, int target) {  
        vector<int> tmp = nums;  
        sort(tmp.begin(), tmp.end());  
        int l = 0; int r = tmp.size() - 1;  
        while(l < r) {  
            int mid = tmp[l] + tmp[r];  
            if(mid == target) break;  
            else if(mid > target) r --;  
            else l ++;  
        }  
          
        int idx1 = -1, idx2 = -1;  
        for(int i = 0; i < nums.size(); i ++)  
            if(nums[i] == tmp[l]) { idx1 = i;   break; }  
        for(int j = nums.size() - 1; j >= 0; j --)  
            if(nums[j] == tmp[r]) { idx2 = j ;  break; }  
          
        if(idx1 > idx2) { idx1 ^= idx2; idx2 ^= idx1; idx1 ^= idx2; }  
        return vector<int>{idx1+1, idx2+1};  
    }  
};  