import java.util.Map;
import java.util.HashMap;
import java.util.List;
import java.util.ArrayList;

public class LongestPalindrome {
    private String input, output = "";
    private Map<Character, List<Integer>> m;

    public LongestPalindrome(String input) {
        this.input = input;
        populate();
        compute();
    }

    private void populate() {
        m = new HashMap<>();
        for (int i = 0; i < input.length(); i++) {
            Character c = input.charAt(i);
            if (!m.containsKey(c)) 
                m.put(c, new ArrayList<Integer>());
            m.get(c).add(i);
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
        for (Character c : m.keySet()) {
            List<Integer> lst = m.get(c);
            for (int i = 0; i < lst.size(); i++) {
                for (int j = i; j < lst.size(); j++) {
                    int index1 = lst.get(i);
                    int index2 = lst.get(j);
                    if (index2 - index1 + 1 > output.length()) {
                        String substring = input.substring(index1, index2 + 1);
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

    public static void test(String testCase) {
        System.out.println("Test case: " + testCase);
        LongestPalindrome result = new LongestPalindrome(testCase);
        System.out.println("Longest palindrome: " + result);
    }

    public static void main(String[] args) {
        test("x");
        test("xx");
        test("xyyx");
        test("1xyyx2");
        test("abcdedcba");
        test("xx1abcdedcba1y");
        test("");
        test("  abba");
    }
}
