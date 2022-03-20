import java.util.ArrayList;

public interface UserList {
	default void testMethod() {
		System.out.println("Hello world");
	}
	void addUser (User user);
	void searchID (Integer ID) throws UserNotFoundException;
	void searchIN (Integer IN);
	void numUsers ();
}
