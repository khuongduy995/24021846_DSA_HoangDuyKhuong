
#include <iostream>
#include <cstring>
using namespace std;

struct Symbol {
    char name[100];
    char type[20];
};

class SymbolTable {
private:
    Symbol table[100];
    int count;

public:
    SymbolTable() {
        count = 0;
    }

    // Insert
    void insert(const char* name, const char* type) {

        for (int i = 0; i < count; i++) {
            if (strcmp(table[i].name, name) == 0) {
                cout << "Symbol da ton tai!\n";
                return;
            }
        }

        if (count >= 100) return;

        Symbol s;
        strcpy(s.name, name);
        strcpy(s.type, type);

        table[count] = s;
        count++;
    }

    // Lookup
    int lookup(const char* name) {

        int i = 0;

        while (i < count) {

            if (strcmp(name, table[i].name) == 0) {
                break;
            }

            i++;
        }

        if (i == count) return -1;

        return i;
    }

    // Remove
    void remove(const char* name) {

        int pos = lookup(name);

        if (pos < 0) {
            cout << "Khong tim thay Symbol!\n";
            return;
        }

        int i = pos;

        while (i < count - 1) {
            table[i] = table[i + 1];
            i++;
        }

        count--;
    }

    // Display
    void display() {

        if (count == 0) {
            cout << "Symbol Table rong!\n";
            return;
        }

        cout << "\nName\t\tType\n";

        int i = 0;

        while (i < count) {
            cout << table[i].name << "\t\t"
                 << table[i].type << endl;

            i++;
        }
    }
}

