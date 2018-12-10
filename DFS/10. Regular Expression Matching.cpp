
/*
   一开始题目看错，以为是字符串的模板匹配，没注意*是前面一个元素的重复，针对错误的理解，该方法利用DFS回溯的方法进行解答，当碰到字符或者 . 的时候
   往后运行，碰到*的时候有三种方式：
     1. *当空，直接跳过和下面一个进行匹配
     2.*当一个字符，和当前字符匹配后失效
     3.*当多个字符，和当前匹配完成后，继续和s下面的进行匹配

*/


class Solution {
public:
    
    
    void DFS(const string&s,const string&p,bool&find)
    {
        if(find) return;
        if(s==""&&(p=="*"||p=="")){find=true; return;}
        
        if(s=="" || p=="") return;
        
        int i=0;
        while((i<s.size()&&i<p.size())&&(p[i]=='.'||(p[i]>='a'&&p[i]<='z')))
        {
            if(s[i]!=p[i]) return;
            i++;
        }
        if(i==s.size()&&i==p.size()) {find=true;return;}
        if(i==s.size()||i==p.size()) return;
        
        DFS(s,p.substr(1),find);
        DFS(s.substr(1),p.substr(1),find);
        DFS(s.substr(1),p,find);
    }

    bool isMatch(string s, string p)
    {
        bool find=false;
        DFS(s,p,find);
        return find;
    }
    
};
