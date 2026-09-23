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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // 1. Stack memory par dummy node banaya (Koi dynamic new/delete ka jhanjhat nahi)
        ListNode dummy(0);
        dummy.next = head;

        ListNode* fast = &dummy;
        ListNode* slow = &dummy;

        
        for (int i = 0; i <= n; i++) {
            fast = fast->next;
        }

    
        while (fast != nullptr) {
            fast = fast->next;
            slow = slow->next;
        }

        
        ListNode* toDelete = slow->next;
        slow->next = slow->next->next;
        delete toDelete; 

       
        return dummy.next;
    }
};