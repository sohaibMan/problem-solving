package sohaib_manah;

import java.util.Comparator;
import java.util.HashMap;
import java.util.PriorityQueue;
import java.util.Queue;


/**
 * Title:        AStartSearchEngine<p>
 * Description:  Performs an A start search in an 8 puzzle<p>
 * Company:      Fstt<p>
 * website:      <a href="https://sohaibmanah.netlify.app">Author website</a>
 *
 * @author Sohaib Manah
 * @version 1.0
 */


public class AStartSearchEngine extends AbstractSearchEngine {


    HashMap<Integer, State> open;
    Queue<State> close;


    public AStartSearchEngine(EightPuzzle eightPuzzle) {
        super(eightPuzzle);

        Comparator<State> customComparator = Comparator.comparingInt(a -> a.getEstimatedTotalCost(eightPuzzle.getGoalState()));
        close = new PriorityQueue<>(customComparator);// first in first out
        open = new HashMap<>();
        System.out.println("Breadth First Search Started");
        System.out.println("Initial State:");
        this.close.offer(eightPuzzle.getInitialState());
    }

    @Override
    public void run() {
        int cost = 0;
        while (!close.isEmpty()) {
            State currentState = close.poll();
            if (currentState.compareTo(eightPuzzle.getGoalState()) == 0) {
                System.out.println("Goal state found after " + cost + " iterations");
                break;
            }

            open.put(currentState.hashCode(), currentState);
            currentState.printState();
            currentState.setCost(++cost);

            for (State state : eightPuzzle.getPossibleMoves(currentState)) {
                // prevent loops
                if (open.containsKey(state.hashCode())) {
                    if (open.get(state.hashCode()).getCost() > state.getCost()) {
                        // update the cost
                        open.get(state.hashCode()).setCost(state.getCost());
                    }
                } else {
                    state.printState();
                    close.add(state);
                }
            }

        }


    }

}
