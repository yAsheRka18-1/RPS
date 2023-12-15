#include "getinfo.h"

int GetInt(string message) {
    cout << message;

    // Временная переменная для хранения ввода.
    double value = 0;

    // Продолжает цикл до получения корректного целочисленного ввода.
    while (true) {
        cin >> value;

        // Проверка, находится ли поток в состоянии ошибки (ввод не числовой).
        if (cin.fail()) {
            cin.clear();    // Сброс состояния ошибки.
            cin.ignore(numeric_limits<streamsize>::max(), '\n');   // Игнорирование некорректного ввода до символа новой строки.
            cout << "\nUse correct values!\n\n";
            cout << message;
        }
        // Проверка, больше ли введенное значение нуля.
        else if (value <= 0) {
            cout << "\nValue must be >0\n\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << message;
        }
        // Проверка, имеет ли введенное значение ненулевую дробную часть
        else if (value - (int)value > 0) {
            cout << "\nUse integer values!\n\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << message;
        }
        // Если все проверки пройдены успешно, возвращает введенное значение в виде целого числа.
        else {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return int(value);
        }
    }
}

int GetValue(string message) {
    cout << message;

    // Временная переменная для хранения ввода.
    double value = 0;

    // Продолжает цикл до получения корректного числового ввода.
    while (true) {
        cin >> value;

        // Проверка, находится ли поток в состоянии ошибки (ввод не числовой).
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "\nUse correct values!\n\n";
            cout << message;
        }
        // Проверка, имеет ли введенное значение ненулевую дробную часть
        else if (value - (int)value > 0) {
            cout << "\nUse integer values!\n\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << message;
        }
        // Если все проверки пройдены успешно, возвращает введенное значение в виде целого числа.
        else {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return int(value);
        }
    }
}
