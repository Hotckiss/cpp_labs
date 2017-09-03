#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include <string>
#include <fstream>
#include <iostream>

#include "../include/employees.h"

Employee::Employee() {}

Developer::Developer() {}

SalesManager::SalesManager() {}

Employee::~Employee() {
    delete[] _name;
}

Developer:: ~Developer() {}

SalesManager::~SalesManager() {}

EmployeesArray::EmployeesArray() {
    cap = 2;
    sz = 0;
    _employees = new Employee*[cap];
}

EmployeesArray::~EmployeesArray() {
    for (int i = 0; i < sz; i++)
        delete _employees[i];
    delete[] _employees;
}

int SalesManager::salary() const {
    return _base_salary + _sold_nm * _price * 0.01;
}

int Developer::salary() const {
    return _base_salary + (_has_bonus ? 1000 : 0);
}

void EmployeesArray::add(const Employee *e) {
    if (sz == cap) {
        Employee** tmp = new Employee*[2 * cap];
        memcpy(tmp, this->_employees, sz * sizeof(Employee*));
        delete[] this->_employees;
        this->_employees = tmp;
        cap *= 2;
    }
    this->_employees[sz] = (Employee *) e;
    sz++;
}

std::ofstream & operator<<(std::ofstream &fout, const Employee & e) {
    e.fprint(fout);
    return fout;
}

std::ostream & operator<<(std::ostream &fout, const Employee & e) {
    e.print(fout);
    return fout;
}

std::istream & operator>>(std::istream &fin, Employee & e) {
    e.read(fin);
    return fin;
}

std::ifstream & operator>>(std::ifstream &fin, Employee & e) {
    e.readf(fin);
    return fin;
}

void Developer::print(std::ostream &fout) const {
    fout << "Developer\nName: " << _name << "\nBase Salary: " << _base_salary << "\nHas bonus: " << (_has_bonus ? "+" : "-") << "\n";
}

void Developer::fprint(std::ofstream &fout) const {
    int32_t type = 1;
    fout.write((char*)&type, sizeof(type));
    fout.write(_name, strlen(_name) + 1);
    fout.write((char*)&_base_salary, sizeof(_base_salary));
    fout.write((char*)&_has_bonus, sizeof(_has_bonus));
}

void Developer::read(std::istream &fin) {
    std::string str;
    fin >> str;
    _name = new char[str.length() + 1];
    strcpy(_name, str.c_str());
    fin >> _base_salary >> _has_bonus;
}

void Developer::readf(std::ifstream &fin) {
    std::string str;
    getline(fin, str, '\0');
    _name = new char[str.length() + 1];
    strcpy(_name, str.c_str());
    fin.read((char*)&_base_salary, sizeof(int32_t));
    fin.read((char*)&_has_bonus, sizeof(bool));
}

void SalesManager::print(std::ostream &fout) const {
    fout << "Sales Manager\nName: " << _name << "\nBase Salary: " << _base_salary << "\nSold items: " << _sold_nm << "\nItem price: " << _price << "\n";
}

void SalesManager::fprint(std::ofstream &fout) const {
    int32_t type = 2;
    fout.write((char*)&type, sizeof(type));
    fout.write(_name, strlen(_name) + 1);
    fout.write((char*)&_base_salary, sizeof(_base_salary));
    fout.write((char*)&_sold_nm, sizeof(_sold_nm));
    fout.write((char*)&_price, sizeof(_price));
}

void SalesManager::read(std::istream &fin) {
    std::string str;
    fin >> str;
    _name = new char[str.length() + 1];
    strcpy(_name, str.c_str());
    fin >> _base_salary >> _sold_nm >> _price;
}
void SalesManager::readf(std::ifstream &fin) {
    std::string str;
    getline(fin, str, '\0');
    _name = new char[str.length() + 1];
    strcpy(_name, str.c_str());
    fin.read((char*)&_base_salary, sizeof(int32_t));
    fin.read((char*)&_sold_nm, sizeof(int32_t));
    fin.read((char*)&_price, sizeof(int32_t));
}

std::ifstream & operator>>(std::ifstream &fin, EmployeesArray & employees) {
    int32_t n, type;
    fin.read((char*)&n, sizeof(int32_t));
    for (int i = 0; i < n; i++) {
        fin.read((char*)&type, sizeof(int32_t));
        if (type == 1) {
            Developer *d;
            d = new Developer;
            fin >> *d;
            employees.add(d);
        }
        if (type == 2) {
            SalesManager *sm;
            sm = new SalesManager;
            fin >> *sm;
            employees.add(sm);
        }
    }
    return fin;
}

std::ofstream & operator<<(std::ofstream &fout, EmployeesArray & employees) {
    fout.write((char*)&employees.sz, sizeof(employees.sz));
    for (int i = 0; i < employees.sz; i++)
        fout << *employees._employees[i];
    return fout;
}

std::ostream & operator<<(std::ostream &fout, EmployeesArray & employees) {
    for (int i = 0; i < employees.sz; i++) {
        fout << i + 1 << ". ";
        fout << *employees._employees[i];
    }
    return fout;
}

int EmployeesArray::total_salary() const {
    int ans = 0;
    for (int i = 0; i < sz; i++) {
        ans += _employees[i]->salary();
    }
    return ans;
}
