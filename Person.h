#ifndef PERSON_H
#define PERSON_H
#include <iostream>
#include <fstream>
#include <string>

using namespace std;
#pragma once

class Person {
private:
    string ten;
    string sdt;
    string diachi;

public:
    const string& getTen() const {
        return ten;
    }

    void setTen(const string& tenPerson) {
        ten = tenPerson;
    }

    const string& getSDT() const {
        return sdt;
    }

    void setSDT(const string& sdtPerson) {
        sdt = sdtPerson;
    }

    const string& getDiaChi() const {
        return diachi;
    }

    void setDiaChi(const string& diaChiPerson) {
        diachi = diaChiPerson;
    }
};

#endif