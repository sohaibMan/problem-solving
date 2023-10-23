package labyrinthe;

import java.util.HashMap;
import java.util.Stack;

/**
 * Title:        DepthFirstSearchEngine<p>
 * Description:  Performs a dfs search in an 8 puzzle<p>
 * Company:      Fstt<p>
 * website:      <a href="https://sohaibmanah.netlify.app">Author website</a>
 *
 * @author Sohaib Manah
 * @version 1.0
 */



public class DepthFirstSearchEngine extends AbstractSearchEngine {

    HashMap<Integer, State> visited = new HashMap<>();
    Stack<State> stack = new Stack<>();// last in first out

    int iterations = 1;


    public DepthFirstSearchEngine(EightPuzzle eightPuzzle) {
        super(eightPuzzle);
        System.out.println("Depth First Search Started");
        System.out.println("Initial State:");
        this.stack.push(eightPuzzle.getInitialState());
    }

    @Override
    public void run() {
        while (!stack.empty()) {
            State currentState = stack.pop();
            if (currentState.compareTo(eightPuzzle.getGoalState()) == 0) {
                System.out.println("Goal state found after " + iterations + " iterations");
                break;
            } else {
                visited.put(currentState.hashCode(), currentState);
                currentState.printState();

                for (State state : eightPuzzle.getPossibleMoves(currentState)) {
                    // prevent loops
                    if (!visited.containsKey(state.hashCode())) {
                        iterations++;
                        state.printState();
                        stack.push(state);
                    }
                }
            }
        }


    }

}
