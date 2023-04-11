public class Solution {
    public static void main(String[] args) {
        int image[][] = { { 1, 1, 1 }, { 1, 1, 0 }, { 1, 0, 1 } };
        int sr = 1, sc = 1, color = 2;
        Solution s = new Solution();
        int[][] result = s.floodFill(image, sr, sc, color);
        for (int i = 0; i < result.length; i++) {
            for (int j = 0; j < result[0].length; j++) {
                System.out.print(result[i][j] + " ");
            }
            System.out.println();
        }
    }

    public int[][] floodFill(int[][] image, int sr, int sc, int color) {
        if (image[sr][sc] == color)
            return image;
        int oldColor = image[sr][sc];
        image[sr][sc] = color;

        if (sr > 0 && image[sr - 1][sc] == oldColor)
            floodFill(image, sr - 1, sc, color);

        if (sr < image[0].length - 1 && image[sr + 1][sc] == oldColor)
            floodFill(image, sr + 1, sc, color);

        if (sc > 0 && image[sr][sc - 1] == oldColor)
            floodFill(image, sr, sc - 1, color);

        if (sc < image.length - 1 && image[sr][sc + 1] == oldColor)
            floodFill(image, sr, sc + 1, color);

        return image;
    }
}