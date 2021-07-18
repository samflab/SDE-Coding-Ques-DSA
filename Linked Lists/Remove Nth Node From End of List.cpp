/* Given the head of a linked list, remove the nth node from the end of the list and return its head.*/

//CODE

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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *start = new ListNode();   //cuurently, a null node
        start -> next = head;
        ListNode *fast = start, *slow = start;
        for(int i = 0; i < n; i++){
            fast = fast -> next;        //reached the nth node from start
        }
        
        while(fast->next != NULL){
            slow = slow->next;
            fast = fast->next;
        }
        
        slow -> next = slow -> next -> next;
        
        return start -> next;       
        
    }
};
