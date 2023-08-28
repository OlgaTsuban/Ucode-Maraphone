#include "../inc/calculator.h"

int main(int argc, char *argv[]) {
    enum e_operation eoperation ;
    enum e_error err = -1;
    t_operation toperation;
    if (argc != 4) {
        mx_printerr("usage: ./calc [operand1] [operation] [operand2]\n");
        return 0;
    }
    int a = mx_atoi(argv[1]);
    char *b = argv[2];
    int c = mx_atoi(argv[3]);
    if (a == NOT_NUM || c == NOT_NUM) {
        err = INCORRECT_OPERAND;
    }
    if ( mx_strcmp(b,"+") == 0) {
        eoperation = ADD ;
        toperation.op = eoperation;
        toperation.f = mx_add;
    }
    else if (mx_strcmp(b, "-") == 0) {
        eoperation = SUB;
        toperation.op = eoperation;
        toperation.f = mx_sub;
    }
    else if (mx_strcmp(b, "*") == 0) {
        eoperation = MUL;
        toperation.op = eoperation;
        toperation.f = mx_mul;
    }
    else if (mx_strcmp(b, "/") == 0) {
        eoperation = DIV;
        toperation.op = eoperation;
        toperation.f = mx_div;
    }
    else if (mx_strcmp(b, "%") == 0) {
        eoperation = MOD;
        toperation.op = eoperation;
        toperation.f = mx_mod;
    }
    else {
        err =  INCORRECT_OPERATION;
    }
    if (c == 0 &&  (eoperation == DIV || eoperation == MOD)) {
        err = DIV_BY_ZERO;
    }
    if ( err == INCORRECT_OPERATION ) {
        mx_printerr("error: invalid operation\n");
        exit(0);
    }
    else if ( err == DIV_BY_ZERO ) {
        mx_printerr("error: division by zero\n");
        exit(0);
    }
    else if ( err == INCORRECT_OPERAND ) {
        mx_printerr("error: invalid number\n");
        exit(0);
    }
    int result = toperation.f(a, c);
    mx_printint(result);
    mx_printchar('\n');
    return 0;
}


