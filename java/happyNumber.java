

// Write an algorithm to determine if a number n is happy.
// A happy number is a number defined by the following process:
// Starting with any positive integer, replace the number by the sum of the squares of its digits.
// Repeat the process until the number equals 1 (where it will stay), or it loops endlessly in a cycle which does not include 1.
// Those numbers for which this process ends in 1 are happy.
// Return true if n is a happy number, and false if not.
// EXAMPLE:
// Input: n = 19
// Output: true
// Explanation:
// 1^2 + 9^2 = 82
// 8^2 + 2^2 = 68
// 6^2 + 8^2 = 100
// 1^2 + 0^2 + 0^2 = 1


public class happyNumber {
	public static boolean isHappy(int n) {
		int number = 0;
		if(n == 1 || n == 7) return true;
		else if(n < 10) return false;
		while(n!=0){
				number += Math.pow(n%10, 2);
				n = n/10;
		}
		return isHappy(number);
	}

	public static void main(String[] args){
    System.out.println(isHappy(19));
		System.out.println(isHappy(100));
		System.out.println(isHappy(2));
		System.out.println(isHappy(484));
		System.out.println(isHappy(18));
		System.out.println(isHappy(1));
  }
}
