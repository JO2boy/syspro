#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void print_all_environment_variables() {
    extern char **environ;
    for (char **env = environ; *env != NULL; env++) {
        printf("%s\n", *env);
    }
}

void print_user_info() {
    uid_t real_uid = getuid();
    uid_t effective_uid = geteuid();
    printf("My Realistic User ID: %d\n", real_uid);
    printf("My Valid User ID: %d\n", effective_uid);
}

void print_group_info() {
    gid_t real_gid = getgid();
    gid_t effective_gid = getegid();
    printf("My Realistic Group ID: %d\n", real_gid);
    printf("My Valid Group ID: %d\n", effective_gid);
}

void print_process_id() {
    pid_t pid = getpid();
    printf("My Process ID: %d\n", pid);
}

void print_parent_process_id() {
    pid_t ppid = getppid();
    printf("My Parent Process ID: %d\n", ppid);
}

int main(int argc, char *argv[]) {
    int opt;

    // 여러 옵션을 처리하는 while 문
    while ((opt = getopt(argc, argv, "e:ugip")) != -1) { // -e는 인자 필요
        switch (opt) {
            case 'e': {
                // -e 옵션 처리: 환경 변수 출력
                if (optarg == NULL) {
                    // 인자가 없으면 전체 환경 변수 출력
                    print_all_environment_variables();
                } else {
                    // 환경 변수 이름이 지정되었으면 해당 값 출력
                    const char *env_value = getenv(optarg);
                    if (env_value) {
                        printf("%s=%s\n", optarg, env_value);
                    } else {
                        printf("Environment variable %s not found.\n", optarg);
                    }
                }
                break;
            }
            case 'u':
                // -u 옵션 처리: 사용자 정보 출력
                print_user_info();
                break;
            case 'g':
                // -g 옵션 처리: 그룹 정보 출력
                print_group_info();
                break;
            case 'i':
                // -i 옵션 처리: 프로세스 ID 출력
                print_process_id();
                break;
            case 'p':
                // -p 옵션 처리: 부모 프로세스 ID 출력
                print_parent_process_id();
                break;
            default:
                // 잘못된 옵션 처리
                fprintf(stderr, "Usage: %s [-e <env_var>] [-u] [-g] [-i] [-p]\n", argv[0]);
                exit(1);
        }
    }

    return 0;
}

