#include <iostream>

//Napisz program, który zapyta o dwa ciągi znaków oraz je porówna, nie zwracając uwagi na wielkość
//liter (tzn. żeby traktował literę A i a jako takie same). W tym programie proszę nie używać jeszcze
//typu std::string, tylko ciągi znaków na początku wpisać do odpowiednio pojemnej tablicy char


bool porownaj(char ciag1[], char ciag2[]) {
    int i = 0;
    while (ciag1[i] != '\0' && ciag2[i] != '\0') { //czy ||
        if (ciag1[i] != ciag2[i] && ciag1[i] != ciag2[i] + 32 && ciag1[i] != ciag2[i] - 32) {
            return false;
        }
        i++;
    }
    if (ciag1[i] != ciag2[i]) {
        return false;
    }
    return true;
}
int main() {

    char ciag1[100];
    char ciag2[100];

    std::cout << "Podaj dwa ciągi znakowe" << std::endl;
    std::cin>> ciag1 >> ciag2;
    if (porownaj(ciag1, ciag2)) {
        std::cout << "Ciągi są takie same" << std::endl;
    } else {
        std::cout << "Ciągi są różne" << std::endl;
    }

    return 0;
}
