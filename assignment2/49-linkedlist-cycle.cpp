// https://leetcode.com/problems/linked-list-cycle/


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
    bool hasCycle(ListNode *head) {
        if (head == NULL)
            return false;
        if (head->next == NULL)
            return false;
        
        ListNode* prev = head;
        ListNode* curr = head->next;
        while(curr)
        {
            if (curr == prev)
                return true;
            prev = prev->next;
            
            if (curr->next == NULL)
                break;
            curr = curr->next->next;
        }
        
        return false;
    }
};