#include "class.h"
#include "interface.h"
#include <fstream>
#include "getinfo.h"

/// <summary>
/// ������� �������, � ������� ����������� ��� ���������������� ���� � ������� ���������� �������.
/// </summary>
int main() {
    // ���������� ��� ���������� ���� �����, ���������� � ������ ������������ �������
    int actionMenuForInput = 1;
    int actionSavingMenu = 1;
    int actionWitchOneSave = 1;

    // ������ ��� �������� ������� � ������ �������
    vector<int> arr;
    vector<int> res;
    int sizeOfArr = 0;
    QuickSort sort;

    // ����� ������ � ������ ���������
    Borders();
    Task();
    Borders();


    // �������� ���� ���������
    while (actionMenuForInput) {
        // ����� ���� ������ ������� �����
        MenuForInput();
        actionMenuForInput = static_cast<int>(GetInt("Choose an option:  "));
        // ���������� ��� �������� ����� �����
        string name = "";

        // ����� ��� ������ � ����
        fstream fout;
        switch (actionMenuForInput) {

        case MenuForInput::console:
            // ���� ������� � �������
            sizeOfArr = static_cast<int>(GetInt("Enter array size :  "));
            cout << "\n";
            ConcoleInput(arr, sizeOfArr);  //���� ������� � ����������'
            res = arr;
            cout << "\nOriginal array\n";
            PrintArr(arr);                 //����� ��������� ������� � �������
            cout << sort.NameOfSort();     // ����� �������� ������ ����������.
            sort.Sort(res);   // ����� ������ ����������.
            PrintArr(res);   // ����� ���������������� �������.

            // ��������� ���� ��� ������ ����� ����������
            while (actionSavingMenu) {
                SavingMenu();
                actionSavingMenu = static_cast<int>(GetInt("Choose an option:  "));

                switch (actionSavingMenu) {
                case SavingMenu::savetofile:
                    // ��������� ���� ��� ������ ����� ���������� �������
                    while (actionWitchOneSave) {
                        WitchOneSave();
                        actionWitchOneSave = static_cast<int>(GetInt("Choose an option:  "));

                        switch (actionWitchOneSave) {
                        case WitchOneSave::original:
                            SaveOriginalArr(arr);
                            actionWitchOneSave = 0;
                            break;
                        case WitchOneSave::sorted:
                            SaveSortedArr(res);
                            actionWitchOneSave = 0;
                            break;
                        case WitchOneSave::backToSaving:  
                            actionWitchOneSave = 0;
                            break;
                        default:
                            cout << "Incorect option! Try enter again!" << endl;
                            cin >> actionSavingMenu;
                            break;
                        }
                    }

                    actionWitchOneSave = 1;
                    actionSavingMenu = 0;
                    break;

                case SavingMenu::backToInput:
                    actionSavingMenu = 0;
                    break;

                default:
                    cout << "Incorect option! Try enter again!" << endl;
                    cin >> actionSavingMenu;
                    break;
                }
            }

            actionSavingMenu = 1;
            break;

        case MenuForInput::file:
            // ���� ������� �� �����

            cout << "Enter the name of the file: ";
            cin >> name;

            if (FileInput(arr, name)) {
                cout << "\nOriginal array\n";
                res = arr;
                PrintArr(arr);
                cout << sort.NameOfSort();   // ����� �������� ������ ����������.
                sort.Sort(res);   // ����� ������ ����������.
                PrintArr(res);   // ����� ���������������� �������.
            }
            else {
                actionSavingMenu = 0;
            }

            // ��������� ���� ��� ������ ����� ����������
            while (actionSavingMenu) {
                SavingMenu();
                actionSavingMenu = static_cast<int>(GetInt("Choose an option: "));

                switch (actionSavingMenu) {
                case SavingMenu::savetofile:
                    // ��������� ���� ��� ������ ����� ���������� �������
                    while (actionWitchOneSave) {
                        WitchOneSave();
                        actionWitchOneSave = static_cast<int>(GetInt("Choose an option: "));

                        switch (actionWitchOneSave) {
                        case WitchOneSave::original:
                            SaveOriginalArr(arr);
                            actionWitchOneSave = 0;
                            break;
                        case WitchOneSave::sorted:
                            SaveSortedArr(res);
                            actionWitchOneSave = 0;
                            break;
                        case WitchOneSave::backToSaving:
                            actionWitchOneSave = 0;
                            break;
                        default:
                            cout << "Incorect option! Try enter again!" << endl;
                            cin >> actionSavingMenu;
                            break;
                        }
                    }

                    actionWitchOneSave = 1;
                    actionSavingMenu = 0;
                    break;
                case SavingMenu::backToInput:
                    actionSavingMenu = 0;
                    break;
                default:
                    cout << "Incorect option! Try enter again!" << endl;
                    cin >> actionSavingMenu;
                    break;
                }
            }

            actionSavingMenu = 1;
            break;
        case MenuForInput::random:
            // ��������� ���������� �������
            sizeOfArr = static_cast<int>(GetInt("Enter array size :  "));
            cout << "\n";
            RandomInput(arr, sizeOfArr);
            res = arr;
            cout << "\nOriginal array\n";
            PrintArr(arr);
            cout << sort.NameOfSort();   // ����� �������� ������ ����������.
            sort.Sort(res);   // ����� ������ ����������.
            PrintArr(res);   // ����� ���������������� �������.

            // ��������� ���� ��� ������ ����� ����������
            while (actionSavingMenu) {
                SavingMenu();
                actionSavingMenu = static_cast<int>(GetInt("Choose an option: "));

                switch (actionSavingMenu) {
                case SavingMenu::savetofile:
                    // ��������� ���� ��� ������ ����� ���������� �������
                    while (actionWitchOneSave) {
                        WitchOneSave();
                        actionWitchOneSave = static_cast<int>(GetInt("Choose an option: "));

                        switch (actionWitchOneSave) {
                        case WitchOneSave::original:
                            SaveOriginalArr(arr);
                            actionWitchOneSave = 0;
                            break;
                        case WitchOneSave::sorted:
                            SaveSortedArr(res);
                            actionWitchOneSave = 0;
                            break;
                        case WitchOneSave::backToSaving:
                            actionWitchOneSave = 0;
                            break;
                        default:
                            cout << "Incorect option! Try enter again!" << endl;
                            cin >> actionSavingMenu;
                            break;
                        }
                    }

                    actionWitchOneSave = 1;
                    actionSavingMenu = 0;
                    break;

                case SavingMenu::backToInput:
                    actionSavingMenu = 0;
                    break;
                default:
                    cout << "Incorect option! Try enter again!" << endl;
                    cin >> actionSavingMenu;
                    break;
                }
            }

            actionSavingMenu = 1;
            break;

        case MenuForInput::quit:
            cout << "Programm finished its work!" << endl;
            return EXIT_SUCCESS;
        default:
            cout << "\nIncorect option! Try enter again!\n\n";
            break;
        }
    }
}

