class Solution {
public:
    string reverseWords(string s) {
        string ans="";
        stack<string> st;
        string word="";

        for(int i=0;i<s.size();i++)
        {
           if(s[i]!=' ')
           {
              word+=s[i];
           }
           else if(!word.empty())
           {
              st.push(word);
              word="";
           }
        }
        if(!word.empty())
        {
            st.push(word);
        }
        while(!st.empty())
        {
            ans+= st.top();
            st.pop();
            if(st.size()>0)
            {
                ans+=" ";
            }
        }
        return ans;
    }
};
