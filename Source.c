
#define _CRT_SECURE_NO_DEPRECATE

#include <stdio.h>
#include <conio.h>

#include <stdlib.h>
#define _USE_MATH_DEFINES

#include <math.h>
#include <locale.h>

#define arrh0 30
#define arrh 15
#define arrh1 30 
#define arrsh 6

int main() {
	FILE* pog;
	int sum = 0;
	int arraySUM[arrh0];
	int array[arrh1][arrsh];
	pog = fopen("gonki.txt", "r");
	if (pog == NULL) {
		printf("ERROR");
	}
	for (int i = 0;i < arrh1;i++) {
		fscanf(pog, "%d%d%d%d%d%d", &array[i][0], &array[i][1], &array[i][2], &array[i][3], &array[i][4], &array[i][5]);
	}
	

	int a;
	setlocale(LC_ALL, "RUS");

	int v = 1;
	while (v) {
		printf("¬ыберите нужный вариант:\n1) “аблица результатов соревнований по участникам\n2) ѕравила присваивани€ очков\n3) “аблица результатов соревнований по командам\n4) ¬ыход из программы\n ¬ы выбрали пункт: ");
		scanf_s("%d", &a);
		


		switch (a) {
		case 1:

			for (int i = 1; i < 7; i++) {
				printf("\t\tЁтап %d", i);
			}
			for (int i = 1; i <= arrh1; i++) {
				printf("\n\n");
				for (int j = 0; j < arrsh; j++) {
					if (j == 0) {
						if (array[i - 1][j] == 0) {
							printf("”частник %d", i);
						}
						else {
							printf("”частник %d \t %d", i, array[i - 1][j]);
						}
					}
					else {
						if (array[i - 1][j] == 0) {
							printf("\t");
						}
						else {
							printf("%27d", array[i - 1][j]);
						}
					}
				}
			}
			printf("\n\n");
			

			break;
		case 2:
			printf("ћеста пересчитываютс€ в очки по правилу: —хема проста€ : 1 - е место Ц 15 очков, 2 - е Ц 12, 3 - е Ц 10, 4 - е Ц 8, 5 - е Ц 6, 6 - е Ц 5, 7 - е Ц 4, 8 - е Ц 3, 9 - е Ц 2 и 10 - е Ц 1.");
			break;
		case 3:
			for (int i = 0; i < arrh1; i++) {
				for (int j = 0; j < arrsh; j++) {
					sum += array[i][j];
				}
				if (i % 2 != 0) {

					arraySUM[i-1] = sum;
					sum = 0;

				}
			}
			puts(" оманда     »тог");
			for (int i = 1,j = 0; i < 16;i++) {
				printf(" оманда %d     %d\n", i, arraySUM[j]);
				j = j + 2;

			}
			printf("\n");

			break;
		case 4:
			exit(EXIT_SUCCESS);
			break;
		}
	}
	fclose(pog);
}