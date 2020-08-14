import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;

public class Solution {
	 public int[] twoSum(int[] nums, int target) {
	        
		    HashMap<Integer, Integer>map = new HashMap<Integer, Integer>();    
		    List<Integer> arrlist = new ArrayList<Integer>(); 
		            
		         int it=nums[0];   
		        
		        for(int i=0;i<nums.length;i++){
		             it= target-nums[i];
		            
		            if(map.containsKey(it)){
		                arrlist.add(i);
		                arrlist.add(map.get(it)); 
		                break;
		            } 
		            
		             map.put(nums[i], i); 
		                 
		        }
		        
		    //convert Arraylist containing Integer to primitive int array    
		        int[] ret = new int[arrlist.size()];
		        for (int i=0; i < ret.length; i++)
		        {
		            ret[i] = arrlist.get(i).intValue();
		        }

		         return ret;  
		    }

}
