#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <unistd.h>     // fork, execvp
#include <sys/types.h>
#include <sys/wait.h>   // wait
#include <fcntl.h>      // open

/*
NOTES:

0 - stdin
1 - stdout
2 - stderr

To redirect output to a file:
1. Open the file with open() to get a file descriptor (e.g., outFd).
2. Use dup2(outFd, 1) to redirect stdout to the file.
3. Close the original file descriptor (outFd) after dup2.

*/

using namespace std;

vector<string> tokenize(const string& line) {
    vector<string> tokens;
    stringstream ss(line);
    string temp;

    while (ss >> temp)
        tokens.push_back(temp);

    return tokens;
}

int main()
{
    string input;

    cout << "Enter a command: ";
    getline(cin, input);
    vector<string> tokens = tokenize(input);
    vector<char*> args;

    for (auto& token : tokens) {
        args.push_back((char*)token.c_str());
    }
    args.push_back(nullptr);

    if (args.empty()) {
        cout << "No command entered." << endl;
        return 1;
    }

    pid_t pid = fork();
    if (pid < 0) {
        cerr << "Fork failed" << endl;
        return 1;
    }

    if (pid == 0) {
        // Child process

        // Open outputredir.txt for writing
        int outFd = open("outputredir.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
        if (outFd < 0) {
            cout << "Failed to open outputredir.txt" << endl;
            return 1;
        }
        dup2(outFd, 1); // All outputs will be sent to outputredir.txt
        close(outFd);
        execvp(args[0], args.data());
        cout << "Execution failed" << endl; // Will only reach here if execvp fails
        return 1;
    } else {
        // Parent process
        wait(nullptr); // Wait for child to finish
        cout << "Command executed. Check outputredir.txt\n";
    }



    return 0;
}