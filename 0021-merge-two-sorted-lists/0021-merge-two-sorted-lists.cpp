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
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2) {
    ListNode *ans = new ListNode(-1);
    recurMerge(list1, list2, ans);
    return ans->next; 
}

ListNode *recurMerge(ListNode *list1, ListNode *list2, ListNode *ans){
    if (list1 == nullptr && list2 == nullptr){
        return nullptr;
    }
    else if (list1 == nullptr){
        ListNode* temp = new ListNode(list2->val);
        ans->next = temp;
        return recurMerge(list1, list2->next, ans->next);
    }
    else if (list2 == nullptr){
        ListNode* temp = new ListNode(list1->val);
        ans->next = temp;
        return recurMerge(list1->next, list2, ans->next);
    }
    else if (list1->val < list2->val){
        ListNode* temp = new ListNode(list1->val);
        ans->next = temp;
        return recurMerge(list1->next, list2, ans->next);
    }
    else{
        ListNode* temp = new ListNode(list2->val);
        ans->next = temp;
        return recurMerge(list1, list2->next, ans->next);
    }
    
}
};