class Solution {
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        vector<int> result(n, 0);
        stack<int> st;
        int prevTime = 0;

        for (string log : logs) {
            int id;
            string type;
            int time;

            // Parse log
            int pos1 = log.find(":");
            int pos2 = log.find(":", pos1 + 1);
            id = stoi(log.substr(0, pos1));
            type = log.substr(pos1 + 1, pos2 - pos1 - 1);
            time = stoi(log.substr(pos2 + 1));

            if (type == "start") {
                if (!st.empty())
                    result[st.top()] += time - prevTime;
                st.push(id);
                prevTime = time;
            } else {
                result[st.top()] += time - prevTime + 1;
                st.pop();
                prevTime = time + 1;
            }
        }
        return result;
    }
};