import java.io.*;
import java.util.*;

import javax.jws.soap.SOAPBinding.Use;

import org.omg.CORBA.IdentifierHelper;
import org.omg.CORBA.portable.IDLEntity;

import static java.lang.Math.*;

class User {
	private Integer Identifier;
	private String Name;
	private Integer Balance;

	public String getName() {
		return Name;
	}
	public Integer getBalance() {
		return Balance;
	}
	public Integer getIdentifier() {
		return Identifier;
	}

	public void setName(String name) {
		Name = name;
	}
	public void setBalance(Integer balance) {
		Balance = balance;
	}

	public User(UserIdsGenerator ID, String name, Integer Bal) {
		this.Identifier = ID.generateId();
		this.Name = name;
		this.Balance = Bal;
	}
}

class Transaction {

	private Integer Identifier;
	private User Recipient;
	private User Sender;
	private Boolean TransferCategory;
	private Integer TransferAmount;

	public Transaction(UserIdsGenerator ID, User Rec, User Send, Boolean Cat, Integer Am) {
		this.Identifier = ID.generateId();
		this.Recipient = Rec;
		this.Sender = Send;
		this.TransferCategory = Cat;
		this.TransferAmount = Am;
	}

	public Integer getIdentifier() {
		return Identifier;
	}
	public User getRecipient() {
		return Recipient;
	}
	public User getSender() {
		return Sender;
	}
	public Boolean getTransferCategory() {
		return TransferCategory;
	}
	public Integer getTransferAmount() {
		return TransferAmount;
	}

	public void setRecipient(User recipient) {
		Recipient = recipient;
	}
	public void setSender(User sender) {
		Sender = sender;
	}
	public void setTransferCategory(Boolean transferCategory) {
		TransferCategory = transferCategory;
	}
	public void setTransferAmount(Integer transferAmount) {
		TransferAmount = transferAmount;
	}
}

class UserIdsGenerator {
	private Integer currID = 0;
	public Integer generateId() {
		return currID++;
	}
}

public class Program {
//	private static final Boolean DEBITS = true;
	private static final Boolean CREDITS = false;
	public static void main(String[] args) throws IOException {
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
	}
}