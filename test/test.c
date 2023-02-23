#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <time.h>

int methodAmount = 0;
char **methods = NULL;
int testArrayElementsAmount = 1000;

int* generateRandomArray(size_t size, int max) {
	int *array = calloc(sizeof(int), size);	
	size_t i;

	max++;
	srand(time(NULL));

	for (i = 0 ; i < size ; i++) {
		array[i] = rand() % max;
	}

	return array;
}

char fileExists(const char* filename) {
	FILE *file = fopen(filename, "r");
	
	if (file) {
		fclose(file);
		return 1;
	}
	else {
		return 0;
	}
}

int writeInputData(const char* filename, int* array, size_t size) {
	size_t i;
	FILE *input = fopen("input.txt", "w");
	
	fprintf(input, "%lu\n", size);
	for (i = 0 ; i < size ; i++) {
		fprintf(input, "%d\n", array[i]);
	
	}
	printf("\t%lu elements written.\n", i);

	fclose(input);

	return 0;
}

char verifyOutputData(const char* outputFileName, size_t* errorPosition) {
	int pastValue, value;
	size_t pos = 0;

	FILE *output = fopen(outputFileName, "r");
	if (!output) return -1;

	fscanf(output, "%d", &pastValue);

	while (fscanf(output, "%d", &value) != EOF) {
		pos++;
		if(value < pastValue) {
			*errorPosition = pos;
			return 0;
		}
	}

	printf("\t%lu elements read\n", pos + 1);

	fclose(output);

	return 1;
}

char testMethod(const char *method, size_t testSize) {
	size_t errorPos;
	int *array = generateRandomArray(1000000, testSize);
	char command[80];

	printf("Testing method: %s\n", method);

	printf("Generating test case...\n");
	writeInputData("input.txt", array, testSize);

	printf("Running sorter...\n");
	sprintf(command, "((../sorter -m %s) < input.txt) > output.txt", method);
	system(command);

	printf("Verifing results...\n");
	char status = verifyOutputData("output.txt", &errorPos);

	switch (status) {
		case -1:
			printf("ERROR: Could not open output file.\n");
			break;
		case 0:
			printf("Element at position %lu is larger than the element at position %lu.\n", errorPos - 1, errorPos);
			printf("See the exact input and output on files input.txt and output.txt\n");
			break;
		case 1:
			printf("Working fine\n");
			break;
		default:
			printf("ERROR: Output verification returned a unknown status.\n");
	}

	printf("-----------------------------------------------------\n\n");

	free(array);

	if (fileExists("input.txt") && status != 0) {
		remove("input.txt");
	}
	if (fileExists("output.txt") && status != 0) {
		remove("output.txt");
	}

	return status;
}

char** splitString(char* string, char c, int* size) {
	int i = 1, j = 1;
	int nParts = 0;
	char **matrix;

	for (i = 0 ; string[i] != '\0' ; i++) {
		if (string[i] == c) {
			string[i] = '\0';
			nParts++;
		}	
	};

	nParts++;

	matrix = calloc(sizeof(char*), nParts);
	matrix[0] = string;

	j = 1;
	for (i = 1 ; i < nParts ; i++) {
		while (string[j] != '\0') j++;
		
		j += 1;
		matrix[i] = string + j;
	}

	*size = nParts;

	return matrix;
}

int stringToInt(char *string) {
	int i = 0;
	int stringLenght = strlen(string);
	int total = 0;
	int multiplier = 1;

	int array[stringLenght];

	for (i = 0 ; i < stringLenght ; i++) {
		array[i] = string[i] - 48;	
	}

	for (i = stringLenght - 1 ; i >= 0 ; i--) {
		total += array[i] * multiplier;
		multiplier *= 10;
	}

	return total;
}

void readFlags(int argc, char **argv) {
	int i;
	for (i = 1 ; i < argc ; i++) {
		if (argv[i][0] == '-') {
			if (strcmp(argv[i] + 1, "m") == 0) {
				printf("methods=%s\n", argv[i + 1]);
				methods = splitString(argv[i + 1], ',', &methodAmount);
				i += 1;
			}
			else if(strcmp(argv[i] + 1, "c") == 0) {
				testArrayElementsAmount = stringToInt(argv[i + 1]);				
				i += 1;
			}
		}
	}

}

int main(int argc, char** argv) {
	int i;
	readFlags(argc, argv);

	for (i = 0 ; i < methodAmount ; i++) {
		if(testMethod(methods[i], testArrayElementsAmount) <= 0) break;
	}

	return 0;
}
