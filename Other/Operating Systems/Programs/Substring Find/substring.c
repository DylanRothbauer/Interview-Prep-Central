#include <stdio.h>
#include <string.h>

void isSubstring(const char *str1, const char *str2) {
    if (strstr(str1, str2) != NULL) {
        printf("FOUND\n");
    } else {
        printf("NOT FOUND\n");
    }
}

int main() {
    isSubstring("We like UW-Stout", "UW-Stout");
    isSubstring("We like UW-Stout", "UW-Madison");
    isSubstring("myEXEprogram >txt", ">");

    return 0;
}
