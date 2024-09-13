/*struct Node {
    int val;
    struct Node* next;
    Node(int x){
        val = x;
        next = NULL;
    }
};*/

int getMiddleElement(Node* head) {
    // Using fast slow pointers
    // Fast will reach the end and slow will be 2x as slow, giving us the middle
    Node* fast = head;
    Node* slow = head;

    if (head == nullptr) { // empty list
        return 0;
    }

    while (fast != nullptr && fast->next != nullptr) {
        fast = fast->next->next;
        slow = slow->next;
    }

    return slow->val;

}
