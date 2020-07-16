package challenge2;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.LinkedHashMap;
import java.util.List;
import java.util.Map;

public class challenge2 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		String fileLine;
		File file = new File ("hosts_access_log_00.txt");
		String filePath= file.getAbsolutePath();
		
		int count =0;	
		
	    HashMap<String, Integer> map = new HashMap<String, Integer>();
	    ArrayList<String> al = new ArrayList<String>();
	    
	    LinkedHashMap<String, Integer> map1 = new LinkedHashMap<String, Integer>();
	    List<List<String>> records = new ArrayList<>();

		try (BufferedReader br = new BufferedReader(new FileReader(filePath))) {
			
			while ((fileLine = br.readLine()) != null) {
			
				String [] values = fileLine.split("--");
				records.add(Arrays.asList(values));      
                count++;
			}
		
			//0_input_example.csv
			for(List<String> array: records) {
				
				System.out.println(array);	
			    if(map1.containsKey(array.get(2))){
			       map1.put(array.get(2), map1.get(array.get(2))+Integer.parseInt(array.get(3)));
			    	
			    }else {
			    	map1.put(array.get(2), Integer.parseInt(array.get(3)));
			    }	
			}
			for (Map.Entry entry : map1.entrySet()) { 
	            System.out.println(entry.getKey() + "," + entry.getValue());  
	                
	        }
						
		} catch(IOException exc) {
			System.out.println("IO Error: " + exc);
		  }

	}

}
