#include <bits/stdc++.h>

using namespace std;

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:

    Node* dfs(Node* node, unordered_map<int, Node*>& map){
        Node* new_node = new Node(node->val);
        map[node->val] = new_node;

        for(auto& neighbors: node->neighbors){
            if (map.count(neighbors->val)){
                new_node->neighbors.push_back(map[neighbors->val]);
            }
            else{
                new_node->neighbors.push_back(dfs(neighbors, map));
            }
        }

        return new_node;
    }

    Node* cloneGraph(Node* node) {
        unordered_map<int, Node*> map;

        if(node == nullptr){
            return nullptr;
        }

        return dfs(node, map);
    }
};