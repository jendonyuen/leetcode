class Solution {
public:
    bool isValid(string s) {
        //unsigned small = 0 ,middle = 0, large=0;   //small,middle,large
        vector<int> v ={};
        for(auto a1: s){
            switch(a1){
                case '(':
                    v.push_back(0);
                    break;
                case '[':
                    v.push_back(1);
                    break;
                case '{':
                    v.push_back(2);
                    break;
                case ')':
                    if(!v.empty() && v.back()==0){
                        v.pop_back();
                        break;
                    }else{
                        return false;
                    }
                case ']':
                    if(!v.empty() && v.back()==1){
                        v.pop_back();
                        break;
                    }else{
                        return false;
                    }
                case '}':
                    if(!v.empty() && v.back()==2){
                        v.pop_back();
                        break;
                    }else{
                        return false;
                    }
                default:
                    break;
            }
        }
        if(!v.empty()){return false;}
        return true;
    }
};