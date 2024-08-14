/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

typedef struct ListNode NODE;

extern void addListNode(NODE *node, int val);
extern bool compareListNode(NODE *node, int pointervalue);

bool hasCycle(struct ListNode *head) {
    
    struct ListNode *CurrentPointer = head;
#if 0
    while(CurrentPointer != NULL)
    {
        printf("CurrentPointer = %d \r\n", CurrentPointer);

        printf("CurrentPointer->value = %d \r\n", CurrentPointer->val);
        
        CurrentPointer = CurrentPointer->next;
    }
#endif
    // create a list to recore traveled node
    NODE *TestList, *first;
    
    TestList = (NODE*) malloc(sizeof(NODE));
    first = TestList;
    TestList->val = 1;
    TestList->next = NULL;


#if 0
    addListNode(TestList, 2);
    addListNode(TestList, 3);
    addListNode(TestList, 4);
    TestList = first;

    while(TestList != NULL)
    {
        printf("TestList->val = %d \r\n", TestList->val);
        TestList = TestList->next;
    }
#endif
    // need API for add node => addListNode

    while(CurrentPointer != NULL)
    {
        printf("CurrentPointer = %d \r\n", CurrentPointer);
        printf("CurrentPointer->value = %d \r\n", CurrentPointer->val);

        //compare this pointer is same as record list
        if(!compareListNode(TestList, CurrentPointer))
        {
            // record travel linklist pointer to TestList
            addListNode(TestList, CurrentPointer);
        }
        else
        {
            printf("the pointer is exist = %d \r\n", CurrentPointer);
            return 1;
            break;
        }

        CurrentPointer = CurrentPointer->next;
    }


    return 0;
}

void addListNode(NODE *node, int val)
{
    NODE *newnode;
    newnode = (NODE*) malloc(sizeof(NODE));

    // travel to last node
    while((node->next)!=NULL)
    {
        node = node->next;
    }

    newnode->val = val;
    newnode->next = node->next;
    node->next = newnode;
}

bool compareListNode(NODE *node, int pointervalue)
{
    //travel all node
    while(node != NULL)
    {
        if(node->val == pointervalue)
        {
            return 1;
        }

        node = node->next;
    }
    return 0;

}