#include <string>

using namespace std;
class Node {
private:
    int compute_val(int val, std::string oper) {
        if(oper == "") {
            return val;
        }
        return 65535 ^ val;
    }

    int compute_val(int left_val, int right_val, std::string operation) {
        if(operation == "AND") return left_val & right_val;
        else if(operation == "OR") return left_val | right_val;
        else if(operation == "LSHIFT") return left_val << right_val;
        else return left_val >> right_val;
    }
public:
    int val=-1;
    std::string id;
    std::string operation = "";
    Node *left;
    Node *right;
    int get_val() {
        if(val !=-1) return val;
        if(left == nullptr) this->val = compute_val(right->get_val(), this->operation);
        else this->val = compute_val(left->get_val(), right->get_val(), operation);
        return this->val;
    }
};
