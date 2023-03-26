#pragma once
int checkPair(char inExp[]);
void infixCheckAfterInfixToPostfix(char inExp[], char poExp[]);
int prec(char op);
void infixToPostfix(char inExp[], char poExp[]);
void printResult();
void printOperation(double opr);
void evalPostfixAfterprintResult(char inExp[], char poExp[]);