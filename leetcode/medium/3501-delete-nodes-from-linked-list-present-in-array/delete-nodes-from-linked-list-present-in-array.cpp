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
  ListNode* modifiedList(vector<int>& nums, ListNode* head) {
    unordered_set<int> s(nums.begin(), nums.end());
    while (head && s.count(head->val)) {
      head = head->next;
    }
    ListNode* pre = head;
    ListNode* curr = head ? head->next : nullptr;

    while (curr != NULL) {
      if (s.count(curr->val)) {
        pre->next = curr->next;

      } else {
        pre = curr;
        ;
      }

      curr = curr->next;
    }
    return head;
  }
};