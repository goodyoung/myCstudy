#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <ctype.h>
#include <signal.h>
#include <unistd.h>

#define PID_LIST_SIZE 500
#define TXT_PATH "confession.txt"
#define PROC_PATH "/proc"

int prev_file_size = 0;


int is_all_digits(const char *str) {
    while (*str) {
        if (!isdigit(*str))
            return 0;
        str++;
    }
    return 1;
}

int check_file_size(){
    int cur_file_size;
    FILE * fp;
    fp = fopen(TXT_PATH,"r");
    if (fp==NULL) // 파일이 없다면 0리턴
        return 0;
    fseek(fp,0,SEEK_END);
    cur_file_size = ftell(fp);
    fclose(fp);
    if (cur_file_size > prev_file_size){ // 파일 사이즈 커짐 -> 시그널을 받았다
        printf("5\n");
        cur_file_size = prev_file_size;
        return 1;
    }else{
        return 0;
    }
}

int find_mafia(int mafia[]){
    FILE *file; // 파일 객체
    char line[256]; // 읽어올 줄을 저장할 버퍼
    char last_line[256]; // 마지막으로 읽은 줄을 저장할 버퍼
    // confession 파일 열기
    file = fopen(TXT_PATH, "r");
    if (file == NULL) {
        return -1;
    }

    // confession 파일에서 마피아 찾기
    int idx = 0;
    int size = 0;
    while (fgets(line, sizeof(line), file) != NULL) {
        if (strcmp(line, "...") != 0){
            mafia[size] = idx;
            size +=1;
        }
        idx +=1;
    }
    // 파일 닫기
    fclose(file);
    if (strcmp(last_line, "...") != 0){ // "..."랑 같지 않으면 마피아로 판단
        return 1; // 마피아 프로세스
    } else{
       return 0; // 일반 시민 프로세스
    }
}

void sort_PID(char **PID, int num_elements) {
    for (int i = 0; i < num_elements - 1; i++) {
        for (int j = 0; j < num_elements - i - 1; j++) {
            // 두 PID를 숫자로 변환하여 비교하여 정렬
            int pid1 = atoi(PID[j]);
            int pid2 = atoi(PID[j + 1]);
            if (pid1 < pid2) { // 부등호 방향을 반대로 변경하여 내림차순으로 정렬
                // PID 교환
                char *temp = PID[j];
                PID[j] = PID[j + 1];
                PID[j + 1] = temp;
            }
        }
    }
}
// Signal handler 함수 정의
void sigusr1_handler(int signum) {
    printf("Received SIGUSR1 signal\n");
    // 실제로 필요한 작업을 여기에 추가하세요
}

int main(void){
    // Signal handler를 등록
    if (signal(SIGUSR1, sigusr1_handler) == SIG_ERR) {
        perror("Failed to register SIGUSR1 handler");
        return 1;
    }

    struct dirent *entry; // 디렉토리 내의 파일 목록을 읽기 위함
    char procPath[200];
    char PID[PID_LIST_SIZE];
    int num_elements = 0;
    char* Mafia_List[200];
    int mafia = 0;
    int citizen = 0;
    pid_t pid;

    // "/proc" 디렉토리 열기
	DIR *dir = opendir(PROC_PATH); // 경로 수정 필요

	//////////// "/proc" 디렉토리 안에 숫자 폴더만 가져오기 ////////////
    // while ((entry = readdir(dir)) != NULL) {
    //     if (entry->d_type == DT_DIR) { // 디렉토리인 경우(4)
    //         char *dirName = entry->d_name; // 해당 디렉토리 이름 저장
    //         if (is_all_digits(dirName)) { // 디렉토리가 숫자 형식이면 저장 -> PID 리스트에 저장
    //             // printf("/%s\n", entry->d_name);
    //             PID[num_elements] = dirName; // PID 리스트 저장
    //             num_elements +=1; // index + 1
    //         }
    //     }
    // }
    // sort_PID(PID, num_elements); // 내림차순 정렬

    char command[] = "ps -ef | grep ./linuxtown_class2 | grep -v grep | awk '{print $2}'";
    char buffer[300]; // 명령어 실행 결과를 저장할 버퍼
    int count = 0; // 배열에 저장된 PID의 개수

    FILE *fp = popen(command, "r"); // 쉘 명령어 실행 후 파일 포인터를 얻음
    if (fp == NULL) {
        printf("Failed to execute command\n");
        return 1;
    }

    // 명령어 실행 결과를 읽어와서 배열에 저장
    while (fgets(buffer, sizeof(buffer), fp) != NULL) {
        PID[count++] = atoi(buffer); // 문자열을 정수로 변환하여 배열에 저장
    }

    // 파일 포인터를 닫음
    pclose(fp);

    printf("PID:\n");
    for (int i = 0; i < num_elements; i++) {
        printf("%s", PID[i]);
    }
    printf("\n");
    

    //////////// KILL Signal 보내기 ////////////
    // PID[num_elements] = "37074"; // test
    int result=0;
    int size=0;
    char command[50];

    for(int i = 0; i < num_elements+1; i++){
        if (PID[i] != NULL && (result <= 200)){
            printf("START: %s %d %d\n", PID[i],citizen,mafia);
            pid = PID[i];
            kill(pid, SIGUSR1); // == 0
            // sprintf(command, "kill -10 %s", PID[i]); // system 함수(root권한)를 사용하여 kill 명령어를 실행하여 SIGUSR1 시그널을 해당 PID를 가진 프로세스에 보냄 (SIGUSR1 -> 10)
            // int status = system(command); // command 보내기
            // usleep(50000); // 0.3초 delay (파일 읽는 시간 걸릴 수 있으니 걸어둠)
            // if (check_file_size()) { // 시그널을 받으면
            //     if (find_mafia()){ // 마피아이면
            //         Mafia_List[mafia] = PID[i]; // 마피아 pid 저장
            //         mafia +=1; // 마피아 count
            //     }else{ // 시민이면
            //         citizen +=1; // 시민 count
            //     }
            //     result += 1;
            // } else {
            //     continue;
            // }
        } else{
            break;
        }
    }

    ////////// 출력 //////////
    printf("mafia = %d\n", mafia);
    printf("citizen = %d\n", citizen);
    printf("=== mafia list ===\n");
    for(int i = 0; i<size; i++)
        printf("%s\n",Mafia_List[i]);

	return 0;
}