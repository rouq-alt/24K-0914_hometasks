#include <iostream>
#include <string>
using namespace std;

class ResearchPaper {
private:
    string* authors;
    int count;

public:
    ResearchPaper() {
        count = 3;
        authors = new string[count];
        for (int i=0;i<count;i++) {
            authors[i] = "Unknown";
        }
    }
    ResearchPaper(int n, string names[]) {
        count=n;
        authors = new string[count];
        for (int i =0;i<count;i++) {
            authors[i] = names[i];
        }
    }
    ResearchPaper(const ResearchPaper& obj) {
        count=obj.count;
        authors = new string[count];
        for (int i=0; i<count;i++) {
            authors[i] = obj.authors[i];
        }
    }

    ResearchPaper& operator=(const ResearchPaper& obj) {
        if (this == &obj) return *this;
        delete[] authors;
        count = obj.count;
        authors = new string[count];
        for (int i =0;i<count;i++) {
            authors[i] = obj.authors[i];
        }
        return *this;
    }

    ~ResearchPaper() {
        delete[] authors;
    }

    void showAuthors() {
    	cout<<"\nAuthors:" ;
        for (int i=0;i<count;i++) {
            cout <<authors[i] << " ";
            cout<<endl;
        }
    }

    int getAuthorCount() const {
        return count;
    }
};

int main() {
	ResearchPaper r1;
    cout << "Paper Authors: ";
    r1.showAuthors();
    cout<<"Author Count: " << r1.getAuthorCount()<<endl;
    string names[] = {"Ali", "Babar", "Hania","Aqsa"};
    ResearchPaper r2(4, names);
    cout<<"\nNew Paper Authors: ";
    r2.showAuthors();
    cout << "Author Count: " <<r2.getAuthorCount() << endl;
    return 0;
}
