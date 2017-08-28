

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

class Solution {
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        ListNode dummy(INT_MIN);
        ListNode *tail = &dummy;

        while (l1 && l2) {
            if (l1->val < l2->val) {
                tail->next = l1;
                l1 = l1->next;
            } else {
                tail->next = l2;
                l2 = l2->next;
            }
            tail = tail->next;
        }

        tail->next = l1 ? l1 : l2;
        return dummy.next;
    }

    ListNode* swapPairs(ListNode* head) {
      if(head == NULL || head->next == NULL) return head;

      ListNode * prev = head;
      ListNode * post = head->next;
      ListNode * new_head = head->next;

      while(prev && post){
          ListNode * temp_prev;
          ListNode * temp_post;

          if(post->next != NULL && post->next->next != NULL){

              temp_prev = post->next;
              temp_post = post->next->next;

          }else{
              temp_prev = post->next;
              temp_post = post->next;
          }


          post->next = prev;
          prev->next = temp_post;

          prev = temp_prev;
          post = temp_post;

      }



      return new_head;
  }


  bool hasCycle(ListNode *head) {

      if(head == NULL || head->next == NULL){
          return false;
      }

      ListNode * slow = head;
      ListNode * fast = head->next;

      while(fast != slow){

          if( fast == NULL || fast->next == NULL){
              return false;
          }

          slow = slow->next;
          fast = fast->next->next;

      }

      return true;
  }


  void deleteNode(ListNode* node) {
      node->val = node->next->val;
      node->next = node->next->next;
  }

};
