// File name: caesars_cipher.c
// Author: Zachary Conlyn
// Date: December 2nd, 2016
// Class: CMSC 412
// Purpose: to encrypt ASCII or Unicode strings
// with Caesar's cypher


#include <stdio.h>
#include <stdlib.h>

#define MAX_LENGTH 1000

void encrypt (char *str, int offset);
int convert_offset (char *s);

int main(int argc, char *argv[]) {
  // check for correct # of arguments
  if (argc != 3) {
    printf("Error: Two arguments required (string and offset)\n.");
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
      tmp = *p - 65;
      tmp = tmp + offset;
      tmp = tmp % 26;
      tmp += 65;
      // if p is lowercase:
    } else if (*p >= 'a' && *p <= 'z') {
      tmp = *p - 97;
      tmp = tmp + offset;
      tmp = tmp % 26;
      tmp += 97;
      // if p is neither upper nor lowercase, do nothing
    } else {
      tmp = *p;
    }
    putchar(tmp);
    p++;
	i++;
  }
  putchar('\n');
}

int convert_offset (char *s) {
  int offset = atoi(s);
  if (offset == 0) {
    // check for valid input
    printf("Warning: offset is 0 or not an integer.\n");
  } else if (offset > 25 || offset < -25) {
    printf("Warning: offset not between -25 and 25. ");
    printf("Converting offset to smaller number.\n");
    offset = offset % 26;
  }
  // convert negative offsets to positive
  if (offset < 0) {
    offset = offset + 26;
  }
  return offset;
}