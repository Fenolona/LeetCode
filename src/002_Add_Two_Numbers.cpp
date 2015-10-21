/** 
 * @author          johnsondu 
 * @problem         Add Two Numbers
 * @url             https://leetcode.com/problems/add-two-numbers/
 * @timeComlexity   O(n) 
 * @spaceComplexity O(n) 
 * @strategy        Simulation of two big number additions
 * @status          Accepted, 40ms,  runtime beats 5.20% of cpp submissions 
 * @time            15:48, Oct 21 2015 
 * @version         v1, plain
 */  

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(l1 == NULL && l2 == NULL) return l1;
        if(l1 == NULL && l2 != NULL) return l2;
        if(l1 != NULL && l2 == NULL) return l1;
    
        ListNode* head = new ListNode(-1);
        ListNode* cur = head;
    
        int carry = 0;
        while(l1 || l2 || carry)
        {
            int sum = carry;
            if(l1) { sum += l1->val; l1 = l1->next; }
            if(l2) { sum += l2->val; l2 = l2->next; }
            ListNode* node = new ListNode(sum % 10);
            carry = sum / 10;
            cur->next = node;
            cur = cur->next;
        }
    
        return head->next;
    }
};



/** 
 * @author          johnsondu 
 * @problem         Add Two Numbers
 * @url             https://leetcode.com/problems/add-two-numbers/
 * @timeComlexity   O(n) 
 * @spaceComplexity O(n) 
 * @strategy        Simulation of two big number additions
 * @status          Accepted, 40ms,  runtime beats 5.20% of cpp submissions 
 * @time            15:48, Oct 21 2015 
 * @version         v2, recursive
 */  

 /**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(l1 == NULL && l2 == NULL) return NULL;
        else if(l1 == NULL) return l2;
        else if(l2 == NULL) return l1;
        
        int sum = l1->val + l2->val;
        ListNode *p = new ListNode(sum % 10);
        p->next = addTwoNumbers(l1->next, l2->next);
        if(sum >= 10) p->next = addTwoNumbers(p->next, new ListNode(1));
    
        return p;
    }
};