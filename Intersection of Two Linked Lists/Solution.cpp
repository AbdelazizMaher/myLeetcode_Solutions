/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int m = 0 , n = 0;

        ListNode* pA = headA;
        ListNode* pB = headB;

        while(pA != nullptr || pB != nullptr)
        {
            if( pA != nullptr)
            {
                pA = pA->next;
                m++;
            }
            if( pB != nullptr)
            {
                pB = pB->next;
                n++;
            }
        }

        if( m < n )
        {
            for(auto i = 0 ; i < (n-m) ; i++)
                headB = headB->next;
        }
        else
        {
            for(auto i = 0 ; i < (m-n) ; i++)
                headA = headA->next;            
        }

        while( headB != nullptr )
        {
            if( headA == headB )
                return headA;
            headA = headA->next; 
            headB = headB->next;   
        }
        return nullptr;

    }
};