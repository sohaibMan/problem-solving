package sohaib_manah;

/**
 * Title:        Main function to test<p>
 * Description:  test the implementations<p>
 * Company:      Fstt<p>
 * website:      <a href="https://sohaibmanah.netlify.app">Author website</a>
 *
 * @author Sohaib Manah
 * @version 1.0
 */


public class Main {

    public static void main(String[] args) throws Exception {

        //creating a new search engine using bfs
        AbstractSearchEngine currentSearchEngine = getSearchEngine("bfs");
        currentSearchEngine.run();
        // creating a new search engine using dfs
        currentSearchEngine = getSearchEngine("dfs");
        currentSearchEngine.run();
        // creating a new search engine using a-start
        currentSearchEngine = getSearchEngine("a-start");
        currentSearchEngine.run();

    }

    private static AbstractSearchEngine getSearchEngine(String algo) throws Exception {
        //create a new puzzle
        EightPuzzle eightPuzzle = new EightPuzzle();
        // setting the initial state
        State initialState = new State(new int[][]{{1, 2, 3}, {0, 4, 6}, {7, 5, 8}});
        eightPuzzle.setInitialState(initialState);
        // setting the goal state
        State goalState = new State(new int[][]{{1, 2, 3}, {4, 5, 6}, {7, 8, 0}});
        eightPuzzle.setGoalState(goalState);
        // matching each algo to it's method
        return switch (algo) {
            case "bfs" -> new BreadthFirstSearchEngine(eightPuzzle);
            case "dfs" -> new DepthFirstSearchEngine(eightPuzzle);
            case "a-start" -> new AStartSearchEngine(eightPuzzle);
            default -> throw new Exception("Unhandled algorithms");
        };

    }


}


