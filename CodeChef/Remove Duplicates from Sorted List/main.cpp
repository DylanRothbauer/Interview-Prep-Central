/* Linked List Node
struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
}; */

class Solution {
public:
    Node* removeDuplicates(Node* head) {
        // your code here
        Node* curr = head;

        // Traverse the list
        while (curr != nullptr && curr->next != nullptr) {
            // check for duplicate
            if (curr->data == curr->next->data) {
                Node* nextNext = curr->next->next; // Skip it
                curr->next = nextNext;
            }
            else {
                curr = curr->next;
            }
        }
        return head;
    }
};