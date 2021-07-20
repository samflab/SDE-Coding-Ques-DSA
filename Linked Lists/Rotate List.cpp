/* Given the head of a linked list, rotate the list to the right by k places. */

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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL || head->next == NULL || k == 0)
            return head;
        
        ListNode *temp = head;
        int count = 1;
        while(temp -> next != NULL){
            temp = temp -> next;
            ++count;               //length of the linkedlist
        }
        
        temp -> next = head;
        k = k % count;    //if k >= count, so it gets reduced
        k = count - k;
        
        while(k--){
            temp = temp -> next;    //temp was at head, it will move it (count-k)th node
        }
        
        head = temp -> next;
        temp -> next = NULL;    //break the chain and point the (count-kth) node to null
        
        return head;
        
    }
};
