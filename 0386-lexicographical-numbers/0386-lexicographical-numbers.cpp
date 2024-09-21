class Solution {
public:
    static bool customComparator(string& string1, string& string2) {
        int index1 = 0, index2 = 0;

        // return true/false on comparaing the index of string
        while (index1 < string1.size() && index2 < string2.size()) {
            if (string1[index1] != string2[index2]) {
                return string1[index1] < string2[index2];
            }
            index1++;
            index2++;
        }
        return index1 == string1.size() ? true : false;
    }

    vector<int> lexicalOrder(int n) {
        vector<int> answer;
        vector<string> toCheckString;

        // Converting the number into the string
        for (int index = 1; index <= n; index++) {
            string convertedString = to_string(index);
            toCheckString.push_back(convertedString);
        }

        // sorting the vector of string using customComparator(By index comparing)
        sort(toCheckString.begin(), toCheckString.end(), customComparator);

        // converting the vector of string into number and storing into answer
        for (int index = 0; index < toCheckString.size(); index++) {
            int convertedNumber = stoi(toCheckString[index]);
            answer.push_back(convertedNumber);
        }
        
        return answer;
    }
};