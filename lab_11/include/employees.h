#pragma once

#include <stdint.h>
#include <string.h>
#include <iostream>
#include <string>
#include <fstream>

class Employee {
private:
    virtual void fprint(std::ofstream &fout) const = 0;
    virtual void print(std::ostream &fout) const = 0;
    virtual void read(std::istream &fin) = 0;
    virtual void readf(std::ifstream &fin) = 0;
    Employee(const Employee & e);
    Employee & operator=(const Employee & e);
public:
    Employee();
    friend std::ofstream & operator<<(std::ofstream &fout, const Employee & e);
    friend std::ostream & operator<<(std::ostream &fout, const Employee & e);
    friend std::istream & operator>>(std::istream &fin, Employee & e);
    friend std::ifstream & operator>>(std::ifstream &fin, Employee & e);
    virtual int salary() const = 0;
    virtual ~Employee();
protected:
    char *_name;
    int32_t _base_salary;
};
class Developer : public Employee {
private:
    bool _has_bonus;
    void print(std::ostream &fout) const;
    void fprint(std::ofstream &fout) const;
    void read(std::istream &fin);
    void readf(std::ifstream &fin);
public:
    Developer();
    int salary() const;
    ~Developer();
};

class SalesManager : public Employee {
private:
    int32_t _sold_nm, _price;
    void print(std::ostream &fout) const;
    void fprint(std::ofstream &fout) const;
    void read(std::istream &fin);
    void readf(std::ifstream &fin);
public:
    SalesManager();
    int salary() const;
    ~SalesManager();    
};

class EmployeesArray {
private:
    Employee **_employees;
    int32_t cap;
    int32_t sz;
    EmployeesArray(const EmployeesArray & e);
    EmployeesArray & operator=(const EmployeesArray & e);
public:
    EmployeesArray();
    ~EmployeesArray();
    void add(const Employee *e);
    int total_salary() const;
    friend std::ofstream & operator<<(std::ofstream &fout, EmployeesArray & employees);
    friend std::ostream & operator<<(std::ostream &fout, EmployeesArray & employees);
    friend std::ifstream & operator>>(std::ifstream &fin, EmployeesArray & employees);
};
