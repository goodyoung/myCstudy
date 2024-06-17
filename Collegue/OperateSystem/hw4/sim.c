#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#include "fifo.c" // fifo 알고리즘 
#include "nru.c" // nru 알고리즘 

int main(int argc, char *argv[]) {
    const char* param1 = argv[1]; // 알고리즘 종류 (nru, fifo 중)
    int param2 = atoi(argv[2]); // physical frame number

    // 변수 선언 및 초기화
    int pid, READ=0, WRITE=0, HIT=0, FAULT=0, TOTAL_ACCESS=0;
    char mode[8]; // file에서 read | write 를 받기 위함

    if (strcmp(param1, "fifo")==0){ // FIFO 일 때
        FIFO* fifo = (FIFO*)malloc(sizeof(FIFO)); // fifo 구조체 메모리 할당
        initFIFO(fifo, param2); // pysical frame 초기화
        
        FILE* file = fopen("access.list", "r"); // access 파일 읽기
        if (file == NULL) { perror("파일 열기 실패"); return 1; } // 파일 열기 실패일 때

        while (fscanf(file, "%d %s", &pid, mode) == 2) {
                TOTAL_ACCESS += 1;
                if (strcmp(mode, "read") == 0) // read인 경우
                    READ += 1;
                else
                    WRITE += 1;
                // pysical frame에 특정 pid가 있는지 확인
                if (FIFO_CheckTable(fifo, pid)){
                    // pysical frame에 특정 pid가 있다면 HIT
                    HIT += 1;
                }else{
                    // pysical frame에 특정 pid가 없다면 FAULT
                    FIFO_Append(fifo,pid); // fifo에 pid를 추가
                    FAULT += 1;
                }
            }    
        freeFIFO(fifo); // fifo 메모리 해제
        // 파일 닫기
        fclose(file);
    }
    else if (strcmp(param1, "nru") == 0){// NRU 일 때
        NRU *nru = (NRU*)malloc(sizeof(NRU)); // NRU 구조체 메모리 할당        
        initNRU(nru, param2); // pysical frame 초기화
        
        FILE* file2 = fopen("access.list", "r"); // access 파일 열기
        if (file2 == NULL) { perror("파일 열기 실패"); return 1; } // 파일 열기 실패일 때

        while (fscanf(file2, "%d %s", &pid, mode) == 2) {
            TOTAL_ACCESS += 1;
            if (strcmp(mode, "read") == 0) // read인 경우
                READ += 1;
            else
                WRITE += 1;
            // pysical frame pid가 있는지 확인
            if (NRU_checkTable(nru, pid, mode)){ 
                // pysical frame에 특정 pid가 있다면 HIT
                HIT += 1;
                // continue;
            }else{
                // pysical frame에 특정 pid가 없다면 FAULT
                NRU_Append(nru,pid, mode); // nru에 pid를 추가
                FAULT += 1;
            }
        }
        freeNRU(nru);
        // 파일 닫기
        fclose(file2);
    }

    // 전체 결과값 출력
    float page_fault_rate = (float)FAULT / TOTAL_ACCESS * 100;
    printf("Total number of access: %d\n", TOTAL_ACCESS);
    printf("Total number of read: %d\n", READ);
    printf("Total number of write: %d\n", WRITE);
    printf("Number of page hits: %d\n", HIT);
    printf("Number of page faults: %d\n", FAULT);
    printf("Page fault rate: %d/%d = %.2f%%\n", FAULT, TOTAL_ACCESS, page_fault_rate);

    return 0;
    }