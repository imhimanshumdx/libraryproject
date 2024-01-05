#include<iostream>
#include <vector>
using namespace std;

class Book;

class Date {

private:
    int day;
    int month;
    int year;

public:
    Date(int dd,int mm,int yy) 
    {
        day = dd;
        month = mm;
        year = yy;
    }
    
    void setDueDate(Date &date)
    {
        date.day = date.day + 3;
        date.month = date.month;
        date.year = date.year;
        if(date.month > 12 || date.day > 31)
        {
            fixDate(date);
        }
    }

    void fixDate(Date& date)
    {
        if(date.day > 31)
        {
            date.day = date.day - 31;
            date.month = date.month + 1;
        }
        if(date.month > 12)
        {
            date.year = date.year++;
        }
    }
    
};

class Person {

protected:

    string name;
    string address;
    string email;

public:
    
    void setName ( string& newName) {
        name = newName;
    }

    void setEmail (string& newEmail) {
        email = newEmail;
    }

    void setAddress (string& newAddress) {
        address = newAddress;
    }

    string getAddress()  {
        return address;
    }

    string getEmail()  {
        return email;
    }

    string getName()  {
        return name;
    }

};

class Member : public Person {
    
private:
    int memberID;
    vector<Book> booksLoaned;

public:
    Member(int memID, string newName, string newAddress, string newEmail)
    {
        memberID = memID;
        name = newName;
        address = newAddress;
        email = newEmail;
    }
    int getMemberID() {
        return memberID;
    }

    vector<Book> getBooksBorrowed()  {
        return booksLoaned;
    }

    void setBooksBorrowed (Book& book) {
        booksLoaned.push_back(book);
    }
};

class Librarian : public Person {
private:
    int staffID;
    int salary;

public:
    Librarian (int id, string newName, string newAddress, string newEmail, int newSalary) {
        staffID = id;
        name = newName;
        address = newAddress;
        email = newEmail;
        salary = newSalary;
    }

    int getStaffID() {
        return staffID;
    }

    int getSalary () {
        return salary;
    }
    
    void setStaffID (int newStaffID) {
        staffID = newStaffID;
    }

    void setSalary (int newSalary) {
        salary = newSalary;
    }

    void addMember() {
        int memberID;
        string memberName, memberAddress, memberEmail;
        cout << "Enter Member ID: ";
        cin >> memberID;
        cin.ignore();
        cout << "Enter Member Name: ";
        getline(cin, memberName);
        cout << "Enter Member Address: ";
        getline(cin, memberAddress);
        cout << "Enter Member Email: ";
        getline(cin, memberEmail);

        Member newMember(memberID, memberName, memberAddress, memberEmail);

        cout << "New Member Details:" << endl;
        cout << "Member ID: " << newMember.getMemberID() << endl;
        cout << "Name: " << newMember.getName() << endl;
        cout << "Address: " << newMember.getAddress() << endl;
        cout << "Email: " << newMember.getEmail() << endl;
    }

};

class Book {
private:
    int bookID;
    string bookName;
    string authorFirstName;
    string authorLastName;
    string bookType;
    Date dueDate = Date(12,12,2025);
    Member* borrower;
    
public:
    Book (int id, string name, string firstName, string lastName) 
    {
        bookID = id;
        bookName = name;
        authorFirstName = firstName;
        lastName = authorFirstName;
    }
    int getBookID() {
        return bookID;
    }

    string getBookName(){
        return bookName;
    }

    string getAuthorFirstName() {
        return authorFirstName;
    }

    string getAuthorLastName() {
        return authorLastName;
    }

    Date getDueDate() {
        return dueDate;
    }

    void setDueDate(Date& newDueDate) {
        dueDate = newDueDate;
    }

    void returnBook() {
        borrower = nullptr;
    }

    void borrowBook(Member* newBorrower, Date& newDueDate) {
        borrower = newBorrower;
        dueDate = newDueDate;
    }

};


int main()
{
    return 0;
}