#include<iostream>
#include<string.h>
#include<fstream>
#include<list>
#include "Lexer.h"

using namespace std;






struct SymbolicToken;
struct Lexem;



struct LexemTable;

static SymbolicTokenClass transliterator(char ch)
{
    if ((ch >= 192 && ch <= 255)) { return Alpha; }
    else if (isalpha(ch)) { return Alpha; }
    else if (isdigit(ch)) { return Digit; }
    else if (ch == '+' || ch == '-' || ch == '/' || ch == '%' || ch == '*') { return AR_OP; }
    else if (ch == '>' || ch == '<' || ch == '=' || ch == '!') { return Bool; }
    else if (ch == '(') { return LB; }
    else if (ch == ')') { return RB; }
    else if (ch == ' ') { return Space; }
    else if (ch == '\n') { return LF; }
    else if (ch == ',') { return Comma; }
    else if (ch == ';') { return Sem; }
    else if (ch == ':') { return Colon; }
    else if (ch == EOF) { return EndOF; }
    else { return Error1; }
}








    Parser::Parser()
    {

        for (int i = 0; i < state_number; i++)
        {
            for (int j = 0; j < class_number; j++)
            {
                table[i][j] = &Parser::Error;
            }
        }

        table[A1][Alpha] = &Parser::b1a;
        table[B1][Alpha] = &Parser::m1;
        table[E1][Alpha] = &Parser::v1a;
        table[I1][Alpha] = &Parser::v1a;
        table[I2][Alpha] = &Parser::i2;
        table[V1][Alpha] = &Parser::v1a;
        table[A1][Digit] = &Parser::c1a;
        table[B1][Digit] = &Parser::v1a;
        table[C1][Digit] = &Parser::c1a;
        table[I2][Digit] = &Parser::i2;
        table[V1][Digit] = &Parser::v1a;
        table[A1][AR_OP] = &Parser::a1b;
        table[I2][AR_OP] = &Parser::i2;
        table[A1][Bool] = &Parser::b2a;
        table[B2][Bool] = &Parser::m2b;
        table[I2][Bool] = &Parser::i2;
        table[A1][Space] = &Parser::a1;
        table[B1][Space] = &Parser::a1a;
        table[B2][Space] = &Parser::m2a;
        table[C1][Space] = &Parser::a1con;
        table[E1][Space] = &Parser::a1tk;
        table[I1][Space] = &Parser::i2a;
        table[I2][Space] = &Parser::i2;
        table[V1][Space] = &Parser::a1a;
        table[B1][Comma] = &Parser::a1cm;
        table[C1][Comma] = &Parser::a1cm;
        table[I2][Comma] = &Parser::i2;
        table[V1][Comma] = &Parser::a1cm;
        table[A1][Sem] = &Parser::a1h;
        table[I2][Sem] = &Parser::i2;
        table[A1][LF] = &Parser::a1;
        table[C1][LF] = &Parser::a1con;
        table[E1][LF] = &Parser::a1tk;
        table[I2][LF] = &Parser::a1;
        table[V1][LF] = &Parser::a1a;
        table[A1][EndOF] = &Parser::Exit;
        table[E1][EndOF] = &Parser::a1tk;
        table[I2][EndOF] = &Parser::Exit;
        table[A1][LB] = &Parser::a1k;
        table[I2][LB] = &Parser::i2;
        table[A1][RB] = &Parser::a1l;
        table[I2][RB] = &Parser::i2;
        table[C1][Colon] = &Parser::a1colon;

    }

    void Parser:: parse(std::string filename)
    {
        ifstream in(filename);
        if (!in)
        {
            cout << "Не удалось открыть файл " << filename << endl;
            return;
        }

        int state = A1;   // Текущее состояние автомата.
        while (state != s_Stop && state != EndOF)
        {
            // s_Stop - техническое состояние. Когда автомат попадает в s_Stop, цикл останавливается.
            s.ch =tolower(in.get());

            s.token_class_ = transliterator(s.ch);
            state = (this->*table[state][s.token_class_])();
        }

        in.close();
    }




