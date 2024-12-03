#include <string>
#include <fstream>
#include <vector>
#include "Util.cpp"
#include "day2.cpp"
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
    file.open("day2inp.txt");
    string line;
    vector<vector<int>> data;
    while(getline(file, line)) {
        data.push_back(read_line(line));
    }
    
    cout<<NumSafeReportsWithProblemDampener(data);
}
