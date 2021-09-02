#include <iostream>
#include "Synt.h"
#include "Adaptor.h"
#include "Lexer.h"

using namespace std;

int main() {
	Parser l;
	l.parse("1.txt");
	auto a = Adaptor(l.lt.lexems);
	auto s = Synt();
	s.Start(a.l);
}