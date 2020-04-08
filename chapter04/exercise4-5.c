#include <stdio.h>
#include <stdlib.h>   /* for atof() */
#include <math.h>
#include <string.h>

#define MAXOP  100    /* max size of operant or operator  */
#define NUMBER '0'    /* signat that a number was found */
#define MATHNAME 'm'

int getop(char []);
void push(double);
double pop(void);
void clear(void);
void mathfunc(char []);

/* reverse  Polish calculator */
main()
{
  int type;
  double op2, op3;
  char s[MAXOP];

  while ((type = getop(s)) != EOF) {
    switch (type) {
    case NUMBER:
      push(atof(s));
      break;
    case MATHNAME:
      mathfunc(s);
      break;
    case '+':
      push(pop() + pop());
      break;
    case '*':
      push(pop() * pop());
      break;
    case '-':
      op2 = pop();
      push(pop() - op2);
      break;
    case '/':
      op2 = pop();
      if (op2 != 0.0)
        push(pop() / op2);
      else
        printf("error: zero divisor\n");
      break;
    case '%':
      op2 = pop();
      if (op2 != 0.0) 
        push(fmod(pop(), op2));
      else
        printf("error: zero divisor\n");
      break;
    case 'p':
      op2 = pop();
      printf("\t%.8g\n", op2);
      push(op2);
      break;
    case 's':
      op2 = pop();
      op3 = pop();
      push(op2);
      push(op3);
      break;
    case 'd':
      op2 = pop();
      push(op2);
      push(op2);
      break;
    case 'c':
      clear();
      break;
    case '\n':
      printf("\t%.8g\n", pop());
      break;
    default:
      printf("error: unknown command %s\n", s);
      break;
    }
  }
  return 0;
}

#define MAXVAL 100    /* maximum depth of val stack */

int sp = 0;          /* next free stack position */
double val[MAXVAL];  /* value stack */

/* push: push f onto value stack */
void push(double f)
{
  if (sp < MAXVAL)
    val[sp++] = f;
  else {
    printf("error: stack full, can't push %g\n", f);
  }
}

/* pop: pop and return top value from stack */
double pop(void)
{
  if (sp > 0)
    return val[--sp];
  else {
    printf("error: stack empty\n");
    return 0.0;
  }
}

void clear(void)
{
  sp = 0;
}

#include <ctype.h>

int getch(void);
void ungetch(int);

/* getop: get next character or numeric operand */
int getop(char s[])
{
  int i, c;

  while ((s[0] = c = getch()) == ' ' || c == '\t')
    ;
  s[1] = '\0';

  i = 0;
  if ('a' <= c && c <= 'z') {
    while ('a' <= c && c <= 'z') {                                             
      s[i++] = c;
      c = getch();
    }
    s[i] = '\0';
    if (c != EOF)
      ungetch(c);
    if (strlen(s) > 1) {
     printf("getup %s\n", s);
     return MATHNAME;
    }
    else
      return c;
  }

  if (!isdigit(c) && c != '.' && c != '-')
    return c;        /* not a number */
  if (c == '-')
    if (isdigit(c = getch()) || c == '.')
      s[++i] = c;
    else {
      if (c != EOF)
        ungetch(c);
      return '-';
   }
  if (isdigit(c))    /* collect integer part */
    while (isdigit(s[++i] = c = getch()))
      ;
  if (c == '.')      /* collect fraction part */
    while (isdigit(s[++i] = c = getch()))
      ;
  s[i] = '\0';
  if (c != EOF)
    ungetch(c);
  return NUMBER;
}

void mathfunc(char s[])
{
  double op2, op1;
  printf("%s\n", s);
  if ((strcmp("sin", s) == 0)) {
    printf("sinYO\n");
    push(sin(pop()));
  }
  else if ((strcmp("exp", s) == 0)) {
   op1 = (double) pop();
   printf("%lf\n", op1);
   push(exp(op1));
  }
  else if ((strcmp("pow", s) == 0)) {
    op2 = pop();
    push(pow(pop(), op2));
  }
}

#define BUFSIZE 100

char buf[BUFSIZE];    /* buffer for ungetch */
int bufp = 0;         /* ext free position in buf */

int getch(void)  /* get a (possibly pushed-back) character */
{
  return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c)
{
  if (bufp >= BUFSIZE)
    printf("ungetch: too many characters\n");
  else
    buf[bufp++] = c;
}

