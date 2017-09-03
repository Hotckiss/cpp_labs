#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include "matrix.h"
using namespace std;
int get() {
    string re;
    cin >> re;
    return re[1] - '0';
}
int main() {
    Matrix reg[10];
    while (1) {
        try {
            string cmd;
            cin >> cmd;
            if (cmd == "add") {
                int r1 = get(), r2 = get();
                reg[r1] += reg[r2];
            }
            else if (cmd == "mul") {
                int r1 = get(), r2 = get();
                reg[r1] *= reg[r2];
            }
            else if (cmd == "exit")
                break;
            else if (cmd == "load") {
                int re = get(), r, c, num;
                string filename;
                cin >> filename;
                ifstream ifs(filename.c_str(), ifstream::in);
                ifs >> r >> c;
                Matrix mtx(r, c);
                for (int i = 0; i < r; i++)
                    for (int j = 0; j < c; j++)
                        ifs >> num, mtx.set(i, j, num);
                reg[re] = mtx;
            }
            else if (cmd == "elem") {
                int re = get();
                string row, col;
                cin >> row >> col;
                cout << reg[re].get(atoi(row.c_str()), atoi(col.c_str())) << "\n";
            }
            else if (cmd == "print") {
                reg[get()].print(cout);
            }
            else
                continue;
        }
        catch(const MatrixException& matrixException) {
            cerr << matrixException.GetErrorMessage();
        }
    }
    return 0;
}
