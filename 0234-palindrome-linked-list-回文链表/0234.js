/**
 * Definition for singly-linked list.
 * function ListNode(val) {
 *     this.val = val;
 *     this.next = null;
 * }
 */
/**
 * @param {ListNode} head
 * @return {boolean}
 */
var isPalindrome = function(head) {
    if (!head || !head.next) return true;
    slow = head;
    fast = head;
    next = slow.next;
    while (fast.next && fast.next.next) {
        fast = fast.next.next;
        last = slow;
        slow = next;
        next = slow.next;
        slow.next = last;
    }

    // fast往回, slow往后
    if (fast.next) {        // 偶
        fast = slow;
        slow = next;
    } else {                // 奇
        fast = slow.next;
        slow = next;
    }

    next = fast.next;
    while (slow) {
        if (fast.val != slow.val) {
            return false
        }
        slow = slow.next
        last = fast;
        fast = next;
        next = fast.next;
        fast.next = last;
    }
    return true;
};