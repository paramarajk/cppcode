#include <iostream>
#include <string.h>
using namespace std;

class assign {
    char *_emp_name;
    int _emp_id;
public:
    assign(const char *name = NULL, int id = 0) : _emp_id(id) {
        if(name != NULL) {
            _emp_name = new char[strlen(name)];
            strcpy(_emp_name, name);
            } else {
                _emp_name = NULL;
            }
            cout << "assign ctor" << endl;    
    }
    
    assign(const assign &obj) {
        if(obj._emp_name != NULL) {
            _emp_name = new char[strlen(obj._emp_name)];
            strcpy(_emp_name, obj._emp_name);
            _emp_id = obj._emp_id;    
        }
        cout << "assign copy ctor" << endl;
    }
    
    assign& operator=(const assign &obj) {
        if(this != &obj) {
            if (_emp_name != NULL) {
                delete [] _emp_name;
                _emp_name = NULL;
            }
            _emp_name = new char[strlen(obj._emp_name)];
            strcpy((char*)_emp_name, obj._emp_name);
            _emp_id = obj._emp_id;
        }
        cout << "assign assignmnet operator" << endl;
        return *this;
    }
    
    void print() {
        cout << "assign print func ---------->" << endl;
        cout << "emp name : " << _emp_name << endl;
        cout << "emp id : " << _emp_id << endl;
    }
    
    ~assign() {
        if(_emp_name != NULL) {
            delete [] _emp_name;
            _emp_name = NULL;
            cout << "assign dest" << endl;
        }
    }
};


int main() {
    assign a1("Ramu", 10001);
    a1.print();
    assign a2(a1);
    a2.print();
    assign a3;
    a3 = a2;
    a3.print();
    
    return 0;
}