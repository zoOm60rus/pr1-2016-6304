#include <string.h>
#include <stdio.h> 
#define MAX 100
int main(int argc, char* argv[])
{
    char  s[MAX];
    char  substr[MAX];
    int   n = 0;   // ���-�� ���������
    char* temp;
    gets(s);
    gets(substr);
    temp = s;
    while (temp = strstr(temp, substr) )  // ����� ������ ���������� � temp
    {
        n++;
        temp++;   // ������� �� ��������� ������ ��� ���������
    }
    printf("N = %d", n);
    getchar();
    return 0;
}
