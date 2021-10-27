import java.util.*;

// Given an array of integers nums and an integer target,
// return indices of the two numbers such that they add up to target
public class twoSum {

  public static int[] twoSum(int[] nums, int target){
    Map<Integer, Integer> map = new HashMap<>();
    for(int i = 0; i < nums.length; i++){
        int first = target - nums[i];
        if(map.containsKey(first)){
            return new int[] {map.get(first), i};
        } else {
            map.put(nums[i], i);
        }
    }
    return new int[] {};
}

  public static void main(String[] args){
    int[] arrayOne = new int[] {2, 7, 11, 15};
    int targetOne = 9;
    int[] sumOne = twoSum(arrayOne, targetOne);

    for (int i = 0; i < sumOne.length; i++){
      System.out.println(sumOne[i]);
    }

  }
}
