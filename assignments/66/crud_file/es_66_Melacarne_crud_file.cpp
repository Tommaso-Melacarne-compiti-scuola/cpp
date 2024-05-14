#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <fstream>
#include <ranges>
#include <sstream>

using namespace std;

struct Employee {
    int id{};
    string name;
    string lastname;
    string birthdate;
    double salary{};
};


enum Choice {
    INSERT = 1,
    UPDATE = 2,
    DELETE = 3,
    SEARCH = 4,
    SORT_BY_LASTNAME = 5,
    SORT_BY_SALARY_ASC = 6,
    SORT_BY_SALARY_DESC = 7,
    WRITE_FILE = 8,
    READ_FILE = 9,
    EXIT = 0
};


Choice displayMenu() {
    int choice;
    cout << "1) Inserisci un nuovo dipendente\n"
            "2) Aggiorna lo stipendio di un dipendente indicando l'id numerico\n"
            "3) Cancella un dipendente indicando l'id numerico\n"
            "4) Ricerca e stampa un dipendente indicando l'id numerico\n"
            "5) Ordina e stampa l'array per cognome\n"
            "6) Ordina e stampa l'array per stipendio crescente\n"
            "7) Ordina e stampa l'array per stipendio decrescente\n"
            "8) Scrivi su file\n"
            "9) Leggi da file\n"
            "0) Uscita dal programma\n"
            "Scelta: ";
    cin >> choice;
    return static_cast<Choice>(choice);
}


void newEmployee(vector<Employee> &employees) {
    Employee employee;
    auto &[id, name, lastname, birthdate, salary] = employee;

    cout << "Inserisci l'id del dipendente: ";
    cin >> id;
    cout << "Inserisci il nome del dipendente: ";
    cin >> name;
    cout << "Inserisci il cognome del dipendente: ";
    cin >> lastname;
    cout << "Inserisci la data di nascita del dipendente: ";
    cin >> birthdate;
    cout << "Inserisci lo stipendio annuo del dipendente: ";
    cin >> salary;

    employees.push_back(employee);
}

void updateSalary(vector<Employee> &employees) {
    int id;
    cout << "Inserisci l'id del dipendente: ";
    cin >> id;

    for (auto &employee: employees) {
        if (employee.id == id) {
            cout << "Inserisci il nuovo stipendio: ";
            cin >> employee.salary;
            return;
        }
    }

    cout << "Dipendente non trovato\n";
}

void shiftLeft(vector<Employee> &employees, int index) {
    for (int i = index; i < employees.size() - 1; i++) {
        employees[i] = employees[i + 1];
    }
    employees.pop_back();
}


void deleteEmployee(vector<Employee> &employees) {
    int id;
    cout << "Inserisci l'id del dipendente: ";
    cin >> id;

    for (int i = 0; i < employees.size(); i++) {
        if (employees[i].id == id) {
            shiftLeft(employees, i);
            return;
        }
    }

    cout << "Dipendente non trovato\n";
}


void printEmployee(const Employee &employee) {
    cout << "Id: " << employee.id << "\n"
                                     "Nome: " << employee.name << "\n"
                                                                  "Cognome: " << employee.lastname << "\n"
                                                                                                      "Data di nascita: "
         << employee.birthdate << "\n"
                                  "Stipendio: " << employee.salary << "\n";
}

void searchEmployee(vector<Employee> &employees) {
    int id;
    cout << "Inserisci l'id del dipendente: ";
    cin >> id;

    for (auto &employee: employees) {
        if (employee.id == id) {
            cout << "Dipendente trovato:\n";
            printEmployee(employee);
        }
    }

    cout << "Dipendente non trovato\n";
}

template<typename T, typename Cmp>
int partition(vector<T> &arr, int low, int high, Cmp compare) {
    T pivot = arr[low];

    int count = 0;
    for (int i = low + 1; i <= high; i++) {
        if (!compare(arr[i], pivot)) {
            count++;
        }
    }

    int pivotIndex = low + count;
    swap(arr[pivotIndex], arr[low]);

    int i = low, j = high;

    while (i < pivotIndex && j > pivotIndex) {
        while (!compare(arr[i], pivot)) {
            i++;
        }
        while (compare(arr[j], pivot)) {
            j--;
        }
        if (i < pivotIndex && j > pivotIndex) {
            swap(arr[i++], arr[j--]);
        }
    }

    return pivotIndex;
}

template<typename T, typename Cmp>
requires std::invocable<Cmp, const T &, const T &>
void quickSort(vector<T> &arr, int start, int end, Cmp compare) {
    if (start >= end) {
        return;
    }

    int p = partition(arr, start, end, compare);

    quickSort(arr, start, p - 1, compare);

    quickSort(arr, p + 1, end, compare);
}

void sortByLastname(vector<Employee> &employees) {
    quickSort(employees, 0, (int) employees.size() - 1, [](const Employee &a, const Employee &b) {
        return a.lastname < b.lastname;
    });
}

void sortBySalaryAsc(vector<Employee> &employees) {
    quickSort(employees, 0, (int) employees.size() - 1, [](const Employee &a, const Employee &b) {
        return a.salary < b.salary;
    });
}

void sortBySalaryDesc(vector<Employee> &employees) {
    quickSort(employees, 0, (int) employees.size() - 1, [](const Employee &a, const Employee &b) {
        return a.salary > b.salary;
    });
}

void printEmployees(const vector<Employee> &employees) {
    for (const auto &employee: employees) {
        printEmployee(employee);
        cout << "\n";
    }
}

string serializeEmployee(const Employee &employee) {
    const auto &[id, name, lastname, birthdate, salary] = employee;
    const char separator = ',';

    // use join
    string ret = to_string(id) + separator + name + separator + lastname + separator + birthdate + separator +
                 to_string(salary);
    return ret;
}

vector<string> split(const string &str, const char separator) {
    vector<string> strings;
    istringstream f(str);
    string s;
    while (getline(f, s, separator)) {
        cout << s << endl;
        strings.push_back(s);
    }

    return strings;
}

Employee deserializeEmployee(const string &employee) {
    Employee ret;
    const char separator = ',';

    vector<string> strings = split(employee, separator);

    ret.id = stoi(strings[0]);
    ret.name = strings[1];
    ret.lastname = strings[2];
    ret.birthdate = strings[3];
    ret.salary = stod(strings[4]);

    return ret;
}

void writeToFile(const vector<Employee> &employees, const string &filename) {
    ofstream file(filename);

    for (const auto &employee: employees) {
        file << serializeEmployee(employee) << "\n";
    }

    file.close();
}

void readFromFile(vector<Employee> &employees, const string &filename) {
    ifstream file(filename);

    string line;
    while (getline(file, line)) {
        employees.push_back(deserializeEmployee(line));
    }

    file.close();
}


int main() {
    vector<Employee> employees;

    string filename = "employees.txt";

    bool exit = false;
    do {
        auto menu = displayMenu();

        switch (menu) {
            case INSERT:
                cout << "Inserisci un nuovo dipendente\n";
                newEmployee(employees);
                break;
            case UPDATE:
                cout << "Aggiorna lo stipendio di un dipendente indicando l'id numerico\n";
                updateSalary(employees);
                break;
            case DELETE:
                cout << "Cancella un dipendente indicando l'id numerico\n";
                deleteEmployee(employees);
                break;
            case SEARCH:
                cout << "Ricerca e stampa un dipendente indicando l'id numerico\n";
                searchEmployee(employees);
                break;
            case SORT_BY_LASTNAME:
                cout << "Ordina e stampa l'array per cognome\n";
                sortByLastname(employees);
                printEmployees(employees);
                break;
            case SORT_BY_SALARY_ASC:
                cout << "Ordina e stampa l'array per stipendio crescente\n";
                sortBySalaryAsc(employees);
                printEmployees(employees);
                break;
            case SORT_BY_SALARY_DESC:
                cout << "Ordina e stampa l'array per stipendio decrescente\n";
                sortBySalaryDesc(employees);
                printEmployees(employees);
                break;
            case WRITE_FILE:
                cout << "Scrittura su file\n";
                writeToFile(employees, filename);
                break;
            case READ_FILE:
                cout << "Lettura da file\n";
                readFromFile(employees, filename);
                break;
            case EXIT:
                cout << "Uscita dal programma\n";
                exit = true;
            default:
                cout << "Scelta non valida\n";
        }
    } while (!exit);
}