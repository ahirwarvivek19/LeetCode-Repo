class Solution {
public:
    bool isValid(string s) {
        stack<char> st;

        for (int i = 0; s[i] != '\0'; i++)
        {
            if (s[i] == '(' || s[i] == '[' || s[i] == '{')
            {
                st.push(s[i]);
            }
            else if (s[i] == '}')
            {
                if (st.size() != 0)
                {
                    char a = st.top();
                    st.pop();
                    if (a != '{')
                    {
                        return false;
                    }
                }
                else
                {
                    return false;
                }
            }
            else if (s[i] == ']')
            {
                if (st.size() != 0)
                {
                    char a = st.top();
                    st.pop();
                    if (a != '[')
                    {
                        return false;
                    }
                }
                else
                {
                    return false;
                }
            }
            else if (s[i] == ')')
            {
                if (st.size() != 0)
                {
                    char a = st.top();
                    st.pop();
                    if (a != '(')
                    {
                        return false;
                    }
                }
                else
                {
                    return false;
                }
            }
        }
        if (st.size() == 0)
        {
            return true;
        }
        return false;
    }
};