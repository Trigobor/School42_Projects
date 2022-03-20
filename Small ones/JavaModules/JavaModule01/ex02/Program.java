import java.io.*;
import java.util.ArrayList;

import org.w3c.dom.UserDataHandler;

public class Program {
	private static final Boolean CREDITS = false;
	public static void main(String[] args) throws UserNotFoundException{
		UserIdsGenerator gen = new UserIdsGenerator();
		User Jake = new User(gen, "Jake", 100);
		User Finn = new User(gen, "Finn", 200);
		Transaction Cred = new Transaction(gen, Jake, Finn, CREDITS, 10);
		if (Cred.getRecipient().getBalance() < 0 || Cred.getSender().getBalance() < 0) {
			System.out.println("OOOPSIE");
		} else {
			System.out.println("All good");
			System.out.print("Recipient balance " + Cred.getRecipient().getBalance() + "\n");
			System.out.print("Sender balance " + Cred.getRecipient().getBalance() + "\n");
		}
		if (Cred.getTransferCategory() == CREDITS && Cred.getTransferAmount() < 0) {
			System.out.println("OOOPSIE");
		} else {
			System.out.println("All good");
			System.out.print("Transfer amount " + Cred.getTransferAmount());
		}
		System.out.println("\nJake ID is " + Jake.getIdentifier());
		System.out.println("Finn ID is " + Finn.getIdentifier());
		System.out.println("Transaction ID is " + Cred.getIdentifier());
		UserArrayList list = new UserArrayList();
		list.addUser(Jake);
		list.addUser(Finn);
		list.searchIN(10);
		list.numUsers();
		list.searchID(1);
		System.out.println("Here it comes!");
		list.searchID(10);
	}
}

