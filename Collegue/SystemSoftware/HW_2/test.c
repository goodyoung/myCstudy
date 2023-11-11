#include <stdio.h>
#include <stdlib.h>

// int func2(int a, int b)
// {
// 	__asm__ __volatile__
//   	(
// 		"movl 16(%ebp),%edx \n\t"
// 		"movl 24(%ebp),%eax \n\t"
// 		"cmpl %eax,%edx \n\t" // edx가 eax보다 작거나 같으면
// 		"jle L0 \n\t" // eax >= edx
// 		"movl $1,%eax \n\t" // eax = 1 -> return 1
// 		"jmp L1 \n\t"
// 	"L0: \n\t"
// 		"movl $0,%eax \n\t" // eax = 0 -> return 0
// 	"L1: \n\t" 
// 	);
// }

// void func1(int *a, int *b)
// {
// 	__asm__ __volatile__
//   	(
// 		"movl 24(%ebp),%ecx \n\t" // ecx = a
// 		"movl 16(%ebp),%edx \n\t" // edx = b
// 		"movl (%ecx),%eax \n\t"  // eax = a
// 		"movl (%edx),%ebx \n\t" // ebx = b
// 		"movl %eax,(%edx) \n\t" // edx = a
// 		"movl %ebx,(%ecx) \n\t" // ecx = b // swap
// 	);
// }


void func1(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int func2(int a, int b) {
    return (b <= a) ? 0 : 1;
}
void select_sort(int* arr,int size){
    int idx, flag;
    for(int i = 0; i<(size-1) ; i++){
        flag = arr[i];
        idx = i;
        for (int j = i+1; j<size; j++){
            if (func2(arr[j],flag)){
                flag = arr[j];
                idx = j;
            }
        }
        if (flag != arr[i]){
            func1(&arr[idx],&arr[i]);
        }
    }
}

int main(int argc, char *argv[]) {
	 
	int arr[] = { 1, 9, 5, 6, 3, 2, 9, 4, 1, 3 };

	// Sort arr
	// YOU MUST USE func1, func2 

	// Output MUST be
	// 1 1 2 3 3 4 5 6 9 9
	
	// Fill your own codes from here
	select_sort(arr,10);


    int size = 10;

	for(int i = 0; i<size; i++)
		printf("%d ",arr[i]);

	
	return 0;
}
