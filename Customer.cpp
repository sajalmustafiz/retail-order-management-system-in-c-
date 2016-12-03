#include <iostream>
using namespace std;

class Customer {
public:
    Customer() {
        ID = 0;
        Name = "";
        Address = "";
        ContactNumber = "";
    }

    void SetID(int idVal) {
        ID = idVal;
    }

    void SetName(string n) {
        Name = n;
    }

    void SetAddress(string addr) {
        Address = addr;
    }

    void SetContactNumber(string CN) {
        ContactNumber = CN;
    }

    int GetID() {
        return ID;
    }

    string GetName() {
        return Name;
    }

    string GetAddress() {
        return Address;
    }

    string GetContactNumber() {
        return ContactNumber;
    }

private:
    int ID;
    string Name;
    string Address;
    string ContactNumber;
};
