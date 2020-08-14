
public class Solution {
	  public void reverseString(char[] s) {

	        //in place method
	        int right= s.length-1;
	        int left=0;
	     
	        while(left<right){
	          char temp=s[left];
	          temp= s[left];
	          s[left++]=s[right];
	          s[right--]=temp;
	           
	        }
	        
	    }

}
