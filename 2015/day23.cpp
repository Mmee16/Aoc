#include <iostream>
#include <string>
#include <unordered_map>
#include "Util.cpp"

using namespace std;
unordered_map<int, string> map_instr;
unordered_map<char, int> var_map;
int max_len = 0;

void run_ins(string ins, int &currId) {
    vector<string> ins_vec = parse(ins, ' ');
    if(ins_vec[0] == "jio") {
        if(var_map[ins_vec[1][0]] == 1) currId+=(stoi(ins_vec[2])-1);
    }
    else if(ins_vec[0] == "jie") {
        if(var_map[ins_vec[1][0]] %2 == 0) currId+=(stoi(ins_vec[2])-1);
    }
    else if(ins_vec[0] == "jmp") {
        currId += (stoi(ins_vec[1])-1);
    }
    else if(ins_vec[0] == "hlf") {
        var_map[ins_vec[1][0]] = var_map[ins_vec[1][0]]/2;
    }
    else if(ins_vec[0] == "tpl") {
        var_map[ins_vec[1][0]] = var_map[ins_vec[1][0]]*3;
    }
    else if(ins_vec[0] == "inc") {
        var_map[ins_vec[1][0]] = var_map[ins_vec[1][0]]+1;
    }
    currId++;
}

void populate_ins_map(string line, int id) {
    map_instr[id] = line;
    max_len = id;
}

void run_program() {
    int currId = 1;
    var_map['a'] = 1;
    var_map['b'] = 0;
    while(currId <= max_len) {
        string ins = map_instr[currId];
        cout<<ins<<endl;
        run_ins(ins, currId);
    }
}
