class Solution {
    
public:
    vector<string> split(string str, string pattern)
    {
        int pos;
        vector<string> result;
        str+=pattern;
        int size = str.size();
        
        for(int i = 0; i<size; i++)
        {
            pos=str.find(pattern,i);
            if(pos < size)
            {
                string s=str.substr(i,pos-i);
                result.push_back(s);
                i=pos+pattern.size()-1;
            }
        }
        return result;
    }
    
    bool wordPattern(string pattern, string str) {
        if(pattern.length() < 1 || str.length() < 1)
            return false;
        
        bool res = true;
        map<char,int> mpPattern;
        map<string,int> mpStr;
        vector<string> animal = split(str," ");
        
        if(pattern.length() != animal.size())
            return false;
        
        for(int i = 0; i < pattern.length(); i++)
        {
            mpPattern[pattern[i]]=i;
            mpStr[animal[i]]=i;
        }
        
        for(int i = 0; i < pattern.length(); i++)
        {
            if(mpPattern[pattern[i]] != mpStr[animal[i]])
            {
                res = false;
                break;
            }
        }
        
        return res;
    }
};