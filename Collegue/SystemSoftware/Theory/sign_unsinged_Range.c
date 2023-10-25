#include <stdio.h>
#include <limits.h>
//case 1
// int main ()
// {
// 	unsigned i;
// 	for (i = 10; i >= 0; i--)
// 	printf ("%u\n", i);
// }

//case 2
// void main()
// {
// char i = -2;
// printf("%d\n", i);
// i = i >> -2;
// printf("%d\n", i);
// }

//case 3
// #include <stdio.h>
// int main () {
// 	int n = 123456789;
// 	int nf, ng;
// 	float f;
// 	double g;
// 	f = (float) n;
// 	g = (double) n;
// 	nf = (int) f;
// 	ng = (int) g;
// 	printf ("nf=%d ng=%d\n", nf, ng);
// }

//case 4
// #include <stdio.h>
// int main () {
// 		double d;
// 		// d = 1.0 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1
// 		// + 0.1 + 0.1 + 0.1 + 0.1 + 0.1;
//         d = 1.000 + 0.125 + 0.125 + 0.125 + 0.125 + 0.125 +
//                    0.125 + 0.125 + 0.125;

// 		if (d==2.00)
// 		printf("true 1\n");
// 		if (d==2)
// 		printf("true 2\n");
// 		if ((int)d==2)
// 		printf("true 3\n");
// 		printf ("d = %.20f\n", d);
// }

//case 5
// #include <stdio.h>
// int main () {
// 		float f1 = (3.14 + 1e20) - 1e20;
// 		float f2 = 3.14 + (1e20 - 1e20);
// 		printf ("f1 = %f, f2 = %f\n", f1, f2);
// }

//case 6
// #include <stdio.h>
// union {
// int i;
// unsigned char c[4];
// } u;
// int main () {
// u.i = 0x12345678;
// printf ("%x %x %x %x\n", u.c[0], u.c[1], u.c[2], u.c[3]);
// }

//case 7
// int main ()
// {
// 	unsigned i;
// 	for (i = 10; i > 0; i--)
// 	printf ("%u\n", i);
// }

//case 8
// #include <stdio.h>
// union {
// char i;
// unsigned char c[4];
// } u;

//case 9
// int main () {
// // u.i = 0x12345678;
// // u.i = "15213";
// char c[6]= "15213";
// // c = "15213";

// printf ("%x %x %x %x\n", c[0], c[1], c[2], c[3]);
// // printf ("%x %x %x %x\n", u.c[0], u.c[1], u.c[2], u.c[3]);
// }

//case 10
// void doit(int *xp, int *yp)
// {
// int t0 = *xp;
// *yp = t0;
// }

// ////////////////////////////////////////////////////////
// doit:
// pushl %ebp
// movl %esp,%ebp

// movl 8(%ebp),%eax
// movl 12(%ebp),%edx
// leal (%edx,%eax),%ecx
// sall $4,%ecx
// movl (%ecx),%eax

// movl %ebp,%esp
// popl %ebp
// ret
// What's wrong?


//case 11
// int main()
// {
//     char i = -27;
//     printf("%d\n", i);
//     i = i / 8;
//     printf("%d\n", i);
//     char i2 = -27;
//     i2 = i2 >> 3;
//     printf("%d\n", i2);
// }
// int main(){
// 	printf("asd");
// 	return 0;
// }