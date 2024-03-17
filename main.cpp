#include <iostream>
#include <fstream>
#include <windows.h>
#include <vector>
#include "Car.h"
#include "Customer.h"
#include "Rent.h"

using namespace std;

//Допоміжні методи

vector<Car> createCarArray() { //Створити масив машин на основі файлу
    vector<Car> carArr;
    try {
        ifstream cars("cars.txt");
        if (!cars.is_open()) throw "Failed to open file cars.txt";
        while (!cars.eof()) {
            char line[50];
            cars.getline(line, 50);
            if (strlen(line) == 0) break;

            string model;
            int price;

            model = line;
            cars.getline(line, 50);
            price = stoi(line);
            carArr.push_back(Car(model, price));
        }
        cars.close();
    } catch (const char *ex) {
        cerr << ex;
    }
    return carArr;
}

vector<Rent> createRentArray() { //Створити масив транзакцій на основі файлу
    vector<Rent> rentArr;
    try {
        ifstream rents("rents.txt");
        if (!rents.is_open()) throw "Failed to open file rents.txt";
        while (!rents.eof()) {
            char line[50];
            rents.getline(line, 50);
            if (strlen(line) == 0) break;

            string name;
            string surname;
            string model;
            int price;
            int amountOfDays;

            name = line;
            rents.getline(line, 50);
            surname = line;
            rents.getline(line, 50);
            model = line;
            rents.getline(line, 50);
            price = stoi(line);
            rents.getline(line, 50);
            amountOfDays = stoi(line);
            rentArr.push_back(Rent(Car(model, price), Customer(name, surname), amountOfDays));
        }
        rents.close();
    } catch (const char *ex) {
        cerr << ex;
    }
    return rentArr;
}

void rewriteFile(const vector<Car> &carArr) { //Переписати файл на основі змін в масиві
    ofstream cars("cars.txt");
    for (const auto &car: carArr) {
        cars << car.getModel() << endl;
        cars << car.getPriceForADay() << endl;
    }
    cars.close();
}

int findInArray(const vector<Car> &carArr, string &search) { //Повернути індекс шуканої машини в масиві
    for (int i = 0; i < carArr.size(); i++) {
        if (carArr[i].getModel() == search) return i;
    }
    return -1;
}

//Методи адміністратора

void changePrice(vector<Car> &carArr) { //Поміняти ціну на машину
    string search;
    cout << "Введіть модель машини на яку хочете поміняти ціну: ";
    cin.ignore();
    getline(cin, search);
    int index = findInArray(carArr, search);
    if (index != -1) {
        int price;
        cout << "Введіть нову ціну: ";
        cin >> price;
        carArr[index].setPriceForADay(price);
        rewriteFile(carArr);
    } else cout << "Такої машини не існує!\n";
}

void deleteCar(vector<Car> &carArr) { //Видалити машину зі списку
    string search;
    cout << "Введіть модель машини яку хочете видалити: ";
    cin.ignore();
    getline(cin, search);
    int index = findInArray(carArr, search);
    if (index != -1) {
        carArr.erase(carArr.begin() + index);
        rewriteFile(carArr);
    } else cout << "Такої машини не існує!\n";
}

void addCar(vector<Car> &carArr) { //Додати машину в список
    string model;
    int price;
    cout << "Введіть модель: ";
    cin.ignore();
    getline(cin, model);
    cout << "Введіть ціну: ";
    cin >> price;

    ofstream cars("cars.txt", ios_base::app);
    cars << model << endl;
    cars << price << endl;
    cars.close();

    carArr.push_back(Car(model, price));
}

void adminPanel() { //Меню адміна
    bool exit = false;
    vector<Car> carArr = createCarArray();
    vector<Rent> rentArr = createRentArray();
    do {
        cout << "Меню адміністратора. \n";
        cout << "Виберіть дію: \n";
        cout << "1 - Додати машину \n";
        cout << "2 - Видалити машину \n";
        cout << "3 - Редагувати ціни \n";
        cout << "4 - Подивитись історію покупок \n";
        cout << "5 - Подивитись наявні машини \n";
        cout << "6 - Вийти з програми\n";

        int choice;
        cin >> choice;
        switch (choice) {
            case 1:
                addCar(carArr);
                break;
            case 2:
                deleteCar(carArr);
                break;
            case 3:
                changePrice(carArr);
                break;
            case 4:
                for (const auto &rent: rentArr) cout << rent;
                break;
            case 5:
                for (const auto &car: carArr) cout << car;
                break;
            default:
                exit = true;
        }
    } while (!exit);
}

//Методи входу для адміна

void loginAdmin() { //Авторизація адміна
    string username;
    string password;
    bool isSuccessful = false;

    do {
        cout << "Введіть логін: ";
        cin.ignore();
        getline(cin, username);
        cout << "Введіть пароль: ";
        getline(cin, password);

        try {
            ifstream admins("admins.txt");
            if (!admins.is_open()) throw "Failed to open file admins.txt";
            while (!admins.eof()) {
                char line[50];
                admins.getline(line, 50);
                if (line == username) {
                    admins.getline(line, 50);
                    if (line == password) {
                        isSuccessful = true;
                        break;
                    }
                } else admins.getline(line, 50);
            }
            admins.close();
        } catch (const char *ex) {
            cerr << ex;
        }

        if (!isSuccessful) cout << "Неправильно введений логін або пароль!\n";
    } while (!isSuccessful);
    adminPanel();
}

void registerAdmin() { //Реєстрація адміна
    string username;
    string password;
    bool isFailed;
    do {
        isFailed = false;
        cout << "Введіть логін: ";
        cin.ignore();
        getline(cin, username);
        cout << "Введіть пароль: ";
        getline(cin, password);

        try {
            ifstream admins("admins.txt");
            if (!admins.is_open()) throw "Failed to open file admins.txt";
            while (!admins.eof()) {
                char line[50];
                admins.getline(line, 50);
                if (line == username) {
                    isFailed = true;
                    break;
                } else admins.getline(line, 50);
            }
            admins.close();
        } catch (const char *ex) {
            cerr << ex;
        }

        if (isFailed) cout << "Логін вже зайнятий\n";
        else {
            ofstream add("admins.txt", ios_base::app);
            add << username << endl;
            add << password << endl;
            add.close();
        }
    } while (isFailed);
}

//Вибір користувача (адмін або покупець)

int main() {
    SetConsoleOutputCP(CP_UTF8);

    cout << "Вітаємо! \n";
    cout << "Виберіть тип авторизації: \n";
    cout << "1 - Адмін \n";
    cout << "2 - Покупець \n";
    cout << "3 - Вийти з програми\n";

    int choice;
    cin >> choice;
    switch (choice) {
        case 1:
            cout << "1 - Реєстрація, 2 - Авторизація: ";
            cin >> choice;
            if (choice == 1) registerAdmin();
            loginAdmin();
            break;
        case 2:
            break;
    }

    return 0;
}
