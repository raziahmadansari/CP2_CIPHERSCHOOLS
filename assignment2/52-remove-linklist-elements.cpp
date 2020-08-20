// https://leetcode.com/problems/remove-linked-list-elements/


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if (head == nullptr)
            return head;
        
        while (head != nullptr && val == head->val)
            head = head->next;
        
        ListNode* prev = head;
        ListNode* curr = head;
        if (head != nullptr)
            curr = head->next;
        
        while (curr)
        {
            if (curr->val == val)
                prev->next = curr->next;
            else
                prev = curr;
            curr = curr->next;
        }
        
        return head;
    }
};