#include <iostream>
#include <string>

class BigInt{

public:
    std::string number;
    BigInt();
    BigInt(std::string);
    BigInt& operator=(const BigInt&);
   std::string add(BigInt);
   std::string subtract(BigInt);
};
BigInt::BigInt() {
    this->number = "0";
}
BigInt::BigInt(std::string s) {
    this->number = s;
}

BigInt& BigInt::operator=(const BigInt& b) {
    if (this != &b) {
        this->number = b.number;
    }
    return *this;
}
 std::string BigInt::add(BigInt b) {
   std::string first_number = this->number;
   std::string second_number = b.number;
   std::string result;
   std::string bufor = "0";
   int cases = 0;
     if(first_number[0] != '-' && second_number[0] != '-'){
         cases = 0;
     }
         //oba ujemne
     else if(first_number[0] == '-' && second_number[0] == '-'){
         cases = 1;
         first_number.erase(0, 1);
         second_number.erase(0, 1);
     }
         //ujemna i dodatnia
     else if(first_number[0] == '-' && second_number[0] != '-'){
         cases = 2;
         first_number.erase(0, 1);
     }
         //dodatnia i ujemna
     else if(first_number[0] != '-' && second_number[0] == '-'){
         cases = 3;
         second_number.erase(0, 1);
     }

     //po caseach mamy liczby juz jako ich absolute value

     //tu dodajemy zera by byly rownej dlugosci
     while(first_number.length() < second_number.length()){
         first_number = "0" + first_number;
     }
     while(first_number.length() > second_number.length()){
         second_number = "0" + second_number;
     }

    switch(cases){
        case 0:

            for(int i = first_number.length() - 1; i >= 0; i--){
                if( (first_number[i] + second_number[i] + std::stoi(bufor)) > 9){
                    result = std::to_string((first_number[i]-'0' + second_number[i]-'0' + std::stoi(bufor)) % 10) + result;
                    bufor = std::to_string((first_number[i] -'0' + second_number[i] -'0' + std::stoi(bufor)) / 10);
                }
                else{
                    result = std::to_string(first_number[i]-'0' + second_number[i]-'0' + std::stoi(bufor)) + result;
                    bufor = "0";
                }
            }

            if(bufor != "0"){
                result = bufor + result;
            }

            break;
        case 1:

            result = BigInt(first_number).add(BigInt(second_number));
            if(bufor != "0"){
                result = bufor + result;
            }
            result = "-" + result;

            break;

        case 2:

            result = BigInt(second_number).subtract(BigInt(first_number));
            break;
        case 3:

            result = BigInt(first_number).subtract(BigInt(second_number));
            break;
    }
    return result;
}

std::string BigInt::subtract(BigInt b) {
    std::string first_number = this->number;
    std::string second_number = b.number;
    std::string result;
    std::string bufor = "0";
    int cases = 0;
    //oba dodatnie
    if(first_number[0] != '-' && second_number[0] != '-'){
        cases = 0;
    }
    //oba ujemne
    else if(first_number[0] == '-' && second_number[0] == '-'){
        cases = 1;
        first_number.erase(0, 1);
        second_number.erase(0, 1);
    }
    //ujemna i dodatnia
    else if(first_number[0] == '-' && second_number[0] != '-'){
        cases = 2;
        first_number.erase(0, 1);
    }
    //dodatnia i ujemna
   else if(first_number[0] != '-' && second_number[0] == '-'){
        cases = 3;
        second_number.erase(0, 1);
    }

   //po caseach mamy liczby juz jako ich absolute value

   //tu dodajemy zera by byly rowenej dlugosci
    while(first_number.length() < second_number.length()){
        first_number = "0" + first_number;
    }
    while(first_number.length() > second_number.length()){
        second_number = "0" + second_number;
    }
    switch (cases) {
        case 0:
            if(first_number < second_number){
                result = BigInt(second_number).subtract(BigInt(first_number));
                result = "-" + result;
            }else if(first_number == second_number){
                return "0";
            }else{

                for(int i = first_number.length() - 1; i >= 0; i--){
                    if( (first_number[i] -'0' - (second_number[i]-'0') - std::stoi(bufor)) < 0){

                        result = std::to_string((first_number[i] -'0' - (second_number[i] -'0') - std::stoi(bufor)) + 10) + result;
                        bufor = "1";
                    }
                    else{
                        result = std::to_string(first_number[i] -'0' - (second_number[i] -'0') - std::stoi(bufor)) + result;
                        bufor = "0";
                    }
                }
                if(bufor != "0"){
                    result = bufor + result;
                }
            }
            break;
        case 1:
            result = BigInt(second_number).subtract(BigInt(first_number));

            break;
        case 2:

            result = BigInt(second_number).add(BigInt(first_number));
            result = "-" + result;
            break;
        case 3:

            result = BigInt(first_number).add(BigInt(second_number));
            break;
    }

    return result;
}


int main() {
BigInt a("123");
BigInt b("456");
BigInt k("-333");
BigInt l("-222");
//sprawdzenie przypadkow

std::string c = a.add(b);       // 123 + 456 = 579
std::string d = a.subtract(b);  // 123 - 456 = -333
std::cout << c << std::endl;
std::cout << d << std::endl;
std::string e = k.add(l);       // -333 + -222 = -555
std::string f = k.subtract(l);  // -333 - -222 = -111
std::cout << e << std::endl;
std::cout << f << std::endl;
std::string g = a.add(k);       // 123 + -333 = -210
std::string h = a.subtract(l);  // 123 - -222 = 345
std::cout << g << std::endl;
std::cout << h << std::endl;
std::string i = k.add(b);       // -333 + 456 = 123
std::string j = k.subtract(b);  // -333 - 456 = -789
std::cout << i << std::endl;
std::cout << j << std::endl;

    return 0;
}
