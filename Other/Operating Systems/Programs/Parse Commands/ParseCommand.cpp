#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

using namespace std;

vector<string> tokenize(const string& line) {
    vector<string> tokens;
    stringstream ss(line);
    string temp;

    while (ss >> temp)
        tokens.push_back(temp);

    return tokens;
}

int findOperator(const vector<string>& tokens, const string& op) {
    for (int i = 0; i < tokens.size(); i++) {
        if (tokens[i] == op)
            return i;
    }
    return -1;
}

void parseCommand(const vector<string>& tokens, ofstream& out, int index) {

    int pipePos = findOperator(tokens, "|");
    int inPos = findOperator(tokens, "<");
    int outPos = findOperator(tokens, ">");

    out << "Command " << index << ": ";

    // Pipe |
    if (pipePos != -1)
        out << "I found in position " << pipePos;
    else
        out << "No I";

    out << ", ";

    // Input <
    if (inPos != -1)
        out << "< found in position " << inPos;
    else
        out << "No <";

    out << ", ";

    // Output >
    if (outPos != -1)
        out << "> found in position " << outPos;
    else
        out << "No >";

    out << endl;
}

int main() {

    ifstream inFile("commands.txt");
    ofstream outFile("parsingreslts.txt");

    if (!inFile) {
        cout << "Error opening commands.txt\n";
        return 1;
    }

    string line;
    int commandIndex = 0;

    while (getline(inFile, line)) {

        if (line.empty())
            continue;

        vector<string> tokens = tokenize(line);

        parseCommand(tokens, outFile, commandIndex);

        commandIndex++;
    }

    inFile.close();
    outFile.close();

    return 0;
}
