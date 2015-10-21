/**
 * @author          johnsondu
 * @problem         Evaluate Reverse Polish Notation
 * @url             https://leetcode.com/problems/evaluate-reverse-polish-notation/
 * @timeComlexity   O(n)
 * @spaceComplexity O(1)
 * @strategy        Reverse Polish Notation, simple simulation
 * @status          Accepted, runtime beats 29.57% of cpp submissions. 16ms
 * @time            20:12, Oct 21 2015
 */

class Solution {
public:
    int transfer(const string& digits) {
        int cnt = 0;
        int idx = 0;
        if(digits[0] == '-') idx ++;
        for(int i = idx; i < digits.size();  i ++)
            cnt = cnt * 10 + digits[i] - '0';
        if(idx) cnt = -cnt;
        return cnt;
    }
    
    int evalRPN(vector<string>& tokens) {
        stack<int> nums;
        for(int i = 0; i < tokens.size(); i ++) {
            if(tokens[i][0] >= '0' && tokens[i][0] <= '9' || tokens[i].size() > 1) {
                nums.push(transfer(tokens[i]));
            }
            else {
                int rt = nums.top(); nums.pop();
                int lf = nums.top(); nums.pop();
                switch(tokens[i][0]) {
                case '+':
                    nums.push(lf + rt);
                    continue;
                case '-':
                    nums.push(lf - rt);
                    continue;
                case '*':
                    nums.push(lf * rt);
                    break;
                default:
                    nums.push(lf / rt);
                    continue;
                }
            }
        }
        return nums.top();
    }
};