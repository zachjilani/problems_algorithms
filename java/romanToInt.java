class Solution {
    public int romanToInt(String s) {
        //creating map to hold the roman numerals
        Map <Character, Integer> m = new HashMap<>();

        m.put('I',1);
        m.put('V',5);
        m.put('X',10);
        m.put('L',50);
        m.put('C',100);
        m.put('D',500);
        m.put('M',1000);
      
        //our result starting from the value at the end of the string
        int res = m.get(s.charAt(s.length() - 1));

        //iterating from the end of the string to the front
        //this is to differentiate things like IV and VI
        for(int i = s.length() - 2; i >= 0; i--){
            //IV case where we have to subtract. ex 5 - 1 = 4
            if(m.get(s.charAt(i)) < m.get(s.charAt(i + 1))){
                res -= m.get(s.charAt(i));
            }else{
                //VI case where we have to add. ex 5 + 1 = 6
                res += m.get(s.charAt(i));
            }
        }
        return res;
    }
}
