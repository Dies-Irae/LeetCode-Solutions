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
    int returnMin(vector<ListNode*>& ptrLists){
        auto tmp = ptrLists.begin();
        
        auto minPointer = ptrLists.begin();
        int min = (*minPointer)->val;
        while(tmp != ptrLists.end())
        {
            if(*tmp == NULL)
            {
                tmp = ptrLists.erase(tmp);
            }
            else
            {
                if((*tmp)->val < min)
                {
                    min = (*tmp) -> val;
                    minPointer = tmp;
                }
            }
            ++tmp;
        }
        *minPointer = (*minPointer) -> next;
        if (*minPointer == NULL)
            ptrLists.erase(minPointer);
        
        return min;
        
}
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {    
        if(lists.size()==0)
            return NULL;
        ListNode *head = new ListNode(0);
        ListNode *p, *q; 
        p = head;
        
        int i = 0;
        bool Null = true;
        
        
        
        
        auto elem = lists.begin();
        while(elem != lists.end())
        {
            if(*elem==NULL)
                elem = lists.erase(elem);
            else
            {
                Null = false;
                ++elem;
            }
            
        }
        //cout<<lists[0]->val;
     
        if(Null == true)
            return NULL;
        while(lists.size() != 0)
        {
            i = returnMin(lists);
            #cout << i;
            q = new ListNode(i);
            p->next = q;
            p = p->next;
            
        }
        return head->next;
        
    }
};