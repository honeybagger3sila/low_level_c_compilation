#include <stdio.h>
#include <ctype.h>
#include <string.h>

typedef enum {
    TOKEN_KEYWORD,
    TOKEN_IDENTIFIER,
    TOKEN_NUMBER,
    TOKEN_OPERATOR,
    TOKEN_UNKNOWN,
    TOKEN_EOF
} TokenType;

void print_token(TokenType type, const char *lexeme) {
    const char *type_names[] = {"KEYWORD", "IDENTIFIER", "NUMBER", "OPERATOR", "UNKNOWN", "EOF"};
    printf("Token: [%s] -> Lexeme: %s\n", type_names[type], lexeme);
}

int is_keyword(const char *str) {
    return strcmp(str, "int") == 0 || strcmp(str, "float") == 0 || strcmp(str, "if") == 0;
}

void analyze_lexer(const char *src) {
    int i = 0;
    while (src[i] != '\0') {
        if (isspace(src[i])) {
            i++;
            continue;
        }
        if (isalpha(src[i])) {
            char buffer[32];
            int idx = 0;
            while (isalnum(src[i]) && idx < 31) {
                buffer[idx++] = src[i++];
            }
            buffer[idx] = '\0';
            if (is_keyword(buffer)) {
                print_token(TOKEN_KEYWORD, buffer);
            } else {
                print_token(TOKEN_IDENTIFIER, buffer);
            }
            continue;
        }
        if (isdigit(src[i])) {
            char buffer[32];
            int idx = 0;
            while (isdigit(src[i]) && idx < 31) {
                buffer[idx++] = src[i++];
            }
            buffer[idx] = '\0';
            print_token(TOKEN_NUMBER, buffer);
            continue;
        }
        if (src[i] == '+' || src[i] == '-' || src[i] == '=' || src[i] == ';') {
            char buffer[2] = {src[i], '\0'};
            print_token(TOKEN_OPERATOR, buffer);
            i++;
            continue;
        }
        i++;
    }
}

int main() {
    const char *source_code = "int x = 42 + 10;";
    printf("Lexical Analysis for source: %s\n", source_code);
    analyze_lexer(source_code);
    return 0;
}
