#include <iostream>
using namespace std;

class CL1 {
public:
    CL1(int x) : x(x) {}
    void print() { cout << x << endl; }
    class CL2 {
    public:
        CL2(CL1& a1, int y1) : a(a1), y(y1) {}
        void print() {
            cout << "CL1::CL2::print()->" << endl;
            a.print();
            cout << y << endl;
        }
        class CL3 {
        public:
            CL3(CL2& b1, int z1) : b(b1), z(z1) {}
            void print() {
                cout << "CL1::CL2::CL3::print()->" << endl;
                b.print();
                cout << z << endl;
            }
        private:
            CL2& b;
            int z;
        };
    private:
        CL1& a;
        int y;
    };
private:
    int x;
};

int main() {
    CL1 a(1);
    a.print(); // Outputs: 1
    CL1::CL2 b(a, 2);
    b.print(); // Outputs: CL1::CL2::print()-> 1 2
    CL1::CL2::CL3 c(b, 3);
    c.print(); // Outputs: CL1::CL2::CL3::print()-> CL1::CL2::print()-> 1 2 3
    return 0;
}
