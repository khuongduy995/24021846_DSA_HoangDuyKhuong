
#include <iostream>
#include <cstring>
using namespace std;

struct Symbol {
    char name[50];
    char type[20];
    Symbol* next;
};

class SymbolTable {
private:
    Symbol* head;

public:
    SymbolTable() {
        head = NULL;
    }

    // Insert
    void insert(const char* name, const char* type) {

        Symbol* p = head;

        while (p != NULL) {
            if (strcmp(p->name, name) == 0) {
                cout << "Symbol da ton tai!\n";
                return;
            }
            p = p->next;
        }

        Symbol* newNode = new Symbol;

        strcpy(newNode->name, name);
        strcpy(newNode->type, type);
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
        }
        else {
            Symbol* temp = head;

            while (temp->next != NULL) {
                temp = temp->next;
            }

            temp->next = newNode;
        }
    }

    // Lookup
    Symbol* lookup(const char* name) {

        for (Symbol* p = head; p != NULL; p = p->next) {
            if (strcmp(p->name, name) == 0) {
                return p;
            }
        }

        return NULL;
    }

    // Remove
    void remove(const char* name) {

        Symbol* p = head;

        if (head == NULL) return;

        if (strcmp(head->name, name) == 0) {
            head = head->next;
            delete p;
            return;
        }

        while (p->next != NULL) {

            if (strcmp(p->next->name, name) == 0) {

                Symbol* temp = p->next;
                p->next = temp->next;

                delete temp;
                return;
            }

            p = p->next;
        }
    }

    // Display
    void display() {

        cout << "\nName\t\tType\n";

        for (Symbol* p = head; p != NULL; p = p->next) {
            cout << p->name << "\t\t"
                 << p->type << endl;
        }
    }

    // Destructor
    ~SymbolTable() {

        while (head != NULL) {

            Symbol* temp = head;
            head = head->next;

            delete temp;
        }
    }
};


