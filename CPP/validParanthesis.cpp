#include<vector>
#include<map>
#include<algorithm>
#include<stack>
#include<string>
#include<iostream>

bool valid(std::string paren)
{
    std::map<char,char> match;
    std::stack<char> parenthesis;
    bool balanced;
    match.insert(std::make_pair('(',')'));
    match.insert(std::make_pair('{','}'));
    match.insert(std::make_pair('[',']'));
    for(char x:paren)
    {
        if(match.count(x))
        {
            parenthesis.push(x);
        }
        else if (x==')' || x=='}' || x== ']')
        {
            if(!parenthesis.empty())
                if(x==match[parenthesis.top()])
                    parenthesis.pop();
            else
            {
                balanced=false;
                return balanced;
            }
        }
    }
    balanced = parenthesis.empty();
    return balanced;
}

int main()
{
    std::vector<std::string> parens;
    parens.push_back("(]");
    parens.push_back("([)]");
    parens.push_back("{[]}");
    parens.push_back("])");
    parens.push_back("(){}}{");

    for(auto c:parens)
        std::cout<<c<<"\t";
    std::cout<<"\n";
    for(auto p: parens)
    {
        if(valid(p))
            std::cout<<p<<" is balanced\n";
        else
            std::cout<<p<<" is not balanced.\n";
    }
    return 0;
}