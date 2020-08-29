// https://leetcode.com/problems/add-two-numbers/


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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int length1 = 0;
        int length2 = 0;
        
        ListNode* ptr = l1;
        while (ptr)
        {
            length1++;
            ptr = ptr->next;
        }
        
        ptr = l2;
        while (ptr)
        {
            length2++;
            ptr = ptr->next;
        }
        
        int carry = 0;
        
        ListNode* result = nullptr;
        ListNode* ptr1 = l1;
        ListNode* ptr2 = l2;
        while (length1 && length2)
        {
            int sum = ptr1->val + ptr2->val + carry;
            carry = sum / 10;
            sum = sum % 10;
            
            length1--;
            length2--;
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
            
            ListNode* temp = new ListNode(sum);
            
            ListNode* temp1 = result;
            
            if (temp1 == nullptr)
            {
                result = temp;
                continue;
            }
            
            while (temp1->next)
                temp1 = temp1->next;
            temp1->next = temp;
        }
        
        while (length1)
        {
            int sum = ptr1->val + carry;
            carry = sum / 10;
            sum = sum % 10;
            
            length1--;
            ptr1 = ptr1->next;
            
            ListNode* temp = new ListNode(sum);
            ListNode* temp1 = result;
            
            if (temp1 == nullptr)
            {
                result = temp;
                continue;
            }
            while (temp1->next)
                temp1 = temp1->next;
            temp1->next = temp;
        }
        
        while (length2)
        {
            int sum = ptr2->val + carry;
            carry = sum / 10;
            sum = sum % 10;
            
            length2--;
            ptr2 = ptr2->next;
            
            ListNode* temp = new ListNode(sum);
            ListNode* temp1 = result;
            
            if (temp1 == nullptr)
            {
                result = temp;
                continue;
            }
            while (temp1->next)
                temp1 = temp1->next;
            temp1->next = temp;
        }
        
        if (carry)
        {
            ListNode* temp = new ListNode(carry);
            ListNode* temp1 = result;
            while (temp1->next)
                temp1 = temp1->next;
            temp1->next = temp;
        }
        
        return result;
    }
};