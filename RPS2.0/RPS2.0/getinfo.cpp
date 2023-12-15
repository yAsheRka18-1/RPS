#include "getinfo.h"

int GetInt(string message) {
    cout << message;

    // ��������� ���������� ��� �������� �����.
    double value = 0;

    // ���������� ���� �� ��������� ����������� �������������� �����.
    while (true) {
        cin >> value;

        // ��������, ��������� �� ����� � ��������� ������ (���� �� ��������).
        if (cin.fail()) {
            cin.clear();    // ����� ��������� ������.
            cin.ignore(numeric_limits<streamsize>::max(), '\n');   // ������������� ������������� ����� �� ������� ����� ������.
            cout << "\nUse correct values!\n\n";
            cout << message;
        }
        // ��������, ������ �� ��������� �������� ����.
        else if (value <= 0) {
            cout << "\nValue must be >0\n\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << message;
        }
        // ��������, ����� �� ��������� �������� ��������� ������� �����
        else if (value - (int)value > 0) {
            cout << "\nUse integer values!\n\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << message;
        }
        // ���� ��� �������� �������� �������, ���������� ��������� �������� � ���� ������ �����.
        else {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return int(value);
        }
    }
}

int GetValue(string message) {
    cout << message;

    // ��������� ���������� ��� �������� �����.
    double value = 0;

    // ���������� ���� �� ��������� ����������� ��������� �����.
    while (true) {
        cin >> value;

        // ��������, ��������� �� ����� � ��������� ������ (���� �� ��������).
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "\nUse correct values!\n\n";
            cout << message;
        }
        // ��������, ����� �� ��������� �������� ��������� ������� �����
        else if (value - (int)value > 0) {
            cout << "\nUse integer values!\n\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << message;
        }
        // ���� ��� �������� �������� �������, ���������� ��������� �������� � ���� ������ �����.
        else {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return int(value);
        }
    }
}
