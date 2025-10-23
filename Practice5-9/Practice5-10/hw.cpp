#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

class Person {
private:
    char* name;
    int id;

public:
    Person(int id, const char* name);      // 생성자
    Person(const Person& person);          // 복사 생성자
    ~Person();                             // 소멸자

    void changeName(const char* name);     // 이름 변경
    void show() { cout << id << ", " << name << endl; }
};

Person::Person(int id, const char* name) { // 생성자
    this->id = id;
    int len = strlen(name);
    this->name = new char[len + 1];
    strcpy(this->name, name);
}

Person::Person(const Person& person) {     // 복사 생성자
    this->id = person.id;
    int len = strlen(person.name);
    this->name = new char[len + 1];
    strcpy(this->name, person.name);
    cout << "복사 생성자 실행. 원본 객체의 이름 = " << this->name << endl;
}

Person::~Person() {                        // 소멸자
    if (name)
        delete[] name;
}

void Person::changeName(const char* name) {
    if (strlen(name) > strlen(this->name))
        return;
    strcpy(this->name, name);
}

int main() {
    Person father(1, "Kitae");             // (1) father 객체 생성
    Person daughter(father);               // (2) daughter 복사 생성자 호출

    cout << "daughter 객체 생성 직후 ---" << endl;
    father.show();                         // (3)
    daughter.show();                       // (3)

    daughter.changeName("Grace");          // (4)
    cout << "daughter 이름을 Grace로 변경한 후 ---" << endl;
    father.show();                         // (5)
    daughter.show();                       // (5)

    return 0;                              // (6)(7) 소멸자 호출
}
