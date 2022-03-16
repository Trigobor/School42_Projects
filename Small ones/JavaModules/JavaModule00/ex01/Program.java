import java.io.*;
import static java.lang.Math.*;

public class Program {

	public static void main(String[] args) throws IOException {

		BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
		System.out.print("-> ");
		String str = reader.readLine();
		String regex = "\\d+";
		if (!(str.matches(regex))) {
			System.out.println("theIllegalArgument");
			System.exit(-1);
		}
		int num = Integer.parseInt(str);
		if (num <= 1) {
			System.out.println("theIllegalArgument");
			System.exit(-1);
		}
		int iter = 0;
		Double tmp = Math.sqrt(num);
		int del = tmp.intValue() + 1;
		for (int i = 2; i <= del; i++)
		{
			if ((num % i) == 0) {
				System.out.printf("false %d", i - 1);
				System.exit(0);
			}
			iter++;
		}
		System.out.printf("true %d", iter);
		System.exit(0);
	}
}