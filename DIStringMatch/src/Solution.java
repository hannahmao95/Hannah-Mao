
public class Solution {
public int[] diStringMatch(String S) {
        
        char[]str= S.toCharArray(); 
        int[] arr= new int[str.length+1]; 
        int min=0;
        int max=str.length;
        
        for(int i=0;i<str.length;i++){
            
            if(str[i]=='I'){  
               arr[i]=min;
               min++;    
            }else if(str[i]=='D'){   
               arr[i]=max;
               max--;    
            }    
        }
        arr[str.length]=min;
        return arr;  
    }

}
