import java.util.*;


// Given an integer n, return the number of prime numbers
// that are strictly less than n
// EXAMPLE:
// Input: n = 10
// Output: 4
// Explanation: There are 4 prime numbers less than 10, they
// are 2, 3, 5, 7.
public class countPrimes {
	public static int countPrimes(int n) {
		int count = 0;
		boolean[] primes = new boolean[n + 1];
		isPrime(n, primes);
		for (int i = 2;i < n;i++) {
			if (!primes[i]) {
				count++;
			}
		}
		return count;
	}
	public static void isPrime (int num, boolean[] primes) {
		for (int i = 2;i * i <= num;i++) {
			if (!primes[i]) {
				for (int j = i * 2;j <= num; j += i) {
					primes[j] = true;
				}
			}
		}
	}

	public static void main(String[] args){
    System.out.println(countPrimes(10));
		System.out.println(countPrimes(1453));
  }
}
