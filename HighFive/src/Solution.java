import java.util.ArrayList;
import java.util.Collections;
import java.util.HashMap;
import java.util.Map;

public class Solution {
	public int[][] highFive(int[][] items) {
        HashMap<Integer, ArrayList<Integer>>map = new HashMap<>();
        
        for(int[]arr:items){
         int id= arr[0];
         int score= arr[1];
            
         System.out.println("id: "+id+" score: "+score);         
         map.putIfAbsent(id, new ArrayList<Integer>());
         map.get(id).add(score);
  
        }
        
         int[][] result = new int[map.size()][2];
          int idx=0;
    for (Map.Entry<Integer, ArrayList<Integer>> entry : map.entrySet()) {
         
        Collections.sort(entry.getValue(), Collections.reverseOrder());
        System.out.println(entry.getKey()+" : "+entry.getValue());
        
        ArrayList<Integer> list = entry.getValue();
        
        int sum =0;
        int index=0;

       while(index<5 && index<list.size()){
           sum+=list.get(index); 
           index++;
           
       }
        result[idx][0]= entry.getKey();
        result[idx][1]=sum/5;
        idx++;
    }
            
      return result;
       
   }

}
