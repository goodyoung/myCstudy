#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#include "fifo.c" // nru 알고리즘 
// #include "nru.c" // nru 알고리즘 

int main(int argc, char *argv[]) {
    
    const char* param1 = argv[1]; // 알고리즘 종류
    int param2 = atoi(argv[2]); // physical frame number

    // 파일 열기
    FILE* file = fopen("access.list", "r");
    if (file == NULL) { perror("Failed to open file"); return 1; }

    // 변수 선언
    int pid, READ=0, WRITE=0, HIT=0, FAULT=0, TOTAL_ACCESS=0;
    char mode[6]; // "read\0" 또는 "write\0"를 담기 위한 배열
    

    // 알고리즘에 따라 데이터 구조가 변경
    //////// 없애고 인자값 받게 변경해야 한다 ////////
    char* param3 = "fifo";
    param2 = 100;
    if (strcmp(param3, "fifo")==0){ // FIFO
        FIFO q;
        initFIFO(&q, param2); // page table 초기화
        // 파일 읽기
        while (fscanf(file, "%d %s", &pid, mode) == 2) {
                TOTAL_ACCESS += 1;
                if (strcmp(mode, "read") == 0) // read인 경우
                    READ += 1;
                else
                    WRITE += 1;
                // page table에 pid가 있는지 확인
                if (FIFO_CheckTable(&q, pid)){
                    // 테이블에 특정 pid가 있다면 HIT
                    HIT += 1;
                    // continue;
                }else{
                    // FAULT 일 경우 -> FIFO algorithm
                    FIFO_Append(&q,pid);
                    FAULT += 1;
                }

            }
            // else{ // NRU
            // }
            
        }

    float page_fault_rate = (float)FAULT / TOTAL_ACCESS * 100;
    printf("Total number of access: %d\n", TOTAL_ACCESS);
    printf("Total number of read: %d\n", READ);
    printf("Total number of write: %d\n", WRITE);
    printf("Number of page hits: %d\n", HIT);
    printf("Number of page faults: %d\n", FAULT);
    printf("Page fault rate: %d/%d = %.2f%%\n", FAULT, TOTAL_ACCESS, page_fault_rate);

    // 파일 닫기
    fclose(file);
    return 0;

    }