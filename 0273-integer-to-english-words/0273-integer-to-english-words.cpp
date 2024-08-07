class Solution {
public:
    string numberToEnglish(char ch){
        switch(ch){
            case '1':return "One";
            case '2':return "Two";
            case '3':return "Three";
            case '4':return "Four";
            case '5':return "Five";
            case '6':return "Six";
            case '7':return "Seven";
            case '8':return "Eight";
            case '9':return "Nine";
        }
        return "";
    }
    string tenConversion(char ch){
        switch(ch){
            case '2':return "Twenty";
            case '3':return "Thirty";
            case '4':return "Forty";
            case '5':return "Fifty";
            case '6':return "Sixty";
            case '7':return "Seventy";
            case '8':return "Eighty";
            case '9':return "Ninety";
        }
        return "";
    }
    string specialConvert(char ch){
        switch(ch){
            case '0':return "Ten";
            case '1':return "Eleven";
            case '2':return "Twelve";
            case '3':return "Thirteen";
            case '4':return "Fourteen";
            case '5':return "Fifteen";
            case '6':return "Sixteen";
            case '7':return "Seventeen";
            case '8':return "Eighteen";
            case '9':return "Nineteen";
        }
        return "";
    }
    string convert(string str){
        string ans="";
        if(str[0]>='1' && str[0]<='9'){
            ans+=numberToEnglish(str[0]);
            ans+= " Hundred";
        }
        if(str[1]>='2' && str[1]<='9'){
            if(ans.size()>0)
                ans+=' ';
            ans+=tenConversion(str[1]);
        }
        if(str[1]=='1'){
            if(ans.size()>0)
                ans+=' ';
            ans+=specialConvert(str[2]);
        }
        else if(str[2]!='0'){
            if(ans.size()>0)
                ans+=' ';
            ans+=numberToEnglish(str[2]);
        }
        return ans;
    }
    string numberToWords(int num) {
        ios::sync_with_stdio(false);
        cin.tie(0);
        if(num==0)
            return "Zero";
        string ans="";
        string temp = to_string(num);
        vector<string> store;
        int n = temp.size();
        for(int i=n-1;i>=0;i-=3){
            string evaluate = "";
            if(i-2>=0){
                evaluate = temp.substr(i-2,3);
                evaluate = convert(evaluate);
                store.push_back(evaluate);
            }
            else{
                evaluate = temp.substr(0,n%3);
                if(n%3==1)
                    evaluate = "00" + evaluate;
                else
                    evaluate = '0' + evaluate;
                evaluate = convert(evaluate);
                store.push_back(evaluate);
            }
        }
        for(int i=store.size()-1;i>=0;i--){
            if(store[i]!=""){
                if(ans.size()>0)
                    ans+=' ';
                ans+=store[i];
                if(i==3)
                    ans+=" Billion";
                else if(i==2)
                    ans+=" Million";
                else if(i==1)
                    ans+=" Thousand";
            }
        }
        return ans;
        //Please upvote if you like the solution
    }

};