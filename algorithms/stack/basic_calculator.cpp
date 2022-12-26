// https://leetcode.com/problems/basic-calculator/

class Solution
{
	public:

		int calculate(string s)
		{
			stack<char> opS;
			stack<int> numS;
			s = '(' + s + ')';

			int i, curNum = 0, len = s.size();
			for (i = 0; i < len; ++i)
			{
				if (s[i] == ' ')
					continue;
				else if (isdigit(s[i])) curNum = curNum *10 + (s[i] - '0');

				else if (s[i] == '(')
				{
					opS.push('(');
					opS.push('+');
				}
				else if (s[i] == ')')
				{
					while (!opS.empty() && (opS.top() == '*' || opS.top() == '/'))
					{
						curNum = opS.top() == '/' ? numS.top() / curNum : numS.top() *curNum;
						opS.pop();
						numS.pop();
					}

					if ('-' == opS.top()) curNum = -curNum;
					opS.pop();
					while (opS.top() != '(')
					{
						curNum += (opS.top() == '-') ? -numS.top() : numS.top();
						opS.pop();
						numS.pop();
					}

					opS.pop();
				}
				else
				{
					while (!opS.empty() && (opS.top() == '*' || opS.top() == '/'))
					{
						curNum = opS.top() == '/' ? numS.top() / curNum : numS.top() *curNum;
						opS.pop();
						numS.pop();

					}

					opS.push(s[i]);
					numS.push(curNum);
					curNum = 0;
				}
			}

			return curNum;
		}
};
