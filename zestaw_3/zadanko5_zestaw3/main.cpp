#include <iostream>
#include <string>
#include <iomanip>
#include "sha256.h"
#include <chrono>

const int MAX = 10000000;

using namespace std;



string mine(int numer_bloku, const string& transakcje, const string &poprzedni_hash, int zera){

    SHA256 sha256;

    string prefix_str(zera, '0');

    for (int i = 0; i < MAX; i++){
        string text = to_string(numer_bloku) + transakcje + poprzedni_hash + to_string(i);
        string new_hash = sha256(text);

        if (new_hash.substr(0, zera) == prefix_str){
            cout << "Wykopano bitcoina o wartosci: " << i << endl;
            return new_hash;
        }

    }

    throw std::runtime_error("Nie znaleziono odpowiedniego hasha po " + std::to_string(MAX) + " probach");

}


int main() {

    string transakcje = R"(
        Ola->Kamil->20,
        Maciek->Zosia->45
    )";

    int trudnosc = 4;

    auto start = chrono::steady_clock::now();
    cout << "Rozpoczecie kopania" << std::endl;

    string nowy_hash = mine(5, transakcje, "0000000xa036944e29568d0cff17edbe038f81208fecf9a66be9a2b8321c6ec7", trudnosc);

    auto koniec = std::chrono::steady_clock::now();
    chrono::duration<double> czas = koniec - start;

    cout << "Zakonczenie kopania. Kopanie zajelo: " << czas.count() << " seconds" << endl;
    cout << "Nowy hash " << nowy_hash << endl;

    return 0;
}