#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

void getStringTokens(const std::string& sentence, std::vector<std::string>& tokens) {
    std::stringstream ss(sentence);
    std::string word;
    while (ss >> word) {
        tokens.push_back(word);
    }
}

int main() {
    std::string sentence = "./prog1 | ./prog2 > out.txt";
    std::vector<std::string> myStringTokens;

    getStringTokens(sentence, myStringTokens);

    // C_String copy
    char* C_StyleString[myStringTokens.size() + 1];
    for (size_t i = 0; i < myStringTokens.size(); i++) {
        C_StyleString[i] = (char*)myStringTokens[i].c_str();
    }
    C_StyleString[myStringTokens.size()] = nullptr; // Null-terminate the array

    // Print the C-style strings
    for (size_t i = 0; i < myStringTokens.size(); i++) {
        std::cout << C_StyleString[i] << std::endl;
    }


    return 0;
}
