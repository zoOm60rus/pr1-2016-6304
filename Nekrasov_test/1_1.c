#include <stdio.h>
#include <stdlib.h>
 
int main(void) {
 
    float m, rez = 1;
    int n;
 
    printf("������� ��������� ������� M: ");
    scanf("%f", &m);
    if (m >= 10 || m <= -10) {
        printf("��������� ������� �� ����������� ��������� (-10, 10).\n");
        return EXIT_SUCCESS;
    }
 
    printf("������� ���������� ������� N: ");
    scanf("%d", &n);
    if (n >= 10 || n <= 0) {
        printf("���������� ������� �� ����������� ��������� (0, 10).\n");
        return EXIT_SUCCESS;
    }
 
    for( ; n > 0; --n) {
        rez *= m;
    }
 
    printf("M ^ N = %g\n", rez);
 
    return EXIT_SUCCESS;
}