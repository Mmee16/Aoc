#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "day5.cpp"
using namespace std;


int main() {
    fstream file;
    file.open("day5inp.txt");
    string line;
    vector<vector<int>> data;
    while(getline(file, line)) {
        parse_ins(line);
    }
    cout<<get_invalid_count();
}
