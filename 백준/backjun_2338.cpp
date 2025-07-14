// 이 지랄 하지말고 파이썬으로 할것.
// 버그와 환장할 디버깅으로 인해 명예의 전당 ㄱㄱ

#include <iostream>
#include <algorithm>

using namespace std;

class BigInt{
    private : 
        typedef struct bigNum{
            bool isMinus;
            string num, rev;
            int len;

            bigNum(string x){
                if(x[0] == '-'){
                    isMinus = true;
                    num = x.substr(1);
                    len = num.length();
                }
                else{
                    isMinus = false;
                    num = x;
                    len = num.length();
                }
                rev = num;
                reverse(begin(rev),end(rev));
            }
        }bigNum;

        bigNum a,b;
        bool isSwap = false;

    public :
        BigInt(string x, string y) : a(x), b(y) {
            if(a.len < b.len || (a.len == b.len && a.num < b.num)){
                swap(a,b);
                isSwap = true;
            } 
        }
        string bigAdd();
        string bigSub();
        string bigMul();
        
        string add(string x, string y);
        string sub(string x, string y);
        string mul(string x, int y);
        
        void remove0padding(string & x);
};

string BigInt::add(string x, string y){
    string ans = "";

    if(x.length() < y.length()) 
        swap(x,y);

    int xlen = x.length(), ylen = y.length();
    for(int i = ylen; i < xlen; ++i){
        y+= '0';
    }

    int carry = 0;
    for(int i = 0; i < xlen; ++i){
        int t = x[i] -'0', z = y[i] -'0';
        int r = t + z + carry;
        carry = r/10;
        r %= 10;
        ans += r + '0';
    }

    if(carry) ans += '1';

    return ans;
}

void BigInt::remove0padding(string & x){
    int pos = 0, len = x.length();
    for(; pos < len; ++pos)
        if(x[pos] != '0') break;

    if(pos==len) x = "0";
    else x = x.substr(pos);
}

string BigInt::bigAdd(){
    string ans = "";

    if(a.isMinus == b.isMinus){
        ans = add(a.rev,b.rev);

        reverse(begin(ans),end(ans));
        remove0padding(ans);


        if(a.isMinus == true && ans!="0")
            ans = '-' + ans;
        return ans;
    }

    string nine_complemnt = "";
    for(int i = 0; i < a.len; ++i)
        nine_complemnt += '0' + ('9' - a.rev[i]);

    string tmp = add(nine_complemnt, b.rev);

    for(int i = 0; i < tmp.length(); ++i){
        ans+='0'+('9'- tmp[i]);
    }

    reverse(begin(ans),end(ans));
    remove0padding(ans);

    if(ans == "0") return ans;

    if(a.isMinus == true)
        ans = '-' + ans;

    return ans;
}

string BigInt::bigSub(){
    b.isMinus = !b.isMinus;
    string ans = bigAdd();
    b.isMinus = !b.isMinus;

    if(ans == "0") return "0";

    if(isSwap == true){
        if(ans[0] == '-') return ans.substr(1);
        return '-' + ans;
    }

    return ans;
}

string BigInt::mul(string x, int y){
    string ans = "";
    int carry = 0;

    for(int i = 0; i < x.length(); ++i){
        int tmp = (x[i] - '0') * y + carry;
        ans += '0' + (tmp % 10); 
        carry = tmp / 10;
    }

    if(carry > 0) ans += '0' + carry;

    return ans;
}


string BigInt::bigMul(){
    if(a.num == "0" || b.num == "0")
        return "0";

    string ans = "";
    
    for(int i = 0; i < b.len; ++i){
        if(b.rev[i] == '0') continue;
        string zero = "";

        for(int j = 0; j < i; ++j)
            zero += '0';
        
        string tmp = mul(a.rev, b.rev[i] -'0');
        tmp = zero + tmp;
        ans = add(tmp, ans);
    }

    reverse(begin(ans),end(ans));
    remove0padding(ans);

    if((a.isMinus != b.isMinus) && ans != "0") ans = '-' + ans;
    return ans;
}

int main(){
    string a, b;
    cin >> a >> b;

    if(b=="0") {
        cout << a << "\n";
        cout << a << "\n";
        cout << "0\n";
        return 0;
    }

    if(a=="0"){
        cout << b << "\n";
        cout << (b[0]=='-'?b.substr(1):'-'+b) << "\n";
        cout << "0\n";
        return 0;
    }

    BigInt myInt(a,b);

    cout << myInt.bigAdd() << '\n';
    cout << myInt.bigSub() << '\n';
    cout << myInt.bigMul() << '\n';
    return 0;
}