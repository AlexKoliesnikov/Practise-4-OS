#include <stdio.h>
#include <unistd.h>
#include <sys/utsname.h>

void printHostname() {
    char hostname[256];
    if (gethostname(hostname, sizeof(hostname)) == 0) {
        printf("Computer's hostname: %s\n", hostname);
    } else {
        perror("Error getting the hostname");
    }
}

void printComputerInfo() {
    struct utsname uname_data;
    if (uname(&uname_data) == 0) {
        printf("Operating System: %s\n", uname_data.sysname);
        printf("Node Name: %s\n", uname_data.nodename);
        printf("OS Release: %s\n", uname_data.release);
        printf("OS Version: %s\n", uname_data.version);
        printf("Architecture: %s\n", uname_data.machine);
    } else {
        perror("Error getting computer information");
    }
}

int main() {
    printHostname();
    printComputerInfo();
    return 0;
}
