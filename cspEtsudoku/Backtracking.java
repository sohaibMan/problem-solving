package cspEtsudoku;

import java.util.*;

public class Backtracking {

    public static String getVariable(ST<String, String> config, ST<String, SET<String>> domain, Graph graph, boolean useMRV, boolean useDegreeHeuristic) {
        if (useMRV) {
            return getVariableMRV(config, domain);
        } else if (useDegreeHeuristic) {
            return getVariableDegreeHeuristic(config, graph);
        } else
            return getVariableDefault(config);
    }

    private static String getVariableDegreeHeuristic(ST<String, String> config, Graph graph) {
        // select the variable that is involved in the largest number of constraints on other unassigned variables
        String maxDegreeVariable = null;
        int maxDegree = Integer.MIN_VALUE;
        for (String s : config) {
            if (config.get(s).equalsIgnoreCase("")) {
                int degree = 0;
                for (String adj : graph.adjacentTo(s)) {
                    if (config.get(adj).equalsIgnoreCase("")) {
                        degree++;
                    }
                }
                if (degree > maxDegree) {
                    maxDegree = degree;
                    maxDegreeVariable = s;
                }
            }
        }
        return maxDegreeVariable;
    }

    private static String getVariableDefault(ST<String, String> config) {
        for (String s : config) {
            if (config.get(s).equalsIgnoreCase("")) {
                return s;
            }
        }

        return null;
    }

    private static String getVariableMRV(ST<String, String> config, ST<String, SET<String>> domain) {
        String minRemainingVariable = null;
        int minRemainingValues = Integer.MAX_VALUE;

        for (String s : config) {
            if (config.get(s).equalsIgnoreCase("")) {
                int remainingValues = domain.get(s).size();
                if (remainingValues < minRemainingValues) {
                    minRemainingValues = remainingValues;
                    minRemainingVariable = s;
                }
            }
        }

        return minRemainingVariable;
    }

    public static Set<String> orderDomainValue(String variable, ST<String, SET<String>> domain, Graph graph, boolean useLCV) {
        if (useLCV) {
            return orderDomainValueLCV(variable, domain, graph);
        } else {
            return orderDomainValueDefault(variable, domain);
        }
    }

    private static Set<String> orderDomainValueDefault(String variable, ST<String, SET<String>> domain) {
        Set<String> result = new TreeSet<>();
        for (String v : domain.get(variable)) {
            result.add(v);
        }
        return result;
    }

    private static Set<String> orderDomainValueLCV(String variable, ST<String, SET<String>> domain, Graph graph) {
        //prefers the value that rules out the fewest choices
        //for the neighboring variables in the constraint graph. The heuristic is trying to
        //leave the maximum flexibility for subsequent variable assignments.
        //return the SET of domain values for the variable
        SET<String> domainValues = domain.get(variable);
        TreeMap<String, Integer> sortedDomainValues = new TreeMap<>(Comparator.reverseOrder());
        for (String s : domainValues) {
            // calculate the number of values that will be ruled out if we assign this value to the variable
            int ruledOutValues = 0;
            // take all the adjacent variables to the variable
            for (String adj : graph.adjacentTo(variable)) {
                // if we choose s we will rule out all the values that are in the domain of the adjacent variable
                if (domain.get(adj).contains(s)) {
                    ruledOutValues++;
                }
            }
            // add the value to the sorted map
            sortedDomainValues.put(s, ruledOutValues);
        }
        //transform the sorted map to a set
        return sortedDomainValues.keySet();
    }

    public static boolean complete(ST<String, String> config) {

        for (String s : config) {
            //if we find a variable in the config with no value, then this means that the config is NOT complete
            if (config.get(s).equalsIgnoreCase(""))
                return false;
        }

        //ALL variables in config have a value, so the configuration is complete
        return true;
    }


    public static boolean consistent(String value, String variable, ST<String, String> config, Graph g) {

        //we need to get the adjacency list for the variable
        for (String adj : g.adjacentTo(variable)) {

            //if the adjacency list member's value is equal to the variable's selected value, then consistency fails
            if (config.get(adj).equalsIgnoreCase(value)) {
                //consistency check fail

                return false;
            }
        }

        //consistency check passed according to the variable's adjacancy list
        return true;
    }

    public static boolean consistent(String value, String variable, ST<String, String> config,
                                     ST<String, ST<String, ST<String, SET<String>>>> constraintsTable) {

        //we need to get the constraint list for the variable
        for (String constraints : constraintsTable.get(variable)) {
            //if the adjacency list member's value is equal to the variable's selected value, then consistency fails
            if (!config.get(constraints).isEmpty() && !(constraintsTable.get(constraints).get(value).contains(config.get(constraints)))) {
                return false;
            }
        }

        //consistency check passed according to the variable's adjacency list
        return true;
    }

    static void aff(ST<String, String> config) {
        System.out.println();
        System.out.print(" - ");

        if (config == null)
            System.out.print("Pas de solution");
        else
            for (String s : config)
                System.out.print("(" + s + ", " + config.get(s) + ")");


    }

    public static ST<String, String> backtracking
            (ST<String, String> config, ST<String, SET<String>> domain, Graph g) {

        // Arrêter s'il s'agit d'une affectation complete
        if (complete(config))
            return config;

        ST<String, String> result;

        // Variable à affecter
        // sance MRV : String v = getVariable(config, domain, true);
        // String v = getVariable(config, domain, true);
        // Choosing the next variable to assign
        String v = getVariable(config, domain, g, false, false);


        // Domaine de cette variable (liste des valeurs)
        //Choosing a value to assign
        //Once a variable has been selected, the algorithm must decide on the order in
        //which to assign values to it.
        Set<String> vu = orderDomainValue(v, domain, g, false);

        // Parcourir la liste des valeurs
        for (String u : vu) {
            if (consistent(u, v, config, g)) {
                config.put(v, u); //
                // forward checking
                enforceArcConsistency(config, domain, g);
                aff(config);

                result = backtracking(config, domain, g);
                if (result != null)
                    return result;

                config.put(v, ""); // X
                // config.remove(v)
                restoreArcConsistency(config, domain, g);

            }
        }
        return null;
    }

    private static void restoreArcConsistency(ST<String, String> config, ST<String, SET<String>> domain, Graph g) {
        // for each variable in the config
        for (String variable : config) {
            // if the variable is not assigned
            if (config.get(variable).equalsIgnoreCase("")) {
                List<String> toAdd = new ArrayList<>();
                // for each value in the domain of the variable
                for (String value : domain.get(variable)) {
                    // if the value is consistent with the variable
                    if (consistent(value, variable, config, g)) {
                        // add the value to the domain of the variable
                        toAdd.add(value);
                    }
                }
                for (String value : toAdd) {
                    domain.get(variable).add(value);
                }
            }
        }
    }

    private static void enforceArcConsistency(ST<String, String> config, ST<String, SET<String>> domain, Graph g) {
        // for each variable in the config
        for (String variable : config) {
            // if the variable is not assigned
            if (config.get(variable).equalsIgnoreCase("")) {
                List<String> toRemove = new ArrayList<>();
                // for each value in the domain of the variable
                for (String value : domain.get(variable)) {
                    // if the value is not consistent with the variable
                    if (!consistent(value, variable, config, g)) {
                        // remove the value from the domain of the variable
                        toRemove.add(value);
                    }
                }
                for (String value : toRemove) {
                    domain.get(variable).remove(value);
                }

            }
        }
    }


    public static void main(String[] args) {

        // Création du graphe
        long startTime = System.currentTimeMillis();
        Graph G = new Graph();

        // Ajouter des variables et des contraintes
        G.addEdge("x1", "x2");
        G.addEdge("x1", "x3");
        G.addEdge("x1", "x4");
        G.addEdge("x1", "x7");
        G.addEdge("x2", "x6");
        G.addEdge("x3", "x7");
        G.addEdge("x4", "x5");
        G.addEdge("x5", "x6");
        G.addEdge("x5", "x7");

        // Afficher le graphe
        System.out.println(G);


        // Liste des domaines (liste des listes de variables)
        ST<String, SET<String>> domainTable = new ST<>();

        // Création des domaines (vides)
        SET<String> domainX1 = new SET<>();
        SET<String> domainX2 = new SET<>();
        SET<String> domainX3 = new SET<>();
        SET<String> domainX4 = new SET<>();
        SET<String> domainX5 = new SET<>();
        SET<String> domainX6 = new SET<>();
        SET<String> domainX7 = new SET<>();

        // Ajout des valeurs aux domaines
        domainX1.add("R");
        domainX1.add("V");
        domainX1.add("B");

        domainX2.add("R");


        domainX3.add("R");
        domainX3.add("V");
        domainX3.add("B");


        domainX4.add("B");

        domainX5.add("R");
        domainX5.add("V");
        domainX5.add("B");

        domainX6.add("R");
        domainX6.add("B");

        domainX7.add("R");


        // Associer les variables à leurs domaines
        domainTable.put("x1", domainX1);
        domainTable.put("x2", domainX2);
        domainTable.put("x3", domainX3);
        domainTable.put("x4", domainX4);
        domainTable.put("x5", domainX5);
        domainTable.put("x6", domainX6);
        domainTable.put("x7", domainX7);

        // Créer une affectation vide
        ST<String, String> config = new ST<>();

        config.put("x1", "");
        config.put("x2", "");
        config.put("x3", "");
        config.put("x4", "");
        config.put("x5", "");
        config.put("x6", "");
        config.put("x7", "");

        // Appliquer l'algorithme du backtracking
        ST<String, String> result = backtracking(config, domainTable, G);

        // Afficher la solution si elle existe
        aff(result);

        long endTime = System.currentTimeMillis();

        long executionTime = endTime - startTime;
        System.out.println("Execution time: " + executionTime + " milliseconds");
    }

}
