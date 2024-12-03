#include <string>
using namespace std;
string do_stuff(string s) {
    int i=0;
    string temp;
    int count=1;
    while(i<s.size()) {
        if(s[i] == s[i+1]) {
            count++;
        }
        else {
            temp+=(to_string(count)+s[i]);
            count=1;
        }
        i++;
    }
    return temp;
}
