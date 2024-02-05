#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <cstdio>
#include <iomanip>
#include <cstring>
#include <algorithm>
#include <cctype>
#include <limits>
#include <ctime>

class Data {
public: std::string name;
      std::string password;
      int role = 0;
};

class Employee {
public: std::string birthday;
      std::string department;
      std::string name;
      std::string startdate;
      std::string position;
};

void MenuAdmin() {
    std::cout << std::endl << "\tMenu admin" << std::endl << std::endl;
    std::cout << "(D)isplay employees" << std::endl << "(V)iew data" << std::endl << "(E)dit" << std::endl << "(S)ort" << std::endl << "Sea(r)ch" << std::endl << "(Q)uit" << std::endl << std::endl << "Choose command: " << std::endl;
}
void MenuUser() {
    std::cout << std::endl << "\tMenu user" << std::endl << std::endl;
    std::cout << "(D)isplay employees" << std::endl << "(S)ort" << std::endl << "Sea(r)ch" << std::endl << "(Q)uit" << std::endl << std::endl << "Choose command: " << std::endl;
}
void DisplayEmployees(const std::string& employees) {
    std::ifstream file(employees);
    if (!file) {
        std::cout << "Error opening file." << std::endl;
        return;
    }

    std::cout << "+------------+----------------------+--------------------------------+--------------------------+-------------------------+" << std::endl;
    std::cout << "|  Birthday  |     Department       |             Name               |       Start date         |        Position         |" << std::endl;
    std::cout << "+------------+----------------------+--------------------------------+--------------------------+-------------------------+" << std::endl;

    Employee employee;
    for (; file >> employee.birthday >> employee.department >> employee.name >> employee.startdate >> employee.position;) {
        std::cout << "| " << std::left << std::setw(11) << employee.birthday << "| "
            <<
            std::left << std::setw(21) << employee.department << "| " <<
            std::left << std::setw(31) << employee.name << "| " <<
            std::left << std::setw(25) << employee.startdate << "| " <<
            std::left << std::setw(24) << employee.position << "|" << std::endl;
    }

    std::cout << "+------------+----------------------+--------------------------------+--------------------------+-------------------------+" << std::endl;
}

void DisplayData() {
    std::ifstream file("data.txt");
    if (!file) {
        std::cout << "Error opening file." << std::endl;
        return;
    }

    Data data;
    std::cout << "+------------------+------------------+------------+" << std::endl;
    std::cout << "|      Name        |     Password     |    Role    |" << std::endl;
    std::cout << "+------------------+------------------+------------+" << std::endl;

    for (; file >> data.name >> data.password >> data.role;) {
        std::cout << "| " << std::setw(12) << data.name << "     | " << std::setw(12) << data.password << "     | " << std::setw(6) << data.role << "     |" << std::endl;
    }

    std::cout << "+------------------+------------------+------------+" << std::endl;

    file.close();
}

void Edit() {
    std::cout << std::endl << "\tEdit" << std::endl;
    std::cout << std::endl << "Enter in (e)mployees" << std::endl << "Delete in e(m)ployees" << std::endl << "Enter in (d)ata" << std::endl << "Delete in d(a)ta" << std::endl << "(Q)uit" << std::endl;
}
void Sort() {
    std::cout << std::endl << "\tSort" << std::endl;
    std::cout << std::endl << "(B)irthday" << std::endl << "(D)epartment" << std::endl << "(N)ame" << std::endl << "(S)tart Date" << std::endl << "(P)osition" << std::endl << "Employees of (r)etirement age" << std::endl << "(Q)uit" << std::endl;
}
void Search() {
    std::cout << std::endl << "\tSearch" << std::endl;
    std::cout << std::endl << "(B)irthday" << std::endl << "(D)epartment" << std::endl << "(N)ame" << std::endl << "(S)tart date" << std::endl << "(P)osition" << std::endl << "(Q)uit" << std::endl;
}
void bubbleSortByBirthday(std::vector < Employee >& employees) {
    std::sort(employees.begin(), employees.end(), [](const Employee& a,
        const Employee& b) {
            return a.birthday < b.birthday;
        });
}

void bubbleSortByDepartment(std::vector < Employee >& employees) {
    std::sort(employees.begin(), employees.end(), [](const Employee& a,
        const Employee& b) {
            return a.department < b.department;
        });
}

void bubbleSortByName(std::vector < Employee >& employees) {
    std::sort(employees.begin(), employees.end(), [](const Employee& a,
        const Employee& b) {
            return a.name < b.name;
        });
}

void bubbleSortByStartDate(std::vector < Employee >& employees) {
    std::sort(employees.begin(), employees.end(), [](const Employee& a,
        const Employee& b) {
            return a.startdate < b.startdate;
        });
}

void bubbleSortByPosition(std::vector < Employee >& employees) {
    std::sort(employees.begin(), employees.end(), [](const Employee& a,
        const Employee& b) {
            return a.position < b.position;
        });
}

int calculateAge(int birthYear, int birthMonth, int birthDay) {
    time_t now = time(0);
    tm currentTime;
    if (localtime_s(&currentTime, &now) != 0) {
    }
    int currentYear = currentTime.tm_year + 1900;
    int currentMonth = currentTime.tm_mon + 1;
    int currentDay = currentTime.tm_mday;
    int age = currentYear - birthYear;
    if (currentMonth < birthMonth) {
        age--;
    }
    else if (currentMonth == birthMonth && currentDay < birthDay) {
        age--;
    }

    return age;
}

bool compareByStartDate(const Employee& emp1, const Employee& emp2) {
    return emp1.startdate < emp2.startdate;
}

void calculateAgesFromFile(const std::string& filename) {
    std::ifstream file(filename);
    if (!file) {
        std::cout << "Failed to open the file." << std::endl;
        return;
    }

    std::string line;
    std::vector<Employee> employees;

    for (; std::getline(file, line); ) {
        std::stringstream ss(line);
        Employee employee;
        std::string dateStr, roleStr, name, startDate, department, position;

        ss >> dateStr >> roleStr;
        std::getline(ss, name, ' ');
        std::getline(ss, startDate, ' ');
        std::getline(ss, department, ' ');
        std::getline(ss, position, ' ');

        for (std::string part; ss >> part; ) {
            name += ' ' + part;
            if (part.front() == '"')
                break;
        }

        employee.birthday = dateStr;
        employee.department = department;
        employee.name = name;
        employee.startdate = startDate;
        employee.position = position;

        employees.push_back(employee);
    }

    file.close();

    std::sort(employees.begin(), employees.end(), compareByStartDate);

    for (const auto& employee : employees) {
        int year, month, day;
        std::stringstream ss(employee.birthday);
        char delimiter;
        ss >> year >> delimiter >> month >> delimiter >> day;

        int age = calculateAge(year, month, day);

        if (age >= 65) {
            std::cout << "----------------------------------------------------------" << std::endl;
            std::cout << "Information about the employee:" << std::endl << "Position: " << employee.position << std::endl;
            std::cout << "Age: " << age << std::endl;
            std::cout << "Name: " << employee.startdate << std::endl;
            std::cout << "Start date: " << employee.department << std::endl;
            std::cout << "Birthday: " << employee.birthday << std::endl;
            std::cout << "----------------------------------------------------------" << std::endl;
        }
    }
}

bool isValidDate(const std::string& date) {
    if (date.size() != 10) {
        return false;
    }

    if (date[4] != '.' || date[7] != '.') {
        return false;
    }

    for (int i = 0; i < 10; i++) {
        if (i != 4 && i != 7 && !std::isdigit(date[i])) {
            return false;
        }
    }
    return true;
}

void printEmployees(const std::vector < Employee >& employees) {
    std::cout << "+------------+----------------------+--------------------------------+--------------------------+-------------------------+" << std::endl;
    std::cout << "|  Birthday  |     Department       |             Name               |       Start date         |        Position         |" << std::endl;
    std::cout << "+------------+----------------------+--------------------------------+--------------------------+-------------------------+" << std::endl;

    for (const auto& employee : employees) {
        std::cout << "|" << std::setw(10) << employee.birthday << "  | " << std::setw(20) << employee.department << " | " <<
            std::setw(30) << employee.name << " | " << std::setw(24) << employee.startdate << " | "
            <<
            std::setw(23) << employee.position << " |" << std::endl;
    }

    std::cout << "+------------+----------------------+--------------------------------+--------------------------+-------------------------+" << std::endl;
}

void searchEmployees(const std::string& searchKeyword,
    const std::string& searchField) {
    std::ifstream infile("employees.txt");
    Employee employee;

    if (!infile) {
        std::cout << "File opening error!" << std::endl;
        return;
    }

    std::string lowercaseSearchKeyword = searchKeyword;
    std::transform(lowercaseSearchKeyword.begin(), lowercaseSearchKeyword.end(), lowercaseSearchKeyword.begin(), [](unsigned char c) {
        return std::tolower(c);
        });

    bool found = false;
    for (; infile >> employee.birthday >> employee.department >> employee.name >> employee.startdate >> employee.position;) {
        std::string lowercaseField;
        if (searchField == "birthday") {
            lowercaseField = employee.birthday;
        }
        else if (searchField == "department") {
            lowercaseField = employee.department;
        }
        else if (searchField == "name") {
            lowercaseField = employee.name;
        }
        else if (searchField == "startdate") {
            lowercaseField = employee.startdate;
        }
        else if (searchField == "position") {
            lowercaseField = employee.position;
        }
        else {
            std::cout << "Invalid search field!" << std::endl;
            return;
        }

        std::transform(lowercaseField.begin(), lowercaseField.end(), lowercaseField.begin(), [](unsigned char c) {
            return std::tolower(c);
            });

        if (lowercaseField.find(lowercaseSearchKeyword) != std::string::npos) {
            found = true;
            std::cout << employee.birthday << " " << employee.department << " " << employee.name << " " << employee.startdate << " " << employee.position << std::endl;
        }
    }

    if (!found) {
        std::cout << "No matching employees found." << std::endl;
    }
}

void findEmployeeByBirthday(const std::string& employeeBirthday) {
    searchEmployees(employeeBirthday, "birthday");
}

void findEmployeeByDepartment(const std::string& employeeDepartment) {
    searchEmployees(employeeDepartment, "department");
}

void findEmployeeByName(const std::string& employeeName) {
    searchEmployees(employeeName, "name");
}

void findEmployeeByStartDate(const std::string& employeeStartData) {
    searchEmployees(employeeStartData, "startdate");
}

void findEmployeeByPosition(const std::string& employeePosition) {
    searchEmployees(employeePosition, "position");
}

void deleteLinesFromFile(std::string filename) {
    std::ifstream inFile(filename);
    if (!inFile) {
        std::cout << "File could not be opened.\n";
        return;
    }

    std::vector < std::string > lines;
    std::string currentLine;
    for (; std::getline(inFile, currentLine);) {
        lines.push_back(currentLine);
    }
    inFile.close();

    std::vector < std::string > linesToDelete;
    std::cout << "Enter the lines you want to delete. Enter a blank line to finish:\n";
    for (; std::getline(std::cin, currentLine);) {
        if (currentLine.empty()) {
            break;
        }
        linesToDelete.push_back(currentLine);
    }

    std::vector < std::string > updatedLines;
    for (const std::string& line : lines) {
        if (std::find(linesToDelete.begin(), linesToDelete.end(), line) == linesToDelete.end()) {
            updatedLines.push_back(line);
        }
    }

    std::ofstream outFile(filename, std::ios_base::trunc);
    for (const std::string& line : updatedLines) {
        outFile << line << std::endl;

    }
    outFile.close();

    std::cout << "Lines successfully deleted from the file.\n";
}

void appendDataToFile(const std::string& filename) {
    std::ofstream outFile(filename.c_str(), std::ios_base::app);
    if (!outFile) {
        std::cout << "File could not be opened.\n";
        return;
    }

    Data data;

    std::cout << "Enter the name: ";
    std::getline(std::cin, data.name);
    std::transform(data.name.begin(), data.name.end(), data.name.begin(), [](unsigned char c) { return std::tolower(c); });

    std::cout << "Enter the password: ";
    std::getline(std::cin, data.password);
    std::transform(data.password.begin(), data.password.end(), data.password.begin(), [](unsigned char c) { return std::tolower(c); });

    bool validRole = false;
    while (!validRole) {
        std::cout << "Enter the role (1 or 2): ";
        std::cin >> data.role;

        if (data.role == 1 || data.role == 2) {
            validRole = true;
        }
        else {
            std::cout << "Incorrect value entered for role. Please enter 1 or 2.\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }

    outFile << data.name << " ";
    outFile << data.password << " ";
    outFile << data.role << std::endl;

    outFile.close();
    std::cout << "The data has been successfully added to the file.\n";
}

std::string promptAndValidateInput(const std::string& prompt, bool (*validator)(const std::string&)) {
    std::string input;
    do {
        std::cout << prompt;
        std::getline(std::cin, input);
    } while (!validator(input));
    return input;
}

void appendEmployeeToFile(const std::string& filename) {
    std::ofstream outFile(filename.c_str(), std::ios_base::app);
    if (!outFile) {
        std::cout << "File could not be opened.\n";
        return;
    }

    Employee employee;

    employee.birthday = promptAndValidateInput("Enter the birthday (yyyy.mm.dd): ", isValidDate);

    employee.department = promptAndValidateInput("Enter the department: ", [](const std::string& s) { return !s.empty(); });

    employee.name = promptAndValidateInput("Enter the name (FULL_NAME): ", [](const std::string& s) { return !s.empty(); });

    employee.startdate = promptAndValidateInput("Enter the startdate (yyyy.mm.dd): ", isValidDate);

    employee.position = promptAndValidateInput("Enter the position: ", [](const std::string& s) { return !s.empty(); });

    outFile << employee.birthday << " ";
    outFile << employee.department << " ";
    outFile << employee.name << " ";
    outFile << employee.startdate << " ";
    outFile << employee.position << std::endl;

    outFile.close();
    std::cout << "The data has been successfully added to the file.\n";
}

int main() {

    std::string str1, str2;
    int d = 0;

    char q, l = '0';
    int p = 10, s = 10, r = 10, t = 10;
    std::string employeesinfo;
    std::cout << "Write your login: ";
    std::getline(std::cin, str1);
    for (char& c : str1) {
        c = std::tolower(c);
    }

    std::cout << "Write your password: ";
    std::getline(std::cin, str2);
    for (char& c : str2) {
        c = std::tolower(c);

    }

    std::ifstream infile("data.txt");
    Data data;
    for (; infile >> data.name >> data.password >> data.role;) {
        if (str1 == data.name && str2 == data.password && (data.role == 1 || data.role == 2)) {
            d = data.role;
            break;

        }
    }

    infile.close();

    if (d == 1) {

        MenuAdmin();

        for (; p == 10;) {
            std::cin >> q;
            q = std::tolower(q);

            if (q == 'd') {
                std::cout << "Display employees" << std::endl;
                std::ifstream file("employees.txt");
                if (!file) {
                    std::cerr << "Failed to open the file." << std::endl;
                    return 1;
                }

                Employee employee;
                std::string employees = "employees.txt";
                DisplayEmployees(employees);

                MenuAdmin();

                file.close();

            }
            else if (q == 'v') {

                std::cout << "View data" << std::endl;

                std::ifstream file("data.txt");
                if (!file) {

                    std::cerr << "Failed to open the file." << std::endl;
                    return 1;
                }

                Employee employee;
                std::string employees = "data.txt";
                DisplayData();

                MenuAdmin();

                file.close();
            }
            else if (q == 'e') {

                Edit();

                r = 10;

                for (; r == 10;) {

                    std::cin >> l;
                    l = std::tolower(l);

                    if (l == 'e') {

                        std::string filename = "employees.txt";
                        std::cin.ignore();
                        appendEmployeeToFile(filename);

                        Edit();
                    }
                    else if (l == 'm') {

                        std::string filename = "employees.txt";
                        std::cin.ignore();
                        deleteLinesFromFile(filename);

                        Edit();
                    }

                    else if (l == 'd') {

                        std::string filename = "data.txt";
                        std::cin.ignore();
                        appendDataToFile(filename);

                        Edit();
                    }
                    else if (l == 'a') {

                        std::string filename = "data.txt";
                        std::cin.ignore();
                        deleteLinesFromFile(filename);

                        Edit();
                    }
                    else if (l == 'q') {

                        r = 0;
                        MenuAdmin();
                    }
                    else std::cout << std::endl << "You have entered an invalid character, please enter the present character" << std::endl;
                }

            }

            if (q == 's') {

                Sort();

                std::ifstream file("employees.txt");
                if (!file) {

                    std::cerr << "Unable to open file" << std::endl;
                    return 1;
                }

                std::vector < Employee > employees;

                std::string line;
                for (; getline(file, line);) {

                    std::istringstream iss(line);
                    Employee employee;

                    if (!(iss >> employee.birthday >> employee.department >> employee.name >> employee.startdate >> employee.position)) {

                        continue;
                    }

                    employees.push_back(employee);
                }

                s = 10;

                for (; s == 10;) {

                    std::cin >> l;
                    l = std::tolower(l);

                    if (std::tolower(l) == 'b') {

                        bubbleSortByBirthday(employees);
                        std::cout << "Employees sorted by birthday:" << std::endl;
                        printEmployees(employees);
                        Sort();
                    }
                    else if (l == 'd') {

                        bubbleSortByDepartment(employees);
                        std::cout << "Employees sorted by department:" << std::endl;
                        printEmployees(employees);
                        Sort();
                    }
                    else if (l == 'n') {

                        bubbleSortByName(employees);
                        std::cout << "Employees sorted by name:" << std::endl;
                        printEmployees(employees);
                        Sort();
                    }
                    else if (l == 's') {

                        bubbleSortByStartDate(employees);
                        std::cout << "Employees sorted by start date:" << std::endl;
                        printEmployees(employees);
                        Sort();
                    }
                    else if (l == 'p') {

                        bubbleSortByPosition(employees);
                        std::cout << "Employees sorted by start position:" << std::endl;
                        printEmployees(employees);
                        Sort();
                    }
                    else if (l == 'r') {

                        std::cout << "Employees of retirement age:" << std::endl;
                        calculateAgesFromFile("employees.txt");
                        Sort();
                    }

                    if (l == 'q') {

                        s = 0;

                        MenuAdmin();
                    }

                }

            }

            if (q == 'r') {

                Search();

                r = 10;

                for (; r == 10;) {

                    std::cin >> l;
                    l = std::tolower(l);

                    if (l == 'b') {

                        std::cout << "Enter birthday: ";
                        std::cin >> employeesinfo;
                        std::cout << "Result" << std::endl;

                        findEmployeeByBirthday(employeesinfo);
                        Search();
                    }
                    else if (l == 'd') {

                        std::cout << "Enter department: ";
                        std::cin >> employeesinfo;
                        std::cout << "Result" << std::endl;

                        findEmployeeByDepartment(employeesinfo);
                        Search();
                    }
                    else if (l == 'n') {

                        std::cout << "Enter name: ";
                        std::cin >> employeesinfo;
                        std::cout << "Result" << std::endl;

                        findEmployeeByName(employeesinfo);
                        Search();
                    }
                    else if (l == 's') {

                        std::cout << "Enter start date: ";
                        std::cin >> employeesinfo;
                        std::cout << "Result" << std::endl;

                        findEmployeeByStartDate(employeesinfo);
                        Search();
                    }
                    else if (l == 'p') {
                        std::cout << "Enter positin: ";
                        std::cin >> employeesinfo;
                        std::cout << "Result" << std::endl;

                        findEmployeeByPosition(employeesinfo);
                        Search();
                    }
                    else if (l == 'q') {
                        r = 0;
                        MenuAdmin();
                    }
                    else std::cout << std::endl << "You have entered an invalid character, please enter the present character" << std::endl;
                }

            }
            if (q == 'q') {
                std::cout << "Quit" << std::endl;
                p = 0;
            }
        }
        if (l == 'q') {
            s = 0;
        }

    }

    if (d == 2) {

        MenuUser();

        for (; p == 10;) {
            std::cin >> q;
            q = std::tolower(q);

            if (q == 'd') {
                std::cout << "Display employees" << std::endl;
                std::ifstream file("employees.txt");
                if (!file) {
                    std::cerr << "Failed to open the file." << std::endl;
                    return 1;
                }

                Employee employee;
                std::string employees = "employees.txt";
                DisplayEmployees(employees);

                MenuUser();

                file.close();

            }

            if (q == 's') {

                Sort();

                std::ifstream file("employees.txt");
                if (!file) {

                    std::cerr << "Unable to open file" << std::endl;
                    return 1;
                }

                std::vector < Employee > employees;

                std::string line;
                for (; getline(file, line);) {

                    std::istringstream iss(line);
                    Employee employee;

                    if (!(iss >> employee.birthday >> employee.department >> employee.name >> employee.startdate >> employee.position)) {

                        continue;
                    }

                    employees.push_back(employee);
                }

                s = 10;

                for (; s == 10;) {

                    std::cin >> l;
                    l = std::tolower(l);

                    if (std::tolower(l) == 'b') {

                        bubbleSortByBirthday(employees);
                        std::cout << "Employees sorted by birthday:" << std::endl;
                        printEmployees(employees);
                        Sort();
                    }
                    else if (l == 'd') {

                        bubbleSortByDepartment(employees);
                        std::cout << "Employees sorted by department:" << std::endl;
                        printEmployees(employees);
                        Sort();
                    }
                    else if (l == 'n') {

                        bubbleSortByName(employees);
                        std::cout << "Employees sorted by name:" << std::endl;
                        printEmployees(employees);
                        Sort();
                    }
                    else if (l == 's') {

                        bubbleSortByStartDate(employees);
                        std::cout << "Employees sorted by start date:" << std::endl;
                        printEmployees(employees);
                        Sort();
                    }
                    else if (l == 'p') {

                        bubbleSortByPosition(employees);
                        std::cout << "Employees sorted by start position:" << std::endl;
                        printEmployees(employees);
                        Sort();
                    }
                    else if (l == 'r') {
                        std::cout << "Employees of retirement age:" << std::endl;
                        calculateAgesFromFile("employees.txt");
                        Sort();
                    }

                    if (l == 'q') {

                        s = 0;

                        MenuUser();
                    }

                }

            }

            if (q == 'r') {

                Search();

                r = 10;

                for (; r == 10;) {

                    std::cin >> l;
                    l = std::tolower(l);

                    if (l == 'b') {

                        std::cout << "Enter birthday: ";
                        std::cin >> employeesinfo;
                        std::cout << "Result" << std::endl;

                        findEmployeeByBirthday(employeesinfo);
                        Search();
                    }
                    else if (l == 'd') {

                        std::cout << "Enter department: ";
                        std::cin >> employeesinfo;
                        std::cout << "Result" << std::endl;

                        findEmployeeByDepartment(employeesinfo);
                        Search();
                    }
                    else if (l == 'n') {

                        std::cout << "Enter name: ";
                        std::cin >> employeesinfo;
                        std::cout << "Result" << std::endl;

                        findEmployeeByName(employeesinfo);
                        Search();
                    }
                    else if (l == 's') {

                        std::cout << "Enter start date: ";
                        std::cin >> employeesinfo;
                        std::cout << "Result" << std::endl;
                        findEmployeeByStartDate(employeesinfo);

                        Search();
                    }
                    else if (l == 'p') {
                        std::cout << "Enter positin: ";
                        std::cin >> employeesinfo;
                        std::cout << "Result" << std::endl;

                        findEmployeeByPosition(employeesinfo);
                        Search();
                    }
                    else if (l == 'q') {
                        r = 0;
                        MenuUser();
                    }
                    else std::cout << std::endl << "You have entered an invalid character, please enter the present character" << std::endl;
                }

            }
            if (q == 'q') {
                std::cout << "Quit" << std::endl;
                p = 0;
            }

        }
        if (l == 'q') {
            s = 0;
        }

    }
    else {
        std::cout << "\tClosed" << std::endl;

    }

    return 0;

}