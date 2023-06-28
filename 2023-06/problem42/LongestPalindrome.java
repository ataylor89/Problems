import java.util.Map;
import java.util.HashMap;
import java.util.List;
import java.util.ArrayList;

public class LongestPalindrome {
    private String input, output = "";
    private Map<Character, List<Integer>> map;

    public LongestPalindrome(String input) {
        this.input = input;
        populate();
        compute();
    }

    private void populate() {
        map = new HashMap<>();
        for (int i = 0; i < input.length(); i++) {
            Character c = input.charAt(i);
            if (!map.containsKey(c)) 
                map.put(c, new ArrayList<Integer>());
            map.get(c).add(i);
        }
    }

    private boolean isPalindrome(String substring) {
        boolean palindrome = true;
        int len = substring.length();
        for (int i = 0; i < len/2; i++) {
            if (substring.charAt(i) != substring.charAt(len-1-i)) {
                palindrome = false;
                break;
            }
        }
        return palindrome;
    }

    private void compute() {
        if (input.isEmpty()) { 
            return;
        }
        output = input.substring(0, 1);
        for (Character c : map.keySet()) {
            List<Integer> lst = map.get(c);
            int len = lst.size();
            for (int i = 0; i < len; i++) {
                for (int j = len-1; j > i; j--) {
                    int begin = lst.get(i);
                    int end = lst.get(j);
                    if (end - begin + 1 > output.length()) {
                        String substring = input.substring(begin, end + 1);
                        if (isPalindrome(substring)) {
                            output = substring;
                        }
                    }
                }
            }
        }
    }

    @Override
    public String toString() {
        return output;
    }

    public static void main(String[] args) {
        if (args.length != 1) {
            System.out.println("Usage: java LongestPalindrome <string>");
            return;
        }
        String input = args[0];
        System.out.println("Input: " + input);
        long start = System.currentTimeMillis();
        LongestPalindrome output = new LongestPalindrome(input);
        long time = System.currentTimeMillis() - start;
        System.out.println("Output: " + output);
        System.out.printf("Time taken: %d ms\n", time);
    }
}
