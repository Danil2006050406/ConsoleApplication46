#include <iostream>
#include <sstream>
#include <string>


using namespace std;

bool isNumber(const string& str) {
    
    for (char c : str) {
        if (!isdigit(c) && c != '.' && c != '-') {
            return false;
        }
    }
    return true;
}

double getNumberInput() {
    string input;
    double number;

    while (true) {
        cout << "Введіть число: ";
        cin >> input;

        if (isNumber(input)) {
            stringstream ss(input);
            ss >> number;
            break;
        }
        else {
            cout << "Введене значення не є числом. Спробуйте ще раз." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }

    return number;
}

int main() {
    
    double num1, num2;
    char op;

    cout << "Простий калькулятор" << endl;

    num1 = getNumberInput();

    cout << "Виберіть операцію (+, -, *, /): ";
    cin >> op;

    num2 = getNumberInput();

    double result;
    switch (op) {
    case '+':
        result = num1 + num2;
        break;
    case '-':
        result = num1 - num2;
        break;
    case '*':
        result = num1 * num2;
        break;
    case '/':
        if (num2 != 0) {
            result = num1 / num2;
        }
        else {
            cout << "Помилка: Ділення на нуль!" << endl;
            return 1;
        }
        break;
    default:
        cout << "Непідтримувана операція" << endl;
        return 1;
    }

    cout << "Результат: " << result << endl;

    return 0;
}
