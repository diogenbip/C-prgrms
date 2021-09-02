#include<iostream>
#include<vector>
#include<list>
#include"Lexer.h"
#pragma once

class Adaptor {
public:
	std::vector<std::string> l;
	bool label;
	Adaptor();
	Adaptor(std::list<Lexem> p);
	std::string Check(LexemClass lc, std::string val);

};