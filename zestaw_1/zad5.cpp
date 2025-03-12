#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>

/* Napisz program, który wczyta wskazany plik tekstowy, umieszczając go w obiekcie std::string,
a następnie posortuje wszystkie wyrazy i wypisze 10 wyrazów najczęściej występujących (wyraz – liczba wystąpień). */

void podziel_na_wyrazy(std::string s1, std::vector<std::string> &words) {
    std::string word;
    for (int i = 0; i < s1.size(); i++) {
        if (s1[i] != ' ' && s1[i] != '.' && s1[i] != ',') { // Pomijamy spacje i kropki
            word += s1[i];
        } else if ((s1[i] == '.' || s1[i] == ',') && i + 1 < s1.size() &&
                   s1[i + 1] == ' ') { // Jeśli po kropce lub przecinku jest spacja
            if (!word.empty()) {
                words.push_back(word);
                word = "";
            }
            // Pomijamy kropkę i spacje
            i++;
            while (i + 1 < s1.size() && s1[i + 1] == ' ') { // Pomijamy więcej niż jedną spację
                i++;
            }
        } else {
            if (!word.empty()) {
                words.push_back(word);
                word = "";
            }
        }
    }
    if (!word.empty()) { // Dodajemy ostatni wyraz
        words.push_back(word);
    }
}


void sortuj_tablice(std::vector<std::string> &words_with_count, std::vector<int> &count) {
    for (int i = 0; i < words_with_count.size(); i++) {
        for (int j = 0; j < words_with_count.size() - 1; j++) {
            if (count[j] < count[j + 1]) {
                std::swap(count[j], count[j + 1]);
                std::swap(words_with_count[j], words_with_count[j + 1]);
            }
        }
    }
}

void
words_and_count(std::vector<std::string> &words, std::vector<std::string> &words_with_count, std::vector<int> &count) {
    int liczba_wystapien = 1;
    for (int i = 0; i < words.size() - 1; i++) {
        if (words[i] == words[i + 1]) {
            liczba_wystapien++;
        } else {
            words_with_count.push_back(words[i]);
            count.push_back(liczba_wystapien);
            liczba_wystapien = 1; // zaczynamy od 1 dla nowego wyrazu
        }
    }
    // Dodanie ostatniego wyrazu
    words_with_count.push_back(words.back());
    count.push_back(liczba_wystapien);
}

int main() {
    std::string line, s1;
    std::vector<std::string> words;
    std::vector<std::string> words_with_count; //wyrazy bez powtorzen
    std::vector<int> count; //liczba wystapien

    // otwieranie pliku, wczytywanie do stringa
    std::ifstream file("file.txt");
    if (!file) {
        std::cerr << "No file found" << std::endl;
        exit(1);
    }
    while (!file.eof()) {
        std::getline(file, line);
        if (!file.eof()) {
            s1 += line + ' ';
        }
    }
    file.close();

    podziel_na_wyrazy(s1, words);

    std::sort(words.begin(), words.end());

    words_and_count(words, words_with_count, count);

    sortuj_tablice(words_with_count, count);

    std::cout << "10 najczesciej wystepujacych wyrazow: " << std::endl;

    for (int i = 0; i < 10; i++) {
        std::cout << words_with_count[i] << " - " << count[i] << std::endl;
    }

    return 0;
}
