class Solution {
public:
    int pr(char ch) {
        if (ch == '+' || ch == '-')
            return 1;
        if (ch == '*' || ch == '/')
            return 2;
        return 0;
    }

    long long solve(long long a, long long b, char op) {
        if (op == '+')
            return a + b;
        if (op == '-')
            return a - b;
        if (op == '*')
            return a * b;
        if (op == '/')
            return a / b;
        return 0;
    }

    bool isUnaryMinus(string& s, int i) {
        int j = i - 1;
        while (j >= 0 && isspace(s[j]))
            j--;
        if (j < 0)
            return true;
        if (s[j] == '(' || s[j] == '+' || s[j] == '-' || s[j] == '*' ||
            s[j] == '/')
            return true;
        return false;
    }

    int calculate(string s) {
        stack<long long> val;
        stack<char> op;

        for (int i = 0; i < s.length(); i++) {
            if (isspace(s[i]))
                continue;

            if (s[i] == '-' && isUnaryMinus(s, i)) {
                int j = i + 1;
                while (j < s.length() && isspace(s[j]))
                    j++;

                if (j < s.length() && isdigit(s[j])) {
                    i = j;
                    long long num = 0;
                    while (i < s.length() && isdigit(s[i])) {
                        num = num * 10 + (s[i] - '0');
                        i++;
                    }
                    val.push(-num);
                    i--;
                } else {
                    val.push(0);
                    op.push('-');
                }
            } else if (isdigit(s[i])) {
                long long num = 0;
                while (i < s.length() && isdigit(s[i])) {
                    num = num * 10 + (s[i] - '0');
                    i++;
                }
                val.push(num);
                i--;
            } else if (s[i] == '(') {
                op.push('(');
            } else if (s[i] == ')') {
                while (!op.empty() && op.top() != '(') {
                    long long b = val.top();
                    val.pop();
                    long long a = val.top();
                    val.pop();
                    char ch = op.top();
                    op.pop();
                    val.push(solve(a, b, ch));
                }
                op.pop();
            } else {
                while (!op.empty() && pr(op.top()) >= pr(s[i])) {
                    long long b = val.top();
                    val.pop();
                    long long a = val.top();
                    val.pop();
                    char ch = op.top();
                    op.pop();
                    val.push(solve(a, b, ch));
                }
                op.push(s[i]);
            }
        }

        while (!op.empty()) {
            long long b = val.top();
            val.pop();
            long long a = val.top();
            val.pop();
            char ch = op.top();
            op.pop();
            val.push(solve(a, b, ch));
        }

        return (int)val.top();
    }
};
