#include<iostream>
using namespace std;

class Person {

protected:

    string name;
    string address;
    string email;

public:
    
    void setName (const string& newName) {
        name = newName;
    }

    void setEmail (const string& newEmail) {
        email = newEmail;
    }

    void setAddress (const string& newAddress) {
        address = newAddress;
    }

    string getAddress() const {
        return address;
    }

    string getEmail() const {
        return email;
    }

    string getName() const {
        return name;
    }

    

};

int main()
{

}