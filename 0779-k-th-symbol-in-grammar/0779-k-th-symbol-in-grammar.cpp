class Solution {
public:
    int kthGrammar(int n, int k) {

        if(n == 1) return 0;
        if( n == 2){

            if(k == 1) return 0;
            else return 1;
        }

        // for n >= 3

        int tn = n;
        bool rev = false;
        int tk = k;

        while( tn >=3 ){

            if( tk > pow(2 , tn-2)){

                tk = tk - pow(2 , tn-2);
                rev = !rev;
            }

            tn--;
        }

        if( tk == 1){

            if(!rev) return 0;
            else return 1;
        }

        else{

            if(!rev) return 1;
            else return 0;
        }
    
    }
};