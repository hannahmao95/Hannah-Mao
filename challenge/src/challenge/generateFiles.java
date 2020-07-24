package challenge;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStream;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Comparator;
import java.util.HashMap;
import java.util.LinkedHashMap;
import java.util.List;
import java.util.Map;


public class generateFiles {

	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
			
		String fileLine;
		File file = new File ("input_example.csv");
		String filePath= file.getAbsolutePath();
		
		int count =0;	
		LinkedHashMap<String, Integer> map = new LinkedHashMap<String, Integer>();
	    List<List<String>> records = new ArrayList<>();

		try (BufferedReader br = new BufferedReader(new FileReader(filePath))) {
			
			while ((fileLine = br.readLine()) != null) {
			
				String [] values = fileLine.split(",");
				records.add(Arrays.asList(values));      
                count++;
			}
			System.out.println("number of total orders: "+count);
			System.out.println("");
			
			//0_input_example.csv
			for(List<String> array: records) {
				
				System.out.println(array);	
			    if(map.containsKey(array.get(2))){
			       map.put(array.get(2), map.get(array.get(2))+Integer.parseInt(array.get(3)));
			    	
			    }else {
			    	map.put(array.get(2), Integer.parseInt(array.get(3)));
			    }	
			}
			
			System.out.println("");
			System.out.println("0_input_example.csv:");
			
			//write to csv
			FileWriter writer1 = new FileWriter("0_input_example.csv");

			for (Map.Entry entry : map.entrySet()) { 
	            System.out.println(entry.getKey() + "," + Double.parseDouble(entry.getValue().toString())/count);  
	                writer1.append(entry.getKey().toString());
	                writer1.append(',');
	                writer1.append(String.valueOf(Double.parseDouble(entry.getValue().toString())/count));
	                writer1.append('\n');
	        }
			writer1.flush();
			writer1.close();
			
			System.out.println("");
			System.out.println("1_input_example.csv:");
		
			FileWriter writer2 = new FileWriter("1_input_example.csv");
			
			LinkedHashMap<String, Integer> map1 = new LinkedHashMap<String, Integer>();
			LinkedHashMap<String, String> map2 = new LinkedHashMap<String, String>();
			
			
			//1_input_example.csv
			for(List<String> array: records) {
				
				int max = 0;
				
				if(map1.containsKey(array.get(2))){
						
					max= Math.max(Integer.parseInt(array.get(3)), map1.get(array.get(2)));
				    
				    	 map1.put(array.get(2), max);
				    	 
				    	 if(map1.get(array.get(2))==max){
				    			map2.put(array.get(2), array.get(4));
		    		 
				    	 }
	    	 		   	
				    }else {
				    	map1.put(array.get(2), Integer.parseInt(array.get(3)));
				    	map2.put(array.get(2), array.get(4));	
				    }			
			}
			
		
				
			for (Map.Entry entry : map2.entrySet()) { 
	            System.out.println(entry.getKey() + "," + entry.getValue().toString()); 
	            	writer2.append(entry.getKey().toString());
	            	writer2.append(',');
	            	writer2.append(entry.getValue().toString());
	            	writer2.append('\n');        
	        } 
			writer2.flush();
			writer2.close();
						
		} catch(IOException exc) {
			System.out.println("IO Error: " + exc);
		  }
	}

}
