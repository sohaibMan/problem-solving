package labyrinthe;

import java.util.Arrays;

public record State(int[][] state) implements Comparable<State> {

    void printState() {
        for (int[] row : state) {
            for (int i : row) {
                System.out.print(i + " ");
            }
            System.out.println();
        }
        System.out.println();
    }

    @Override
    public int hashCode() {
        return Arrays.deepHashCode(state);
    }


    public int compareTo(State o) {
        if (Arrays.deepEquals(o.state, this.state)) {
            return 0;  // Content is the same
        } else {
            // If content is different, compare based on index
            return Integer.compare(this.hashCode(), o.hashCode());
        }
    }
}
