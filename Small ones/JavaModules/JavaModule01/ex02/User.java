public class User {
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
