#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

void alarmHandler(int signo) {
    printf("Wake up\n");
    exit(0);
}

int main() {
    struct sigaction sa;

    // sigaction 구조체 초기화
    sa.sa_handler = alarmHandler; // 핸들러 설정
    sigemptyset(&sa.sa_mask);     // 블록할 시그널 집합 초기화
    sa.sa_flags = 0;               // 추가 플래그 설정 (없음)

    // SIGALRM에 대해 sigaction 설정
    if (sigaction(SIGALRM, &sa, NULL) == -1) {
        perror("sigaction");
        exit(1);
    }

    alarm(5);  // 알람 시간 설정

    short i = 0;
    while (1) {
        sleep(1);
        i++;
        printf("%d second\n", i);
    }

    printf("end\n");
    return 0;
}

