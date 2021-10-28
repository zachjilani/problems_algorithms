import java.util.*;

// Given a non-negative integer x, compute
// and return the square root of x.
// You are not allowed to use any built-in
// exponent function or operator, such as pow(x, 0.5)
// or x ** 0.5
// EXAMPLE:
// Input: x = 8
// Output: 2
// Explanation: The square root of 8 is 2.82842...,
// since the decimal part is truncated, 2 is returned.
public class squareRoot {
	public static int mySqrt(int x) {
		int start = 1;
		int end = x;
		int value = 0;

		if(x == 1 || x == 0){
				return x;
		}

		while(start <= end){
				int mid = start + (end - start)/2;
				if(mid <= x/mid){
						start = mid + 1;
						value = mid;
				}else{
						end = mid - 1;
				}
		}
		return value;
	}

	public static void main(String[] args){
		System.out.println(mySqrt(5));
		System.out.println(mySqrt(69));
		System.out.println(mySqrt(764374));
		System.out.println(mySqrt(999));
		System.out.println(mySqrt(239845672));
  }
}
