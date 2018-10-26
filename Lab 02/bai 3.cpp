//
//  bai 3.cpp
//  c++
//
//  Created by L Khang on 10/26/18.
//  Copyright © 2018 L Khang. All rights reserved.
//

#include <stdio.h>
#include <iostream>
using namespace std;
class tinhToan {
private:
    int a, b;
    char phepTinh;
public:
  static void iNit();
   static void tinh();
};
    void tinhToan::tinh() {
    int a, b;
    char c;
    double result = 0;
    cout << "Enter first number, operator, second number: ";
    cin >> a >> c >> b;
    switch (c) {
        case '+':
            result = a + b;
            break;
        case '-':
            result = a - b;
            break;
        case '*':
            result = a*b;
            break;
        case '/':
            result = a/b;
            break;
        default:
            cout << " thong tin nhap sai.." << endl;
            break;
    }
    cout << "Answer: " << result << endl;
}
 void tinhToan::iNit() {
    char c;
    bool flag, ans;
    do {
        flag = true;
        ans = true;
        tinh();
        while (ans) {
            cout << "Do another (y/n)? : ";
            cin >> c;
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
int main() {
    tinhToan::iNit();
    return 0;
}
