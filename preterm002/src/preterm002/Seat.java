package preterm002;

//A seat object associate the client's id with clinet's seating

public class Seat {
	
	private String lastname;
	private String firstname;
    private int id;
    int row;
    int col;
    boolean canBeAssigned=true;

    
	public Seat(String f, String l, int i, int r , int c) {
		
		firstname = f;
		lastname=l;
		id = i;	
		row =r;
		col= c;
		//canBeAssigned=a;
		
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
		
	String getID() {
		
		if(this.id<10) {
	       String ID = "0"+Integer.toString(id);
	     
	       return ID;
	       
		}else {
			
			String ID = Integer.toString(id);
			return ID;	
		}			
	}
	
	boolean getCanBeAssigned() {
		return canBeAssigned;
	}
	
	
	String getSeat() {
		
		//return rows A-J, columns 1-10
		String seat= (char)((row+1)+64) + "-" +(col+1);
	
		return seat;	
	}
	
	String getFullname() {
		
		String full = (firstname + " "+ lastname);
		return full;
		
	}	
	
      String getInitialIDString() {
		
		if(id<10) {
		String full = ("id:" + '0'+id + "/" + firstname.charAt(0) + lastname.charAt(0));
		return full;
		}
		else {
			String full = ("id:" + id + "/" + firstname.charAt(0) + lastname.charAt(0));
			
			return full;
			
		}
    }
}

