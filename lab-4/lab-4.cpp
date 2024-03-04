#include <iostream> 
#include <Windows.h>
#include <string> 
#include <algorithm>
#include <random> 
#include <locale> 

using namespace std; // Использование пространства имен std

// Функция для вывода меню и считывания выбора пользователя
int getUserChoice() {
    int choice;
    cout << "\nВыберите действие:" << endl;
    cout << "1. Вывести слово задом наперед" << endl;
    cout << "2. Вывести слово без гласных" << endl;
    cout << "3. Вывести слово без согласных" << endl;
    cout << "4. Рандомно раскидывать буквы заданного слова" << endl;
    cout << "5. Выход" << endl;
    cout << "Ваш выбор: ";
    cin >> choice; // Считывание выбора пользователя
    return choice; // Возвращение выбора
}

// Функция для вывода слова без определенных букв
void printWordWithoutChars(const string& word, const string& charsToRemove) {
    string result = word; // Создание копии входного слова
    // Удаление символов из входного слова, если они встречаются в строке charsToRemove
    result.erase(remove_if(result.begin(), result.end(), [&charsToRemove](char c) {
        return charsToRemove.find(c) != string::npos; // Проверка наличия символа в строке charsToRemove
        }), result.end()); // Удаление символов
    cout << result << endl; // Вывод результата
}

int main() {
    SetConsoleCP(1251); // Установка кодовой страницы ввода консоли для поддержки русского языка
    SetConsoleOutputCP(1251); // Установка кодовой страницы вывода консоли для поддержки русского языка
    string word; // Переменная для хранения введенного слова
    int choice; // Переменная для хранения выбора пользователя

    cout << "Введите слово: ";
    cin >> word; // Считывание слова от пользователя


    // Входим в цикл, который будет продолжаться до тех пор, пока пользователь не выберет выход
    do {
        choice = getUserChoice(); // Получаем выбор пользователя

        // Выводим результат в зависимости от выбора пользователя
        switch (choice) {
        case 1:
            cout << "Слово задом наперед: " << string(word.rbegin(), word.rend()) << endl; // Вывод слова задом наперед
            break;
        case 2:
            cout << "Слово без гласных: ";
            printWordWithoutChars(word, "аеёиоуыэюя"); // Вывод слова без гласных букв
            break;
        case 3:
            cout << "Слово без согласных: ";
            printWordWithoutChars(word, "бвгджзйклмнпрстфхцчшщъь"); // Вывод слова без согласных букв
            break;
        case 4:
            random_shuffle(word.begin(), word.end()); // Рандомно переставляем буквы в слове
            cout << "Слово с рандомно раставленными буквами: " << word << endl; // Вывод результата
            break;
        case 5:
            cout << "Завершение работы" << endl;
            break;
        default:
            cout << "Неправильный выбор. Попробуйте еще раз." << endl; // Сообщение об ошибке в случае некорректного выбора
        }
    } while (choice != 5); // Цикл будет продолжаться до тех пор, пока пользователь не выберет выход

    return 0;
}