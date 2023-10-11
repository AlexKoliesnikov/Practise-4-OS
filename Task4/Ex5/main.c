#include <stdio.h>
#include <pwd.h>
#include <unistd.h>

void getUserInfoByUID() {
    struct passwd *user_by_uid;
    uid_t uid = getuid();
    user_by_uid = getpwuid(uid);

    if (user_by_uid != NULL) {
        printf("Username by UID %d: %s\n", uid, user_by_uid->pw_name);
    } else {
        perror("Error getting information by UID");
    }
}

void getUserInfoByUsername() {
    struct passwd *root_user;
    char *root_username = "root";
    root_user = getpwnam(root_username);

    if (root_user != NULL) {
        printf("Username by username '%s': %s\n", root_username, root_user->pw_name);
    } else {
        perror("Error getting information by username");
    }
}

int main() {
    getUserInfoByUID();
    getUserInfoByUsername();

    return 0;
}
