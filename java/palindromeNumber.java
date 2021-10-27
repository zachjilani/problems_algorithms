import java.util.*;

// Given an integer x, return true if x is palindrome integer.

public class palindromeNumber {
  public static boolean isPalindrome(int x){
    if(x < 0){
        return false;
    }
    ArrayList<Integer> arr = new ArrayList<Integer>();
    while(x > 0){
        arr.add(x%10);
        x = x/10;
    }
    int left = 0;
    int right = (arr.size() - 1);
    while(left <= right){
        if(arr.get(left) == arr.get(right)){
            left++;
            right--;
        }else{
            return false;
        }
    }
    return true;
  }

  public static void main(String[] args){
    int[] numbers = new int[] {123, -121, 10, -101, 55455, 55343, 12321, 55, -14421};
    boolean[] answers = new boolean[numbers.length];

    for (int i = 0; i < numbers.length; i++){
      answers[i] = isPalindrome(numbers[i]);
    }
    for (int i = 0; i < answers.length; i++){
      System.out.println(answers[i]);
    }
  }

}
