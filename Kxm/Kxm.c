#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable : 4996)
#define COUNT_BOOK 12

struct Book {
	char autor[100];
	char name[100];
	char edition[100];
	int price;
}booklist[COUNT_BOOK];

void addBook();
void Revision();
void Search();

int main() {

	addBook();
	int choice;

	while (1) {
		printf("    Menu\n");
		printf("1 - Revision\n");
		printf("2 - Search\n");
		printf("3 - Exit\n");
		printf("Choice: ");
		scanf("%d", &choice);

		switch (choice)
		{
		case 1:
			Revision();
			break;
		case 2:
			Search();
			break;
		case 3:
			exit(0);
			break;
		}
	}

}
void addBook() {

	FILE* f;

	f = fopen("booklist.txt", "r");

	if (f == NULL) {
		printf("\nError open file\n");
	}

	char c;
	int j = 0;
	for (int i = 0; i < COUNT_BOOK; i++) {
		while ((c = getc(f)) != '/') {
			if (c == '\n') {
				break;
			}
			booklist[i].name[j] = c;
			j++;
		}
		j = 0;
		while ((c = getc(f)) != '/') {
			if (c == '\n') {
				break;
			}
			booklist[i].edition[j] = c;
			j++;
		}
		j = 0;
		while ((c = getc(f)) != '/') {
			if (c == '\n') {
				break;
			}
			booklist[i].autor[j] = c;
			j++;
		}
		j = 0;
		char num[4];
		while ((c = getc(f)) != '/') {
			if (c == '\n') {
				break;
			}
			num[j] = c;
			j++;
		}
		j = 0;
		booklist[i].price = atoi(num);
		memset(num, 0, 4);
	}

	fclose(f);

}
void Revision() {

	char line[200];

	getchar();
	printf("Enter book name: ");
	fgets(line, 200, stdin);

	line[strlen(line) - 1] = '\0';

	for (int i = 0; i < COUNT_BOOK; i++) {
		if (strcmp(line, booklist[i].name) == 0) {
			printf("\nBook found!\n");
			printf("Name: %s\n", booklist[i].name);
			printf("Edition: %s\n", booklist[i].edition);
			printf("Autor: %s\n", booklist[i].autor);
			printf("Price: %d UAH\n", booklist[i].price);
		}
	}
	printf("\n");
}
void Search() {

	int count = 0;
	int sum_price = 0;

	for (int i = 0; i < COUNT_BOOK; i++) {
		if (strstr(booklist[i].name, "C ") == NULL && strstr(booklist[i].name, " C ") == NULL && strstr(booklist[i].name, " C. ") == NULL && 
			strstr(booklist[i].name, "C. ") == NULL) {
			continue;
		}
		else {
			printf("Name: %s\n", booklist[i].name);
			printf("Edition: %s\n", booklist[i].edition);
			printf("Autor: %s\n", booklist[i].autor);
			printf("Price: %d UHA\n\n", booklist[i].price);
			count++;
			sum_price += booklist[i].price;
		}
	}

	printf("Count Book: %d\n", count);
	printf("Total price: %d UAH\n\n", sum_price);

}


