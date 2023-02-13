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

//VECTOR BASED APPROACH
// class Solution {
// public:
//     bool isPalindrome(ListNode* head) {
//          vector<int> nums;
//         ListNode* curr = head;
        
//         while(curr != NULL){ 
//             nums.push_back(curr->val);
//             curr = curr->next;
//         }
//         //checking for palindrome
//         for(int i = 0; i < nums.size() / 2; i++){
//             if(nums[i] != nums[nums.size() - i - 1])
//                 return false;
//         }
        
//         return true;
//     }
// };

// 2nd Approach
class Solution {
public:
    ListNode* reverse(ListNode* head){
        ListNode *prev = NULL , *temp = head , *curr = head;
        while(curr){
            temp = curr;
            curr = curr->next;
            temp->next = prev;
            prev = temp;
        }
        head = prev;
        return head;
    }
    
    bool isPalindrome(ListNode* head) {
        ListNode *slow = head , *fast = head;
        while(fast && fast->next){
            fast = fast->next->next;
            slow = slow->next;
        }
        slow = reverse(slow);
        while(slow && slow->val== head->val){
            slow = slow->next;
            head = head->next;
        }
        return slow==NULL;
    }
};