#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define DAYS_IN_MONTH 30

double annuityСredit(char *sum, char *month,char *procent, double *overpayment, double *totalSum) {
    double sums = atof(sum);
    double months = atof(month);
    double procents = (atof(procent) / 100) /12;
    double PMT = sums * (procents*(pow(1+(procents), months)/(pow(1+(procents), months) - 1)));
    *totalSum = PMT * months;
    *overpayment = *totalSum - sums;
    return PMT;
}

//double differentiatedСredit(char *sum, char *month,char *procent, double *overpayment, double *totalSum) {

//}
