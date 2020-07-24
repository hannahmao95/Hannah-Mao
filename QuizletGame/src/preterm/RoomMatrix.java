package preterm;

public class RoomMatrix {

	private int column=10;   //columns 1 to 10
	private int row=10;      //rows A to J
	private int dataCount;    
	
	
	String[][] Roommatrix=new String[10][10];   //matrix[row][columns]
	 
	public RoomMatrix() {
				
	}
	
	//print out seats matrix	
	public void printRoomMatrix(Client Clientcopy[]) {
	
		int count=0;
		int rowmax= 9;
		int columnmax=9;
		
		Client[] assignClient = new Client[25]; // list assigning the clients to seats	                                    
		Seat[] seatlist= new Seat[25]; // list associating client ids with seating
		
		//passing array argument
		for (int k=0;k<assignClient.length;k++) {
			assignClient[k]= Clientcopy[k];
		}
	 
	    //print out column labels
		for (int k = 1; k < 11; k++) 
		 System.out.printf("%-15s","\t" + "Seat "+k);
		 System.out.println();
		 
		 for(int x = 0; x < 161; x++)
		    {
		        System.out.print("-");
		    }
		   
		   System.out.print("\n");
		 
		   //print out clients assigned to seats
		for (int i = 0; i < Roommatrix.length; i++) {
			
			//print out row label
			System.out.printf("%-10s","row "+(char)('A'+i));
		
			for (int j = 0; j < Roommatrix[i].length; j++) {
			
			    while(count<25) {
					int randr = (int) Math.floor(Math.random()*(rowmax+1));     
				    int randc = (int) Math.floor(Math.random()*(columnmax+1));
					//assigning seat to random spots
				       if(Roommatrix[randr][randc] == null) {
						 
				    	   Roommatrix[randr][randc]=assignClient[count].getInitialIDString(); 
						  
				    	   //creating client seating list that associate the id, name, and seating of the client
				    	   
				    	   seatlist[count] = new Seat(assignClient[count].getFullname(),assignClient[count].getClientId(), randr, randc);
				    	   	 
						  count++;	
						  	
						}        
				  }				    
				       System.out.printf("%-16s", Roommatrix[i][j]);	
			 }
			System.out.println();	
        }
		
		System.out.println();	
		
	    System.out.println("- display list of clients with seat assignment\n");
		
		 System.out.printf( "%-30s %-30s %-30s\n","Client","ID","Seat");
		 //print horizontal line
		   for(int x = 0; x < 70; x++)
		    {
		        System.out.print("-");
		    }
		   
		   System.out.print("\n");
		 
		
		for (int k=0;k<25;k++) {
			 System.out.printf( "%-30s %-30s %-30s\n",seatlist[k].getFullname(), seatlist[k].getID(),seatlist[k].getSeat());
			 
		}
		
		System.out.println();	
		
    }
	
}
