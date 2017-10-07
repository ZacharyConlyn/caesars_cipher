// File name: caesars_cipher.c
// Author: Zachary Conlyn
// Date: December 2nd, 2016
// Purpose: to encrypt ASCII or Unicode
// strings with Caesar's cipher

#include <stdio.h>
#include <stdlib.h>

#define MAX_LENGTH 1000

void encrypt (char *str, int offset);
int convert_offset (char *s);

int main(int argc, char *argv[]) {
	// check for correct # of arguments
	if (argc != 3) {
		fprintf(stderr, "Error: Two arguments required (string and offset).\n");
		exit(EXIT_FAILURE);
	}
	// convert offset
	int offset = convert_offset(argv[2]);
	// convert string
	encrypt (argv[1], offset);
}

void encrypt (char *str, int offset) {
	char *p = str;
	int i = 0;
	int tmp;
	while (*p && (i < MAX_LENGTH)) {
		// if p is uppercase:
		if (*p >= 'A' && *p <= 'Z') {
			tmp = *p - 'A';
			tmp = tmp + offset;
			tmp = tmp % 26;
			tmp += 'A';
			// if p is lowercase:
		} else if (*p >= 'a' && *p <= 'z') {
			tmp = *p - 'a';
			tmp = tmp + offset;
			tmp = tmp % 26;
			tmp += 'a';
			// if p is neither upper nor lowercase, do nothing
		} else {
			tmp = *p;
		}
		putchar(tmp);
		p++;
		i++;
	}
	putchar('\n');
	exit(EXIT_SUCCESS);
}

int convert_offset (char *s) {
	int offset = atoi(s);
	if (offset == 0) {
		// check for valid input
		fprintf(stderr, "Warning: offset is 0 or not an integer.\n");
	} else if (offset > 25 || offset < -25) {
		fprintf(stderr, "Warning: offset not between -25 and 25. ");
		fprintf(stderr, "Converting offset to smaller number.\n");
		offset = offset % 26;
	}
	// convert negative offsets to positive
	if (offset < 0) {
		offset = offset + 26;
	}
	return offset;
}
