/*
Given the head of a singly linked list, return the middle node of the linked list.
If there are two middle nodes, return the second middle node.

From Leetcode: 
https://leetcode.com/problems/middle-of-the-linked-list/description/
*/


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

    /*
        Tortosie and the Hare/Slow and Fast Pointers Algorithm

        
        Fast pointer: moves two steps at a time


        if it was the first middle node, fast should automatically start at
    head->next
        */
        
        /// Slow Pointer: moves one step at a time 
       /// Fast Pointer: moves two steps at a time

        /* standard linked list while loop 
        Node *itr=this->head;
        while(itr->next!=NULL)
        {
            do something
            itr=itr->next
        }
        */
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
    

        // both start at head
        ListNode *slow=head;
        ListNode *fast=head;

        while(fast!=NULL && fast->next!=NULL)
        {
            slow=slow->next;
            fast=fast->next->next;
        }

        return slow;

    }
};