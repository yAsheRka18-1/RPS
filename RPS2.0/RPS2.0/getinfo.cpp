#include "getinfo.h"


/// <summary>
/// Функция для получения целочисленного ввода от пользователя с валидацией.
/// </summary>
/// <param name="message">Сообщение, которое будет отображено пользователю для запроса ввода.</param>
/// <returns>Введенное целое число.</returns>
int GetInt(string message) {
    cout << message;

    // Временная переменная для хранения ввода.
    double tmp = 0;

    // Продолжает цикл до получения корректного целочисленного ввода.
    while (true) {
        cin >> tmp;

        // Проверка, находится ли поток в состоянии ошибки (ввод не числовой).
        if (cin.fail()) {
            cin.clear();    // Сброс состояния ошибки.
            cin.ignore(numeric_limits<std::streamsize>::max(), '\n');   // Игнорирование некорректного ввода до символа новой строки.
            cout << "\nUse correct values!\n\n";
            cout << message;
        }

        // Проверка, больше ли введенное значение нуля.
        else if (tmp <= 0) {
            cout << "\nValue must be >0\n\n";
            cin.clear();
            cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
            cout << message;
        }

        // Проверка, имеет ли введенное значение ненулевую дробную часть
        else if (tmp - (int)tmp > 0) {
            cout << "\nUse integer values!\n\n";
            cin.clear();
            cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
            cout << message;
        }

        // Если все проверки пройдены успешно, возвращает введенное значение в виде целого числа.
        else {
            cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
            return int(tmp);
        }

    }

}

/// <summary>
/// Функция для получения числового значения от пользователя с валидацией на целочисленность.
/// </summary>
/// <param name="message">Сообщение, которое будет отображено пользователю для запроса ввода.</param>
/// <returns>Введенное целое число.</returns>
int GetValue(string message) {
    cout << message;

    // Временная переменная для хранения ввода.
    double tmp = 0;

    // Продолжает цикл до получения корректного числового ввода.
    while (true) {
        cin >> tmp;

        // Проверка, находится ли поток в состоянии ошибки (ввод не числовой).
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
            cout << "\nUse correct values!\n\n";
            cout << message;
        }

        // Проверка, имеет ли введенное значение ненулевую дробную часть
        else if (tmp - (int)tmp > 0) {
            cout << "\nUse integer values!\n\n";
            cin.clear();
            cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
            cout << message;
        }

        // Если все проверки пройдены успешно, возвращает введенное значение в виде целого числа.
        else {
            cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
            return int(tmp);
        }

    }

}
