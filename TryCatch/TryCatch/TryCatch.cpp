#include <iostream>
#include <regex>
#include <stdexcept>
using namespace std;
class Registration {
public:
    bool isValidLogin(const string& login) {
        return login.length() < 15 && std::regex_match(login, regex("^[a-zA-Z0-9_]+$"));
    }

    bool isValidPassword(const string& password) {
        return password.length() >= 7 && password.length() <= 20 && regex_match(password, regex("^[a-zA-Z0-9_]+$"));
    }

    void registerUser(const string& password, const string& confirmPassword) {

        if (password != confirmPassword) {
            throw invalid_argument("Пароль не совпадает");
        }

        cout << "Пользователь зарегестрирован" << endl;
    }
    void doubleCheck() {
        try {
            string login, password, confirmPassword;

            cout << "Введите логин: ";
            cin >> login;
            if (!isValidLogin(login)) {
                throw invalid_argument("Неправильный логин. Ваш логин должен содержать только латинские буквы цифры и подчеркивания");
            }

            cout << "Введите пароль: ";
            cin >> password;
            if (!isValidPassword(password)) {
                throw invalid_argument("Неправильный пароль. Ваш пароль должен содержать только латинские буквы цифры и подчеркивания");
            }

            cout << "Подтвердите пароль: ";
            cin >> confirmPassword;

            registerUser(password, confirmPassword);
        }
        catch (const invalid_argument& e) {
            cerr << "Ошибка: " << e.what() << std::endl;
        }
    }
};


int main() {
    Registration r;
    setlocale(LC_ALL, "rus");
    r.doubleCheck();

    return 0;
}
