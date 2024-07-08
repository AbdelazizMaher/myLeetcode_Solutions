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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int sum = 0 , carry = 0;

        ListNode* current {nullptr};
        ListNode* Result {current};
        
        while( l1 != nullptr || l2 != nullptr )
        {
            sum = 0;
            sum += carry;

            if( l1 != nullptr )
            {
                sum += l1->val;
                l1 = l1->next;
            }
            if( l2 != nullptr )
            {
                sum += l2->val;
                l2 = l2->next;
            }

            carry = sum / 10;
            sum = sum % 10;

            if( current == nullptr )
            {
                current = new ListNode(sum);
                Result = current;
            }
            else
            {
                current->next = new ListNode(sum);
                current = current->next;
            }           
        }
        if ( carry > 0 )
        {
            current->next = new ListNode(carry);
        }

        return Result;
    }
};