//
//  bai 2.cpp
//  c++
//
//  Created by L Khang on 10/26/18.
//  Copyright © 2018 L Khang. All rights reserved.
//

#include <stdio.h>
#include <iostream>
using namespace std;
class MoneyAcc {
private:
    double money;
    int years;
    double rate;
public:
    MoneyAcc(double mon, int years, double rate) {
        this->money = mon;
        this->years = years;
        this->rate = rate;
    }
static MoneyAcc* iNit();
    void print();
    void tinhToan();
};
MoneyAcc* MoneyAcc::iNit() {
    double mon;
    int years;
    double rate;
    cout <<"Enter initial amount: ";
    cin >> mon;
    cout << "Enter number of years: ";
    cin >> years;
    cout << "Enter interest rate (percent per year): ";
    cin >> rate;
    
    return new MoneyAcc(mon, years,rate);
    
}
void MoneyAcc::tinhToan() {
    for (int i = 0; i < this->years; i++) {
        this->money = (this->money)*(1+(this->rate)/100);
    }
}
void MoneyAcc::print() {
    tinhToan();
    cout << "At the end of " << this->years <<  " years, you will have "<<this->money << " dollars.";
}

int main() {
    MoneyAcc* myAcc = MoneyAcc::iNit();
    myAcc->print();
    return 0;
}
