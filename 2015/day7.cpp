#include <unordered_map>
#include <string>
#include <iostream>
#include <vector>
#include "Node.cpp"

using namespace std;
unordered_map<string, Node*> node_map;

bool int_key(string key) {
    return key[0] >='0' && key[0] <='9';
}


Node* get_node(string key) {
    if(node_map.find(key) != node_map.end()) {
        cout<< endl<<"returning node from map "<<key;
        return node_map[key];
    }
    Node *node = new Node();
    node->id = key;
    if(int_key(key)) node->val = stoi(key);
    node_map[key] = node;
    cout<<endl<<"Node created with id "<< node->id <<" " << node->val;
    return node;
}

void populate_map(vector<string> commands) {
    int len = commands.size();
    Node *key_node = get_node(commands[len-1]);
    key_node->right = get_node(commands[len-3]);
    if(len >= 4) key_node->operation = commands[len-4];
    if(len == 5) key_node->left = get_node(commands[len-5]);
}

void print_map() {
    cout<<endl;
    for(auto x:node_map) {
        cout<< x.first<< " "<< x.second->get_val()<<endl;
    }
}
