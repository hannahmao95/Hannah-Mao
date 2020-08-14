
public class Solution {
	 public int maxProfit(int[] prices) {
	        
	        if(prices.length==0){
	            return 0;
	        }
	        
	        int least = prices[0];
	        int max_profit=0;
	        
	        for (int i =0; i<prices.length;i++){
	            least = Math.min(least, prices[i]);
	            max_profit= Math.max(max_profit, prices[i]-least);
	            
	        }
	        
	        return max_profit;
	    }
}
