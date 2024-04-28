#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

// Scrivere in cpp un programma per gestire un Array di dipendenti.
//Ogni dipendente è identificato da un id numerico, un nome, un cognome, una data di nascita, uno stipendio annuo.
//Attraverso un menù deve essere possibile:
//1) inserire un nuovo dipendente
//2) aggiornare lo stipendio di un dipendente indicando l'id numerico
//3) cancellare un dipendente indicando l'id numerico (bisogna fare lo shift del vettore per non lasciare la posizione vuota nell'array.
//4) ricercare e stampare un dipendente indicando l'id numerico
//5) ordinare e stampare l'array per cognome
//6) ordinare e stampare l'array per stipendio crescente
//7) ordinare e stampare l'array per stipendio decrescente
//8) uscita dal programma

struct Employee {
    int id{};
    string name;
    string lastname;
    string birthdate;
    double salary{};
};


enum Choice {
    INSERT = 1,
    UPDATE,
    DELETE,
    SEARCH,
    SORT_BY_LASTNAME,
    SORT_BY_SALARY_ASC,
    SORT_BY_SALARY_DESC,
    EXIT
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
            "8) Uscita dal programma\n"
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
    int pivotIdx = low;
    T pivot = arr[pivotIdx];

    while (low < high) {
        while (compare(arr[low], pivot)) {
            low++;
        }
        while (!compare(arr[high], pivot)) {
            high--;
        }
        if (low < high) {
            swap(arr[low], arr[high]);
        }
    }

    swap(arr[pivotIdx], arr[high]);
    return high;
}

template<typename T, typename Cmp>
requires std::invocable<Cmp, const T &, const T &>
void quickSort(vector<T> &arr, int low, int high, Cmp compare) {
    if (low < high) {
        int pivot = partition(arr, low, high, compare);
        quickSort(arr, low, pivot - 1, compare);
        quickSort(arr, pivot + 1, high, compare);
    }
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

int main() {
    vector<Employee> employees;

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
                break;
            case SORT_BY_SALARY_ASC:
                cout << "Ordina e stampa l'array per stipendio crescente\n";
                sortBySalaryAsc(employees);
                break;
            case SORT_BY_SALARY_DESC:
                cout << "Ordina e stampa l'array per stipendio decrescente\n";
                sortBySalaryDesc(employees);
                break;
            case EXIT:
                cout << "Uscita dal programma\n";
                return 0;
            default:
                cout << "Scelta non valida\n";
        }
    } while (true);
}