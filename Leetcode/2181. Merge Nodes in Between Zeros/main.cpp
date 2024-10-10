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
    ListNode* mergeNodes(ListNode* head) {
        ListNode* mod = head;
        ListNode* trav = head->next;

        while (trav->next != nullptr) {
            if (trav->val != 0) {
                mod->val += trav->val;
            }
            else {
                mod = mod->next;
                mod->val = 0;
            }
            trav = trav->next;
        }
        mod->next = nullptr;
        return head;
    }
};