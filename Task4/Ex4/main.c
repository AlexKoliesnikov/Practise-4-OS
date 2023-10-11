#include <stdio.h>
#include <stdlib.h>

int clearEnvironment() {
    if (clearenv() == 0) {
        printf("All environment variables have been removed.\n");
        return 0;
    } else {
        perror("Error clearing the environment");
        return -1;
    }
}

int removeEnvironmentVariable(char *variableName) {
    if (unsetenv(variableName) == 0) {
        printf("Variable %s has been removed.\n", variableName);
        return 0;
    } else {
        perror("Error removing environment variable");
        return -1;
    }
}

void printEnvironment() {
    extern char **environ;
    if (environ == NULL) {
        printf("Environment is empty.\n");
    } else {
        char **env_var = environ;
        while (*env_var) {
            printf("%s\n", *env_var);
            env_var++;
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc == 1) {
        clearEnvironment();
    } else if (argc == 2) {
        removeEnvironmentVariable(argv[1]);
    } else {
        printf("Incorrect usage of the program. Usage: %s [VARIABLE_NAME]\n", argv[0]);
        return -1;
    }

    printEnvironment();
    return 0;
}
