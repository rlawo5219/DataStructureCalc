typedef char elementChar;
typedef double elementDouble;

typedef struct stackNodeChar {  //연산자 스택
	elementChar data;
	struct stackNode* link;
}stackNodeChar;

typedef struct stackNodeDouble { //피연산자 스택
	elementDouble data;
	struct stackNodeDouble* link;
}stackNodeDouble;

stackNodeChar* top1;
stackNodeDouble* top2;

void initChar();
int isStackEmptyChar();
void pushChar(elementChar item);
elementChar popChar();
elementChar peekChar();
void peekAllS();

void initDouble();
int isStackEmptyDouble();
void pushDouble(elementDouble item);
elementDouble popDouble();
void peekAllD();