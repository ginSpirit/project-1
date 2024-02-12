#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

class process {
    std::string userName, Email, Password;
    std::string search_name, search_password, search_email;
    fstream file;
public:
    void login();
    void signup();
    void forgot_password();
} obj;

int main() {
    char choice_list;
    std::cout << "1- Login" << std::endl;
    std::cout << "2- Sign-Up" << std::endl;
    std::cout << "3- Forgot Password" << std::endl;
    std::cout << "4- Need Help?" << std::endl;
    std::cout << "Enter Your Choice: ";
    std::cin >> choice_list;
    std::cout << std::endl;

    switch (choice_list) {

    case '1':
        obj.login();
        break;
    case '2':
        obj.signup();
        break;
    case '3':
        obj.forgot_password();
        break;
    case '4':
        system("start https://www.google.com/webhp?hl=en&sa=X&ved=0ahUKEwj478_T6aOEAxWFxjgGHbvACn4QPAgJ");
        break;

    default:
        std::cout << "Invalid Input." << std::endl;
    }
}

void process::signup() {
    cin.ignore();
    std::cout << "Enter Your Name : ";
    getline(cin, userName);
    std::cout << "\nEnter Your E-mail Address : ";
    getline(cin, Email);
    cout << "\nEnter a new Password : ";
    getline(cin, Password);

    file.open("LoginData.txt", ios::out | ios::app);
    file << userName << "*" << Email << "*" << Password << std::endl;
    file.close();
}

void process::login() {
    cin.ignore();
    std::cout << "------------LOGIN------------" << std::endl;
    std::cout << "Enter Your Name : " << std::endl;
    getline(cin, search_name);
    std::cout << "Enter Your Password : " << std::endl;
    getline(cin, search_password);

    file.open("LoginData.txt", ios::in);
    while (getline(file, userName, '*')) {
        getline(file, Email, '*');
        getline(file, Password, '\n');
        if (userName == search_name) {
            if (Password == search_password) {
                std::cout << "\nAccount Login Successfull!";
                std::cout << "\nUsername : " << userName << std::endl;
                std::cout << "Email : " << Email << endl;
                file.close();
                return;
            }
            else {
                std::cout << "Password is Incorrect." << std::endl;
                file.close();
                return;
            }
        }
    }
    std::cout << "Username not found." << std::endl;
    file.close();
}

void process::forgot_password() {
    cin.ignore();
    std::cout << "\nEnter your Name : ";
    getline(cin, search_name);
    std::cout << "\nEnter Your E-mail address : ";
    getline(cin, search_email);

    file.open("LoginData.txt", ios::in);
    while (getline(file, userName, '*')) {
        getline(file, Email, '*');
        getline(file, Password, '\n');
        if (userName == search_name && Email == search_email) {
            std::cout << "Account Found" << std::endl;
            std::cout << "Your Password is : " << Password << std::endl;
            file.close();
            return;
        }
    }
    std::cout << "Account not found." << std::endl;
    file.close();
}