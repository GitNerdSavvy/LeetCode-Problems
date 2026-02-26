class Solution {
public:
    // string addBinary(const string& a, const string& b) {
    //     int i = a.size() - 1;
    //     int j = b.size() - 1;
    //     int carry = 0;
    //     string res;

    //     while (i >= 0 || j >= 0 || carry) {
    //         int sum = carry;

    //         if (i >= 0) sum += a[i--] - '0';
    //         if (j >= 0) sum += b[j--] - '0';

    //         res.push_back(char('0' + (sum % 2)));
    //         carry = sum / 2;
    //     }

    //     reverse(res.begin(), res.end());
    //     return res;
    // }
    //     int numSteps(string s) {
    //         int steps=0;
    //         int i=s.length()-1;
    //         while(i>0){
    //             if(s[i]=='0'){
    //                 steps++;
    //                 i--;
    //             }else{
    //                 steps++;
    //                 addBinary(s.substr(0,i), "1");
    //             }
    //         }
    //         return steps;
    //     }

    int numSteps(string s) {
        int steps = 0;
        int carry = 0;

        for (int i = s.size() - 1; i > 0; --i) {
            int bit = (s[i] - '0') + carry;

            if (bit % 2 == 0) {
                steps += 1;
            } else {
                steps += 2;
                carry = 1;
            }
        }

        return steps + carry;
    }
};