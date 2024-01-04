#include<iostream>
#include <vector>
using namespace std;

class Book;

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

class Member : public Person {
    
private:
    int memberID;
    //std::vector<Book> booksLoaned;

public:
    Member(int memID, string newName, string newAddress, string newEmail)
    {
        memberID = memID;
        name = newName;
        address = newAddress;
        email = newEmail;
    }
};

int main()
{
    return 0;
}