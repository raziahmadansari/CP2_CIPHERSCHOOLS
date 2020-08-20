// https://leetcode.com/problems/merge-two-sorted-lists/


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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        vector<int> v;
        while (l1)
        {
            v.push_back(l1->val);
            l1 = l1->next;
        }
        while (l2)
        {
            v.push_back(l2->val);
            l2 = l2->next;
        }
        sort(v.begin(), v.end());
        reverse(v.begin(), v.end());
        ListNode* result = nullptr;
        for (int i = 0; i < v.size(); i++)
        {
            ListNode* temp = new ListNode(v[i]);
            temp->next = result;
            result = temp;
        }
        return result;
    }
};