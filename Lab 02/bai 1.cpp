#include <iostream>
using namespace std;

class soDT {
private:
    int area;
    int exchange;
    int number;
    
public:

    soDT(){
        this->area = 212;
        this->exchange = 767;
        this->number = 8900;
    }
    soDT(int area, int ex, int num){
        this->area = area;
        this->exchange = ex;
        this->number = num;
    }
    
    string print();
static soDT* iNit();
    
};

soDT* soDT::iNit() {
    cout << "Enter your area code, exchange, number: ";
    int a, e, n;
    cin >> a >> e >>n;
    return new soDT(a,e,n);
}
string soDT::print() {
    return "("+ to_string(this->area) + ") " + to_string(this->exchange) + "-" + to_string(this->number);
}

///////////////////////
int main()
{
    soDT* your = soDT::iNit();
    soDT* my = new soDT();
    cout << "My number is " << my->print() << endl;
    cout << "Your number is " << your->print();
    return 0;
}
