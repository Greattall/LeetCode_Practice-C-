/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
bool hasCycle(struct ListNode *head) {
    
    // create two pointer : fast and slow
    // FastPointer start from head->next 
    // SlowPointer start from head
    // FastPointer go to next node by 2 step
    // SlowPointer go to next node by 1 step
    // if the list is cycle list, FastPointer will catch up to SlowPointer
    // if the list isn't cycle list, FastPointer will travel to NULL


    // boundary condition : empty list or 1 element list 
    if ((head == NULL) || (head->next == NULL))
    {
        return 0; 
    }

    struct ListNode *FastPointer = head->next;
    struct ListNode *SlowPointer = head;

    while(FastPointer != NULL)
    {
        if (FastPointer == SlowPointer)
        {
            return 1; //cycle list
        }
        FastPointer = FastPointer->next;

        if (FastPointer == NULL)
        {
            return 0;
        }
        FastPointer = FastPointer->next;
        
        SlowPointer = SlowPointer->next;

    }
    
    return 0; //isn't cycle list because FastPointer traveled to NULL

}