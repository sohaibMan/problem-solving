package labyrinthe;


/**
 * Title:        MazeBreadthFirstSearch<p>
 * Description:  Demo program for Java AI Programming<p>
 * Copyright:    Copyright (c) Mark Watson, Released under Open Source Artistic License<p>
 * Company:      Mark Watson Associates<p>
 *
 * @author Mark Watson
 * @version 1.0
 */

public class Main {

    public static void main(String[] args) throws Exception {

        //create a new puzzle
        AbstractSearchEngine currentSearchEngine = getSearchEngine("bfs");
        currentSearchEngine.run();
        currentSearchEngine = getSearchEngine("dfs");
        currentSearchEngine.run();
//        currentSearchEngine = getSearchEngine("a-start");
//        currentSearchEngine.run();

    }

    private static AbstractSearchEngine getSearchEngine(String algo) throws Exception {
        EightPuzzle eightPuzzle = new EightPuzzle();
        State initialState = new State(new int[][]{{1, 2, 3}, {0, 4, 6}, {7, 5, 8}});
        // setting the goal state
        State goalState = new State(new int[][]{{1, 2, 3}, {4, 5, 6}, {7, 8, 0}});

        eightPuzzle.setInitialState(initialState);
        eightPuzzle.setGoalState(goalState);

        return switch (algo) {
            case "bfs" -> new BreadthFirstSearchEngine(eightPuzzle);
            case "dfs" -> new DepthFirstSearchEngine(eightPuzzle);
            case "a-start" -> new AStartSearchEngine(eightPuzzle);
            default -> throw new Exception("Unhandled algorithms");
        };

    }


}


