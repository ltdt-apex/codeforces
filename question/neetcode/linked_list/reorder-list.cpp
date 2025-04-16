#include <bits/stdc++.h>
using namespace std;

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
        void reorderList(ListNode* head) {
            ListNode* slow = head;
            ListNode* fast = head;

            while(fast and fast->next){
                slow = slow->next;
                fast = fast->next->next;
            }

            ListNode* second = slow->next;
            ListNode* prev = nullptr;
            slow->next = nullptr;

            while(second){
                ListNode* next = second->next;
                second->next = prev;
                prev = second;
                second = next;
            }

            ListNode* first = head;
            second = prev;
            while(first and second){
                ListNode* firstNext = first->next;
                ListNode* secondNext = second->next;
                first->next = second;
                second->next = firstNext;

                first = firstNext;
                second = secondNext;
            }
        }
    };