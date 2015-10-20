/**
 * @author          johnsondu
 * @problem         Plus One
 * @url             https://leetcode.com/problems/plus-one/
 * @timeComlexity   O(n)
 * @spaceComplexity O(1)
 * @strategy        Simulation
 * @status          Accepted, runtime beats 3.95% of cpp submissions
 * @time            19:03, Oct 20 2015
 */

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry = 1;
        int len = digits.size();
        for(int i = len - 1; i >= 0; i --) {
            int sum = digits[i] + carry;
            digits[i] = sum % 10;
            if(sum > 9) carry = 1;
            else carry = 0;
        }
        if(carry) digits.insert(digits.begin(), 1); 
        
        return digits;
    }
};
