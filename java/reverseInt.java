// Given a signed 32-bit integer x, return x with its digits reversed.
// If reversing x causes the value to go outside the signed 32-bit integer
// range [-231, 231 - 1], then return 0.
//EXAMPLES:
// Input: x = 123
// Output: 321

// Input: x = -123
// Output: -321

public class reverseInt {
	public static int reverse(int x){
		if (x >= -9 && x <= 9){
			return x;
		}
		if (x == Integer.MAX_VALUE || x == Integer.MAX_VALUE){
			return 0;
		}
		int sign = x < 0 ? -1 : 1;
		x = Math.abs(x);
		int res = 0;

		while (x > 0){
			int digit = x % 10;
			if (res > Integer.MAX_VALUE / 10 || res == Integer.MAX_VALUE / 10 && digit > Integer.MAX_VALUE % 10){
				return 0;
			}
			res = res * 10 + digit;
			x /= 10;
		}
		return sign * res;
	}

	public static void main(String[] args) {
		int[] toBeReversed = new int[] {123, -1321, 50, 53940, 43440001, -949213};
		for (int i = 0; i < toBeReversed.length; i++){
			System.out.println("before:");
			System.out.println(toBeReversed[i]);
			System.out.println("after:");
			System.out.println(reverse(toBeReversed[i]));
		}
	}
}
