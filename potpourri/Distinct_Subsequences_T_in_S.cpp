public class Solution {
    public int numDistinct(String S, String T) {
 
        if (S.length() == 0 || T.length() == 0)
            return 0;
 
        int[][] f = new int[T.length() + 1][S.length() + 1];
 
 
 
        for (int j = 0; j <= S.length(); j++)
            f[0][j] = 1;
 
 
        for (int i = 1; i <= T.length(); i++)
            for (int j = 1; j <= S.length(); j++)
                if (T.charAt(i - 1) == S.charAt(j - 1))
                    f[i][j] = f[i - 1][j - 1] + f[i][j - 1];
                else
                    f[i][j] = f[i][j - 1];
 
        return f[T.length()][S.length()];
    }
 
}