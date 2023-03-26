#ifndef SRC_NEW_H_
#define SRC_NEW_H_

#include <ctype.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CHR_NONE '\0'

#define POWER '^'
#define PLUS '+'
#define UNAR_MINUS '~'
#define MINUS '-'
#define MULTIPLY '*'
#define DIVIDE '/'
#define MOD '%'
#define SIN '1'
#define COS '2'
#define TAN '3'
#define ACOS '4'
#define ASIN '5'
#define ATAN '6'
#define SQRT '7'
#define LN '8'
#define LOG '9'
#define OPEN_BKT '('
#define CLOSE_BKT ')'

#define HIGH 1
#define LOW 0

#define LVL_NONE -1

typedef struct node_t {
  double value;
  int is_x;
  char sign;

  struct node_t *next;
} Node;

int start(char *result_culc, double *res, double resX);
int resultCalc(Node **NodeResCalc, double *res, double resX);
void push(Node **head, double value, int is_x, char sign);
int peek(Node **head, char *val);
int pars(Node **head_node, char *result_culc);
int sign_lvl(char c);
int priority(Node **sumbol_node, Node **head_node, char symbol);
void readDouble(char *result_culc, double *result, int *i);
void readWord(char *results, char *result_culc, int *i);
int refractor(char *tmp, char *result);
int issign(char c);
int pop_every_value(Node **head, double *value, int *is_x, char *sign);
int backBracket(Node **head_node, Node **sumbol_node);
int node_is_value(Node **node);
int node_is_x(Node **node);
int node_is_sign(Node **node);
void pushOneNoteNode(Node **node, Node **twonote);
void inverse(Node **node, Node **inverses);
int mathematics_two_arg(double *oneNum, double twoNum, char sign);
int mathematics_one_arg(double *oneNum, char sign);
int node_is_trig(Node **node);
void deleteList(Node **head);

#endif  // SRC_NEW_H_
