#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void file_func1() {
	char arr[] = "Hi this is paramaraj\n i am creating new file.\n This is good for learning\n";
	FILE* fp = NULL;
	char* ptr = NULL;
	int i = 0, ch = 0;

	//fp = fopen("C:\\Users\\p.karuppasamy\\source\\repos\\All_My_C_CPP\\new1.txt", "r");
	fp = fopen("C:\\Users\\pkaruppasamy\\Desktop\\Data\\Param_GL\\Data\\new_data\\My_learning_advance\\Param_CPP\\All_My_C_CPP_New\\new1.txt", "r");

	if (fp == NULL) {
		printf("Error in opening file\n");
		return -1;
	}
	/*ptr = arr;
	while (ptr[i] != '\0') {
		fputc((int)ptr[i], fp);
		i++;
		if (ptr[i] == '\0') break;
	}*/
	printf("Reading from file\n");
	while ((ch = fgetc(fp)) != EOF) {
		printf("%c", ch);
	}

	printf("\n");
	fclose(fp);
}

void file_func2() {
	FILE* fp1, * fp2;
	int ch = 0;

	fp1 = fopen("C:\\Users\\pkaruppasamy\\Desktop\\Data\\Param_GL\\Data\\new_data\\My_learning_advance\\Param_CPP\\All_My_C_CPP_New\\new1.txt", "r");
	//fp1 = fopen("C:\\Users\\p.karuppasamy\\source\\repos\\All_My_C_CPP\\new1.txt", "r");
	if (fp1 == NULL) {
		printf("Error in opening file\n");
		return;
	}

	fp2 = fopen("C:\\Users\\pkaruppasamy\\Desktop\\Data\\Param_GL\\Data\\new_data\\My_learning_advance\\Param_CPP\\All_My_C_CPP_New\\new2.txt", "w");
	//fp2 = fopen("C:\\Users\\p.karuppasamy\\source\\repos\\All_My_C_CPP\\new2.txt", "w");
	if (fp2 == NULL) {
		printf("Error in opening file\n");
		return;
	}

	while ((ch = fgetc(fp1)) != EOF) {
		fputc(ch, fp2);
	}
	printf("FIle coped\n");
	fclose(fp1);
	fclose(fp2);
	fp2 = fopen("C:\\Users\\pkaruppasamy\\Desktop\\Data\\Param_GL\\Data\\new_data\\My_learning_advance\\Param_CPP\\All_My_C_CPP_New\\new2.txt", "r");
	//fp2 = fopen("C:\\Users\\p.karuppasamy\\source\\repos\\All_My_C_CPP\\new2.txt", "r");
	if (fp2 == NULL) {
		printf("Error in opening file\n");
		return;
	}
	printf("Reading info from new2.txt\n");
	while ((ch = fgetc(fp2)) != EOF) {
		printf("%c", ch);
	}
	printf("\n");
	fclose(fp2);
}

void file_func3() {
	FILE* fp1 = NULL;
	char arr[200];
	int ch = 0;

	fp1 = fopen("C:\\Users\\pkaruppasamy\\Desktop\\Data\\Param_GL\\Data\\new_data\\My_learning_advance\\Param_CPP\\All_My_C_CPP_New\\new1.txt", "r");
	//fp1 = fopen("C:\\Users\\p.karuppasamy\\source\\repos\\All_My_C_CPP\\new1.txt", "r");
	if (fp1 == NULL) {
		printf("Error in opening file\n");
		return;
	}

	int i = 0;
	while ((ch = fgetc(fp1)) != EOF) {
		arr[i++] = (char)ch;
	}
	arr[i] = '\0';

	printf("The coped string from file is : %s\n", arr);
	fclose(fp1);
}

void file_func4() {
	FILE* fp1 = NULL;
	fp1 = fopen("C:\\Users\\pkaruppasamy\\Desktop\\Data\\Param_GL\\Data\\new_data\\My_learning_advance\\Param_CPP\\All_My_C_CPP_New\\new1.txt", "r");
	//fp1 = fopen("C:\\Users\\p.karuppasamy\\source\\repos\\All_My_C_CPP\\new1.txt", "r");

	if (fseek(fp1, 0, SEEK_CUR) == 0) {
		printf("%d\n", ftell(fp1));
	}
	else {
		printf("Error in fseek\n");
		return;
	}

	//SEEK_END -> cursor pointing the end of file
	if (fseek(fp1, 0, SEEK_END) == 0) {
		printf("%d\n", ftell(fp1));
	}
	else {
		printf("Error in fseek\n");
		return;
	}

	//SEEK_CRU -> current postion of cursor
	if (fseek(fp1, 0, SEEK_CUR) == 0) {
		printf("%d\n", ftell(fp1));
	}
	else {
		printf("Error in fseek\n");
		return;
	}

	//SEE_SET -> setting cursor at postion 0, strat position
	if (fseek(fp1, 0, SEEK_SET) == 0) {
		printf("%d\n", ftell(fp1));
	}
	else {
		printf("Error in fseek\n");
		return;
	}

	fclose(fp1);
}

int main() {
	file_func1();
	printf("==========================\n");
	file_func2();
	printf("==========================\n");
	file_func3();
	printf("==========================\n");
	file_func4();
	printf("==========================\n");
	return 0;
}