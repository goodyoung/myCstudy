#include <stdio.h>

int main_ss(void)
{
	char name[256];
	printf("이름\n");
	scanf("%s", name, sizeof(name));
	int age;
	printf("나이?\n");
	scanf("%d", &age);
	float weight;
	printf("몸무게는?\n");
	scanf("%f", &weight);
	/*float height;
	printf("키는?\n");
	scanf("%f", &height);*/
	double height;
	printf("키는 몇 cm 이에요?");
	scanf("%lf", &height);
	char crime[256];
	printf("범죄는?\n");
	scanf("%s", crime, sizeof(crime));
	// 조서 내용 출력
	printf("\n\n--- 범죄자 정보 ---\n\n");
	printf("이름? %s\n나이? %d\n몸무게? %.1lf\n키? %.1f\n범죄? %s\n",name,age,weight,height,crime);
}