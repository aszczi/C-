#include <iostream>
#include <string>

std::string conversion(int n){
    //do 3999
    std::string rzymskie = "";
    if(n >= 4000){
        std::cout<<"Liczba jest za duza"<<std::endl;
    }else{
        while(n >= 1000){
            rzymskie += "M";
            n -= 1000;
        }
        if(n >= 900){
            rzymskie += "CM";
            n -= 900;
        }
        if(n >= 500){
            rzymskie += "D";
            n -= 500;
        }
        if(n >= 400){
            rzymskie += "CD";
            n -= 400;
        }
        while(n >= 100){
            rzymskie += "C";
            n -= 100;
        }
        if(n >= 90) {
            rzymskie += "XC";
            n -= 90;
        }
        if(n >= 50) {
            rzymskie += "L";
            n -= 50;
        }
        if(n >= 40) {
            rzymskie += "XL";
            n -= 40;
        }
        while(n >= 10) {
            rzymskie += "X";
            n -= 10;
        }
        if(n >= 9) {
            rzymskie += "IX";
            n -= 9;
        }
        if(n >= 5) {
            rzymskie += "V";
            n -= 5;
        }
        if(n >= 4) {
            rzymskie += "IV";
            n -= 4;
        }
        while(n >= 1) {
            rzymskie += "I";
            n -= 1;
        }
    }
   return rzymskie;
}

int main(int argc, char* argv[]) {

    std::string s1;
    for(int i = 1; i < argc; i++) {
       int a = std::stoi(argv[i]);
       std::cout<<a<<" w zapisie rzymskim to: "<<conversion(a)<<std::endl;
    }
    return 0;
}
