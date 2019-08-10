package preterm;

import java.awt.List;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;

public class Main {
	
	public static void startApp() {
		System.out.println("startApp()");
		System.out.println("- This is where I can setup very basic stuff, at least an app intro");
		
	}
	
	public static void getInput() {
		
		System.out.println("\ngetInput()");
		System.out.println("- get my clients");
		System.out.println("- get a room matrix");
		
		// quick test of the client data structure
		System.out.println("getInput()\n");
		System.out.println("- We are going to create a Client class that will hold data and return itself or some info about it");
		Client testClient = new Client("Gauthier", "Claude", 2);
		System.out.println("Lastname: " + testClient.getClientLastName() + " " + "Firstname: " + testClient.getClientFirstName() + " " + "ID: " + testClient.getClientId());
		System.out.println("\n\n");
		// quick test to see if we can load data from a CSV file
		// and at least get an accurate count of the rows loaded in
		System.out.println("- Testing the ClientStore class\n");
		ClientStore myStore = new ClientStore("clients_list.csv");
		Client[] store = myStore.getClientStore();
		System.out.println("\n");
		System.out.println("- DataCount: " + myStore.getClientDataCount());
		System.out.println("\nThis is a list of all the data in the store\n");
		// iterate via the array of store.
		for(Client c : store) {
			if(c != null) {
				System.out.println(c.getFullClientString());
				
			}
		}
		
	}	
	
	public static void processData() {
		
		System.out.println("\nprocessData()");		
		System.out.println("- associate clients with room matrix");
	}
	
	public static void showOutput() {
		
		System.out.println("\nshowOutput()");
		System.out.println("- display matrix");
		System.out.print("\n");
	
		ClientStore myStore = new ClientStore("clients_list.csv");
		Client[] store = myStore.getClientStore();	
		RoomMatrix room= new RoomMatrix();
		room.printRoomMatrix(store);

	}
	
	public static void endApp() {
		System.out.println("\nendApp()");
		System.out.println("- display an ending message	");
	}
		
	public static void main(String[] args) {
		
		startApp();
		getInput();
		processData();
		showOutput();
		endApp(); 

	}
}
