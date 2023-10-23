package labyrinthe;


/**
 * Title:        DepthFirstSearchEngine<p>
 * Description:  Performs a depth first search in an 8 puzzle<p>
 * Company:      Fstt<p>
 * website:      <a href="https://sohaibmanah.netlify.app">Author website</a>
 *
 * @author Sohaib Manah
 * @version 1.0
 */
public abstract class AbstractSearchEngine {
    protected EightPuzzle eightPuzzle;

    public AbstractSearchEngine(EightPuzzle eightPuzzle) {
        this.eightPuzzle = eightPuzzle;
    }

    public abstract void run();




}
