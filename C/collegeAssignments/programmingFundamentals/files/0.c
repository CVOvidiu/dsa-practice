#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main() {
	FILE* file = fopen("in.txt", "r");
	if (!file) {
		printf("Eroare deschidere fisier.\n");
		return 1;
	}

	FILE* out = fopen("out.txt", "w");
	if (!out) {
		printf("Eroare deschidere fisier.\n");
		return 1;
	}

	int n, cnt = 0;
	scanf("%d", &n);

	char s[100];
	while (!feof(file)) {
		if (cnt != n)
			fputs(s, out);
		cnt++;
		// fgets(s, 99, file);
	}

	fclose(file);
	fclose(out);
	// rename("out.txt", "in.txt");
}