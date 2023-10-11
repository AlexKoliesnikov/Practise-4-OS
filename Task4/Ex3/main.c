#include <stdio.h>
#include <stdlib.h>

int setEnvironmentVariable(const char *var_name, const char *var_value) {
    if (setenv(var_name, var_value, 1) != 0) {
        perror("Error setting the environment variable");
        return 1;
    }
    return 0;
}

int retrieveAndPrintEnvironmentVariable(const char *var_name) {
    char *env_value = getenv(var_name);

    if (env_value == NULL) {
        printf("Failed to retrieve the environment variable %s.\n", var_name);
        return 1;
    } else {
        printf("Environment Variable: %s\nValue: %s\n", var_name, env_value);
    }
    return 0;
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <variable> <value>\n", argv[0]);
        return 1;
    }

    const char *var_name = argv[1];
    const char *var_value = argv[2];

    if (setEnvironmentVariable(var_name, var_value) != 0) {
        return 1;
    }

    if (retrieveAndPrintEnvironmentVariable(var_name) != 0) {
        return 1;
    }

    return 0;
}
