#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

const char *input_stream;
int current_index = 0;

void advance() {
    current_index++;
}

char peek() {
    return input_stream[current_index];
}

int parse_expression();

int parse_factor() {
    char c = peek();
    if (isdigit(c)) {
        advance();
        return c - '0';
    }
    printf("Syntax Error: unexpected character '%c'\n", c);
    exit(1);
}

int parse_term() {
    int result = parse_factor();
    while (peek() == '*' || peek() == '/') {
        char op = peek();
        advance();
        int next = parse_factor();
        if (op == '*') result *= next;
        else result /= next;
    }
    return result;
}

int parse_expression() {
    int result = parse_term();
    while (peek() == '+' || peek() == '-') {
        char op = peek();
        advance();
        int next = parse_term();
        if (op == '+') result += next;
        else result -= next;
    }
    return result;
}

int main() {
    input_stream = "3+5*2";
    printf("Parsing arithmetic expression: %s\n", input_stream);
    int result = parse_expression();
    printf("Result: %d\n", result);
    return 0;
}
