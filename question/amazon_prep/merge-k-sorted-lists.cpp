#include<bits/stdc++.h>
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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* root = new ListNode(0);
        ListNode* cur = root;

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> q;
        int n = lists.size();

        for(int i=0;i<n;i++){
            if(lists[i]) q.push({lists[i]->val, i});
        }

        while(not q.empty()){
            auto [v,i] = q.top(); q.pop();
            cur->next = lists[i];
            cur = cur->next;
            
            lists[i] = lists[i]->next;
            if(lists[i]) q.push({lists[i]->val, i});

        }

        return root->next;
    }
};