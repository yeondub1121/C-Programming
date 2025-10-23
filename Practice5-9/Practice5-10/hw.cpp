#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

class Person {
private:
    char* name;
    int id;

public:
    Person(int id, const char* name);      // ������
    Person(const Person& person);          // ���� ������
    ~Person();                             // �Ҹ���

    void changeName(const char* name);     // �̸� ����
    void show() { cout << id << ", " << name << endl; }
};

Person::Person(int id, const char* name) { // ������
    this->id = id;
    int len = strlen(name);
    this->name = new char[len + 1];
    strcpy(this->name, name);
}

Person::Person(const Person& person) {     // ���� ������
    this->id = person.id;
    int len = strlen(person.name);
    this->name = new char[len + 1];
    strcpy(this->name, person.name);
    cout << "���� ������ ����. ���� ��ü�� �̸� = " << this->name << endl;
}

Person::~Person() {                        // �Ҹ���
    if (name)
        delete[] name;
}

void Person::changeName(const char* name) {
    if (strlen(name) > strlen(this->name))
        return;
    strcpy(this->name, name);
}

int main() {
    Person father(1, "Kitae");             // (1) father ��ü ����
    Person daughter(father);               // (2) daughter ���� ������ ȣ��

    cout << "daughter ��ü ���� ���� ---" << endl;
    father.show();                         // (3)
    daughter.show();                       // (3)

    daughter.changeName("Grace");          // (4)
    cout << "daughter �̸��� Grace�� ������ �� ---" << endl;
    father.show();                         // (5)
    daughter.show();                       // (5)

    return 0;                              // (6)(7) �Ҹ��� ȣ��
}
