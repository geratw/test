#include <math.h>
#include <stdio.h>
#include <stdlib.h>

double annuityСredit(double *sums, double *months, double *procents,
                     double *overpayment, double *totalSum) {
  double PMT = *sums * (*procents * (pow(1 + (*procents), *months) /
                                     (pow(1 + (*procents), *months) - 1)));
  *totalSum = PMT * *months;
  *overpayment = *totalSum - *sums;
  return PMT;
}

double differentiatedСredit(double *sums, double *months, double *procents,
                            double *d) {
  double PMT = (*d) + ((*sums) - (*d) * ((*months) - 1)) * (*procents);
  return PMT;
}
