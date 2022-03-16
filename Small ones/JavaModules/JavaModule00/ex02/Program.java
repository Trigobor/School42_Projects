import java.io.*;
import static java.lang.Math.*;

public class Program {

	public static void main(String[] args) throws IOException {

	String str;
	int iter = 0;
	do {
		BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
		System.out.print("-> ");
		str = reader.readLine();
		iter++;
		int num = 0;
		for (int i = Integer.parseInt(str); i > 0; i /= 10)
			num += i % 10;
		Double tmp = Math.sqrt(num);
		int del = tmp.intValue() + 1;
		if (num != 2) {
			for (int i = 2; i <= del; i++)
			{
				if ((num % i) == 0) {
					iter--;
					break ;
				}
			}
		}
	} while (Integer.parseInt(str) != 42);
	System.out.printf("Count of coffee-request - %d", iter);
	System.exit(0);
	}
}