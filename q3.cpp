#include <iostream>
using namespace std;

class Exam {
private:
    int* marks;
    int size;

public:
    Exam(int s) {
        size=s;
        marks = new int[size];
        for (int i=0; i<size; i++) {
            marks[i] =0;
        }
    }
    ~Exam() {
        delete[] marks;
    }

    void showMarks() {
        for (int i=0; i<size; i++) {
            cout<<marks[i] << " ";
        }
        cout << endl;
    }

    void setMark(int index, int value) {
        if (index>=0 && index <size) {
            marks[index]=value;
        }
    }
};


int main() {
    Exam e1(3);
    cout << "Exam e1 marks: ";
    e1.showMarks();
    Exam e2 = e1;
    e2.setMark(0, 92);
    e2.setMark(1,78);
    e2.setMark(2,86);
    cout << "Exam e2 marks: ";
    e2.showMarks();
    cout << "Exam e1 marks after copying:";
    e1.showMarks();

    return 0;
}
