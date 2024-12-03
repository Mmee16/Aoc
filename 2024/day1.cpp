#include <unordered_map>
#include <vector>
#include <string>

using namespace std;

vector<int> list1;
unordered_map<int, int> list2_map;
void insert_in_list(vector<string> lines) {
    list1.push_back(stoi(lines[0]));
    int num2 = stoi(lines[1]);
    if(list2_map.find(num2) != list2_map.end()) {
        list2_map[num2]++;
    } 
    else {
        list2_map[num2] = 1;
    }
}

int get_difference() {
    int sum = 0;
    int len = list1.size();
    for(int i=0; i<len; i++) {
        int num = list1[i];
        if(list2_map.find(num) != list2_map.end()) {
            sum += list2_map[num] * num;
        }
    }
    return sum;
}


