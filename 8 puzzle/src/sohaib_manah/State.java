package sohaib_manah;

import java.util.Arrays;

public class State implements Comparable<State> {

    private final int[][] state;
    private int cost ;


    public State(int[][] state) {
        this.state = state;
        this.cost = 0;

    }

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

    public int getEstimatedTotalCost(State goalState) {
        return this.cost + heuristic(goalState);
    }


    private int heuristic(State goalState) {

        int count = 0;
        for (int i = 0; i < goalState.getState().length; i++) {
            for (int j = 0; j < goalState.getState().length; j++) {
                if (goalState.getState()[i][j] != this.getState()[i][j] && this.getState()[i][j] != 0) {
                    count++;
                }
            }
        }
        return count;
    }


    public int[][] getState() {
        return state;
    }

    public int getCost() {
        return cost;
    }

    public void setCost(int cost) {
        this.cost = cost;
    }
}
