#include <iostream>
using namespace std;

void f(int x) {
    class Local {
    public:
        Local(int z) : y(z) {}
        void print() { cout << "Rezult = " << y << endl; }
    private:
        int y;
    };
    
    Local obj(x);
    obj.print();
}

int main() {
    f(5); // Outputs: Rezult = 5
    return 0;
}
