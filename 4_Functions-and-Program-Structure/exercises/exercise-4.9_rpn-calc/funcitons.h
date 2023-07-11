#ifndef C_LANGUAGE_FUNCITONS_H
#define C_LANGUAGE_FUNCITONS_H

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include <stdlib.h> /* for atof() */

#define MAXVAL 100   /* maximum depth of val stack */
#define MAXOP 100  /* max size of operand or operator */
#define BUFSIZE 100
#define MAXSIZE 1000
#define MAXLINE 1000
#define NUMBER '0' /* signal that a number was found */
#define NAME 'n'

int getch(void);
void ungetch(int);
void ungets(char s[]);
void push(double);
double pop(void);
void clearst(void);
int getop(char s[]);
void mathfnc(char s[]);
int get_line(char s[], int lim);

#endif //C_LANGUAGE_FUNCITONS_H
