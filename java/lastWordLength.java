import java.util.*;


// Given a string s consisting of some words separated by some number of
// spaces, return the length of the last word in the string.

// A word is a maximal substring consisting of non-space characters only.
// EXAMPLE:
// Input: s = "   fly me   to   the moon  "
// Output: 4
// Explanation: The last word is "moon" with length 4.
public class lastWordLength {
  public static int lengthOfLastWord(String s) {
    int count = 0;
    String trimmed = s.trim();
    int i = trimmed.length() - 1;
    while(i >= 0 && !Character.isWhitespace(trimmed.charAt(i))){
        i--;
        count++;
    }
    return count;
  }

  public static void main(String[] args){
    String s = "  fly me to the moon";
    System.out.print(lengthOfLastWord(s));
  }
}
