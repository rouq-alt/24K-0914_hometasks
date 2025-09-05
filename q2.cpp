#include <iostream>
using namespace std;

class Box {
private:
    int* volume;

public:
    Box() {
        volume = new int(0);
    }

    Box(int v) {
        volume = new int(v);
    }

    Box(const Box& obj) {
        volume = new int(*obj.volume);
    }

    ~Box() {
        delete volume;
    }

    void setVolume(int v) {
        *volume = v;
    }

    int getVolume() {
        return *volume;
    }
};

int main() {
    Box b1; 
    cout << "b1 Volume:" << b1.getVolume() << endl;
    Box b2(500);
    cout << "b2 Volume: " << b2.getVolume() << endl;
    Box b3 = b2;
    b3.setVolume(100);
    cout << "b3 Volume (changed): "<<b3.getVolume() << endl;
    cout << "b2 Volume (original unchanged): " << b2.getVolume() << endl;
    return 0;
}
