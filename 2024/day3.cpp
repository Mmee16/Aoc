#include <iostream>
#include <fstream>
#include <string>


using namespace std;

bool is_valid(char c) {
    return (c>='0' && c<='9') || c == ',';
}

int get_mul(string line) {
    int left;
    int right;
    string temp;
    for(char c:line) {
        if(c == ',') { 
            left = stoi(temp);
            temp="";
       }
        else {
            temp.push_back(c);
        }
    }
    right = stoi(temp);
    return right*left;
}
int get_sum_new(string line, bool &eval) {
    int sum=0;
    for(int i=0; i<line.size(); i++ ) {
        if(line[i] == 'm') {
            if(line.substr(i,4) != "mul(") continue;
            i+=4;
            string temp;
            while(i<line.size() && is_valid(line[i])) {
                temp.push_back(line[i++]);
            }
            cout<<eval<<endl;
            if(line[i--] != ')' || !eval) continue;
            sum+=get_mul(temp);
        }
        if(i< line.size()-6 && line.substr(i,7) == "don't()") 
            eval = false;
        if(i< line.size()-4 && line.substr(i,4) == "do()") 
            eval = true;
    }
    return sum;
}
int get_sum(string line, bool eval) {
    if(line.size() <=4 || line.substr(0,4) != "mul(") {
        return 0;
    }
    int i=4;
    string temp;
    while(i<line.size() && is_valid(line[i])) {
        temp.push_back(line[i++]);
    }
    cout<<eval<<endl;
    if(line[i] != ')' || !eval) return 0;
    return get_mul(temp);

}
int main() {
    static bool eval = true;
    int sum=0;
    fstream file;
    file.open("input.txt");
    string line;
    while(getline(file, line)) {
        sum+=get_sum_new(line, eval);
    }
    cout<<endl<<sum;
}
