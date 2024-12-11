#include <algorithm>
#include <string>
#include <vector>
using namespace std;



string master_word = "MAS";
string rev_master_word = master_word;
vector<string> letter_map;
int width = 0;
int depth = 0;

void insert_row(string inp) {
    letter_map.push_back(inp);
}

int horizontal_count(int row, int coloumn) {
    if(coloumn > width - master_word.size()) return 0;
    if(letter_map[row].substr(coloumn, master_word.size()) == master_word ||
         letter_map[row].substr(coloumn, master_word.size()) == rev_master_word)
        return 1;
    return 0;
}

int verticle_count(int row, int coloumn) {
    int master_word_size = master_word.size();
    if(row > depth - master_word_size) return 0;
    string temp;
    for(int i=0; i<master_word_size; i++) {
        temp.push_back(letter_map[row+i][coloumn]);
    }
    if(temp == master_word || temp == rev_master_word) return 1;
    return 0;
}

int forward_dia_count(int row, int coloumn) {
    if(coloumn > width - master_word.size()) return 0;
    string temp;
    for(int i=0; i<master_word.size(); i++) {
        temp.push_back(letter_map[row+i][coloumn+i]);
    }
    if(temp == master_word || temp == rev_master_word) return 1;
    return 0;
}

int backward_dia_count(int row, int coloumn) {
    if(coloumn < master_word.size() -1) return 0;
    string temp;
    for(int i=0; i<master_word.size(); i++) {
        temp.push_back(letter_map[row+i][coloumn-i]);
    }
    if(temp == master_word || temp == rev_master_word) return 1;
    return 0;
}

int diagnal_count(int row, int coloumn) {
    int master_word_size = master_word.size();
    if(row > depth - master_word_size) return 0;
    return forward_dia_count(row, coloumn) 
            + backward_dia_count(row, coloumn);

}

int count1() {
    reverse_copy(master_word.begin(), master_word.end(), rev_master_word.begin());
    width = letter_map[0].size();
    depth = letter_map.size();
    int count = 0;
    for(int row=0; row<depth; row++) {
        for(int coloumn=0; coloumn< width; coloumn++) {
            if(letter_map[row][coloumn] == master_word[0] || letter_map[row][coloumn] == rev_master_word[0]) {
                count += horizontal_count(row, coloumn);
                count += verticle_count(row, coloumn);
                count += diagnal_count(row, coloumn);
            }
        }

    }
    return count;
}

bool is_valid(int row, int coloumn) {
    int master_word_size = master_word.size();
    if(row > depth - master_word_size || coloumn > width - master_word.size()) return false;

    if(letter_map[row][coloumn] != master_word[0] 
       && letter_map[row][coloumn] != rev_master_word[0]) 
        return false;
    if(letter_map[row][coloumn+master_word_size-1] != master_word[0] 
       && letter_map[row][coloumn+master_word_size-1] != rev_master_word[0]) 
        return false;
    if(forward_dia_count(row, coloumn) == 1
        && backward_dia_count(row, coloumn+master_word_size-1) == 1)
        return true;

    return false;
}

int count2() {
    reverse_copy(master_word.begin(), master_word.end(), rev_master_word.begin());
    width = letter_map[0].size();
    depth = letter_map.size();
    int count = 0;
    for(int row=0; row<depth; row++) {
        for(int coloumn=0; coloumn< width; coloumn++) {
            if(is_valid(row, coloumn)) {
                count++;
            }
        }
    }
    return count;
 }
