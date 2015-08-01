public class Hello {

	public static void main(String[] argv) {
		//int x = currentLight(13);
		//System.out.println(x);
		printerB(4);
		System.out.println(countSubs(333, 3));
	}

	public static int currentLight(int[] timer, int seconds) {
		// time r should contain natural numbers
		int len = timer.length;
		for (int i = 0; i < len; i++) { if (timer[i] < 0) { return -1; } }

		int i;
		for (i = 1; seconds > 0; i++) {
			seconds -= timer[i % len];
		}
		return i % len;
	}

	public static void printerA(int rows) {
		for (int i = 0; i <= rows; i++) {
			for(int j = 0; j <= i; j++) {
				System.out.printf("%d ", i -j);
			}
			System.out.println("");
		}
	}

	public static void printerB(int rows) {
		/*
		      1
		    2 1
		  3 2 1
		*/
		int limit = rows + 1;
		for (int i = 1; i <= limit; i++) {
			for (int j = i; j < limit; j++) {
				System.out.printf("%s ", " " );
			}
			for (int j = i; j >= 1; j--) {
				System.out.printf("%d ", j);
			}
			System.out.println("");
		}
	}

	public static int countSubs(int heystack, int needle) {
		int len = numLength(needle);
		int number = 0;
		while (heystack > 0) {
			if (tail(heystack, len) == needle) number++;
			heystack /= 10;
		}
		return number;
	}

	public static int numLength(int x) {
		int i;
		for (i = 0; x > 0; i++) {
			x /= 10;
		}
		return i;
	}
	public static int tail(int x, int len) {
		int number = 1;
		for (int i = 0; i < len; i++) number *= 10;
		return x - (x / number) * number;
	}
}
