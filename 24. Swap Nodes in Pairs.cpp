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
    ListNode* swapPairs(ListNode* head) {
        if(head == nullptr || head->next == nullptr)
            return head;
        ListNode *p=head, *h = head, *q = p->next;
        head = q;
        while(1)
        {
            
            p->next = q->next;
            q->next = p;
            h = p;
            
            p = p->next;
            if(p == nullptr)
                break;
            q = p->next;
            if(q == nullptr)
                break;
            h->next = q;
        }
        return head;
        
    }
};