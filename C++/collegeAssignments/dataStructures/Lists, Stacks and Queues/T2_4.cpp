// #4

#include <iostream>
#include <stack>
#include <string>

void main() {
	std::stack<char> stack;
	std::string str; std::cin >> str;

	for (int i = 0; i < str.size(); i++) {
		char current = str[i];

		if (stack.size()) {
			if (current == '[' && stack.top() == '(' ||
				current == '{' && stack.top() == '(' ||
				current == '{' && stack.top() == '[')
				break;
			else if (current == ')' && stack.top() == '(' ||
				current == ']' && stack.top() == '[' ||
				current == '}' && stack.top() == '{')
				stack.pop();
			else
				stack.push(current);
		}
		else
			stack.push(current);
	}

	if (stack.empty())
		std::cout << "Sirul este corect";
	else
		std::cout << "Sirul NU este corect";
}