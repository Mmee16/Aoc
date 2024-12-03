#include <string>

using namespace std;

int sum=0;


bool is_number(char c) {
    return (c >= '0' && c <='9');
}

void parse_line(string line) {
    string temp = "";
    for(int i=0; i <= line.size(); i++) {
        if(line[i] == '-' || is_number(line[i])) {
            bool negitive = false;
            if(line[i] == '-') {
                negitive = true;
                i++;
            }
            while (is_number(line[i])) {
                temp.push_back(line[i]);
                i++;
            }
            int number = stoi(temp);
            if(negitive) number = -1*number;
            sum+=number;
            temp="";
        }
    }
}


int get_number() {
    return sum;
}


