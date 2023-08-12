class Codec {
public:

    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
        string s = "";

        for (int i = 0; i < strs.size(); i++) {
            s += to_string(strs[i].size()) + "/" + strs[i];
        }
        cout << s;
        return s;
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        vector<string> strs;
        int i = 0;
        while (i < s.length()) {
            int index = s.find('/', i);
            int size = stoi(s.substr(i, index - i));
            strs.push_back(s.substr(index + 1, size));
            i = index + 1 + size;
        }
        return strs;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(strs));