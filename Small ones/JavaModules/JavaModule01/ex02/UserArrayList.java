import java.lang.reflect.Executable;
import java.util.ArrayList;

class UserNotFoundException extends Exception {
	public UserNotFoundException(String message){
		super(message);
	}
}

public class UserArrayList implements UserList{
	{
		this.arr = new ArrayList<User>();
	}
	private ArrayList<User> arr;
	public void testMethod() {
		System.out.println("Hello world");
	}
	public void addUser (User user) {
		this.arr.add(user);
	};
	public void searchID (Integer ID) throws UserNotFoundException
	{
		for (int i = 0; i < arr.size(); i++){
			User tmp = this.arr.get(i);
			if (tmp.getIdentifier() == ID){
				System.out.println("ID is " + tmp.getIdentifier());
				System.out.println("Name is " + tmp.getName());
				System.out.println("Balance is " + tmp.getBalance());
				return ;
			}
		}
		throw new UserNotFoundException("Invalid User ID");
	};
	public void searchIN (Integer IN)
	{
		User tmp;
		try {
			tmp = this.arr.get(IN);	
		} catch (IndexOutOfBoundsException e) {
			System.out.println("There is no User quite like asked");
			return ;
		}
		System.out.println("ID is " + tmp.getIdentifier());
		System.out.println("Name is " + tmp.getName());
		System.out.println("Balance is " + tmp.getBalance());
	};
	public void numUsers ()
	{
		System.out.println("Num of Users is " + this.arr.size());
	};
}

