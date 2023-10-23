package labyrinthe;

import java.util.HashMap;
import java.util.LinkedList;
import java.util.Queue;

/**
 * Title:        DepthFirstSearchEngine<p>
 * Description:  Performs a depth first search in an 8 puzzle<p>
 * Company:      Fstt<p>
 * website:      <a href="https://sohaibmanah.netlify.app">Author website</a>
 *
 * @author Sohaib Manah
 * @version 1.0
 */


public class BreadthFirstSearchEngine extends AbstractSearchEngine {

    HashMap<Integer, State> visited = new HashMap<>();
    Queue<State> queue = new LinkedList<>();// first in first out
    int iterations = 1;


    public BreadthFirstSearchEngine(EightPuzzle eightPuzzle) {
        super(eightPuzzle);
        System.out.println("Breadth First Search Started");
        System.out.println("Initial State:");
        this.queue.offer(eightPuzzle.getInitialState());
    }

    @Override
    public void run() {
        while (!queue.isEmpty()) {
            State currentState = queue.poll();
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
                        queue.add(state);
                    }
                }
            }
        }


    }

}
