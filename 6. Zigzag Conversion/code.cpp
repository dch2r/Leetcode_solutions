class Solution {
public:
    string convert(string s, int numRows) {
        string result = "";
        if(numRows==1)
           return s;

        int s1,s2;
        int len=s.size();
        for(int i=0;i<numRows;++i){
            s1=(numRows-i-1)*2;
            s2=(i)*2;
            int pos=i;
            if(pos<len)
               result+=s.at(pos);
            while(1){
                pos+=s1;
                if(pos>=len)
                   break;
        if(s1)
            result+=s.at(pos);
                pos+=s2;
                if(pos>=len)
                    break;
        if(s2) 
            result+=s.at(pos);           
            }
              
        }
        return result;
        
    }
};
