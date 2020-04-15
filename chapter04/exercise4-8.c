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
void ungets(char []);

/* reverse  Polish calculator */
main()
{
  int type, var_index;
  double op2, op3, last_printed_val;
  char s[MAXOP];
  double variables[26];

  /* test at most one character of push back */
  char str[] = "4";
  ungets(str);

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
    case '=':
      pop();
      if ('A' <= var_index && var_index <= 'Z')
        variables[var_index - 'A'] = pop();
      else
        printf("error: nonvariable\n");
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
      last_printed_val = pop();
      printf("\t%.8g\n", last_printed_val);
      break;
    default:
      if ('A' <= type && type <= 'Z') {
        push(variables[type - 'A']);
        var_index = type;
      }
      else
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

char getch(void);
void ungetch(char);

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
  double op;
  if ((strcmp("sin", s) == 0))
    push(sin(pop()));
  else if ((strcmp("exp", s) == 0))
   push(exp(pop()));
  else if ((strcmp("pow", s) == 0)) {
    op = pop();
    push(pow(pop(), op));
  }
}

#define BUFSIZE 100

char bufp = 0;         /* stores pushed back character */

char getch(void)  /* get a (possibly pushed-back) character */
{
  char c = bufp;
  if (c != 0) {
   bufp = 0;     /* return pushed back character and reset bufp */
   return c;
  }
  else
    return getchar();
}

void ungetch(char c)
{
  if (bufp != 0)
    printf("ungetch: too many characters\n");
  else
    bufp = c; /* store charater in bufp  */
}

/* pushes back string s onto the input  */
void ungets(char s[]) 
{
  int i = strlen(s);
  printf("%s\n", s);

  while (i > 0) {
    ungetch(s[--i]);
  }
}
