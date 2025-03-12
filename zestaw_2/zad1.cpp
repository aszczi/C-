#include <iostream>
#include <fstream>
#include <string>
#include <vector>

int main() {
    std::vector<std::string> words;
    int letter_width =1;

    std::ifstream file("lorem_ipsum.txt", std::ios::in);
    if (!file.is_open()) {
        std::cerr << "Error: file not opened" << std::endl;
        return 1;
    }
    std::string line;
    int width = 80;

    while (std::getline(file, line)) {
        words.push_back(line);
    }
    file.close();

    std::ofstream file_out("lorem_ipsum.txt", std::ios::out | std::ios::trunc);

      for(auto word : words){
        int count = 0;
        if ((word.size()*letter_width) < width){
            for(auto letter : word) {
                if (letter == ' ') {
                    count++;
                }
            }

            int missing = width - (word.size()*letter_width);
            int missing_spaces = missing / count;
            int extraspaces = (missing % count);

            for(auto letter : word) {

                if (letter == ' ') {
                    if (extraspaces) {
                        for(size_t i = 0; i < missing_spaces + 1; i++) {
                            file_out << " ";
                        }
                        extraspaces--;
                    } else {
                        for(size_t i = 0; i < missing_spaces; i++) {
                            file_out << " ";
                        }
                    }

                }
                file_out << letter;
            }
            file_out << std::endl;
        } else{
            file_out << word << std::endl;
        }
    }

    file_out.close();

    return 0;
}
