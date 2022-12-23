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
        if(head == nullptr){ return nullptr;}
        ListNode *reversed = new ListNode(head->val);
        return reverseRecursive(head->next, reversed);
    }

    ListNode* reverseRecursive(ListNode* head, ListNode* reversed){
        if(head == nullptr){
            return reversed;
        }
        else{
            ListNode *curr = new ListNode(head->val);
            curr->next = reversed;
            return reverseRecursive(head->next, curr);
        }
    }
};