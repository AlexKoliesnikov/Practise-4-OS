#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <environment_variable_name>\n", argv[0]);
        return 1;
    }

    const char *env_var_name = "PATH";
    char *env_var_value = getenv(env_var_name);

    if (env_var_value) {
        printf("Value of %s: %s\n", env_var_name, env_var_value);
    } else {
        printf("Environment variable '%s' is not set.\n", env_var_name);
    }

    return 0;
}
