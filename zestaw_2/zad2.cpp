#include <iostream>
#include <random>
#include <vector>

void zapelnij_losowymi(std::vector<int> &liczby, int rozmiar){
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(1, 10000);
    for (size_t i = 0; i < rozmiar; ++i) {
        liczby.push_back(distrib(gen));
    }
}

void wypisz_tablice(std::vector<int> tab, int rozmiar){
    for (size_t i = 0; i < rozmiar; i++){
        std::cout<<tab[i]<<"\n";
    }
}

void quickSort(std::vector<int> &tab, int lewy, int prawy)
{
    if(prawy <= lewy) return;
    int i = lewy -1, j = prawy +1,
            pivot = tab[(lewy+prawy)/2]; //wybieramy punkt odniesienia
    while(1)
    {
        while(pivot>tab[++i]);
        while(pivot<tab[--j]);
        if( i <= j)
            std::swap(tab[i],tab[j]);
        else
            break;
    }

    if(j > lewy)
        quickSort(tab, lewy, j);
    if(i < prawy)
        quickSort(tab, i, prawy);
}


int main() {
    std::vector<int> tablica;

    zapelnij_losowymi(tablica, 10000);
    std::cout<<"Tablica przed sortowaniem: \n";

    wypisz_tablice(tablica, 10000);
    quickSort(tablica, 0, tablica.size() - 1);
    std::cout << "Tablica po sortowaniu: \n";
    wypisz_tablice(tablica, tablica.size());


    return 0;
}
