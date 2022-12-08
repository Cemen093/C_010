#include <iostream>
#include <conio.h>
using namespace std;

//Тема: Структуры Домашнее задание 1
//Задание 1. Разработайте программу «Библиотека».Создайте структуру «Книга»(название, автор, издательство, жанр).
struct Book
{
    char title[30];
    char author[30];
    char publishingHouse[30];
    char genre[30];
};

void show(Book book);

//Реализуйте следующие возможности :
//■ Редактировать книгу;
void addBook(Book*& books, int& n)
{
    books = (Book*)realloc(books, (n + 1) * sizeof(Book));
    Book book;

    system("cls");
    cout << "добавление книги" << endl;
    cout << "название >> ";
    gets_s(book.title);
    cout << "автор >> ";
    gets_s(book.author);
    cout << "издательство >> ";
    gets_s(book.publishingHouse);
    cout << "жанр >> ";
    gets_s(book.genre);
    books[n] = book;
    n++;

    cout << "книга добавлена" << endl;
    system("pause");
}
void deleteBook(Book*& books, int& n)
{
    char title[30];
    system("cls:");
    cout << "удаление книги" << endl;
    cout << "название >> ";
    gets_s(title);
    bool notFound = true;
    for (size_t i = 0; i < n; i++)
    {
        if (_stricmp(title, books[i].title) == 0)
        {
            notFound = false;
            for (size_t j = 0; j < n - 1; j++)
            {
                books[j] = books[j + 1];
            }
            books = (Book*)realloc(books, (n - 1) * sizeof(Book));
            n--;
            i--;
        }
    }

    if (notFound)
    {
        cout << "book not found" << endl;
    }
    else
    {
        cout << "книга удалена" << endl;
    }
    system("pause");
}

void editBook(Book*& books, int& n)
{

    char title[30];
    system("cls:");
    cout << "редактирование книги" << endl;
    cout << "название >> ";
    gets_s(title);
    bool notFound = true;
    Book book;
    for (size_t i = 0; i < n; i++)
    {
        if (_stricmp(title, books[i].title) == 0)
        {
            notFound = false;
            book = books[i];
            break;
        }
    }
    if (notFound)
    {
        cout << "book not found" << endl;
        system("pause");
        return;
    }

    char ch;
    do
    {
        system("cls");
        cout << "Меню редактирование книги" << endl;
        cout << "Книга" << endl;
        show(book);
        cout << endl;
        cout << "1 - названия" << endl;
        cout << "2 - автор" << endl;
        cout << "3 - издательство" << endl;
        cout << "4 - жанр" << endl;
        cout << "5 - выход" << endl;
        cout << ">> ";
        ch = _getch();

        switch (ch)
        {
        case '1':
            gets_s(book.title);
            break;
        case '2':
            gets_s(book.author);
            break;
        case '3':
            gets_s(book.publishingHouse);
            break;
        case '4':
            gets_s(book.genre);
            break;
        default:
            cout << "пункт не определен" << endl;
            system("pause");
            break;
        }
    } while (ch != '5');
}

void editing(Book*& books, int& n)
{
    char ch;
    do
    {
        system("cls");
        cout << "Меню редактирование" << endl;
        cout << "1 - добавить книгу" << endl;
        cout << "2 - удалить книгу" << endl;
        cout << "3 - редактировать книгу" << endl;
        cout << "4 - назад" << endl;
        cout << " >> ";
        ch = _getch();

        switch (ch)
        {
        case '1':
            addBook(books, n);
            break;
        case '2':
            deleteBook(books, n);
            break;
        case '3':
            editBook(books, n);
            break;
        case '4':
            break;
        default:
            cout << "пункт не определен" << endl;
            system("pause");
            break;
        }
    } while (ch != '4');
}

//■ Печать всех книг;
void show(Book book)
{
    cout << "title\t\t" << book.title << endl;
    cout << "author\t\t" << book.author << endl;
    cout << "publishing\t" << book.publishingHouse << endl;
    cout << "genre\t\t" << book.genre << endl;
}

void ptintAll(Book* books, int n)
{
    system("cls");
    cout << "Все книги:" << endl;
    if (n == 0)
    {
        cout << "Книги не найдены" << endl;
    }

    for (size_t i = 0; i < n; i++)
    {
        show(books[i]);
        cout << endl;
    }
    system("pause");
}
//■ Поиск книг по автору;
void authorSearch(Book* books, int n)
{
    system("cls");
    cout << "поиск книги по автору" << endl;
    cout << "введите автора книги >> ";
    char str[30];
    gets_s(str);

    bool check = true;
    for (size_t i = 0; i < n; i++)
    {
        if (_stricmp(str, books[i].author) == 0)
        {
            show(books[i]);
            cout << endl;
            check = false;
        }
    }

    if (check)
    {
        cout << "книги не найдены" << endl;
    }
        system("pause");
}
//■ Поиск книги под названием;
void titleSearch(Book* books, int n)
{
    system("cls");
    cout << "поиск книги по названию" << endl;
    cout << "введите название книги >> ";
    char str[30];
    gets_s(str);

    bool check = true;
    for (size_t i = 0; i < n; i++)
    {
        if (_stricmp(str, books[i].title) == 0)
        {
            show(books[i]);
            check = false;
        }
    }

    if (check)
    {
        cout << "книги не найдены" << endl;
    }
        system("pause");
}
//■ Сортировка массива под названием книг;
void sortTitle(Book* books, int n)
{
    system("cls");
    cout << "сортировка по названию" << endl;
    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = n-1; j > i; j--)
        {
            if (_stricmp(books[j].title, books[j-1].title) < 0)
            {
                Book book = books[j];
                books[j] = books[j - 1];
                books[j - 1] = book;
            }
        }
    }
    cout << "выполнено" << endl;
    system("pause");
}
//■ Сортировка массива по автору;
void sortAuthor(Book* books, int n)
{
    system("cls");
    cout << "сортировка по автору" << endl;
    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = n - 1; j > i; j--)
        {
            if (_stricmp(books[j].author, books[j - 1].author) < 0)
            {
                Book book = books[j];
                books[j] = books[j - 1];
                books[j - 1] = book;
            }
        }
    }
    cout << "выполнено" << endl;
    system("pause");
}
//■ Сортировка массива по издательству.
void sortPublishing(Book* books, int n)
{
    system("cls");
    cout << "сортировка по издателю" << endl;
    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = n - 1; j > i; j--)
        {
            if (_stricmp(books[j].publishingHouse, books[j - 1].publishingHouse) < 0)
            {
                Book book = books[j];
                books[j] = books[j - 1];
                books[j - 1] = book;
            }
        }
    }
    cout << "выполнено" << endl;
    system("pause");
}




//Задание 2. Реализовать структуру «Машина»(цвет, модель, номер).
struct Car
{
    char color[30];
    char model[30];
    char number[30];
};


void show(Car car)
{
    cout << "color\t" << car.color << endl;
    cout << "model\t" << car.model << endl;
    cout << "number\t" << car.number << endl;
}
//Реализуйте следующие возможности :
//■ Редактировать машину;
void addCar(Car*& cars, int& n)
{
    cars = (Car*)realloc(cars, (n + 1) * sizeof(Car));
    Car car;

    system("cls");
    cout << "добавление машины" << endl;
    cout << "цвет >> ";
    gets_s(car.color);;
    cout << "модель >> ";
    gets_s(car.model);;
    cout << "номер >> ";
    gets_s(car.number);;
    cars[n] = car;
    n++;

    cout << "машина добавлена" << endl;
    system("pause");
}
void deleteCar(Car*& cars, int& n)
{
    char number[30];
    system("cls:");
    cout << "удаление машины" << endl;
    cout << "номер >> ";
    gets_s(number);
    bool notFound = true;
    for (size_t i = 0; i < n; i++)
    {
        if (_stricmp(number, cars[i].number) == 0)
        {
            notFound = false;
            for (size_t j = 0; j < n - 1; j++)
            {
                cars[j] = cars[j + 1];
            }
            cars = (Car*)realloc(cars, (n - 1) * sizeof(Car));
            n--;
            i--;
        }
    }

    if (notFound)
    {
        cout << "машина не найдена" << endl;
    }
    else
    {
        cout << "машина удалена" << endl;
    }
    system("pause");
}

void editCar(Car*& cars, int& n)
{

    char number[30];
    system("cls:");
    cout << "редактирование машины" << endl;
    cout << "номер >> ";
    gets_s(number);
    bool notFound = true;
    Car car;
    for (size_t i = 0; i < n; i++)
    {
        if (_stricmp(number, cars[i].number) == 0)
        {
            notFound = false;
            car = cars[i];
            break;
        }
    }
    if (notFound)
    {
        cout << "машина не найдена" << endl;
        system("pause");
        return;
    }

    char ch;
    do
    {
        system("cls");
        cout << "Меню редактирование машины" << endl;
        cout << "Машина" << endl;
        show(car);
        cout << endl;
        cout << "1 - цвет" << endl;
        cout << "2 - модель" << endl;
        cout << "3 - номер" << endl;
        cout << "4 - выход" << endl;
        cout << ">> ";
        ch = _getch();

        switch (ch)
        {
        case '1':
            gets_s(car.color);
            break;
        case '2':
            gets_s(car.model);
            break;
        case '3':
            gets_s(car.number);
            break;
        case '4':
            break;
        default:
            cout << "пункт не определен" << endl;
            system("pause");
            break;
        }
    } while (ch != '4');
}

void editingCar(Car*& cars, int& n)
{
    char ch;
    do
    {
        system("cls");
        cout << "Меню редактирование" << endl;
        cout << "1 - добавить" << endl;
        cout << "2 - удалить" << endl;
        cout << "3 - редактировать" << endl;
        cout << "4 - назад" << endl;
        cout << " >> ";
        ch = _getch();

        switch (ch)
        {
        case '1':
            addCar(cars, n);
            break;
        case '2':
            deleteCar(cars, n);
            break;
        case '3':
            editCar(cars, n);
            break;
        case '4':
            break;
        default:
            cout << "пункт не определен" << endl;
            system("pause");
            break;
        }
    } while (ch != '4');
}
//■ Печать всех машин;

void ptintAll(Car* cars, int n)
{
    system("cls");
    cout << "Все машины:" << endl;
    if (n == 0)
    {
        cout << "Машины не найдены" << endl;
    }

    for (size_t i = 0; i < n; i++)
    {
        show(cars[i]);
        cout << endl;
    }
    system("pause");
}
//■ Поиск машины по номеру.
void numberSearch(Car* cars, int n)
{
    system("cls");
    cout << "поиск по номеру" << endl;
    cout << "введите номер >> ";
    char str[30];
    gets_s(str);

    bool check = true;
    for (size_t i = 0; i < n; i++)
    {
        if (_stricmp(str, cars[i].number) == 0)
        {
            show(cars[i]);
            check = false;
        }
    }

    if (check)
    {
        cout << "не найдено" << endl;
    }
    system("pause");
}

int main()
{
    setlocale(LC_ALL, "");
    srand(time(NULL));

    Book* books = nullptr;
    int n = 0;

    char choice;
    do
    {
        system("cls");
        cout << "Главное меню библиотеки" << endl;
        cout << "1 - Редактировать книгу" << endl;
        cout << "2 - Печать всех книг" << endl;
        cout << "3 - Поиск книг по автору" << endl;
        cout << "4 - Поиск книги под названием" << endl;
        cout << "5 - Сортировка массива под названием книг" << endl;
        cout << "6 - Сортировка массива по автору" << endl;
        cout << "7 - Сортировка массива по издательству" << endl;
        cout << "8 - Выход" << endl;
        cout << ">> ";
        choice = _getch();
        switch (choice)
        {
        case '1':
            editing(books, n);
            break;
        case '2':
            ptintAll(books, n);
            break;
        case '3':
            authorSearch(books, n);
            break;
        case '4':
            titleSearch(books, n);
            break;
        case '5':
            sortTitle(books, n);
            break;
        case '6':
            sortAuthor(books, n);
            break;
        case '7':
            sortPublishing(books, n);
            break;
        case '8':
            cout << "пока" << endl;
            break;
        default:
            cout << "пункт не определен" << endl;
            system("pause");
            break;
        }
    } while (choice != '8');

    Car* cars = nullptr;
    int m = 0;

    char choice2;
    do
    {
        system("cls");
        cout << "Главное меню автосалона" << endl;
        cout << "1 - Редактировать" << endl;
        cout << "2 - Печать всех" << endl;
        cout << "3 - Поиск по номеру" << endl;
        cout << "4 - Выход" << endl;
        cout << ">> ";
        choice2 = _getch();
        switch (choice2)
        {
        case '1':
            editingCar(cars, m);
            break;
        case '2':
            ptintAll(cars, m);
            break;
        case '3':
            numberSearch(cars, m);
            break;
        case '4':
            break;
        default:
            cout << "пункт не определен" << endl;
            system("pause");
            break;
        }
    } while (choice2 != '4');

}