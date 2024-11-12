#include <iostream>
#include <fstream>
#include <string>
#include <stdexcept>
#include <unordered_map>

using namespace std;

void addLikedIngredients(string ingredient, unordered_map<string, int>& map) {
    map[ingredient]++;  // Increment liked ingredient count
}

void addDislikedIngredients(string ingredient, unordered_map<string, int>& map) {
    map[ingredient]--;  // Decrement disliked ingredient count
}

void printIngredients(const unordered_map<string, int>& likedMap, const unordered_map<string, int>& dislikedMap) {
    int numberOfIngredients = 0;
    string output;

    // Traverse through liked ingredients and print those that are not disliked
    for (const auto& i : likedMap) {
        // Only include ingredients that are liked (count > 0) and not in disliked map
        if (i.second > 0 && dislikedMap.find(i.first) == dislikedMap.end()) {
            numberOfIngredients++;
            output += i.first + " ";
        }
    }

    cout << numberOfIngredients << " " << output << endl;
}

void addClients(int potentialClients, ifstream& inFile, unordered_map<string, int>& likedMap, unordered_map<string, int>& dislikedMap) {
    string word;
    string numberOfLikedIngredients;
    string numberOfDislikedIngredients;

    for (int i = 0; i < potentialClients; i++) {
        if (inFile >> word) {
            numberOfLikedIngredients = word;

            try {
                int likedCount = stoi(numberOfLikedIngredients); // Try catches for stoi errors
                for (int i = 0; i < likedCount; i++) {
                    if (inFile >> word) {
                        //cout << "Liked Ingredient: " << word << endl;
                        addLikedIngredients(word, likedMap);
                    }
                    else {
                        cout << "Error reading liked ingredient." << endl;
                        break;
                    }
                }
            }
            catch (const invalid_argument& e) {
                cout << "Invalid number for liked ingredients: " << numberOfLikedIngredients << endl;
                break;
            }
            catch (const out_of_range& e) {
                cout << "Number out of range for liked ingredients: " << numberOfLikedIngredients << endl;
                break;
            }

            if (inFile >> word) {
                numberOfDislikedIngredients = word;

                try {
                    int dislikedCount = stoi(numberOfDislikedIngredients); // Try catches for stoi errors
                    for (int i = 0; i < dislikedCount; i++) {
                        if (inFile >> word) {
                            //cout << "Disliked Ingredient: " << word << endl;
                            addDislikedIngredients(word, dislikedMap);
                        }
                        else {
                            cout << "Error reading disliked ingredient." << endl;
                            break;
                        }
                    }
                }
                catch (const invalid_argument& e) {
                    cout << "Invalid number for disliked ingredients: " << numberOfDislikedIngredients << endl;
                    break;
                }
                catch (const out_of_range& e) {
                    cout << "Number out of range for disliked ingredients: " << numberOfDislikedIngredients << endl;
                    break;
                }
            }
        }
        else {
            cout << "Error reading client data at position " << i + 1 << endl;
            break;
        }
    }
}

int main() {
    ifstream inFile;
    inFile.open("C:\\Users\\RothbauerDylan\\Downloads\\a_an_example.in.txt");

    if (!inFile) {
        cout << "Error opening file" << endl;
        return 1;
    }

    string firstLine;
    int potentialClients;
    unordered_map<string, int> likedMap;
    unordered_map<string, int> dislikedMap;

    if (inFile >> firstLine) {
        try {
            potentialClients = stoi(firstLine);
            //cout << "Potential Clients: " << potentialClients << endl;
            addClients(potentialClients, inFile, likedMap, dislikedMap);
        }
        catch (const invalid_argument& e) {
            cout << "Invalid number for potential clients: " << firstLine << endl;
        }
        catch (const out_of_range& e) {
            cout << "Number out of range for potential clients: " << firstLine << endl;
        }
    }

    // Print the liked ingredients that are not disliked
    printIngredients(likedMap, dislikedMap);

    inFile.close();
    return 0;
}
