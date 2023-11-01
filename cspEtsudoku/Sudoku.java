package cspEtsudoku;

/**
 * @author Sohaib
 */
public class Sudoku {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        Graph G = new Graph();
        String[][] grille = {{"", "", "", "", "", "", "7", "2", ""},
                {"", "1", "3", "", "", "7", "", "4", ""},
                {"2", "", "", "", "5", "", "", "", "8"},
                {"", "", "", "", "", "6", "4", "7", ""},
                {"7", "8", "", "4", "", "1", "", "3", "6"},
                {"", "9", "4", "3", "", "", "", "", ""},
                {"3", "", "", "", "6", "", "", "", "4"},
                {"", "7", "", "5", "", "", "8", "1", ""},
                {"", "5", "8", "", "", "", "", "", ""}};


        for (int i = 0; i < 9; i++) { // Ligne
            System.out.println();
            for (int j = 0; j < 9; j++) // Colonne
                if (!((String) grille[i][j]).isEmpty())
                    System.out.print(grille[i][j]);
                else
                    System.out.print(".");
        }

        for (int i = 1; i <= 9; i++) // Ligne
            for (int j = 1; j <= 8; j++) // Colonne
                for (int k = j + 1; k <= 9; k++) {
                    String var1 = "x" + i + j;
                    String var2 = "x" + i + k;
                    G.addEdge(var1, var2);
                }

        for (int i = 1; i <= 9; i++) // Colonne
            for (int j = 1; j <= 8; j++) // Ligne
                for (int k = j + 1; k <= 9; k++) {
                    String var1 = "x" + j + i;
                    String var2 = "x" + k + i;
                    G.addEdge(var1, var2);
                }

        for (int ii = 1; ii <= 3; ii++) // Ligne de la sous-grille
            for (int jj = 1; jj <= 3; jj++) { // Colonne de la sous-grille
                int toplefti = (ii - 1) * 3;
                int topleftj = (jj - 1) * 3;
                for (int i = 1; i <= 3; i++) // Colonne dans la sous-grille
                    for (int j = 1; j <= 3; j++) // Ligne dans de la sous-grille
                    {
                        for (int k = 1; k <= 3; k++) // Lignes et colonnes impliquées dans des
                            for (int l = 1; l <= 3; l++)
                                if (k != i && l != j) {
                                    String var1 = "x" + (toplefti + i) + "" + (topleftj + j);
                                    String var2 = "x" + (toplefti + k) + "" + (topleftj + l);
                                    G.addEdge(var1, var2);
                                }
                    }
            }
        ST<String, SET<String>> domainTable = new ST<>();
        Object[][] domains = new Object[9][9];
        for (int i = 0; i < 9; i++) // Colonne
            for (int j = 0; j < 9; j++) // Ligne
                domains[i][j] = new SET<String>();

        for (int i = 0; i < 9; i++) // Colonne
            for (int j = 0; j < 9; j++) { // Ligne
                if (!((String) grille[i][j]).isEmpty())
                    ((SET<String>) domains[i][j]).add(new String((String) grille[i][j])); // Domaine avec une seule valeur (case remplie )
                else {
                    for (int k = 1; k <= 9; k++)
                        ((SET<String>) domains[i][j]).add("" + k);// Domaine avec {1, 2,3, ..., 9} ( case vide)
                }
            }

        for (int i = 1; i <= 9; i++)
            for (int j = 1; j <= 9; j++)
                domainTable.put("x" + i + j, ((SET<String>) domains[i - 1][j - 1]));

        ST<String, String> config = new ST<String, String>();
        for (int i = 1; i <= 9; i++) // Ligne
            for (int j = 1; j <= 9; j++) // Colonne
                config.put("x" + i + j, ""); // Variables non affectées

        for (int i = 1; i <= 9; i++) // Ligne
            for (int j = 1; j <= 9; j++) // Colonne
                config.put("x" + i + j, ""); // Variables non affectées

        for (int i = 1; i <= 9; i++) { // Ligne
            System.out.println("");
            for (int j = 1; j <= 9; j++) // Colonne
                System.out.print(config.get("x" + i + "" + j) + " ");
        }



    }
}
