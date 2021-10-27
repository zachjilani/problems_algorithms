import java.util.*;


// Given an integer array nums and an integer val, remove all 
// occurrences of val in nums in-place. The relative order of 
// the elements may be changed.
// Do not allocate extra space for another array. You must do
// this by modifying the input array in-place with O(1) extra memory.
// EXAMPLE:
// Input: nums = [0,1,2,2,3,0,4,2], val = 2
// Output: 5, nums = [0,1,4,0,3,_,_,_]
// Explanation: Your function should return k = 5, with the first five elements of nums containing 0, 0, 1, 3, and 4.
// Note that the five elements can be returned in any order.
// It does not matter what you leave beyond the returned k (hence they are underscores).

public class removeElement {
  public static int removeElement(int[] nums, int val){
    int i = 0;
    for(int j = 0; j < nums.length; j ++){
        if(nums[j] != val){
            nums[i] = nums[j];
            i++;
        }
    }
    return i;
  }

  public static void main(String[] args){
    int[] nums = new int[]{0,1,2,2,3,0,4,2};
    int val = 2;
    int ans = removeElement(nums, val);
    System.out.println(ans);
  }
}
