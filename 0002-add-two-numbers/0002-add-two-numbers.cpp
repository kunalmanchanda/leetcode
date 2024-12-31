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
    ListNode* add(ListNode* p, ListNode* q) {
        ListNode* temp = new ListNode(-1);
        ListNode* ret = temp;
        int carry = 0;

        while(p != NULL || q != NULL || carry != 0) {
            int sum = carry;

            if(p != NULL) {
                sum += p->val;
                p = p->next;
            }

            if(q != NULL) {
                sum += q->val;
                q = q->next;
            }

            carry = sum/10;
            temp->next = new ListNode(sum%10);
            temp = temp->next;
        }

        return ret->next;
    }
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* revAdd = add(l1, l2);

        return revAdd;
    }
};