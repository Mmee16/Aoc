#include <string>
#include <vector>


using namespace std;


vector<string> parse(string str, char seperator) {
    vector<string> seperated_strings;
    string temp;
    for(int i=0; i< str.size(); i++) {
        if(str[i] == seperator) {
            seperated_strings.push_back(temp);
            temp="";
        }
        else {
            temp.push_back(str[i]);
        }
    }
    seperated_strings.push_back(temp);
    return seperated_strings;
}

vector<vector<int>> permute(vector<int> vec) {
    return vector<vector<int>>(10, vector<int>(3,0));
}
void generate_permutations(int size) {
    vector<int> base_vec = vector(size,0);
    for(int i=0; i<size; i++) {
        base_vec[i] = i;
    }
}
