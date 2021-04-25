#include <iostream>
#include <string>
#include <regex>
#include <iterator>

/*
	Regular Expressions tester
*/

// My template
template <typename T>
void GetUserInput(T *input, std::string ask) {
	std::cout << ask << std::endl;
	std::getline(std::cin, *input);
}

int main()
{
	std::string
		input_string,
		input_regex
	;

	GetUserInput<std::string>(&input_string, "Input your string that you wish to test the RegEx against:");
	GetUserInput<std::string>(&input_regex, "Input your RegEx that the string will be tested against:");

	// Missing RegEx validation :|

	std::regex our_regex(input_regex);
	std::smatch regex_matches;

	// If failed to match the string, or RegEx was invalid!
	if (!std::regex_match(input_string, regex_matches, our_regex)) {
		std::cout << "Failed to match the string!" << std::endl;
		return 1;
	}

	// Successfully matched input
	std::cout << "Your input:" << input_string << std::endl;
	
	for (std::smatch::iterator i = regex_matches.begin(); i < regex_matches.end(); ++ i) {
		std::ssub_match sub_match = *i;
		std::string match_string = sub_match.str();
		std::cout << " submatch " << *i << " : " << match_string << std::endl;
	}

	// No problem occurred
	return 0;
}
