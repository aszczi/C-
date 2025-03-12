#include <iostream>
#include <string>
//Napisz program, który wczytuje zdanie, a potem sprawdza, czy jest palindromem (tzn. czytane wspak
//brzmi tak samo). Przykład: Kobyła ma mały bok. Należy ignorować białe znaki oraz nie zwracać uwagi
//na wielkość liter. Nie używać polskich liter
std::string usun_spacje(std::string zdanie) {
    std::string wynik = "";
    for (int i = 0; i < zdanie.length(); i++) {
        if (zdanie[i] != ' ') {
            wynik += zdanie[i];
        }
    }
    return wynik;
}

bool czy_palindrom(std::string zdanie) {
    usun_spacje(zdanie);

    for(int i  =0; i < zdanie.length()/2; i++){
        zdanie[i] = tolower(zdanie[i]);
        zdanie[zdanie.length()-1-i] = tolower(zdanie[zdanie.length()-1-i]);
        if(zdanie[i] != zdanie[zdanie.length()-1-i]){
            return false;
        }
    }
    return true;
}

int main() {
    std::string zdanie;
    std::cin >> zdanie;

    if(czy_palindrom(zdanie)){
        std::cout<< "Zdanie jest palindromem";
    } else {
        std::cout<< "Zdanie nie jest palindromem";
    }

    return 0;
}
