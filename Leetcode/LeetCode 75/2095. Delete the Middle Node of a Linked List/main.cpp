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
    ListNode* deleteMiddle(ListNode* head) {
        // Handle edge cases
        if (head == nullptr) return nullptr; // Empty list
        if (head->next == nullptr) { // Only one node
            delete head;
            return nullptr;
        }

        // Initialize pointers for finding the middle
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev = nullptr;

        // Move fast pointer two steps and slow pointer one step
        while (fast != nullptr && fast->next != nullptr) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        // Slow pointer is now at the middle node
        // `prev` is the node before the middle node
        if (prev != nullptr) {
            prev->next = slow->next; // Bypass the middle node
            delete slow; // Delete the middle node
        }
        else {
            // Special case: head was the only node
            head = head->next; // Update head to the next node
            delete slow; // Delete the old head node
        }

        return head;
    }
};