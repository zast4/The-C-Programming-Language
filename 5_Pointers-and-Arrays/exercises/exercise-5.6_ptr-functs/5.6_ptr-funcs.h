#include <string.h>
#include <math.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>

#define MAXLINE 1000

int get_line(char *s, int lim);
int atoi_v2(char *s);
void itoa_v2(int n, char *s);
int getop(char *s);
void reverse(char *s);
int strindex(char *s, char *t);