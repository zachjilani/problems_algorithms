// A phrase is a palindrome if, after converting all uppercase letters
// into lowercase letters and removing all non-alphanumeric characters,
// it reads the same forward and backward. Alphanumeric characters include
// letters and numbers.
// Given a string s, return true if it is a palindrome, or false otherwise.

public class isPalindrome {
  public boolean isPalindrome(String s) {
    String b = s.replaceAll("[^a-zA-Z0-9]", "");
    String a = b.toLowerCase();
    char[] chars = new char[a.length()];
    for(int i = 0; i < a.length(); i++){
        chars[i] = a.charAt(i);
    }
    int left = 0;
    int right = chars.length - 1;
    while(left <= right){
        if(chars[left] == chars[right]){
            left++;
            right --;
        }else{
            return false;
        }
    }
    return true;
  }
}
