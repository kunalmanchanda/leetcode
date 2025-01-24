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
    ListNode *reverse(ListNode *start) {
        if(start == NULL || start->next == NULL) {
            return start;
        }

        ListNode *temp = reverse(start->next);
        
        start->next->next = start;
        start->next = NULL;

        return temp;
    }

    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode *prevStart = NULL;
        ListNode *start = head;
        ListNode *end = head;
        ListNode *endNext = NULL;
        int temp_count = 1;

        while(temp_count < left) {
            prevStart = start;
            start = start->next;
            temp_count++;
        }

        if(prevStart){
            prevStart->next = NULL;
        }

        end = start;
        if(end!= NULL) {
            endNext = end->next;
        }

        while(temp_count < right) {
            end = end->next;
            if(end!= NULL) 
            endNext = end->next;
            temp_count++;
        }
        
        if(end) {
            end->next = NULL;
        }

        ListNode *temp = reverse(start);

        if(prevStart) {
            prevStart->next = temp;
            if(endNext) {
                while(temp->next != NULL) {
                    temp = temp->next;
                }
                temp->next = endNext;
            }
            return head;
        } else {
            ListNode *curr = temp;
            if(endNext) {
                while(temp->next != NULL) {
                    temp = temp->next;
                }
                temp->next = endNext;
            }
            return curr;
        }
    }
};