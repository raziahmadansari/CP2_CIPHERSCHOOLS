// https://leetcode.com/problems/merge-k-sorted-lists/


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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector<int> v;
        int size = lists.size();
        
        ListNode* result = nullptr;
        if (size == 0)
            return result;
        
        for (int i = 0 ; i < size; i++)
        {
            ListNode* temp = lists[i];
            while (temp)
            {
                v.push_back(temp->val);
                temp = temp->next;
            }
        }
        
        if (v.size() == 0)
            return result;
        
        sort(v.begin(), v.end());
        reverse(v.begin(), v.end());
        
        for (int i = 0; i < v.size(); i++)
        {
            ListNode* node = new ListNode(v[i]);
            node->next = result;
            result = node;
        }

        return result;
    }
};