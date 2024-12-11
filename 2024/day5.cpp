#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include "Util.cpp"
using namespace std;


unordered_map<int, vector<int>> page_map;
bool rules_end = false;
int valid_count = 0;
int invalid_count = 0;
bool custom_comp(int a, int b) {
    vector<int> ins_a = page_map[a];
    vector<int> ins_b = page_map[b];
    for(int i:ins_a) {
        if(i == b) return true;
    }
    for(int i:ins_b) return false;
    return true;
}

bool is_visited(unordered_set<int> &visitor_map, vector<int> &page_ins) {
    for(int i:page_ins) {
        if(visitor_map.find(i) != visitor_map.end())
            return true;
    }
    return false;
}

bool is_valid_ins(vector<int> instructs) {
    unordered_set<int> vistor_set;
    for(int i:instructs) {
        vistor_set.insert(i);
        if(is_visited(vistor_set, page_map[i])) 
            return false;
    }
    return true;
}
void fill_page_map(int a, int b) {
    if(page_map.find(a) != page_map.end()) 
        page_map[a].push_back(b);
    else 
        page_map[a] ={b};
}

void parse_ins(string line) {
    if(line.size() == 0) {
        rules_end = true;
        return;
    }
    if(!rules_end) {
        vector<string> seperated_inp = parse(line, '|');
        fill_page_map(stoi(seperated_inp[0]), stoi(seperated_inp[1]));
    }
    else {
        vector<int> instructs;
        vector<string> seperated_inp = parse(line, ',');
        for(string s: seperated_inp) {
            instructs.push_back(stoi(s));
        }
        if(is_valid_ins(instructs)) {
            valid_count+=instructs[instructs.size()/2];
        }
        else {
            sort(instructs.begin(), instructs.end(), custom_comp);
            for(int i:instructs) {
                cout<<i<<",";
            }
            cout<<endl;
            invalid_count += instructs[instructs.size()/2];
        }
    }
}


int get_valid_count() {
    return valid_count;
}
int get_invalid_count() {
    return invalid_count;
}
