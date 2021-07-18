/* Given the head of a singly linked list, reverse the list, and return the reversed list.*/
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
    ListNode* reverseList(ListNode* head) {
        ListNode *temp = NULL;
        while(head != NULL){
            ListNode *second = head -> next;    //pointing to the next element
            head->next = temp;  //point to the prev node to reverse it
            temp = head;        // head has become the prev node
            head = second;      //move the head to the next node
        }
        
        return temp;
        
    }
};
