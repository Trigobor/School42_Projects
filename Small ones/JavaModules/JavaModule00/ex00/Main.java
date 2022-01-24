public class Main {

	public static void main(String[] args) {

		String regex = "\\d+";
		if (args.length == 0 || !(args[0].matches(regex))) {
			System.out.println("OOOPSIE!");
			return;
		}
		int rez = 0;
		for (int i = Integer.parseInt(args[0]); i > 0; i /= 10)
			rez += i % 10;
		System.out.println(rez);

	}

}