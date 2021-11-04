import java.util.Arrays;

public class containsDupe {

	public static boolean containsDuplicate(int[] nums){
		Arrays.sort(nums);
		for (int i= 1; i < nums.length; i++){
			if (nums[i] == nums[i - 1]){
				return true;
			}
		}
		return false;
	}

	public static void main(String[] args) {
		int[] nums = new int[]{1,2,3,4,5,6,7,8,9,1};
		boolean value = containsDuplicate(nums);
		System.out.println(value);
	}
}
