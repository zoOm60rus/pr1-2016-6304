#include<stdio.h>
#include<stdlib.h>
void vvod(int mat[][10], int rasm)
{
		int  i, k;
		for (i=0; i<rasm; i++){
			printf("Введите %d-ю строку: ", i+1);
			for(k=0; k<rasm; k++){
					scanf("%d", &mat[i][k]);
			}
		}
		printf("Введеная матрица:\n");
		for (i=0; i<rasm; i++){
			printf("|");
			for(k=0; k<rasm; k++){
					printf("%4d", mat[i][k]);
			}
			printf("|\n");
		}
}		

int opr(int mat[][10], int rasm)
{
	int i, k, opr;
	if(rasm==2){
		opr=(mat[0][0]*mat[1][1])-(mat[0][1]*mat[1][0]);
		return opr;
	}
}

int main()
{
		int mat[10][10], rasm, mat2[10][10], command;
		printf("1)Сложить две матрицы\n2)Вычесть из первой матрицы второю\n3)Посчитать определитель матрицы\nВведите необходимую команду: ");
		scanf("%d", &command);
		printf("Введите размерность матрицы: ");
		scanf("%d", &rasm);
		if (command==1 || command==2){
				printf("Ввод первой матрицы: \n");
				vvod(mat, rasm);
				printf("Ввод второй матрицы: \n");
				vvod(mat2, rasm);
		}
		else vvod(mat, rasm);
		command = opr(mat, rasm);
		printf("%d\n", command);
}
