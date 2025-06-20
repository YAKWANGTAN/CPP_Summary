#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Book
{
public:
    string title;
    string author;

    Book(const string& title, const string& author)
        :title(title), author(author)
    {
    }
};

class BookManager
{
private:
    vector<Book> books;

public:
    void addBook(const string& title, const string& author)
    {
        books.push_back(Book(title, author));
        cout << "책이 추가되었습니다: " << title << "by " << author << endl;
    }

    void displayAllBooks() const
    {
        if (books.empty())
        {
            cout << "현재 등록된 책이 없습니다." << endl;
            return;
        }

        cout << "현재 도서 목록:" << endl;
        for (size_t i = 0; i < books.size(); i++)
        {
            cout << "- " << books[i].title << "by " << books[i].author << endl;
        }
    }

    void searchByTitle(string& title)
    {
        for (Book& book : books)
        {
            if (title == book.title)
            {
                cout << "책 제목: " << title << "을(를) 찾았습니다." << endl;
                return:
            }
        }

        cout << title << "라는 책을 찾지 못했습니다." << endl;
    }

    void searchByAuthor(string& author)
    {
        for (Book& book : books)
        {
            if (author == book.author)
            {
                cout << "책 제목: " << book.title << "을(를) 찾았습니다." << endl;
                return:
            }
        }

        cout << "저자 " << title << "의 책을 찾지 못했습니다." << endl;
    }
};

class BorrowManager { ... };

int main()
{
    BookManager manager;

    while (true)
    {
        system("cls");

        cout << "\n도서관 관리 프로그램" << endl;
        cout << "1. 책 추가" << endl;
        cout << "2. 모든 책 출력" << endl;
        cout << "3. 제목으로 책 검색" << endl;
        cout << "4. 저자로 책 검색" << endl;
        cout << "5. 종료" << endl;
        cout << "선택:";

        int choice;
        cin >> choice;
        cin ignore();

        if(choice == 1)
        {
            string title, author;
            cout << "책 제목: ";
            getline(cin, title);
            cout << "책 저자: ";
            getline(cin, author);
            manager.addBook(title, author);
        }
        else if (choice == 2)
        {
             manager.displayAllBooks();
        }
        else if (choice == 3)
        {
             string title;
             cout << "검색할 책 제목: ";
             getline(cin, title);
             manager.searchByTitle(title);
        }
        else if (choice == 4)
        {
             string author;
             cout << "검색할 책 저자: ";
             getline(cin, author);
             manager.searchByAuthor(author);
        }
        else if (choice == 5)
        {
            cout << "프로그램을 종료합니다." << endl;
            break;
        }
        else
        {
            cout << "잘못된 입력입니다. 다시 시도하세요." << endl;
        }

        system("pause");
    }

    return 0;
}