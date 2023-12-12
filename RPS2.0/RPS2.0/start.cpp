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
    int sizeOfArr = 0;

    // ����� ������ � ������ ���������
    Borders();
    Task();
    Borders();

    // ���������� ��� �������� ����� �����
    string name = "";

    // ����� ��� ������ � ����
    fstream fout;

    // �������� ���� ���������
    while (actionMenuForInput) {
        // ����� ���� ������ ������� �����
        MenuForInput();
        actionMenuForInput = static_cast<int>(GetInt("Choose an option:  "));

        switch (actionMenuForInput) {
        case MenuForInput::console:
            // ���� ������� � �������
            sizeOfArr = static_cast<int>(GetInt("Enter array size :  "));
            cout << "\n";
            ConcoleInput(arr, sizeOfArr);
            cout << "\nOriginal array\n";
            PrintArr(arr);
            SortWithCertainMethod(make_shared<QuickSort>(), arr);

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
                            SaveSortedArr(arr);
                            actionWitchOneSave = 0;
                            break;
                        case WitchOneSave::back3:
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
                case SavingMenu::back2:
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
                PrintArr(arr);
                SortWithCertainMethod(make_shared<QuickSort>(), arr);
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
                            SaveSortedArr(arr);
                            actionWitchOneSave = 0;
                            break;
                        case WitchOneSave::back3:
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
                case SavingMenu::back2:
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
            cout << "\nOriginal array\n";
            PrintArr(arr);
            SortWithCertainMethod(make_shared<QuickSort>(), arr);

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
                            SaveSortedArr(arr);
                            actionWitchOneSave = 0;
                            break;
                        case WitchOneSave::back3:
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
                case SavingMenu::back2:
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

