import java.io.*;
import java.util.*;
import java.util.stream.Collectors;

public class Program {

	public static String func(int l, int tithe) {
		char[] rez = new char[l/tithe];
		for (int i = 0; i < rez.length ; i++) {
			rez[i] = '#';
		}
		return String.copyValueOf(rez);
	}
	public static void main(String[] args) throws IOException {
	TreeMap<Character, Integer> sortedByKey = new TreeMap<Character, Integer>();
	BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
	System.out.print("-> ");
	char[] str = (reader.readLine()).toCharArray();
	for (int i = 0; i < str.length; i++) {
		if (sortedByKey.containsKey(str[i])) {
			sortedByKey.replace(str[i], (sortedByKey.get(str[i])) + 1);
		}
		else {
			sortedByKey.put(str[i], 1);
		}
	}
	if (sortedByKey.size() == 0) {
		return ;
	}
	if (sortedByKey.size() == 1) {
		System.out.println(sortedByKey.entrySet().iterator().next().getValue());
		System.out.println(sortedByKey.entrySet().iterator().next().getKey());
		return ;
	}
	Map<Character, Integer> sortedByValue = 
		sortedByKey.entrySet().stream()
		.sorted(Collections.reverseOrder(Map.Entry.comparingByValue()))
		.collect(Collectors.toMap(Map.Entry::getKey, Map.Entry::getValue,(e1, e2) -> e1,LinkedHashMap::new));

	Iterator<Map.Entry<Character, Integer>> first = sortedByValue.entrySet().iterator();
	int tithe = sortedByValue.entrySet().iterator().next().getValue() / 10;
	int size = (10 > sortedByValue.size() ? sortedByValue.size() : 10);
	String[] rez = new String[size];
	for (int i = 0 ; i < size ; i++) {
		Map.Entry<Character, Integer> some = first.next();
		rez[i] = String.format("%c %s%d", some.getKey(), func(some.getValue(), tithe), some.getValue());
	}
	for (int i = 0 ; i < size ; i++) {
		System.out.println(rez[i]);
	}
}
}