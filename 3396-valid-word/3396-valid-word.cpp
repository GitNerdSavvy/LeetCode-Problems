class Solution {
public:
    bool cons(char ch) {
        if (ch == 'b' || ch == 'c' || ch == 'd' || ch == 'f' || ch == 'g' ||
            ch == 'h' || ch == 'j' || ch == 'k' || ch == 'l' || ch == 'm' ||
            ch == 'n' || ch == 'p' || ch == 'q' || ch == 'r' || ch == 's' ||
            ch == 't' || ch == 'v' || ch == 'w' || ch == 'x' || ch == 'y' ||
            ch == 'z' ) {
            return true;
        } else {
            return false;
        }
    }
    bool isValid(string w) {
        //    string word=tolower(w);
        // if (w.length() < 3)
        //     return false;
        int ans=0;
        bool let = false;
        bool v = false;
        bool c = false;
        for (auto s : w) {
            char it = (char)tolower(s);
            // A to Z
            
            if (it == 'a' || it == 'e' || it == 'i' || it == 'o' || it == 'u') {
                v = true;
                ans++;
            }

           else if (cons(it)) {
                c = true;
                ans++;
            }
            else if (it-'0'>=0 && it-'0'<=9){
                ans++;
            }   
                
                else{
                return false;
            }
        }
        return (v && c && ans>2);
    }
};