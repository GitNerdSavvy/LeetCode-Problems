class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& snd) {
        queue<int>q;
        for(int i=0;i<students.size();i++){
            q.push(students[i]);
        }
        stack<int>st;
        for(int i=snd.size()-1;i>=0;i--){
            st.push(snd[i]);
        }

        int count = 0;
        while(!q.empty() && count < q.size()) {
            if(q.front() == st.top()) {
                q.pop();
                st.pop();
                count = 0;
            } else {
                q.push(q.front());
                q.pop();
                count++;
            }
        }
        return q.size();
    }
};