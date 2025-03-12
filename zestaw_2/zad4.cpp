#include <iostream>
#include <filesystem>


int main() {
    std::string sciezka;
    std::cout << "Podaj sciezke do katalogu: ";
    std::cin >> sciezka;

    if (!std::filesystem::exists(sciezka)) {
        std::cout << "Podana sciezka nie istnieje." << std::endl;
        return 1;
    }

    if (!std::filesystem::is_directory(sciezka)) {
        std::cout << "Podany adres nie jest katalogiem." << std::endl;
        return 1;
    }

    bool znaleziono_pliki = false;

    for (const auto& entry : std::filesystem::directory_iterator(sciezka)) {
        if (std::filesystem::is_regular_file(entry)) {

            std::cout << "Plik: " << entry.path().filename() << ", Rozmiar: " << std::filesystem::file_size(entry) << " B" << std::endl;
            znaleziono_pliki = true;
        }
    }

    if (!znaleziono_pliki) {
        std::cout << "Brak zwyklych plikow w podanym katalogu." << std::endl;
    }

    return 0;
}
