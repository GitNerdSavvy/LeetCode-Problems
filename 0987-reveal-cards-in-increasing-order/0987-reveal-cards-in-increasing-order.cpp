class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        int n=deck.size();
        sort(deck.begin(),deck.end());
        queue<int>q;
        for(int i=0;i<deck.size();i++){
            q.push(i);
        }
        vector<int>res(n);
       for(int i=0;i<n;i++){
            int id=q.front();
            q.pop();
            q.push(q.front());
            q.pop();
            res[id]=deck[i];
        }
        return res;
    }
};