#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "Library_Management.cpp"

using namespace std;

TEST_CASE("Date Class Tests") {
    SECTION("Test setDueDate method") {
        Date currentDate(1, 1, 2025);
        Date dueDate(1, 1, 2025);
        dueDate.setDueDate(currentDate);
        REQUIRE(dueDate.getDay(dueDate) == 4);
        REQUIRE(dueDate.getMonth(dueDate) == 1);
        REQUIRE(dueDate.getYear(dueDate) == 2025);
    }
}

TEST_CASE("Member Class Tests") {
    SECTION("Test setName, getEmail, and setAddress methods") {
        Member member(1, "John Doe", "123 Main St", "john@example.com");
        member.setName("New Name");
        member.setEmail("newemail@example.com");
        member.setAddress("456 Oak St");
        REQUIRE(member.getName() == "New Name");
        REQUIRE(member.getEmail() == "newemail@example.com");
        REQUIRE(member.getAddress() == "456 Oak St");
    }

    SECTION("Test getMemberID and getBooksBorrowed methods") {
        Member member(1, "John Doe", "123 Main St", "john@example.com");
        REQUIRE(member.getMemberID() == 1);
        REQUIRE(member.getBooksBorrowed().empty());
    }

    SECTION("Test setBooksBorrowed method") {
        Member member(1, "John Doe", "123 Main St", "john@example.com");
        Book book(1, "Science Fiction", "John", "Doe");
        member.setBooksBorrowed(book);
        REQUIRE(member.getBooksBorrowed().size() == 1);
    }
}

TEST_CASE("Book Class Tests") {
    SECTION("Test getBookID, getBookName, getAuthorFirstName, and getAuthorLastName methods") {
        Book book(1, "Science Fiction", "John", "Doe");
        REQUIRE(book.getBookID() == 1);
        REQUIRE(book.getBookName() == "Science Fiction");
        REQUIRE(book.getAuthorFirstName() == "John");
        REQUIRE(book.getAuthorLastName() == "Doe");
    }

    SECTION("Test borrowBook and returnBook methods") {
        Member borrower(1, "Borrower", "789 Elm St", "borrower@example.com");
        Book book(1, "Science Fiction", "John", "Doe");
        Date dueDate(1, 1, 2026);

        SECTION("Test borrowBook method") {
            book.borrowBook(&borrower, dueDate);
            REQUIRE(book.getDueDate().getYear() == 2026);
            REQUIRE(book.getDueDate().getMonth() == 1);
            REQUIRE(book.getDueDate().getDay() == 1);
            REQUIRE(book.getDueDate().getYear(book.getDueDate()) == 2026);
        }

        SECTION("Test returnBook method") {
            book.returnBook();
            REQUIRE(book.getDueDate().getYear() == 2025);
            REQUIRE(book.getDueDate().getMonth() == 12);
            REQUIRE(book.getDueDate().getDay() == 12);
        }
    }
}

TEST_CASE("Librarian Class Tests") {
    SECTION("Test addMember method") {
        Librarian librarian(1, "Librarian", "Librarian", "librarian@email.com", 50000);
        librarian.addMember();
        REQUIRE(librarian.members.size() == 1);
    }

    SECTION("Test issueBook and returnBook methods") {
        Librarian librarian(1, "Librarian", "Librarian", "librarian@email.com", 50000);
        librarian.addMember(); 
        librarian.issueBook(1, 1);
        REQUIRE(librarian.members[0].getBooksBorrowed().size() == 1);
        librarian.returnBook(1, 1);
        REQUIRE(librarian.members[0].getBooksBorrowed().empty());
    }

    SECTION("Test displayBorrowedBooks method") {
        Librarian librarian(1, "Librarian", "Librarian", "librarian@email.com", 50000);
        librarian.addMember();
        librarian.issueBook(1, 1);
        ostringstream oss;
        streambuf* p_cout_streambuf = cout.rdbuf();
        cout.rdbuf(oss.rdbuf());
        librarian.displayBorrowedBooks(1);
        cout.rdbuf(p_cout_streambuf);
        REQUIRE(oss.str() == "Borrowed Books by Member ID 1:\nBook ID: 1, Book Name: Science Fiction\n");
    }

    SECTION("Test calcFine method") {
        Librarian librarian(1, "Librarian", "Librarian", "librarian@email.com", 50000);
        librarian.addMember();
        librarian.issueBook(1, 1);
        ostringstream oss;
        streambuf* p_cout_streambuf = cout.rdbuf();
        cout.rdbuf(oss.rdbuf());
        librarian.calcFine(1);
        cout.rdbuf(p_cout_streambuf);
        REQUIRE(oss.str() == "No fines for this member.\n");
    }
}
