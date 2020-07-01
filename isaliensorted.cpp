class Solution {
public:
    map<char,int> M;
    bool sorted(string s1,string s2)
    {
    	int i=0;
    	int m = s1.length();
    	int n = s2.length();
    	while (s1[i]==s2[i])
    		i++;
    	if(i==m) return true;
    	if(M[s1[i]]<M[s2[i]]) return true;
    		
    	return false;

    }
    bool isAlienSorted(vector<string>& words, string order) {
        
        for(int i=0;i<order.size();i++)
        {
        	M[order[i]]=i;
        }
        for(int i=1;i<words.size();i++)
        {
        	if(!(sorted(words[i-1],words[i])))
        		return false;

        }	
        return true;
    }
};

//best possible solution
class Solution {
    public boolean isAlienSorted(String[] words, String order) {
        int[] orderArray = new int[26];
        for(int i=0; i<order.length(); i++){
            orderArray[order.charAt(i) - 'a'] = i;
        }
        
        for(int i=1; i<words.length; i++){
            if(!stringCompare(words[i-1], words[i], orderArray)) return false;
        }
        return true;
    }
    
    boolean stringCompare(String left, String right, int[] order){
        int i = 0, j = 0;
        while(i < left.length() && j < right.length() 
             && left.charAt(i) == right.charAt(j)){
            i++;
            j++;
        }
        if(i == left.length()){
            return true;
        }else if (j == right.length()){
            return false;
        }else{
            return order[left.charAt(i) - 'a'] < order[right.charAt(j) - 'a'];
        }
    }
}