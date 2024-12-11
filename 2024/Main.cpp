#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "Util.cpp"
#include "day4.cpp"
using namespace std;

vector<int> read_line(string line) {
    vector<string> break_ups = parse(line, ' ');
    vector<int> row;
    for(string i: break_ups) {
        row.push_back(stoi(i));
    }
    return row;
}


int main() {
    fstream file;
    file.open("day4inp.txt");
    string line;
    vector<vector<int>> data;
    while(getline(file, line)) {
        insert_row(line);
    }
    cout<<count2();
    
}
