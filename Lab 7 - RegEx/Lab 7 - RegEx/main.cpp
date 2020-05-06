#include <iostream>

#include "functions.hpp"

int main()
{
	std::string login1("SuperKoksu420");
	std::cout << login1 << " result: " << isLoginValid(login1) << std::endl;

	std::string login2("the_best_gamer");
	std::cout << login2 << " result: " << isLoginValid(login2) << std::endl;

	std::string login3(";DROP TABLE USERS;");
	std::cout << login3 << " result: " << isLoginValid(login3) << std::endl;

	std::string login4("Rick&Morty");
	std::cout << login4 << " result: " << isLoginValid(login4) << std::endl;

	std::string login5("ilikegames");
	std::cout << login5 << " result: " << isLoginValid(login5) << std::endl << std::endl;

	//---------------------------------------------------------------------------------------------//
	
	std::string email1("adamsmith@gmail.com");
	std::cout << email1 << " result: " << isEmailValid(email1) << std::endl;

	std::string email2("Adam-Smith@ex1am_ple.pl");
	std::cout << email2 << " result: " << isEmailValid(email2) << std::endl;

	std::string email3("-Adam-Smith@example.eu");
	std::cout << email3 << " result: " << isEmailValid(email3) << std::endl;

	std::string email4("ThePresident45@mail.gov.com");
	std::cout << email4 << " result: " << isEmailValid(email4) << std::endl;

	std::string email5("_lol_mail@lolmail.gov.com");
	std::cout << email5 << " result: " << isEmailValid(email5) << std::endl;

	//---------------------------------------------------------------------------------------------//

	std::string sentence1("A kiwi tastes like a kiwi - kiwilicious!");
	std::regex checkSenetence1("kiwi[^\\S]");
	showMatches(sentence1, checkSenetence1);

	std::string sentence2("How much wood would a woodchuck chuck if a woodchuck could chuck wood? Would Woodie who chucked that driftwood know?");
	std::regex checkSenetence2("([a-zA-Z]*[wW]ood[a-zA-Z]*)|([a-zA-Z]*[cC]huck[a-zA-Z]*)");
	showMatches(sentence2, checkSenetence2);

	//---------------------------------------------------------------------------------------------//

	std::string uglyString = "To be     fair, you have    to have a\n\n very high     IQ to understand   Rick and Morty.\n\n\nAnd    yes, by   the way, I\n DO have a Rick & Morty tattoo.";
	std::string prettyString;

	prettyString = std::regex_replace(uglyString, std::regex("(\\\n){2,}"), "\n");			// nadmiarowe nowe linie
	prettyString = std::regex_replace(prettyString, std::regex("( ){2,}"), " ");			// nadmiarowe spacje
	prettyString = std::regex_replace(prettyString, std::regex("( a\\n)"), " \na");			// przerzucenie do nowej lini 'a'
	prettyString = std::regex_replace(prettyString, std::regex("( I\\n)"), " \nI");			// przerzucenie do nowej lini 'I'

	std::cout << uglyString << std::endl << std::endl;
	std::cout << prettyString << std::endl << std::endl;

	//---------------------------------------------------------------------------------------------//

	std::string before = "You are a f***ing m********ker";
	std::string after = std::regex_replace(before, std::regex("[a-zA-Z]\\*+ing"), "quacking");
	after = std::regex_replace(after, std::regex("[a-zA-Z]\\*+[a-z]*"), "duck");

	std::cout << "String before: " << before << "\nString after: " << after;

	std::getchar();
	return 0;
}