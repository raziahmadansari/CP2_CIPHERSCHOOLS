// https://leetcode.com/problems/odd-even-linked-list/


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
    ListNode* oddEvenList(ListNode* head) {
        if (head == nullptr || head->next == nullptr || head->next->next == nullptr)
            return head;
        
        ListNode* o = head, *se = head->next, *e = head->next;
        
        while(e && e->next)
        {
            o->next = o->next->next;
            o = o->next;
            e->next = e->next->next;
            e = e->next;
        }
        o->next = se;
        return head;        
    }
};