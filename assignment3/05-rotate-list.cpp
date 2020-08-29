// https://leetcode.com/problems/rotate-list/


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
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == nullptr || k == 0)
            return head;
        if (head->next == nullptr)
            return head;
        
        int length = 0;
        ListNode* ptr = head;
        while (ptr)
        {
            length++;
            ptr = ptr->next;
        }
        
        k = k % length;
        
        while (k)
        {
            ListNode* ptr = head;
            while (ptr->next->next != nullptr)
                ptr = ptr->next;
            ptr->next->next = head;
            head = ptr->next;
            ptr->next = nullptr;
            k--;
        }
        return head;
    }
};