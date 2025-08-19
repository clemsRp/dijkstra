<h1 align="center">🗺️ Dijkstra Solver</h1>

Bienvenue sur **Dijkstra Solver** !  
Un programme en **C** qui implémente l’algorithme de **Dijkstra** afin de calculer le plus court chemin entre deux sommets d’un graphe. Le graphe est défini dans un fichier texte passé en paramètre. 🚀

## 📌 Fonctionnalités
- 📂 Lecture et parsing d’un graphe à partir d’un fichier texte
- 🔗 Construction du graphe sous forme de **liste d’adjacence**
- 🧮 Calcul du **plus court chemin** entre deux nœuds avec l’algorithme de Dijkstra
- 🖥️ Affichage clair du chemin trouvé et de sa distance totale
- ✅ Gestion de la saisie des nœuds de départ (`start`) et d’arrivée (`end`)

## 🛠 Technologies utilisées
- **Langage** : C (ANSI C)
- **Outils** : `gcc`, `make`
- **Algorithmie** : Algorithme de Dijkstra avec liste d’adjacence

## 🚀 Installation et Exécution

```sh
# Cloner le projet
git clone https://github.com/clemsRp/dijkstra_solver.git
cd dijkstra_solver

# Compiler le programme
make

# Exécuter avec un fichier de graphe, un start et un end
./dijkstra_solver graphe.txt A D
