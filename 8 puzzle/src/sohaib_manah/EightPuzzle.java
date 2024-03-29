package sohaib_manah;

import java.awt.*;
import java.util.LinkedList;

public class EightPuzzle {
    State initialState;
    State goalState;

    public State getInitialState() {
        return initialState;
    }

    public void setInitialState(State initialState) {
        this.initialState = initialState;
    }

    public State getGoalState() {
        return goalState;
    }

    public void setGoalState(State goalState) {
        this.goalState = goalState;
    }

    public LinkedList<State> getPossibleMoves(State currentState) {
        LinkedList<State> possibleMoves = new LinkedList<>();
        Point emptySpaceCoordinates = getEmptySpaceCoordinates(currentState);
        Point[] possibleDirections = new Point[4];

        // move left
        possibleDirections[0] = new Point(emptySpaceCoordinates.x - 1, emptySpaceCoordinates.y);
        // move right
        possibleDirections[1] = new Point(emptySpaceCoordinates.x + 1, emptySpaceCoordinates.y);
        // move down
        possibleDirections[2] = new Point(emptySpaceCoordinates.x, emptySpaceCoordinates.y - 1);
        // move up
        possibleDirections[3] = new Point(emptySpaceCoordinates.x, emptySpaceCoordinates.y + 1);

        for (Point possibleDirection : possibleDirections) {
            // check if the possible direction is within the bounds of the puzzle
            if (possibleDirection.x >= 0 && possibleDirection.x < currentState.getState().length && possibleDirection.y >= 0 && possibleDirection.y < currentState.getState().length) {
                // clone the current state to the new state
                int[][] newState = new int[currentState.getState().length][currentState.getState().length];
                for (int i = 0; i < currentState.getState().length; i++) {
                    System.arraycopy(currentState.getState()[i], 0, newState[i], 0, currentState.getState()[i].length);
                }
                // swap the empty space with the possible direction
                newState[emptySpaceCoordinates.x][emptySpaceCoordinates.y] = currentState.getState()[possibleDirection.x][possibleDirection.y];
                newState[possibleDirection.x][possibleDirection.y] = 0;
                possibleMoves.add(new State(newState));
            }
        }

        return possibleMoves;

    }

    Point getEmptySpaceCoordinates(State state) {
        Point point = new Point();
        for (int i = 0; i < state.getState().length; i++) {
            for (int j = 0; j < state.getState()[i].length; j++) {
                if (state.getState()[i][j] == 0) {
                    point.x = i;
                    point.y = j;
                    return point;
                }
            }
        }
        return null;
    }
}
