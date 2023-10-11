#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern char **environ;

void print_environment() {
    char **env = environ;
    if (env == NULL || *env == NULL) {
        printf("Environment is empty.\n");
    } else {
        while (*env) {
            printf("%s\n", *env);
            env++;
        }
    }
}

void print_help() {
    printf("Help:\n");
    printf("-h, --help\t\tShow this help message\n");
    printf("-i, --info <variable>\tDisplay the value of an environment variable\n");
    printf("-s, --set <variable=value>\tSet the value of an environment variable\n");
    printf("-a -v <variable> [value]\tAssign a new value to an environment variable\n");
    printf("-d, --del <variable>\tDelete an environment variable\n");
    printf("-c, --clear\t\tClear the entire environment\n");
}

void print_variable(const char *variable_name) {
    char *value = getenv(variable_name);
    if (value != NULL) {
        printf("%s=%s\n", variable_name, value);
    } else {
        printf("Variable %s is not present in the environment.\n", variable_name);
    }
}

void set_variable(const char *variable_name, const char *value) {
    setenv(variable_name, value, 1);
    printf("%s=%s\n", variable_name, value);
}

void assign_variable(const char *variable_name, const char *value) {
    if (value != NULL) {
        setenv(variable_name, value, 1);
        printf("%s=%s\n", variable_name, value);
    } else {
        unsetenv(variable_name);
        printf("Variable %s has been removed from the environment.\n", variable_name);
    }
}

void delete_variable(const char *variable_name) {
    unsetenv(variable_name);
    printf("Variable %s has been removed from the environment.\n", variable_name);
}

void clear_environment() {
    clearenv();
    printf("\nEnvironment has been cleaned!\n");
}

int main(int argc, char *argv[]) {
    if (argc == 1) {
        print_environment();
    } else {
        if (strcmp(argv[1], "-h") == 0 || strcmp(argv[1], "--help") == 0) {
            print_help();
        } else if (strcmp(argv[1], "-i") == 0 || strcmp(argv[1], "--info") == 0) {
            if (argc == 3) {
                print_variable(argv[2]);
            } else {
                printf("Error: Specify a variable for the -i/--info option\n");
            }
        } else if (strcmp(argv[1], "-s") == 0 || strcmp(argv[1], "--set") == 0) {
            if (argc == 4) {
                set_variable(argv[2], argv[3]);
                print_environment();
            } else {
                printf("Error: Specify a variable and value for the -s/--set option\n");
            }
        } else if (strcmp(argv[1], "-a") == 0 && strcmp(argv[3], "-v") == 0) {
            if (argc == 4) {
                assign_variable(argv[2], NULL);
                print_environment();
            } else if (argc == 5) {
                assign_variable(argv[2], argv[4]);
                print_environment();
            } else {
                printf("Error: Specify a variable and, if needed, a value for the -a -v option\n");
            }
        } else if (strcmp(argv[1], "-d") == 0 || strcmp(argv[1], "--del") == 0) {
            if (argc == 3) {
                delete_variable(argv[2]);
                print_environment();
            } else {
                printf("Error: Specify a variable for the -d/--del option\n");
            }
        } else if (strcmp(argv[1], "-c") == 0 || strcmp(argv[1], "--clear") == 0) {
            clear_environment();
            print_environment();
        } else {
            printf("Error: Unknown option. Use -h or --help for help.\n");
        }
    }
    return 0;
}
