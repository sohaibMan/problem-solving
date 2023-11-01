package cspEtsudoku;

/*************************************************************************
 *  Compilation:  javac Graph.java
 *  Dependencies: ST.java SET.java In.java
 *  
 *  Undirected graph data type implemented using a symbol table
 *  whose keys are vertices (String) and whose values are sets
 *  of neighbors (SET of Strings).
 *
 *  Remarks
 *  -------
 *   - Parallel edges are not allowed
 *   - Self-loop are allowed
 *   - Adjacency lists store many different copies of the same
 *     String. You can use less memory by interning the strings.
 *
 *************************************************************************/

public class Graph {

    // symbol table: key = string vertex, value = set of neighboring vertices
    private final ST<String, SET<String>> st;

    // number of edges
    private int E;

    // create an empty graph
    public Graph() {
        st = new ST<String, SET<String>>();
    }


    // return number of vertices and edges
    public int V() { return st.size(); }
    public int E() { return E;         }

    // return the degree of vertex v 
    public int degree(String v) {
        if (!st.contains(v)) return 0;
        else return st.get(v).size();
    }

    // add w to v's set of neighbors, and add v to w's set of neighbors
    public void addEdge(String v, String w) {
        if (!hasEdge(v, w)) E++;
        if (!hasVertex(v)) addVertex(v);
        if (!hasVertex(w)) addVertex(w);
        st.get(v).add(w);
        st.get(w).add(v);
    }

    // add a new vertex v with no neighbors (if vertex does not yet exist)
    public void addVertex(String v) {
        if (!hasVertex(v)) st.put(v, new SET<String>());
    }

    // return iterator over all vertices in graph
    public Iterable<String> vertices() {
        return st;
    }

    // return an iterator over the neighbors of vertex v
    public Iterable<String> adjacentTo(String v) {
        // return empty set if vertex isn't in graph
        if (!hasVertex(v)) return new SET<String>();
        else               return st.get(v);
    }

    // is v a vertex in the graph?
    public boolean hasVertex(String v) {
        return st.contains(v);
    }

    // is v-w an edge in the graph?
    public boolean hasEdge(String v, String w) {
        if (!hasVertex(v)) return false;
        return st.get(v).contains(w);
    }

    // not very efficient, intended for debugging only
    public String toString() {
        StringBuilder s = new StringBuilder();
        for (String v : st) {
            s.append(v).append(": ");
            for (String w : st.get(v)) {
                s.append(w).append(" ");
            }
            s.append("\n");
        }
        return s.toString();
    }

}

