#include <unistd.h>   // pipe, read, write
#include <sys/types.h>
#include <sys/wait.h> // wait
#include <fcntl.h>
#include <cstring>
#include <iostream>
#include <fstream>

/*
NOTES:

Parent sends passkey entered by the user to a child process (PIPE 1)
Child sends back the word FOUND or NOT FOUND if passkey found in the text file (PIPE 2)

fd1 - parent writes, child reads
    - PARENT
        - fd1[0] - read end (CLOSE)
        - fd1[1] - write end (KEEP)
    - CHILD
        - fd1[0] - read end (KEEP)
        - fd1[1] - write end (CLOSE)

fd2 - child writes, parent reads
    - PARENT
        - fd2[0] - read end (KEEP)
        - fd2[1] - write end (CLOSE)
    - CHILD
        - fd2[0] - read end (CLOSE)
        - fd2[1] - write end (KEEP)
*/

using namespace std;

int main() {
    int fd1[2];
    int fd2[2];

    if (pipe(fd1) == -1 || pipe(fd2) == -1) {
        cout << "Pipe failed" << endl;
        return 1;
    }

    int originalSTDIN = dup(0);
    int originalSTDOUT = dup(1);

    pid_t pid = fork();
    if (pid < 0) {
        cout << "Fork failed" << endl;
        return 1;
    }

    if (pid > 0) {
        // Parent process
        close(fd1[0]); // close read end
        close(fd2[1]); // close write end

        string passkey;
        cout << "Enter 20-character passkey: ";
        getline(cin, passkey);

        // send passkey to child
        //write(fd1[1], passkey.c_str(), passkey.size()+1);
        dup2(fd1[1], 1); // redirect stdout to pipe
        cout << passkey << endl; // write passkey to pipe


        // read result from child
        char result[10];
        //read(fd2[0], result, sizeof(result));
        // cout << result << endl;
        dup2(fd2[0], 0); // redirect stdin to pipe
        cin.getline(result, sizeof(result)); // read result from child

        close(fd1[1]);
        close(fd2[0]);

        // Restore original stdin and stdout
        dup2(originalSTDIN, 0);
        dup2(originalSTDOUT, 1);

        cout << result << endl;

        wait(NULL); // wait for child
    } else {
        // Child process
        close(fd1[1]); // close write end
        close(fd2[0]); // close read end

        char received[21];
        //read(fd1[0], received, sizeof(received));
        dup2(fd1[0], 0); // redirect stdin to pipe
        cin.getline(received, sizeof(received)); // read passkey from pipe

        // Check file
        ifstream fin("passkeys.txt");
        string line;
        string res = "NOT FOUND";
        while (getline(fin, line)) {
            if (line == received) {
                res = "FOUND";
                break;
            }
        }

        //write(fd2[1], res.c_str(), res.size()+1);
        dup2(fd2[1], 1); // redirect stdout to pipe
        cout << res << endl;

        close(fd1[0]);
        close(fd2[1]);
    }

    return 0;
}