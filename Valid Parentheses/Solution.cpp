class Solution {
public:
    bool isValid(string s) {
		std::stack<char> Parentheses;
		size_t i = 0;

		while (i < s.size()) {
			if (s.at(i) == '(' || s.at(i) == '{' || s.at(i) == '[') {
				Parentheses.push(s.at(i));
			} else {
				if (Parentheses.empty()) {
					return false; 
				}
				if ((s.at(i) == ')' && Parentheses.top() == '(') ||
					(s.at(i) == '}' && Parentheses.top() == '{') ||
					(s.at(i) == ']' && Parentheses.top() == '[')) {
					Parentheses.pop();
				} else {
					return false; 
				}
			}
			i++;
		}

		return Parentheses.empty(); 
    }
};