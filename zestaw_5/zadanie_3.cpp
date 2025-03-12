#include <iostream>
#include <string>

class TOsoba {
public:
    unsigned long long PESEL;
    TOsoba() : PESEL(0) {}
    TOsoba(unsigned long long pesel) : PESEL(pesel) {}
    void WyswietlPESEL() {
        std::cout << "Pesel tej osoby to : " << this->PESEL << std::endl;
    }
    unsigned long long ZwrocPESEL() {
        return this->PESEL;
    }

};

class MozeBycStudentem {
public:
    std::string UkonczonaSzkolaSrednia;
    MozeBycStudentem() : UkonczonaSzkolaSrednia("") {}
    MozeBycStudentem(std::string szkola) : UkonczonaSzkolaSrednia(szkola) {}

    void WyswietlSzkole() {
        std::cout << "Ukonczona szkola srednia: " << this->UkonczonaSzkolaSrednia << std::endl;
    }

};

class MozeNauczac {
public:
    std::string UkonczonaUczelniaWyzsza;
    MozeNauczac() : UkonczonaUczelniaWyzsza("") {}
    MozeNauczac(std::string uczelnia) : UkonczonaUczelniaWyzsza(uczelnia) {}

    void WyswietlUczelnie() {
        std::cout << "Ukonczona uczelnia wyzsza: " << this->UkonczonaUczelniaWyzsza << std::endl;
    }
};

class MozeWykBadania {
public:
    int NumerPozwolenia;
    MozeWykBadania() : NumerPozwolenia(0) {}
    MozeWykBadania(int numer) : NumerPozwolenia(numer) {}

    void WyswietlPozwolenie() {
        std::cout << "Numer pozwolenia na badania: " << this->NumerPozwolenia << std::endl;
    }
};

class TStudent : public virtual TOsoba, public MozeBycStudentem {
public:
    int NumerIndeksu;
    TStudent() : NumerIndeksu(0) {}
    TStudent(int indeks, unsigned long long pesel, std::string szkola)
            : TOsoba(pesel), MozeBycStudentem(szkola), NumerIndeksu(indeks) {}

    int ZwrocIndeks() {
        return this->NumerIndeksu;
    }
};

class TDoktorant : public TStudent {
public:
    std::string Specjalizacja;
    TDoktorant() : Specjalizacja("") {}
    TDoktorant(std::string specjalizacja, int indeks, unsigned long long pesel, std::string szkola)
            : TOsoba(pesel), TStudent(indeks, pesel, szkola), Specjalizacja(specjalizacja) {}

    void WyswietlSpecjalizacje() {
        std::cout << "Specjalizacja: " << this->Specjalizacja << std::endl;
    }
};

class TDoktorantNauczyciel : public TDoktorant, public MozeNauczac {
public:
    std::string ProwadzoneZajecia;
    TDoktorantNauczyciel(std::string zajecia, std::string specjalizacja, int indeks, unsigned long long pesel, std::string szkola, std::string uczelnia)
            :  TOsoba(pesel), TDoktorant(specjalizacja, indeks, pesel, szkola), MozeNauczac(uczelnia), ProwadzoneZajecia(zajecia) {}

    void WyswietlProwadzoneZajecia() {
        std::cout << "Prowadzone zajecia: " << ProwadzoneZajecia << std::endl;
    }
};

class TAsystentBadan : public TOsoba, public MozeWykBadania {
public:
    std::string OstatnieProwadzoneBadanie;
    TAsystentBadan() : OstatnieProwadzoneBadanie("") {}
    TAsystentBadan(std::string badanie, int pozwolenie, unsigned long long pesel)
            : TOsoba(pesel), MozeWykBadania(pozwolenie), OstatnieProwadzoneBadanie(badanie) {}

    void WyswietlOstatnieBadanie() {
        std::cout << "Ostatnio prowadzone badanie to: " << this->OstatnieProwadzoneBadanie << std::endl;
    }
};

class TDoktorantBadacz : public virtual TAsystentBadan, public TDoktorant {
public:
    std::string DorobekNaukowy;

    TDoktorantBadacz() : DorobekNaukowy("") {}
    TDoktorantBadacz(std::string dorobek, std::string badanie, int pozwolenie, unsigned long long pesel, std::string specjalizacja, int indeks, std::string szkola)
            : TOsoba(pesel), TAsystentBadan(badanie, pozwolenie, pesel), TDoktorant(specjalizacja, indeks, pesel, szkola), DorobekNaukowy(dorobek) {}

    void WyswietlDorobekNaukowy() {
        std::cout << "Dorobek Naukowy: " << this->DorobekNaukowy << std::endl;
    }
    void WyswietlPESEL(){
        TDoktorant::WyswietlPESEL();
    }
};

int main() {
    TOsoba Ola(91030401234);
    TStudent student1(1195504, 93260501234, "Liceum nr 2 w Krakowie");
    TDoktorant doktorant1("Szczury", 1234567, 81310601234, "Technikum nr 1 w Krakowie");
    TDoktorantNauczyciel doktorantNauczyciel("Programowanie", "Informatyka", 123456789, 79282501234, "Liceum Ogolnoksztalcace w Zabrzu", "Politechnika Warszawska");
    TAsystentBadan asystentBadan( "Badanie nad szczurami", 1234443, 75211501234);
    TDoktorantBadacz doktorantBadacz("opublikowana ksiazka: Szczur w badaniach psychologii spolecznej", "Badanie nad szczurami", 1234443, 77201001034, "Psychologia spoleczna", 123456789, "Liceum Ogolnoksztalcace");

  std::cout<<"Ola: "<<std::endl;
    Ola.WyswietlPESEL();
    std::cout<<std::endl;

    std::cout<<"Student nr 1: "<<std::endl;
    student1.WyswietlPESEL();
    std::cout << "Indeks: " << student1.ZwrocIndeks() << std::endl;
    student1.WyswietlSzkole();
    std::cout<<std::endl;

    std::cout<<"Doktorant: "<<std::endl;
    doktorant1.WyswietlPESEL();
    std::cout << "Indeks: " << doktorant1.ZwrocIndeks() << std::endl;
    doktorant1.WyswietlSzkole();
    doktorant1.WyswietlSpecjalizacje();
    std::cout<<std::endl;

    std::cout<<"Doktorant-Nauczyciel: "<<std::endl;
    doktorantNauczyciel.WyswietlPESEL();
    std::cout << "Indeks : " << doktorantNauczyciel.ZwrocIndeks() << std::endl;
    doktorantNauczyciel.WyswietlSzkole();
    doktorantNauczyciel.WyswietlSpecjalizacje();
    doktorantNauczyciel.WyswietlProwadzoneZajecia();
    doktorantNauczyciel.WyswietlUczelnie();
    std::cout<<std::endl;

    std::cout<<"Asystent Badan: "<<std::endl;
    asystentBadan.WyswietlPESEL();
    asystentBadan.WyswietlOstatnieBadanie();
    asystentBadan.WyswietlPozwolenie();
    std::cout<<std::endl;


    std::cout<<"Doktorant-Badacz: "<<std::endl;
    doktorantBadacz.TAsystentBadan::WyswietlPESEL();
    doktorantBadacz.WyswietlSzkole();
    doktorantBadacz.WyswietlPozwolenie();
    doktorantBadacz.WyswietlOstatnieBadanie();
    doktorantBadacz.WyswietlSpecjalizacje();
    doktorantBadacz.WyswietlDorobekNaukowy();
    std::cout<<std::endl;


    return 0;
}