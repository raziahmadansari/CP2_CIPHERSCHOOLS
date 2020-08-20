// https://leetcode.com/problems/intersection-of-two-linked-lists/


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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (headA == nullptr)
            return headA;
        if (headB == nullptr)
            return headB;
        
        ListNode* ptr1 = headA;
        ListNode* ptr2 = headB;
        
        while(ptr1)
        {
            ptr2 = headB;
            while(ptr2)
            {
                if (ptr1 == ptr2)
                    return ptr1;
                ptr2 = ptr2->next;
            }
            ptr1 = ptr1->next;
        }
        return ptr1;
    }
};