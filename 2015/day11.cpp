#include <iostream>
#include <string>

using namespace std;

bool verify(string str) {
    for(int i=7; i>=0; i--) {
        if(str[i] == 'i' || str[i] == 'l' || str[i] == 'o') return false;
    }
    bool sequence = false;
    for(int i=0; i<6; i++) {
        if(str[i] == str[i+1]-1 && str[i] == str[i+2] -2)
            sequence = true;
    }
    if(!sequence) return false;
    int found = 0;
    for(int i=0; i<7; i++) {
        if(str[i] == str[i+1] && str[i] != str[i+2]) found++;
    }
    return found >= 2;
}

void get_next(string &str) {
    for(int i=7; i>=0; i--) {
        if(str[i] == 'z') {
            str[i] = 'a';
        }
        else {
            str[i]++;
            break;
        }
    }
}
void generate_sol(string line) {
    while(!verify(line)) {
        get_next(line);
    }
    get_next(line);
    while(!verify(line)) {
        get_next(line);
    }
    cout<<line;
}
