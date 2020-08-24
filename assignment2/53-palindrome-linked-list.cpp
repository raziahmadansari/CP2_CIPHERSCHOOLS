// https://leetcode.com/problems/palindrome-linked-list/


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
    bool isPalindrome(ListNode* head) {
        if (head == nullptr || head->next == nullptr)
            return true;
        
        ListNode* ptr = head;
        vector<int> v;
        while(ptr)
        {
            v.push_back(ptr->val);
            ptr = ptr->next;
        }
        
        int i = 0;
        int j = v.size() - 1;
        
        while (i < j)
        {
            if (v[i] != v[j])
                return false;
            i++;
            j--;
        }
        
        return true;
    }
};