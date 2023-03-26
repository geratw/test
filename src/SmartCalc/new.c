#include "new.h"

int start(char *result_culc, double *res, double resX) {
  int error = 1;
  Node *head_node = NULL;
  Node *NodeResCalc = NULL;
  error = pars(&head_node, result_culc);
  if (error) inverse(&head_node, &NodeResCalc);
  if (error) error = resultCalc(&NodeResCalc, res, resX);
  if (!error) *res = 0;
  deleteList(&head_node);
  deleteList(&NodeResCalc);
  return error;
}

void deleteList(Node **head) {
  Node *prev = NULL;
  int error = 1;
  if (*head == NULL) error = 0;
  if (error) {
    while ((*head)->next) {
      prev = (*head);
      (*head) = (*head)->next;
      free(prev);
    }
    free(*head);
  }
}

int resultCalc(Node **NodeResCalc, double *res, double resX) {
  int error = 1;
  double req[10] = {0};
  int i = 0;
  double value = 0.0;
  int is_x = 0;
  char sign = {0};
  double oneNum = 0.0;
  double twoNum = 0.0;
  while (*NodeResCalc != NULL && error) {
    if (node_is_value(NodeResCalc)) {
      pop_every_value(NodeResCalc, &value, &is_x, &sign);
      req[i] = value;
      i++;
    } else if (node_is_sign(NodeResCalc)) {
      pop_every_value(NodeResCalc, &value, &is_x, &sign);
      i -= 2;
      if (i < 0) {
        error = 0;
        break;
      }
      oneNum = req[i];
      twoNum = req[i + 1];
      i++;
      error = mathematics_two_arg(&oneNum, twoNum, sign);
      req[i] = 0.0;
      req[i - 1] = oneNum;
    } else if (node_is_x(NodeResCalc)) {
      pop_every_value(NodeResCalc, &value, &is_x, &sign);
      req[i] = resX;
      i++;
    } else if (node_is_trig(NodeResCalc)) {
      pop_every_value(NodeResCalc, &value, &is_x, &sign);
      i -= 1;
      oneNum = req[i];
      error = mathematics_one_arg(&oneNum, sign);
      req[i] = oneNum;
      i++;
    }
  }

  if (req[1] != 0.0) {
    error = 0;
  }
  *res = req[0];
  return error;
}

int mathematics_one_arg(double *oneNum, char sign) {
  int error = 1;
  if (sign == SIN) {
    *oneNum = sin(*oneNum);
  } else if (sign == COS) {
    *oneNum = cos(*oneNum);
  } else if (sign == TAN) {
    *oneNum = tan(*oneNum);
  } else if (sign == ACOS) {
    if (*oneNum < -1 || *oneNum > 1) {
      error = 0;
    } else {
      *oneNum = acos(*oneNum);
    }
  } else if (sign == ASIN) {
    if (*oneNum < -1 || *oneNum > 1) {
      error = 0;
    } else {
      *oneNum = asin(*oneNum);
    }
  } else if (sign == ATAN) {
    *oneNum = atan(*oneNum);
  } else if (sign == SQRT) {
    if (*oneNum < 0) {
      error = 0;
    } else {
      *oneNum = sqrt(*oneNum);
    }
  } else if (sign == LN) {
    if (*oneNum <= 0) {
      error = 0;
    } else {
      *oneNum = log(*oneNum);
    }
  } else if (sign == LOG) {
    if (*oneNum <= 0) {
      error = 0;
    } else {
      *oneNum = log10(*oneNum);
    }
  } else {
    error = 0;
  }
  return error;
}

int mathematics_two_arg(double *oneNum, double twoNum, char sign) {
  int error = 1;
  if (sign == POWER) {
    *oneNum = pow(*oneNum, twoNum);
  } else if (sign == PLUS) {
    *oneNum = *oneNum + twoNum;
  } else if (sign == MINUS) {
    *oneNum = *oneNum - twoNum;
  } else if (sign == MULTIPLY) {
    *oneNum = *oneNum * twoNum;
  } else if (sign == DIVIDE) {
    *oneNum = *oneNum / twoNum;
    if (!twoNum) {
      error = 0;
    }
  } else if (sign == MOD) {
    *oneNum = fmod(*oneNum, twoNum);
    if (!twoNum) {
      error = 0;
    }
  }
  return error;
}

int pars(Node **head_node, char *result_culc) {
  int error = 1;
  Node *sumbol_node = NULL;
  int lenString = strlen(result_culc);
  double result = 0.0;
  char results = {0};
  for (int i = 0; i < lenString && error; i++) {
    if (isdigit((result_culc[i])) || result_culc[i] == '.') {
      readDouble(result_culc, &result, &i);
      push(head_node, result, false, CHR_NONE);
    } else if (isalpha(result_culc[i]) && result_culc[i] != 'x') {
      readWord(&results, result_culc, &i);
      priority(&sumbol_node, head_node, results);
    } else if (issign(result_culc[i])) {
      if (result_culc[i] == '-' && ((i - 1) < 0)) {
        if (isdigit(result_culc[i + 1])) {
          i++;
          readDouble(result_culc, &result, &i);
          result *= -1;
          push(head_node, result, false, CHR_NONE);
        } else {
          error = 0;
        }
      } else if (result_culc[i] == '-' && (issign(result_culc[i - 1]) ||
                                           result_culc[i - 1] == OPEN_BKT)) {
        i++;
        readDouble(result_culc, &result, &i);
        result *= -1;
        push(head_node, result, false, CHR_NONE);
      } else {
        priority(&sumbol_node, head_node, result_culc[i]);
      }
    } else if (result_culc[i] == OPEN_BKT) {
      push(&sumbol_node, 0.0, false, result_culc[i]);
    } else if (result_culc[i] == CLOSE_BKT) {
      if (result_culc[i - 1] == '(') {
        error = 0;
      } else {
        error = backBracket(head_node, &sumbol_node);
      }
    } else if (result_culc[i] == 'x') {
      push(head_node, 0.0, true, CHR_NONE);
    } else if (result_culc[i] == ' ') {
      continue;
    }
  }
  if (*head_node == NULL) {
    error = 0;
  }
  if (error) pushOneNoteNode(head_node, &sumbol_node);
  deleteList(&sumbol_node);
  return error;
}

int backBracket(Node **head_node, Node **sumbol_node) {
  int error = 1;
  double value = 0.0;
  int is_x = 0;
  char sign = {0};
  peek(sumbol_node, &sign);
  while (sign != '(') {
    if (*sumbol_node == NULL) {
      error = 0;
      break;
    }

    pop_every_value(sumbol_node, &value, &is_x, &sign);
    push(head_node, value, is_x, sign);
    peek(sumbol_node, &sign);
    // sign = '(';
  }
  if (sign == '(' && *sumbol_node != NULL)
    pop_every_value(sumbol_node, &value, &is_x, &sign);
  return error;
}

int priority(Node **sumbol_node, Node **head_node, char symbol) {
  int prior = 0;
  char val = {0};
  if (peek(sumbol_node, &val)) {
    double value = 0.0;
    int is_x = 0;
    char sign = {0};
    if (sign_lvl(val) >= sign_lvl(symbol)) {
      while (sign_lvl(val) >= sign_lvl(symbol) && *sumbol_node != NULL &&
             !(val == '^' && symbol == '^')) {
        pop_every_value(sumbol_node, &value, &is_x, &sign);
        push(head_node, 0.0, false, sign);
        peek(sumbol_node, &val);
      }
      push(sumbol_node, 0.0, false, symbol);
    } else if (sign_lvl(val) < sign_lvl(symbol)) {
      push(sumbol_node, 0.0, false, symbol);
    }
  } else {
    push(sumbol_node, 0.0, false, symbol);
  }
  return prior;
}

// достал дабл число
void readDouble(char *result_culc, double *result, int *i) {
  char tmp[100] = {0};
  int j = 0;
  int countPoint = 0;
  while (((isdigit(result_culc[*i]) || result_culc[*i] == '.')) &&
         countPoint <= 1) {
    if (result_culc[*i] == '.') {
      countPoint++;
    }
    tmp[j] = result_culc[*i];
    j++;
    *i = *i + 1;
  }
  *i = *i - 1;
  *result = atof(tmp);
}

// является ли символ математической операцией
int issign(char c) {
  int error = false;
  if (c == MULTIPLY || c == MINUS || c == PLUS || c == DIVIDE || c == POWER ||
      c == MOD) {
    error = true;
  }
  return error;
}

// прочитать слово
void readWord(char *result, char *result_culc, int *i) {
  char tmp[256] = {0};
  int j = 0;
  while (isalpha(result_culc[*i])) {
    tmp[j] = result_culc[*i];
    j++;
    *i = *i + 1;
  }
  *i = *i - 1;
  // замена слова на чар
  refractor(tmp, result);
}

int refractor(char *tmp, char *result) {
  int error = false;
  if (strcmp(tmp, "sin") == 0) {
    *result = SIN;
  } else if (strcmp(tmp, "cos") == 0) {
    *result = COS;
  } else if (strcmp(tmp, "tan") == 0) {
    *result = TAN;
  } else if (strcmp(tmp, "acos") == 0) {
    *result = ACOS;
  } else if (strcmp(tmp, "asin") == 0) {
    *result = ASIN;
  } else if (strcmp(tmp, "atan") == 0) {
    *result = ATAN;
  } else if (strcmp(tmp, "sqrt") == 0) {
    *result = SQRT;
  } else if (strcmp(tmp, "ln") == 0) {
    *result = LN;
  } else if (strcmp(tmp, "log") == 0) {
    *result = LOG;
  } else {
    error = true;
  }
  return error;
}

int sign_lvl(char c) {
  int lvl = LVL_NONE;
  if (c == SIN || c == COS || c == TAN || c == ACOS || c == ASIN || c == ATAN ||
      c == SQRT || c == LN || c == LOG)
    lvl = 4;
  else if (c == POWER)
    lvl = 3;
  else if (c == MULTIPLY || c == DIVIDE || c == MOD)
    lvl = 1;
  else if (c == PLUS || c == MINUS)
    lvl = 0;
  return lvl;
}

int peek(Node **head, char *val) {
  int status = 1;
  if (*head == NULL) status = 0;
  if (status) {
    *val = (*head)->sign;
  }
  return status;
}

// пуш в список
void push(Node **head, double value, int is_x, char sign) {
  Node *tmp = (Node *)malloc(sizeof(Node));
  if (tmp != NULL) {
    tmp->value = value;
    tmp->is_x = is_x;
    tmp->sign = sign;
    tmp->next = (*head);
    (*head) = tmp;
  }
}

int pop_every_value(Node **head, double *value, int *is_x, char *sign) {
  Node *prev = NULL;
  int status = 1;
  if (*head == NULL) status = 0;
  if (status) {
    prev = (*head);
    *value = prev->value;
    *is_x = prev->is_x;
    *sign = prev->sign;
    (*head) = (*head)->next;
    free(prev);
  }
  return status;
}

int node_is_value(Node **node) {
  int res = false;
  if (node != NULL && (*node)->is_x == false && (*node)->sign == CHR_NONE) {
    res = true;
  }
  return res;
}

int node_is_x(Node **node) {
  int res = false;
  if (node != NULL && (*node)->is_x == true) {
    res = true;
  }
  return res;
}

int node_is_sign(Node **node) {
  int res = false;
  if (node != NULL && (*node)->is_x == false && (*node)->sign != CHR_NONE &&
      ((*node)->sign == PLUS || (*node)->sign == MINUS ||
       (*node)->sign == MULTIPLY || (*node)->sign == DIVIDE ||
       (*node)->sign == POWER || (*node)->sign == MOD)) {
    res = true;
  }
  return res;
}

void pushOneNoteNode(Node **node, Node **twonote) {
  double value = 0.0;
  int is_x = 0;
  char sign = {0};
  while (pop_every_value(twonote, &value, &is_x, &sign)) {
    push(node, value, is_x, sign);
  }
}

void inverse(Node **node, Node **inverses) {
  double value = 0.0;
  int is_x = 0;
  char sign = {0};
  while (pop_every_value(node, &value, &is_x, &sign)) {
    push(inverses, value, is_x, sign);
  }
}

int node_is_trig(Node **node) {
  int res = false;
  if (node != NULL && (*node)->is_x == false && (*node)->sign != CHR_NONE) {
    res = true;
  }
  return res;
}
