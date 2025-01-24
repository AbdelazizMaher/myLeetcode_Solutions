class Solution {
public:
    int evalRPN(vector<string>& tokens) {
       stack<int> rpn{};

        for (auto& token : tokens) {
            if (isOperator(token)) {
                int op2 = rpn.top();
                rpn.pop();
                int op1 = rpn.top();
                rpn.pop();

                rpn.push(evaluateExpr(token, op1, op2)); 
            } else {
                rpn.push(stoi(token));
            }
        }
        return rpn.top();
    }
    bool isOperator(const string& token) {
        return token == "+" || token == "-" || token == "*" || token == "/";
    }
    int evaluateExpr(const string& tokenOp, int op1, int op2 ) {
        switch(tokenOp[0]) {
            case '+':
                return op1 + op2;
            case '-':
                return op1 - op2;
            case '*':
                return op1 * op2;
            case '/':
                return op1 / op2;                                                
        }
        return 0;
    }
};