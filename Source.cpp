#include<iostream>
#include<fstream>
#include<string>
using namespace std;

enum token
{
	PROGRAM_SY,	IS_SY,	BEGIN_SY, ID_SY, END_SY,
	VAR_SY,	INTEGER_SY,	BOOLEAN_SY,	COLOMN_SY,
	COMMA_SY, SEMICOLON_SY, ASSIGNMENT_SY, READ_SY,
	WRITE_SY, IF_SY, THEN_SY, ELSE_SY, WHILE_SY,
	DO_SY, LEFTPAR_SY,	RIGHTPAR_SY, MINUS_SY,
	OR_SY, AND_SY, TRUE_SY,	FALSE_SY, NOT_SY, LESSTHAN_SY,
	GREATERTHAN_SY,	EQUAL_SY, GREATERTHANOREQUAL_SY,
	LESSTHANOREQUAL_SY,	NOTEQUAL_SY, PLUS_SY,
	STAR_SY, DIVSION_SY, NUMERAL_SY, ERROR_SY, EOF_SY
};
class Scanner {
private:
	ifstream file;
	string token_template;
	char chracter_template;
	
	token check_reserved() {
		do
		{
			token_template += chracter_template;
			file.get(chracter_template);
			if (!isalnum(chracter_template)) {
				file.putback(chracter_template);
				break;
			}
		} while (!isspace(chracter_template) && !file.eof());
		if (token_template == "program") return PROGRAM_SY;
		else if (token_template == "is") return IS_SY;
		else if (token_template == "begin") return BEGIN_SY;
		else if (token_template == "end") return END_SY;
		else if (token_template == "var") return VAR_SY;
		else if (token_template == "integer") return INTEGER_SY;
		else if (token_template == "boolean") return BOOLEAN_SY;
		else if (token_template == "read") return READ_SY;
		else if (token_template == "write") return WRITE_SY;
		else if (token_template == "if") return IF_SY;
		else if (token_template == "then") return THEN_SY;
		else if (token_template == "else") return ELSE_SY;
		else if (token_template == "while") return WHILE_SY;
		else if (token_template == "do") return DO_SY;
		else if (token_template == "true") return TRUE_SY;
		else if (token_template == "false") return FALSE_SY;
		else if (token_template == "not") return NOT_SY;
		else if (token_template == "or") return OR_SY;
		else if (token_template == "and") return AND_SY;
		else return ID_SY;
	}

	token get_number() {
		do
		{
			token_template += chracter_template;
			file.get(chracter_template);
			if (!isdigit(chracter_template)) {
				file.putback(chracter_template);
				break;
			}
		} while (!isspace(chracter_template) && !file.eof());
		return NUMERAL_SY;
	}

	token get_special_char() {
		if (chracter_template == ':') {
			file.get(chracter_template);
			if (chracter_template == '=') return ASSIGNMENT_SY;
			else file.putback(chracter_template);
			return COLOMN_SY;
		}
		else if (chracter_template == ';') return SEMICOLON_SY;
		else if (chracter_template == ',') return COMMA_SY;
		else if (chracter_template == '(') return LEFTPAR_SY;
		else if (chracter_template == '+') return PLUS_SY;
		else if (chracter_template == '-') return MINUS_SY;
		else if (chracter_template == '*') return STAR_SY;
		else if (chracter_template == '/') return DIVSION_SY;
		else if (chracter_template == ')') return RIGHTPAR_SY;
		else if (chracter_template == '=') return EQUAL_SY;
		else if (chracter_template == '<') {
			file.get(chracter_template);
			if (chracter_template == '=') return LESSTHANOREQUAL_SY;
			else if (chracter_template == '>') return NOTEQUAL_SY;
			else file.putback(chracter_template);
			return LESSTHAN_SY;
		}
		else if (chracter_template == '>') {
			file.get(chracter_template);
			if (chracter_template == '=') return GREATERTHANOREQUAL_SY;
			else file.putback(chracter_template);
			return GREATERTHAN_SY;
		}
		else return ERROR_SY;
	}

	token analyser() {
		file.get(chracter_template);
		while (isspace(chracter_template) && !file.eof())
		{
			file.get(chracter_template);
		}
		if (file.eof()) return EOF_SY;
		if (isalpha(chracter_template)) {
			check_reserved();
		}
		else if (isdigit(chracter_template)) {
			get_number();
		}
		else {
			get_special_char();
		}
	}

public:
	Scanner(string path) {
		file.open(path);
	}

	~Scanner(){
		file.close();
	}

	void analyse() {
		token result = analyser();
		while (result != EOF_SY) {
			switch (result)
			{
			case PROGRAM_SY:
				display_result(result, token_template);
				break;
			case IS_SY:
				display_result(result, token_template);
				break;
			case BEGIN_SY:
				display_result(result, token_template);
				break;
			case ID_SY:
				display_result(result, token_template);
				break;
			case END_SY:
				display_result(result, token_template);
				break;
			case VAR_SY:
				display_result(result, token_template);
				break;
			case INTEGER_SY:
				display_result(result, token_template);
				break;
			case BOOLEAN_SY:
				display_result(result, token_template);
				break;
			case COLOMN_SY:
				display_result(result, token_template);
				break;
			case COMMA_SY:
				display_result(result, token_template);
				break;
			case SEMICOLON_SY:
				display_result(result, token_template);
				break;
			case ASSIGNMENT_SY:
				display_result(result, token_template);
				break;
			case READ_SY:
				display_result(result, token_template);
				break;
			case WRITE_SY:
				display_result(result, token_template);
				break;
			case IF_SY:
				display_result(result, token_template);
				break;
			case THEN_SY:
				display_result(result, token_template);
				break;
			case ELSE_SY:
				display_result(result, token_template);
				break;
			case WHILE_SY:
				display_result(result, token_template);
				break;
			case DO_SY:
				display_result(result, token_template);
				break;
			case LEFTPAR_SY:
				display_result(result, token_template);
				break;
			case RIGHTPAR_SY:
				display_result(result, token_template);
				break;
			case MINUS_SY:
				display_result(result, token_template);
				break;
			case OR_SY:
				display_result(result, token_template);
				break;
			case AND_SY:
				display_result(result, token_template);
				break;
			case TRUE_SY:
				display_result(result, token_template);
				break;
			case FALSE_SY:
				display_result(result, token_template);
				break;
			case NOT_SY:
				display_result(result, token_template);
				break;
			case LESSTHAN_SY:
				display_result(result, token_template);
				break;
			case GREATERTHAN_SY:
				display_result(result, token_template);
				break;
			case EQUAL_SY:
				display_result(result, token_template);
				break;
			case GREATERTHANOREQUAL_SY:
				display_result(result, token_template);
				break;
			case LESSTHANOREQUAL_SY:
				display_result(result, token_template);
				break;
			case NOTEQUAL_SY:
				display_result(result, token_template);
				break;
			case PLUS_SY:
				display_result(result, token_template);
				break;
			case STAR_SY:
				display_result(result, token_template);
				break;
			case DIVSION_SY:
				display_result(result, token_template);
				break;
			case NUMERAL_SY:
				display_result(result, token_template);
				break;
			case ERROR_SY:
				display_result(result, token_template);
				break;
			case EOF_SY:
				display_result(result, token_template);
				break;
			default:
				//file.get(chracter_template);
				
				break;
			}
			result = analyser();
		}
	}
	void display_result(token t, string value) {
		cout << "the token " << value << " : number " << t << endl;
		token_template = "";
	}
};
void main() {
	// Add your file path
	Scanner sc("your file path");
	sc.analyse();

	system("pause");
}