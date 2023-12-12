#include "getinfo.h"


/// <summary>
/// ������� ��� ��������� �������������� ����� �� ������������ � ����������.
/// </summary>
/// <param name="message">���������, ������� ����� ���������� ������������ ��� ������� �����.</param>
/// <returns>��������� ����� �����.</returns>
int GetInt(string message) {
    cout << message;

    // ��������� ���������� ��� �������� �����.
    double tmp = 0;

    // ���������� ���� �� ��������� ����������� �������������� �����.
    while (true) {
        cin >> tmp;

        // ��������, ��������� �� ����� � ��������� ������ (���� �� ��������).
        if (cin.fail()) {
            cin.clear();    // ����� ��������� ������.
            cin.ignore(numeric_limits<std::streamsize>::max(), '\n');   // ������������� ������������� ����� �� ������� ����� ������.
            cout << "\nUse correct values!\n\n";
            cout << message;
        }

        // ��������, ������ �� ��������� �������� ����.
        else if (tmp <= 0) {
            cout << "\nValue must be >0\n\n";
            cin.clear();
            cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
            cout << message;
        }

        // ��������, ����� �� ��������� �������� ��������� ������� �����
        else if (tmp - (int)tmp > 0) {
            cout << "\nUse integer values!\n\n";
            cin.clear();
            cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
            cout << message;
        }

        // ���� ��� �������� �������� �������, ���������� ��������� �������� � ���� ������ �����.
        else {
            cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
            return int(tmp);
        }

    }

}

/// <summary>
/// ������� ��� ��������� ��������� �������� �� ������������ � ���������� �� ���������������.
/// </summary>
/// <param name="message">���������, ������� ����� ���������� ������������ ��� ������� �����.</param>
/// <returns>��������� ����� �����.</returns>
int GetValue(string message) {
    cout << message;

    // ��������� ���������� ��� �������� �����.
    double tmp = 0;

    // ���������� ���� �� ��������� ����������� ��������� �����.
    while (true) {
        cin >> tmp;

        // ��������, ��������� �� ����� � ��������� ������ (���� �� ��������).
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
            cout << "\nUse correct values!\n\n";
            cout << message;
        }

        // ��������, ����� �� ��������� �������� ��������� ������� �����
        else if (tmp - (int)tmp > 0) {
            cout << "\nUse integer values!\n\n";
            cin.clear();
            cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
            cout << message;
        }

        // ���� ��� �������� �������� �������, ���������� ��������� �������� � ���� ������ �����.
        else {
            cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
            return int(tmp);
        }

    }

}
