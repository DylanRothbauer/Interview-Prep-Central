/*
    * Author: Dylan Rothbauer
    * Date: 2026-04-15
    * Description: A simple shell implementation in C++ that supports command execution, history, redirection, and piping.
    * 
    * Noteworthiness (Extra Credit):
    * 
    * (1) Implemented multi-command redirection (e.g., "cmd1 > out.txt < in.txt")
    * - Added error handling for missing filenames in redirection
    * 
    * (2) Implemented multi-stage piping (e.g., "cmd1 | cmd2 | cmd3")
    * 
    * (3) Added script file to show usage of redirection and piping features
    * 
    * (4) Added version control (GitHub repository) to track development and changes using git & the git CMD line tool
    * 
    * (5) Added various history management features - like clearHistory
    * 
    * Resources Used:
    * > StackOverflow
    * - Clear data from file - https://stackoverflow.com/questions/17032970/clear-data-inside-text-file-in-c
    * - Errors for child processes - https://stackoverflow.com/questions/65136753/how-to-catch-a-child-process-as-soon-as-it-ends
    * 
    * > Google
    * - Asked how to wait for multiple child processes (pids) - results led to using waitpid in a loop
*/

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <unistd.h>
#include <sys/wait.h> 
#include <fcntl.h>
#include <array>

using namespace std;

// Global variables
const string HISTORY_FILE = "history.txt";
vector<string> history;

string pwd() {
    char buffer[1024];
    getcwd(buffer, sizeof(buffer));
    return string(buffer);
}

void loadHistory() {
    ifstream inFile(HISTORY_FILE);
    if (!inFile.is_open()) {
        return;
    }

    string line;
    while (getline(inFile, line)) {
        if (!line.empty()) {
            history.push_back(line);
        }
    }
    inFile.close();
}

void printHistory() {
    if (history.empty()) {
        cout << "No commands in history.\n";
        return;
    }
    for (size_t i = 0; i < history.size(); i++) {
        cout << "  " << (i + 1) << "  " << history[i] << "\n";
    }
}

void addToHistory(const string& cmd) {
    if (cmd.empty()) return;

    history.push_back(cmd);
}

// Clear history file on exit (saves history only for current session)
void clearHistory() {
    history.clear();
    ofstream outFile(HISTORY_FILE, ios::trunc);
    outFile.close();
}

vector<string> tokenize(const string& input) {
    vector<string> tokens;
    istringstream stream(input);
    string token;
    while (stream >> token) {
        tokens.push_back(token);
    }
    return tokens;
}

void runCommand(const vector<string>& tokens) {
    if (tokens.empty()) return;

    // Null-terminated array of C-strings.
    vector<char*> argv;

    for (const string& tok : tokens) {
        argv.push_back(const_cast<char*>(tok.c_str()));
    }
    argv.push_back(nullptr);

    pid_t pid = fork();

    if (pid < 0) { // Fork failed
        perror("fork");

    } else if (pid == 0) { // Child process
        execvp(argv[0], argv.data());
        perror(argv[0]);
        exit(1);

    } else { // Parent process
        wait(nullptr);
    }
}

bool hasRedirection(const vector<string>& tokens) {
    for (const string& tok : tokens) {
        if (tok == ">" || tok == "<") {
            return true;
        }
    }
    return false;
}

bool hasPipe(const string& input) {
    return input.find('|') != string::npos;
}

void runWithRedirection(const vector<string>& tokens) {
    int  inOpIndex  = -1;   // index of "<"
    int  outOpIndex = -1;   // index of ">"

    for (int i = 0; i < (int)tokens.size(); i++) {
        if (tokens[i] == "<") {
            inOpIndex  = i;
        } 
        if (tokens[i] == ">") {
            outOpIndex = i;
        }
    }

    // cmdTokens — everything that isn't an operator or filename
    vector<string> cmdTokens;
    for (int i = 0; i < (int)tokens.size(); i++) {
        if (tokens[i] == "<" || tokens[i] == ">") {
            i++;  // skip the filename token
            continue;
        }
        cmdTokens.push_back(tokens[i]);
    }

    if (cmdTokens.empty()) {
        cerr << "Error: no command found.\n";
        return;
    }

    // Quick validation
    if (inOpIndex  != -1 && inOpIndex  + 1 >= (int)tokens.size()) {
        cout << "Error: missing filename after '<'\n";
        return;
    }
    if (outOpIndex != -1 && outOpIndex + 1 >= (int)tokens.size()) {
        cout << "Error: missing filename after '>'\n"; 
        return;
    }

    string inFile, outFile;

    if (inOpIndex != -1) {
        inFile = tokens[inOpIndex + 1];
    } else {
        inFile = "";
    }
    
    if (outOpIndex != -1) {
        outFile = tokens[outOpIndex + 1];
    } else {
        outFile = "";
    }

    vector<char*> argv;
    for (const string& tok : cmdTokens) {
        argv.push_back(const_cast<char*>(tok.c_str()));
    }
    argv.push_back(nullptr);

    int origSTDIN  = dup(0);
    int origSTDOUT = dup(1);

    pid_t pid = fork();
    if (pid < 0) {
        perror("fork");
    } else if (pid == 0) { // Child process
        if (!inFile.empty()) {
            int inFd = open(inFile.c_str(), O_RDONLY);
            if (inFd < 0) { perror(inFile.c_str()); exit(1); }
            dup2(inFd, STDIN_FILENO);
            close(inFd);
        }
        if (!outFile.empty()) {
            int outFd = open(outFile.c_str(), O_WRONLY | O_CREAT | O_TRUNC, 0666);
            if (outFd < 0) { perror(outFile.c_str()); exit(1); }
            dup2(outFd, STDOUT_FILENO);
            close(outFd);
        }
        execvp(argv[0], argv.data());
        perror(argv[0]);
        exit(1);
    } else {
        wait(nullptr);
        fflush(stdout);
        dup2(origSTDIN,  0);
        dup2(origSTDOUT, 1);
        close(origSTDIN);
        close(origSTDOUT);
        fflush(stdout);
    }
}

void runWithPipe(const string& input) {
    vector<string> commands;
    stringstream ss(input);
    string temp;
    while (getline(ss, temp, '|')) {
        if (!temp.empty()) {
            commands.push_back(temp);
        }
    }

    if (commands.size() < 2) {
        cerr << "Error: need at least two commands for a pipe.\n";
        return;
    }

    int numCmds  = commands.size();
    int numPipes = numCmds - 1;

    // pipes[i][0] = read end of pipe i
    // pipes[i][1] = write end of pipe i
    vector<array<int, 2>> pipes(numPipes);
    for (int i = 0; i < numPipes; i++) {
        if (pipe(pipes[i].data()) < 0) {
            perror("pipe");
            return;
        }
    }

    vector<pid_t> pids;

    for (int i = 0; i < numCmds; i++) {
        vector<string> tokens = tokenize(commands[i]);
        if (tokens.empty()) continue;

        vector<char*> argv;
        for (const string& tok : tokens) {
            argv.push_back(const_cast<char*>(tok.c_str()));
        }
        argv.push_back(nullptr);

        pid_t pid = fork();
        if (pid < 0) {
            perror("fork");
            return;
        }

        if (pid == 0) { // Child i process

            // If not the first command, read from previous pipe
            if (i > 0) {
                dup2(pipes[i - 1][0], STDIN_FILENO);
            }
            // If not the last command, write to current pipe
            if (i < numPipes) {
                dup2(pipes[i][1], STDOUT_FILENO);
            }

            for (int j = 0; j < numPipes; j++) {
                close(pipes[j][0]);
                close(pipes[j][1]);
            }

            execvp(argv[0], argv.data());
            perror(argv[0]);
            exit(1);
        }

        pids.push_back(pid);
    }

    // Parent closes ALL pipe ends
    for (int i = 0; i < numPipes; i++) {
        close(pipes[i][0]);
        close(pipes[i][1]);
    }

    // Wait for ALL children
    for (pid_t pid : pids) {
        waitpid(pid, nullptr, 0);
    }
}

int main() {
    loadHistory();

    while(true) {
        cout << pwd() << " :~$ ";
        cout.flush();

        string command;
        getline(cin, command);

        if (command == "exit") {
            break;
        } else if (command == "pwd") {
            cout << pwd() << endl;
        } else if (command == "history") {
            printHistory();
        } else if (command == "clearhistory") {
            clearHistory();
            cout << "Command history cleared.\n";
        } else if (hasPipe(command)) {
            //size_t pipePos = command.find('|');
            //string leftCmd = command.substr(0, pipePos);
            //string rightCmd = command.substr(pipePos + 1);
            //runWithPipe(leftCmd, rightCmd);
            runWithPipe(command);
        } else {
            vector<string> tokens = tokenize(command);
            if (!tokens.empty()) {
                if (hasRedirection(tokens)) {
                    runWithRedirection(tokens);
                } else {
                    runCommand(tokens);
                }
            }
        }

        addToHistory(command);
    }

    return 0;
}
