#include <iostream>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>

struct Klucz{
    unsigned long long e;
    unsigned long long n;
};


typedef unsigned long long ulong;

// Funkcja mnoży a i b mod n
ulong MnozModulo (ulong a, ulong b, ulong n)
{
    ulong m, w;

    w = 0;
    for(m = 1; m; m <<= 1)
    {
        if(b & m) w = (w + a) % n;
        a = (a << 1) % n;
    }
    return w;
}

// Funkcja oblicza a^e mod n
ulong PotegujModulo (ulong a, ulong e, ulong n)
{
    ulong m, p, w;

    p = a; w = 1;
    for(m = 1; m; m <<= 1)
    {
        if(e & m) w = MnozModulo (w, p, n);
        p = MnozModulo (p, p, n);
    }
    return w;
}

int main() {

    unsigned long long d;
    unsigned long long p = 449;
    unsigned long long q = 443;
    unsigned long long n = p * q;
    unsigned long long phi = (p - 1) * (q - 1);
    //zerujemy liczby które byly potrzebne do kodowania
    p=0;
    q=0;

    unsigned long long e = 3; // przykladem naszej liczby e moze byc 3 (3 jest wzglednie pierwsze z phi)

//liczymy odwrotnosc modulo rozszerzonym euklidesem
    int u, w, x, z, g;

    u = 1; w = e;
    x = 0; z = phi;
    while(w)
    {
        if(w < z)
        {   g = u; u = x; x = g;
            g = w; w = z; z = g;
        }
        g = w / z;
        u -= g * x;
        w -= g * z;
    }
    if(z == 1)
    {   if(x < 0) x += phi;
        d=x;
    }
    else{
        std::cout << "BRAK\n";
        return 1;
    }

    //mamy klucz publiczny (e, n) i klucz prywatny (d, n)
    Klucz klucz_publiczny;
    klucz_publiczny.e = e;
    klucz_publiczny.n = n;
    Klucz klucz_prywatny;
    klucz_prywatny.e = d;
    klucz_prywatny.n = n;

    std::cout<<"Klucz publiczny: ("<<klucz_publiczny.e<<", "<<klucz_publiczny.n<<")"<<std::endl;
    std::cout<<"Klucz prywatny: ("<<klucz_prywatny.e<<", "<<klucz_prywatny.n<<")"<<std::endl;

    //zmieniajemy wiadomosc na liczbe < n
    std::string wiadomosc = "OK";
    std::cout<<"Wiadomosc, ktora chcemy przeslac : "<<wiadomosc<<std::endl;
    std::string zaszyfrowana_wiadomosc = "";
    for(int i = wiadomosc.length()-1; i>=0; i--){
        int kod = wiadomosc[i];
        std::string kod_str = std::to_string(kod);
        zaszyfrowana_wiadomosc = kod_str + zaszyfrowana_wiadomosc;
    }
    std::cout<<"Zaszyfrowana wiadomosc: "<<zaszyfrowana_wiadomosc<<std::endl;
    unsigned long long t = std::stoull(zaszyfrowana_wiadomosc);

    //szyfrujemy kluczem publicznym
    unsigned long long zaszyfrowana_wiadomosc_szyfr = ((unsigned long long)pow(t, klucz_publiczny.e))%n;
    std::cout<<"Wiadomosc zaszyfrowana kluczem publicznym: "<<zaszyfrowana_wiadomosc_szyfr<<std::endl;

    //deszyfrujemy kluczem prywatnym
    unsigned long long zaszyfrowana_wiadomosc_deszyfr = PotegujModulo(zaszyfrowana_wiadomosc_szyfr, klucz_prywatny.e, klucz_prywatny.n);
    std::string zaszyfrowana_wiadomosc_deszyfr_str = std::to_string(zaszyfrowana_wiadomosc_deszyfr);

    std::cout<<"Odszyfrowana wiadomosc za pomoca klucza prywatnego: "<<zaszyfrowana_wiadomosc_deszyfr_str<<std::endl;

    std::cout<<"Odszyfrowana i przekonwertowana do pierwotnej formy wiadomosc: ";
    for(int i = 0; i<zaszyfrowana_wiadomosc_deszyfr_str.length(); i+=2){
        std::string kod_str = zaszyfrowana_wiadomosc_deszyfr_str.substr(i, 2);
        int kod = std::stoi(kod_str);
        char znak = kod;
        std::cout<<znak;
    }

    return 0;
}
