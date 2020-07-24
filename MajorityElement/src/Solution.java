import java.util.HashMap;
import java.util.Map;

public class Solution {
    public int majorityElement(int[] nums) {
	 int maj = nums.length/2;
     int result=0;
     HashMap<Integer, Integer> map = new HashMap<Integer, Integer>();
     
     for(int num:nums){ 
         if(map.containsKey(num)){
             map.put(num,map.get(num)+1);
         }else{
             map.put(num,1);
         }  
     }
     
     for(Map.Entry<Integer,Integer> entry: map.entrySet()){
         if(entry.getValue()>maj){
             result= entry.getKey();
         }
     }
     return result;
  }

}
