public class test {
    public static void main(String[] args) {
        int[] test = new int[] {0,1,2,3,4,5,6,7};
        int[] nums = new int[10];
        int[] nums2 = new int[10];
        int[] nums3 = new int[10];
        int j = 0;

        for(int i = 2; i < test.length; i+=3){
            nums[j] = test[i];
            nums2[j] = test[i-1];
            nums3[j] = test[i-2];
            j++;
        }
    }
}
