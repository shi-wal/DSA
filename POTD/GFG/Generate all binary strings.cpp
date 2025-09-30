// Done myself in single run
class Solution {
    void generate(int i, int n, vector<string>& res, string str){
        if(i==n){
            res.push_back(str);
            return;
        }
        generate(i+1,n,res,str+"0");
        generate(i+1,n,res,str+"1");
    }
  public:
    vector<string> binstr(int n) {
        vector<string> res;
        string str="";
        generate(0,n,res,str);
        return res;
    }
};
