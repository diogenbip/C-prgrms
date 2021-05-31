#include"Syntax.h"
#include<locale>
using namespace std;
int main()
{
	setlocale(LC_ALL, "");
	string name="test4.txt";
	string nameOut = "code.txt";
	ofstream outTS,outTL,outTO,outTA,outErrors;
	outTS.open("TS.txt");
	outTO.open("TO.txt");
	outTL.open("TL.txt");
	outTA.open("TA.txt");
	outErrors.open("Errors.txt");
	//cout << "ֲגוהטעו טלÿ פאיכא" << endl;
	//cin >> name;
	//LexAuto.showTO();
	//LexAuto.showLexemes();
	//LexAuto.TS.showNonEmptyFields();
	//LexAuto.showErrors();
	SyntAuto LexAuto;
	LexAuto.startsynt(name);
	LexAuto.showTA(outTA);
	LexAuto.showLexemes(outTL);
	LexAuto.showErrors(outErrors);
	LexAuto.showErrors(cout);
	LexAuto.showTO(outTO);
	outTS << LexAuto.TS;
	outTS.close();
	outTO.close();
	outTL.close();	
	outTA.close();
	outErrors.close();
	return 0;
}