/*
Node is defined as:
class Node{
  public:
  int data;
  Node* next;
  Node(int data){
      this->data = data;
      this->next = nullptr;
  }
}
*/
int solve(Node* head) {
    Node* curr = head;
    Node* prev = head;
    int criticalPoints = 0;

    if (head == nullptr) {
        return 0;
    }

    curr = curr->next; // Not considering the first

    while (curr != nullptr && curr->next != nullptr) {
        Node* next = curr->next;
        if (prev->data > curr->data && next->data > curr->data) { // Local minima
            criticalPoints++;
            prev = curr;
            curr = curr->next;
        }
        else if (prev->data < curr->data && next->data < curr->data) { // Local maxima
            criticalPoints++;
            prev = curr;
            curr = curr->next;
        }
        else { // No critical points, so just move on
            prev = curr;
            curr = curr->next;
        }
    }

    return criticalPoints;
}