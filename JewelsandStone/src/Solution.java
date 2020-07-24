import java.util.HashMap;

public class Solution {
	  public int numJewelsInStones(String J, String S) {
	        
	        char[]JArray = J.toCharArray();
	        char[]SArray = S.toCharArray();
	        
	        HashMap<Character, Integer>map= new HashMap< Character, Integer>();
	        
	        for(int i=0;i<JArray.length;i++){
	                map.put(JArray[i],1);
	            }
	        int count=0;
	        for(char c:SArray){
	            if(map.containsKey(c)){
	                count++;
	            }       
	        } 
	        return count;  
	    }
}
