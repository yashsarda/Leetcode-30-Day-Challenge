/*
Given a singly linked list, group all odd nodes together followed by the even nodes. Please note here we are talking about the node number and not the value in the nodes.

You should try to do it in place. The program should run in O(1) space complexity and O(nodes) time complexity.
*/
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
    ListNode* oddEvenList(ListNode* head) {
        // Corner cases
        if(!head) return head;
        if(!head -> next) return head;
        
        ListNode* second = head -> next;
        
        ListNode* current = head;
        ListNode* previous = NULL;
        int counter = 0;
        while(current -> next) {
            ListNode* next_node = current -> next;
            if(next_node -> next)
                current -> next = next_node -> next;
            else
                current -> next = NULL;
            counter++;
            previous = current;
            current = next_node;
        }
        if(counter % 2 == 0)
            current -> next = second;
        else
            previous -> next = second;
        return head;
    }
};
