class Solution {
public:
   int pr(char ch)
    {
        if (ch == '+' || ch == '-')
            return 1;
        if (ch == '*' || ch == '/')
            return 2;
        return 0;
    }

    int solve(int a, int b, char op)
    {
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

    int calculate(string s)
    {
        stack<int> val;
        stack<char> op;
        for (int i = 0; i < s.length(); i++)
        {
            if(isspace(s[i])) continue;

            if(isdigit(s[i])) {
                int num = 0;
                while(i < s.length() && isdigit(s[i])) {
                    num = num * 10 + (s[i] - '0');
                    i++;
                }
                val.push(num);
                i--; 
        }
            else
            {
                while (!op.empty() && pr(op.top()) >= pr(s[i]))
                {
                    int b = val.top();
                    val.pop();
                    int a = val.top();
                    val.pop();
                    char ch = op.top();
                    op.pop();
                    val.push(solve(a, b, ch));
                    // cout<<val.top()<<" ";
                }
                op.push(s[i]);
                // cout<<op.top()<<" ";
            }
        }
        while (!op.empty())
        {
            int b = val.top(); val.pop();
            int a = val.top(); val.pop();
            char ch = op.top(); op.pop();
            val.push(solve(a, b, ch));
            // cout<<val.top()<<" ";
        }
        return val.top();
    }
};