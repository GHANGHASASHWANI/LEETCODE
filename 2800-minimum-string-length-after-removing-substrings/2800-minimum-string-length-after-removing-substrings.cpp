class Solution {
public:
    int minLength(string s) {
        stack< char > characters;

        for(int index = 0; index < s.size(); index++){
            if(characters.empty()){
                characters.push(s[index]);
            }else{
                char lastChar = characters.top();
                char currChar = s[index];
                if(lastChar == 'A' && currChar == 'B'){
                    characters.pop();
                }
                else if(lastChar == 'C' && currChar == 'D'){
                    characters.pop();
                }else{
                    characters.push(currChar);
                }
            }
        }
        return characters.size();
    }
};