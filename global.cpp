#include <iostream>
using namespace std;

class CL1 {
public:
    CL1(int x) : x(x) {}
    int Get() { return x; }
private:
    int x;
};

class CL2 {
public:
    CL2(int y) : y(y) {}
    int Get() { return y; }
    int Get(CL1 a) { return a.Get(); }
private:
    int y;
};

int main() {
    CL1 a(1);
    CL2 b(2);
    cout << a.Get() << endl; // Outputs: 1
    cout << b.Get() << endl; // Outputs: 2
    cout << b.Get(a) << endl; // Outputs: 1
    return 0;
}
