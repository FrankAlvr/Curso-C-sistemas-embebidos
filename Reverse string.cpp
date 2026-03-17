class Solution {
public:
    void reverseString(vector<char>& s) {
        int tamaño = s.size();
        char left;
        char right;
        int i = 0;
        
        while(i < tamaño/2){
            left = s[i];
            right = s[tamaño - 1 - i];
            s[i] = right;
            s[tamaño - 1 - i] = left;
            i++;
        }
    }
};
