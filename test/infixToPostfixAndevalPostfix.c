#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "stackLink.h"
#include "infixToPostfixAndevalPostfix.h"

int checkPair(char inExp[]) {
	#pragma region Pair

	char symbol, pair;
	int i, len = strlen(inExp);
	initChar();

	for (i = 0; i < len; i++) {
		symbol = inExp[i];
		switch (symbol) {
		case '(': 
			pushChar(symbol);
			break;
		case ')':
			if (isStackEmptyChar()) {
				return 0;
			}
			else {
				pair = popChar();
				if (pair == '(' && symbol != ')') {
					return 0;
				}
				else {
					break;
				}
			}
		}
	}
	if (top1 == NULL) {
		return 1;
	}
	else {
		return 0;
	}
	#pragma endregion
}

void infixCheckAfterInfixToPostfix(char inExp[], char poExp[]){
	#pragma region Check

	int operandCount = 0, operatorCount = 0;
	int i, pairResult;
	int length = strlen(inExp);

	pairResult = checkPair(inExp);

	if (!pairResult) {
		printf("\n��ȣ�� ���� �ʽ��ϴ�.\n");
		printf("����ǥ����� �ٽ� �Է����ּ��� : ");
		gets(inExp);
		return infixCheckAfterInfixToPostfix(inExp, poExp);
	}

	for (i = 0; i < length; i++) {
		if (inExp[i] == '+' || inExp[i] == '-' || inExp[i] == '*' || inExp[i] == '/' || inExp[i] == '%'
			|| inExp[i] == NULL || inExp[i] == '(' || inExp[i] == ')' || ('0' <= inExp[i] && inExp[i] <= '9')) {

			if (inExp[i] == '+' || inExp[i] == '-' || inExp[i] == '*' || inExp[i] == '/' || inExp[i] == '%') {
				operatorCount++;
			}
			else if ('0' <= inExp[i] && inExp[i] <= '9') {
				operandCount++;
			}

			if (length - 1 == i) {
				if ((operandCount - operatorCount) != 1) {
					break;
				}
			}

			if (length-1 > i) {
				continue;
			}

			infixToPostfix(inExp, poExp);
			return;
		}
		else {
			break;
		}
	}
	printf("\n�߸��� ���ڰ� ���԰ų� ���� �߸��Ǿ����ϴ�.(���� �Ұ�)\n");
	printf("����ǥ����� �ٽ� �Է����ּ��� : ");
	gets(inExp);
	return infixCheckAfterInfixToPostfix(inExp, poExp);

	#pragma endregion
}

int prec(char op) {
	#pragma region Prec

	switch (op) {
	case '(': case ')': return 0;
	case '+': case '-': return 1;
	case '*': case '/': case '%': return 2;
	}

	#pragma endregion
}

void infixToPostfix(char inExp[], char poExp[]) {
	#pragma region Changeandprint

	int i = 0, k = 0, j = 0;
	char ch, top_op;
	int length = strlen(inExp);

	initChar();
	printf("\ninfix   ->   %s\n\n", inExp);
	printf("symbol  ������ stack  postfix ǥ���\n");
	for (i = 0; i < length; i++) {
		ch = inExp[i];
		switch (ch) {
		case '+': case '-': case '*': case '/': case '%':
			while (!isStackEmptyChar() && (prec(ch) <= prec(peekChar()))) {
				poExp[k++] = popChar();
			}
			pushChar(ch);
			break;
		case '(':
			pushChar(ch);
			break;
		case ')':
			top_op = popChar();
			while (top_op != '(') {
				poExp[k++] = top_op;
				top_op = popChar();
			}
			break;
		default:
			poExp[k++] = ch;
			break;
		}

		printf("  %c            ", inExp[i]);
		if (!isStackEmptyChar()) {
			peekAllS();
		}
		else {
			printf("    ");
		}
		printf("\t    ");
		poExp[k] = NULL;
		for (j = 0; j < i; j++) {
			if (poExp[j] == NULL) {
				break;
			}
			printf("%c", poExp[j]);
		}
		printf("\n");
	}

	while (!isStackEmptyChar()) {
		poExp[k++] = popChar();
		poExp[k] = NULL;
	}
	printf("\t\t\t    ");
	for (j = 0; j <= length; j++) {
		if (poExp[j] == NULL) {
			break;
		}
		printf("%c", poExp[j]);
	}
	printf("\n");
	printf("\npostfix   ->   %s\n", poExp);

	evalPostfixAfterprintResult(inExp, poExp);
	#pragma endregion
}


void printOperation(double opr) {
	if ((int)opr - opr == 0) {
		printf("%.0lf", opr);
	}
	else {
		printf("%.2lf", floor(opr*100)/100);
	}
}

void printResult() {
#pragma region Result

	printf("\n");
	double finalResult = popDouble();
	if ((int)finalResult - finalResult == 0) {
		printf("��� ���   ->   %.0lf\n\n", finalResult);
	}
	else {
		printf("��� ���   ->   %.2lf\n\n", floor(finalResult*100)/100);
	}

#pragma endregion
}

void evalPostfixAfterprintResult(char inExp[], char poExp[]) {
	#pragma region Eval

	int value, i = 0;
	double opr1, opr2;
	int length = strlen(poExp);
	char symbol;

	initDouble();
	printf("\nsymbol      �� ��     �ǿ����� stack\n");
	for (i = 0; i < length; i++) {
		symbol = poExp[i];
		printf("  %c\t    ", symbol);
		if (symbol == '+' || symbol == '-' || symbol == '*' || symbol == '/' || symbol == '%') {
			opr2 = popDouble();
			opr1 = popDouble();

			switch (symbol) {
			case '+': 
				printOperation(opr1);
				printf(" + ");
				printOperation(opr2);
				printf("\t   ");
				pushDouble(opr1 + opr2); 
				peekAllD();
				printf("\n");
				break;
			case '-': 
				printOperation(opr1);
				printf(" - ");
				printOperation(opr2);
				printf("\t   ");
				pushDouble(opr1 - opr2);
				peekAllD();
				printf("\n");
				break;
			case '*': 
				printOperation(opr1);
				printf(" * ");
				printOperation(opr2);
				printf("\t   ");
				pushDouble(opr1 * opr2);
				peekAllD();
				printf("\n");
				break;
			case '/': 
				printOperation(opr1);
				printf(" / ");
				printOperation(opr2);
				printf("\t   ");
				pushDouble(opr1 / opr2);
				peekAllD();
				printf("\n");
				break;
			case '%': 
				printOperation(opr1);
				printf(" %% ");
				printOperation(opr2);
				printf("\t   ");
				if ((int)opr1 - opr1 != 0 || (int)opr2 - opr2 != 0 || opr2 == 0) {
					printf("\n\n������ �����ڿ��� �Ǽ� �Ǵ� 2��° �ڸ��� 0�� �� �� �����.\n");
					printf("����ǥ��ĺ��� �ٽ� �Է� ���ּ��� : ");
					gets(inExp);
					return infixCheckAfterInfixToPostfix(inExp, poExp);
				}
				pushDouble((int)opr1 % (int)opr2);
				peekAllD();
				printf("\n");
				break;
			}
		}
		else {
			if (symbol != '+' && symbol != '-' && symbol != '*' && symbol != '/' && symbol != '%') {
				printf("\t\t   ");
			}
			value = symbol - '0';
			pushDouble(value);
			peekAllD();
			printf("\n");
		}
	}
	printResult();

	#pragma endregion
} 