//
//  bai 4.cpp
//  c++
//
//  Created by L Khang on 10/26/18.
//  Copyright © 2018 L Khang. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <sstream>
using namespace std;
class phanSo {
private:
    int tuSo, mauSo;
public:
    phanSo() {
        int tuSo, mauSo;
        char c;
        string frac;
        bool flag = true;
        
        while (flag) {
            cout << " Enter fraction (a/b): ";
            stringstream ss;
            getline(cin,frac);
            ss << frac;
            ss >> tuSo >> c >> mauSo;
            if (c != '/') {
                flag = true;
                cout << "Erro input (a/b). Please do it again ";
            } else {
                flag = false;
                this->tuSo = tuSo;
                this->mauSo = mauSo;
            }
        }
    }
    
    phanSo(int tuSo, int mauSo) {
        this->tuSo = tuSo;
        this->mauSo = mauSo;
    }
    
    
    static phanSo* tinhPhanSo(phanSo* ps1, phanSo* ps2, char phepTinh);
    static phanSo* rutGonPs(int tuSo, int mauSo);
    static int UCLN(int a, int b);
    static void phepTinh2PS();
    static void iNit();
    
    int getTuSo();
    int getMauSo();
};
int phanSo::UCLN(int a, int b) {
    if (a == 0)
        return b;
    return UCLN(b%a, a);
}
phanSo* phanSo::rutGonPs(int tuSo, int mauSo) {
    int ucln = UCLN(tuSo, mauSo);
    return new phanSo(tuSo/ucln,mauSo/ucln);
    
}

phanSo* phanSo::tinhPhanSo(phanSo* ps1, phanSo* ps2, char phepTinh) {
    int tuSo = 0, mauSo = 1;
    switch (phepTinh) {
        case '+': {
            tuSo = ps1->tuSo*ps2->mauSo + ps2->tuSo*ps1->mauSo;
            mauSo = ps1->mauSo*ps2->mauSo;
            break;
        }
        case '-':
        {
            int test = ps1->tuSo/ps1->mauSo - ps2->tuSo/ps2->mauSo;
            if (test >= 0) {
                tuSo = ps1->tuSo*ps2->mauSo - ps2->tuSo*ps1->mauSo;
            } else {
                tuSo = ps2->tuSo*ps1->mauSo - ps1->tuSo*ps2->mauSo;
            }
            mauSo = ps1->mauSo*ps2->mauSo;
            break;
        }
        case '*':
        {
            tuSo = ps1->tuSo*ps2->tuSo;
            mauSo = ps1->mauSo*ps2->mauSo;
            break;
        }
        case '/':
        {
            tuSo = ps1->tuSo*ps2->mauSo;
            mauSo = ps1->mauSo*ps2->tuSo;
        }
    }
    
    return rutGonPs(tuSo, mauSo);
}

void phanSo::phepTinh2PS() {
    string phepTinh;
    char phepTinhC;
    phanSo* ps1 = new phanSo();
    cout << "nhap phep tinh: ";
    getline(cin,phepTinh);
    stringstream ss;
    ss << phepTinh;
    ss >> phepTinhC;
    phanSo* ps2 = new phanSo();
    phanSo* ps3 = phanSo::tinhPhanSo(ps1, ps2, phepTinhC);
    cout << "Answer : " << ps3->getTuSo()<< "/" << ps3->getMauSo() <<" = "<< ps3->getTuSo()/ps3->getMauSo()<< endl;
}
void phanSo::iNit() {
    string s;
    char c;
    bool flag, ans;
    do {
        flag = true;
        ans = true;
        phanSo::phepTinh2PS();
        while (ans) {
            cout << "Do another (y/n)? : ";
            getline(cin, s);
            stringstream ss;
            ss << s;
            ss >>c;
            switch (c) {
                case 'y':
                    flag = true;
                    ans = false;
                    break;
                case 'n':
                    flag = false;
                    ans = false;
                    break;
                default:
                    cout << "Please do it again. ";
                    ans = true;
                    break;
            }
        }
    } while (flag);
}

int phanSo::getTuSo() {
    return this->tuSo;
}
int phanSo::getMauSo() {
    return this->mauSo;
}

int main() {
    phanSo::iNit();
   
    return 0;
}
