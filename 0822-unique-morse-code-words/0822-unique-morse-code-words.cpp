class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        vector<string> a = {".-","-...","-.-.","-..",".","..-.","--.","....",
                  "..",".---","-.-",".-..","--","-.","---",".--.",
                  "--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};

  	unordered_set<string> ump;

  	for (auto it : words) {
  		string t;
  		for (auto c : it) t += a[c - 'a'];
  		ump.insert (t);
  	 }

  return ump.size ();
    }
};