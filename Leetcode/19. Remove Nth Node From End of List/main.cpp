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

 /*
Explanation:
1) Advance fast Pointer by n Steps:
We move the fast pointer n steps ahead. If fast reaches nullptr after these steps, it means we need to remove the head node.

2) Edge Case Handling (Remove Head):
If fast is nullptr after advancing n steps, we simply return head->next as the new head.

3) Simultaneous Movement:
Both slow and fast move together until fast->next becomes nullptr. At this point, slow will be just before the node to be removed.

Time Complexity: O(n), where n is the length of the linked list.
Space Complexity: O(1), as only a few pointers are used
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (head == nullptr) {
            return nullptr;
        }

        ListNode* slow = head;
        ListNode* fast = head;

        for (int i = 0; i < n; i++) { // slow delayed by n
            if (fast == nullptr) {
                break;
            }

            fast = fast->next;
        }

        // Edge case: if fast is null, we need to remove the head node
        if (fast == nullptr) {
            return head->next;
        }

        while (fast->next != nullptr) {
            fast = fast->next;
            slow = slow->next;
        }

        slow->next = slow->next->next;

        return head;
    }
};