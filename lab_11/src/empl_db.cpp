#include <iostream> 
#include <string>
#include <cstring>
#include<fstream>
#include "../include/employees.h"
int main() {
    EmployeesArray arr;
    std::string filename;
    char cm[5];
    while (1) {
        std::cin >> cm;
        if (!strcmp("exit", cm))
            break;
        else if (!strcmp("add", cm)) {
            int32_t type;
            std::cin >> type;
            if (type == 1) {
                Employee *dev = new Developer;
                std::cin >> *dev;
                arr.add(dev);
            }
            else {
                Employee *sm = new SalesManager;
                std::cin >> *sm;
                arr.add(sm);
            }
        }
        else if (!strcmp("list", cm)) {
            std::cout << arr;
            std::cout << "== Total salary: " << arr.total_salary() << "\n\n";
        }
        else if (!strcmp("save", cm)) {
            std::cin >> filename;
            char *fn = new char[filename.length() + 1];
            strcpy(fn, filename.c_str());
            std::ofstream ofs(fn, std::ofstream::binary);
            ofs << arr;
            delete[] fn;
        }
        else if (!strcmp("load", cm)) {
            std::cin >> filename;
            char *fn = new char[filename.length() + 1];
            strcpy(fn, filename.c_str());
            std::ifstream ofs(fn, std::ifstream::binary);
            ofs >> arr;
            delete[] fn;
        }
    }
    return 0;
}
