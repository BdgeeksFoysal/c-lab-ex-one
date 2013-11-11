#include <stdlib.h>
#include <stdio.h>

#define MAX_DIM 5

void get_dimension_input(int *, int *);
int check_dimension_compatibility(int, int);
void get_matrix_data(int [][MAX_DIM], int, int);
void multiply_matrices(int [][MAX_DIM], int [][MAX_DIM], int [][MAX_DIM], int, int, int, int, int *, int *);
void print_matrix(int [][MAX_DIM], int, int);

int main(int argc, char const *argv[]){
	int r1, r2, c1, c2, r3, c3;
	int m1[MAX_DIM][MAX_DIM], m2[MAX_DIM][MAX_DIM], m3[MAX_DIM][MAX_DIM];

	do{
		printf("Matrix 1: \n");
		get_dimension_input(&r1, &c1);

		printf("Matrix 2: \n");
		get_dimension_input(&r2, &c2);
	}while(check_dimension_compatibility(r2, c1) == 0);

	printf("Insert values for Matrix 1:\n");
	get_matrix_data(m1, r1, c1);

	printf("Insert values for Matrix 2:\n");
	get_matrix_data(m2, r2, c2);

	multiply_matrices(m1, m2, m3, r1, c1, r2, c2, &r3, &c3);

	printf("Input Matrix 1:\n");
	print_matrix(m1, r1, c1);

	printf("Input Matrix 2:\n");
	print_matrix(m2, r2, c2);

	printf("Output Matrix:\n");
	print_matrix(m3, r3, c3);

	return 0;
}

//get the dimension of a matrix from user input
//pass the row and column var as pointers.
void get_dimension_input(int *row, int *column){
	do{
		printf("Insert the row numbers of the matrix\n");
		scanf("%d", row);

		printf("Insert the column numbers of the matrix\n");
		scanf("%d", column);
	}while(*row > MAX_DIM || *column > MAX_DIM || *row < 1 || *column < 1);
}

//check if the inserted dimensions are compatible for multiplication
int check_dimension_compatibility(int row2, int col1){
	if(row2 == col1){
		return 1;
	}else{
		printf("The matrices aren't compatible for multiplication.\n");
		return 0;
	}
}

//get user input to fill the matrix data
void get_matrix_data(int matrix[][MAX_DIM], int rows, int columns){
	int i, j;

	for (i = 0; i < rows; ++i){
		for (j = 0; j < columns; ++j){
			printf("value of row %d column %d\n", i, j);
			scanf("%d", &matrix[i][j]);
		}
	}
}

//multiply two matrices and store them in the output matrix
void multiply_matrices(int im1[][MAX_DIM], int im2[][MAX_DIM], int om[][MAX_DIM], int r1, int c1, int r2, int c2, int *r3, int *c3){
	int i, j, k;

	*r3 = r1;
	*c3 = c2;

	for (i = 0; i < r1; ++i){
		for (j = 0; j < c2; ++j){
			om[i][j] = 0;

			printf("row: %d col: %d - \n", i, j);
			for (k = 0; k < c1; ++k){
				printf("%d = %d * %d\n", om[i][j], im1[i][k], im2[k][j]);
				om[i][j] += im1[i][k] * im2[k][j];
			}
		}
	}
}

//print the matrix data
void print_matrix(int matrix[][MAX_DIM], int rows, int columns){
	int i, j;

	for (i = 0; i < rows; ++i){
		for (j = 0; j < columns; ++j){
			printf("%d \t", matrix[i][j]);
		}
		printf("\n");
	}

	printf("\n");
}