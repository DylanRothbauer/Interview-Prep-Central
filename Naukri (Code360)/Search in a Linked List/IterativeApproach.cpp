/*
* Iterative Approach
The idea is to first initialize a pointer pointing to the first element of the Linked List and will check if the pointer's data is equal to the desired value ‘K’. 
If yes, then we will return 1; otherwise, we will move the pointer ahead by 1 position. 
If at any point of time during our travel, the pointer gets to point the NULL node, i.e., the end of Linked List, we will return 0 (as we have reached the end).

Time Complexity
O(N), where ‘N’ is the number of nodes in the Linked List.
We are doing only a single traversal of the Linked List, which takes O(N) in the worst case. Hence the overall complexity will be O(N).

Space Complexity
O(1).
In the worst case, a constant space is required.
*/

/*
    Time Complexity: O(N)
    Space Compexity: O(1)

    Where 'N' is the total nodes in Linked List.
*/

int searchInLinkedList(Node<int>* head, int k)
{

    // Check if the Linked List is empty.
    if (head == NULL)
    {
        return 0;
    }

    // Initialising a pointer pointing to head.
    Node<int>* ptr = head;

    while (ptr)
    {

        // If value is found we end our search.
        if (ptr->data == k)
        {
            return 1;
        }

        // Moving the pointer to the next node.
        ptr = ptr->next;
    }

    // As we reached the end of Linked List without finding value so will return 0.
    return 0;
}