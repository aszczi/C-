#include <iostream>
#include <string>
#include <vector>
#include <fstream>

//program wczytuje macierz pierwsza z pliku macierz_1.txt i macierz druga z pliku macierz_2.txt
//wymnozone macierze zapisuje do pliku macierz_3.txt


int main() {
    std::vector<std::vector<float>> data1;
    std::vector<std::vector<float>> data2;
    std::vector<std::vector<float>> data3;


    std::ifstream file("macierz_1.txt");
    std::ifstream file2("macierz_2.txt");
    std::ofstream file3("macierz_3.txt");

    std::string line;
    int spacje=0;
    if (!file.is_open()) {
        std::cerr << "File not found" << std::endl;
        return 1;
    }

    std::vector<float> row;
    std::string a;

    while (std::getline(file, line)) {
        a="";
        for(int i = 0; i<line.size(); i++){
            if (line[i] == ' '){
                row.push_back(std::stof(a));
                a="";
            }else{
                a+=line[i];
            }

           // std::cout << line[i];
        }
        row.push_back(std::stof(a));
        data1.push_back(row);
        row.clear();

    }


    std::string b;
    while (std::getline(file2, line)) {
        b="";
        for(int i = 0; i<line.size(); i++){
            if (line[i] == ' '){
                row.push_back(std::stof(b));
                b="";
            }else{
                b+=line[i];
            }
            // std::cout << line[i];
        }
        row.push_back(std::stof(b));
        data2.push_back(row);
        row.clear();
    }

    file.close();
    file2.close();

    int kolumny = data1.size();
    int wiersze  = data2[0].size();

    for(int i = 0; i < kolumny; i++) {
        data3.push_back(std::vector<float>());
        for (int j = 0; j < wiersze; j++) {
            data3[i].push_back(0);
        }
    }


//zapisujemy do tablicy
    for(int i = 0; i < kolumny; i++) {
        for (int j = 0; j < wiersze; j++) {
            //data3[i][j] = 0;
            for (int k = 0; k < data1[0].size(); k++) {
                data3[i][j] += data1[i][k] * data2[k][j];
            }
        }
    }

//zapisz dane 3 do pliku
    for(size_t i = 0; i < data3.size(); i++) {
        for (size_t j = 0; j < data3[0].size() ; j++) {
            file3 << data3[i][j] << " ";
        }
        file3<<std::endl;
    }
    return 0;
}
