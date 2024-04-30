/*
* Recursive Approach
Let's try to build a recursive solution to this problem
The recursive function has three cases:

1) The Head is NULL(it means that we have reached the end of the linked list without finding value ‘K’ that means the particular value is not present in the Linked List. So, in this case, we will return 0 as our answer).
2) The Head is Not NULL, and the value of the head is equal to the desired value ‘K’ we will return 1 in this case as we found the desired value in the Linked List.
3) The Head is Not NULL, and the current value is not equal to the desired value ‘K’, so it will recur to the next node of the head and undergo the same process there.

Time Complexity
O(N), where ‘N’ is the number of nodes in the Linked List.
We are doing only a single traversal of the Linked List, which takes O(N) in the worst case. Hence the overall complexity will be O(N).

Space Complexity
O(N), where ‘N’ is the number of nodes in the Linked List.
In the worst case, the maximum depth of the recursion stack can take O(N) space. Hence the overall complexity will be O(N).
*/

/*
    Time Complexity: O(N)
    Space Compexity: O(N)

    Where 'N' is the total nodes in Linked List.
*/

int searchInLinkedList(Node<int>* head, int k)
{

    // Check if we reach the end of the Linked List.
    if (head == NULL)
    {
        return 0;
    }

    // If value found so will end our search.
    if (head->data == k)
    {
        return 1;
    }

    // Recurring for the next node.
    return searchInLinkedList(head->next, k);
}