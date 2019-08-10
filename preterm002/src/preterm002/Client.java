package preterm002;

public class Client {

	private String lastname;
	private String firstname;
	private int id;

	Client(String l, String f, int i) {
		lastname = l;
		firstname = f;
		id = i;
	}
	
	public Client() {
		// TODO Auto-generated constructor stub
	}
	
	int getClientId() {
		return id;
	}
	
	String getClientLastName() {
		return lastname;
	}
	
	String getClientFirstName() {
		return firstname;
	}
	
	String getClientInitials() {
		char[] initialsArr = {' ', ' '};
		initialsArr[0] = firstname.charAt(0);
		initialsArr[1] = lastname.charAt(0); 
		return new String(initialsArr);
	}

	String getFullClientString() {
		String full = ("id: " + id + " lastname: " + lastname + " firstname: " + firstname);
		return full;	
	}
	
	String getFullname() {
		String full = ( firstname + " "+ lastname);
		return full;			
	}
	
	
   //get id and initial of the client	
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
	
	@Override
    public String toString() { 
        return String.format(firstname + " "+ lastname); 
    }
}
	


