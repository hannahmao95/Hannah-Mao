package preterm;

//A seat object associate the client's id with clinet's seating

public class Seat {
	
	private String fullname;
	private int id;
    int row;
    int col;

    
	public Seat(String f, int i, int r , int c) {
		
		fullname = f;
		id = i;	
		row =r;
		col= c;
		
	}
	
	public Seat() {
		
	}
	

	void setSeat( int newrow, int newcol) {
		this.row = newrow;
		this.col= newcol;
	}
	
	
	void setID(int newid) {
		this.id= newid;
	}
	
	void setFullname(String newname) {
		this.fullname= newname;
	}
	
	String getID() {
		
		if(this.id<10) {
	       String ID = "0"+Integer.toString(id);
	     
	       return ID;
	       
		}else {
			
			String ID = Integer.toString(id);
			return ID;
			
		}		
	}
	
	
	String getSeat() {
		
		//return rows A-J, columns 1-10
		String seat= (char)((row+1)+64) + "-" +(col+1);
	
		return seat;	
	}
	
	String getFullname() {
		
		return fullname;
		
	}			
}

