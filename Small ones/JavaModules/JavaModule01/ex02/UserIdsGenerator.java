public class UserIdsGenerator {
	private Integer currID = 0;
	public Integer generateId() {
		return currID++;
	}
}