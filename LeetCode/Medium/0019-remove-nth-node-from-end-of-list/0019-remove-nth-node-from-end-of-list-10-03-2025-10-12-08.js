/**
 * Definition for singly-linked list.
 * function ListNode(val, next) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.next = (next===undefined ? null : next)
 * }
 */
/**
 * @param {ListNode} head
 * @param {number} n
 * @return {ListNode}
 */

var listLen = (head) => {
    let temp = head;
    let len = 0;

    while (temp) {
        temp = temp.next;
        len++;
    }

    return len;
}


var removeNthFromEnd = function (head, n) {
    let nodePos = listLen(head) - n;

    if(nodePos == 0) {
        return head.next;
    }
    
    let temp = head;
    let prev = null;

    while(nodePos--) {
        prev = temp;
        temp = temp.next;
    }

    if(prev == null) {
        return null;
    }

    prev.next = temp.next;

    return head;
};