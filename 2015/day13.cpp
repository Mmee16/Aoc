#include <string>
#include <unordered_map>
#include <vector>
#include "Util.cpp"

std::unordered_map<string, int> happy_map;

void populate_graph(std::string line) {
    vector<string> temp = parse(line, ' ');
    int happiness = temp[2] == "gains" ? stoi(temp[3]) : -1*(stoi(temp[3]));
    happy_map[temp[0]+temp[1]] = happiness;
}
