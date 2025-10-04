class Solution {
    void findRes(vector<string>& res, string& s, int target, int pos, long curr,
    long prev,string expr){
        int n=s.length();
        if(pos==n){
            if(curr==target) res.push_back(expr);
            return;
        }
        for(int i=pos;i<n;i++){
            if(i!=pos && s[pos]=='0') break;
            string part=s.substr(pos,i-pos+1);
            long num=stol(part);
            if(pos==0){
                findRes(res,s,target,i+1,num,num,part);
            }
            else{
                findRes(res,s,target,i+1,curr+num,num,expr+"+"+part);
                findRes(res,s,target,i+1,curr-num,-num,expr+"-"+part);
                findRes(res,s,target,i+1,curr-prev+prev*num,prev*num,expr+"*"+part);
            }
        }
    }
  public:
    vector<string> findExpr(string &s, int target) {
        vector<string> res;
        findRes(res,s,target,0,0,0,"");
        return res;
    }
};
