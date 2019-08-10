package preterm;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;

public class ClientStore {
 
	private Client[] dataStore;
	private int dataCount;
	private String filename;
	
	ClientStore(String f) {
		// for now this is hardcoded, until
		// we learn how to work with a combination of objects and arraylist
		dataStore = new Client[25];
		dataCount = 0;
		filename = f;
		boolean success = loadClientFromFile(f);
		if(!success) {
			// we have a problem
			System.out.println("The file was not loaded and the datastore is empty");
		}
	}

	// for now, this is internal to the method;
	// will be used by loadClientFromFile() method
	
	
	void addClient(Client client) {
		
		if(dataCount < 25) {
			dataStore[dataCount] = client;
			dataCount++;
		} else {
			System.out.println("We have reached our limit of 25 clients");
		}
	}

	boolean loadClientFromFile(String f) {
		// the file will be configured as a Comma Separated Value (CSV) file.
		String fileLine;
		String[] record;
		
		boolean first = true;
		try (BufferedReader br = new BufferedReader(new FileReader(f))) {
			while ((fileLine = br.readLine()) != null) {
				// skip the first line of the CSV 
				// it contains the field names
				if(first == true) {
					first = false;
					continue;
				}
				record = fileLine.split(",");
				Client client = new Client(record[1], record[2], Integer.parseInt(record[0]));	
				addClient(client);

			}
			
		} catch(IOException exc) {
			System.out.println("IO Error: " + exc);
		}
		
		return true;
	}

	// could return an empty store.. 
	Client[] getClientStore() {
		return dataStore;
	}
	
	int getClientDataCount() {
		return dataCount;
	}

}
