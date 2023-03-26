#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <ctype.h>
#include "stackLink.h"
#include "infixToPostfixAndevalPostfix.h"

int main() {
	char inExp[100];
	char poExp[100];
	while (1) {
		printf("중위표기식 입력 (종료 시 x) : ");
		gets(inExp);
		if (toupper(inExp[0]) == 'X') {
			break;
		}
		infixCheckAfterInfixToPostfix(inExp, poExp);
	}

	return 0;
}
