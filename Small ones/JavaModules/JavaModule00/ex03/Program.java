import java.io.*;
import java.util.*;
import static java.lang.Math.*;

public class Program {

	public static void main(String[] args) throws IOException {

	String str;
	Vector<week> stat = new Vector<>();
	for (int i = 0 ; i < 18 ; i++){
		BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
		System.out.print("-> ");
		str = reader.readLine();
		if (str.matches("\\d+") && Integer.parseInt(str) == 42)
			break ;
		if (str.matches("Week.{2,3}")) {
			if (i != 0 && (Integer.parseInt(str.substring(5)) < stat.get(i - 1).num)) {
				System.out.println("IllegalArgument message");
				System.exit(-1);
			}
			stat.addElement(new week(Integer.parseInt(str.substring(5))));
			System.out.print("-> ");
			str = reader.readLine();
			stat.get(i).fillArr(str.split(" "));
		}
	}
	for (int i = 0 ; i < stat.size() ; i++) {
		System.out.printf("Week %d ", stat.get(i).num);
		for (int j = 0; j < stat.get(i).getmin(); j++){
			System.out.print("=");
		}
		System.out.println(">");
	}
	}
}