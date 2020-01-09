class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string s = "";
        char temp;
        int n = -1;
        if(strs.size()>=2){     //如果容器元素数量大于等于2个
            unsigned sz = strs[0].size();
            for(auto a:strs){
                if(a.size()<sz){
                    sz = a.size();
                }
            }
            unsigned i =0;
            bool isBreak = false;
            if(sz!=0){
            while(isBreak == false){
                for(auto a1: strs){         //依次比较每个元素
                    temp = strs[0][i];
                    if(a1[i]!=temp){
                        n = i-1;
                        cout<<"#break"<<n<<endl;
                        isBreak = true;
                        break;
                    }else{
                        n = i;
                    }
                }
                if(i<sz-1){++i;}else{isBreak = true;}    //下一个元素
            }}
        }
        if(strs.size() == 1){
            n = strs[0].size()-1;
        }
        if(n!= -1){
            for (int i2 =0;i2<=n;++i2){
                s.push_back(strs[0][i2]);
            }
        }
        return s;
    }
};