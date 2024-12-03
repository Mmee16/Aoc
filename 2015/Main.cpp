#include <iostream>
#include <string>
#include <fstream>
#include "Util.cpp"
#include "day14.cpp"

using namespace std;

void read_line(string line) {
    vector<string> break_ups = parse(line, ' ');
    setup(break_ups,2503);
}


int main() {
    fstream file;
    file.open("input.txt");
    string line;
    while(getline(file, line)) {
        read_line(line);
    }
    cout<<get_max(2503);
}
