#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <pwd.h>
#include <grp.h>

void print_environment_variable(const char *env_var) {
    char *value = getenv(env_var);
    if (value) {
        printf("%s=%s\n", env_var, value);
    } else {
        printf("Environment variable %s not found.\n", env_var);
    }
}

void print_all_environment_variables() {
    extern char **environ;
    for (char **env = environ; *env != NULL; ++env) {
        printf("%s\n", *env);
    }
}

void print_user_ids() {
    uid_t real_uid = getuid();
    uid_t effective_uid = geteuid();
    printf("my realistic user id : %d\nmy valid user id : %d\n", real_uid, effective_uid);
}

void print_group_ids() {
    gid_t real_gid = getgid();
    gid_t effective_gid = getegid();
    printf("my realistic group id : %d\nmy valid group id : %d\n", real_gid, effective_gid);
}

void print_process_id() {
    pid_t pid = getpid();
    printf("my process number: %d\n", pid);
}

void print_parent_process_id() {
    pid_t ppid = getppid();
    printf("my paret's process number : %d\n", ppid);
}

int main(int argc, char *argv[]) {
    if (argc == 1) {
        printf("Usage: %s [-e ENV_VAR | -u | -g | -i | -p]\n", argv[0]);
        return 1;
    }

    for (int i = 1; i < argc; i++) {
        if (argv[i][0] == '-' && argv[i][1] != '\0') {
            switch (argv[i][1]) {
                case 'e':
                    if (i + 1 < argc) {
                        print_environment_variable(argv[i + 1]);
                        i++; 
                    } else {
                        print_all_environment_variables();
                    }
                    break;
                case 'u':
                    print_user_ids();
                    break;
                case 'g':
                    print_group_ids();
                    break;
                case 'i':
                    print_process_id();
                    break;
                case 'p':
                    print_parent_process_id();
                    break;
                default:
                    printf("Unknown option: %s\n", argv[i]);
                    break;
            }
        } else {
            printf("Invalid argument: %s\n", argv[i]);
        }
    }

    return 0;
}

