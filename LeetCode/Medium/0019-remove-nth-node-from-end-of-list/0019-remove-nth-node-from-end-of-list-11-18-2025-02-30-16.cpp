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
    int len(ListNode* head) {
        int l = 0;
        while(head) {
            l++;
            head = head->next;
        }

        return l;
    }

public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *curr = head, *prev = NULL;
        int m = len(head) - n;

        while(m--) {
            prev = curr;
            curr = curr->next;
        }

        if(prev) {
            prev->next = curr->next;
        } else {
            return head->next;
        }

        return head;
    }
};