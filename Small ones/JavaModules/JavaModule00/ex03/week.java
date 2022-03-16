public class week {
	int num;
	int[] arr;

	week(int num) {
		this.num = num;
		this.arr = new int[5];
	}

	week(week sample)
	{
		this.num = sample.num;
		this.arr = new int[5];
	}

	void fillArr(String[] str)
	{
		for (int i = 0 ; i < 5; i++) {
			arr[i] = Integer.parseInt(str[i]);
		}
	}

	int getmin()
	{
		int tmp = this.arr[0];
		for (int i = 0 ; i < 5; i++) {
			if (tmp > this.arr[i])
				tmp = this.arr[i];
		}
		return tmp;
	}
}
