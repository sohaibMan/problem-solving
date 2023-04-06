import java.util.Arrays;

class Solution {
    public String longestCommonPrefix(String[] strs) {
        String matchPattern = "";

        Arrays.sort(strs, (a, b) -> Integer.compare(a.length(), b.length()));

        for (int j = 0; j < strs[0].length(); j++) {
            for (int i = 0; i < strs.length - 1; i++) {
                if (strs[i].charAt(j) != strs[i + 1].charAt(j))
                    return matchPattern;
            }
            matchPattern += strs[0].charAt(j);
        }

        return matchPattern;
    }
}