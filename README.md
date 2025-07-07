# 🧩 Sudoku Solver

Un résolveur de Sudoku efficace implémenté en C utilisant l'algorithme de backtracking.

## 📋 Table des matières

- [Description](#description)
- [Fonctionnalités](#fonctionnalités)
- [Prérequis](#prérequis)
- [Installation](#installation)
- [Utilisation](#utilisation)
- [Algorithme](#algorithme)
- [Structure du code](#structure-du-code)
- [Exemples](#exemples)
- [Compilation](#compilation)
- [Tests et débogage](#tests-et-débogage)
- [Contribution](#contribution)
- [Licence](#licence)

## 📖 Description

Ce projet implémente un résolveur de Sudoku utilisant l'algorithme de **backtracking**. Le programme peut résoudre automatiquement des grilles de Sudoku 9x9 en respectant les règles classiques du jeu.

Le backtracking est une technique algorithmique qui explore systématiquement toutes les solutions possibles en revenant en arrière (backtrack) lorsqu'une impasse est atteinte.

## ✨ Fonctionnalités

- ✅ Résolution automatique de grilles Sudoku 9x9
- ✅ Affichage formaté de la grille avec bordures
- ✅ Compteur du nombre d'opérations effectuées
- ✅ Validation des contraintes Sudoku (lignes, colonnes, carrés 3x3)
- ✅ Support des grilles partiellement remplies
- ✅ Interface en ligne de commande simple

## 🔧 Prérequis

- **Compilateur C** : GCC ou Clang
- **Make** : Pour utiliser le Makefile
- **Système d'exploitation** : Linux, macOS, ou Windows (avec WSL)

## 🚀 Installation

### Clonage du repository

```bash
git clone <url-du-repository>
cd sudoku-resolver
```

### Compilation

```bash
# Compilation standard
make

# Compilation avec optimisations
make optimized

# Compilation en mode debug
make debug
```

## 💻 Utilisation

### Exécution basique

```bash
# Compiler et exécuter
make run

# Ou exécuter directement
./sudoku_solver
```

### Options de compilation

```bash
# Afficher l'aide
make help

# Nettoyer les fichiers objets
make clean

# Nettoyer complètement
make fclean

# Recompiler entièrement
make re
```

### Tests et débogage

```bash
# Exécuter avec Valgrind (détection de fuites mémoire)
make valgrind

# Compilation avec AddressSanitizer
make debug
```

## 🧠 Algorithme

### Principe du Backtracking

1. **Parcours séquentiel** : Parcourir chaque case vide de la grille
2. **Test des valeurs** : Pour chaque case, tester les valeurs de 1 à 9
3. **Validation** : Vérifier si la valeur respecte les contraintes Sudoku
4. **Récursion** : Si valide, passer à la case suivante
5. **Backtrack** : Si aucune valeur n'est valide, revenir en arrière

### Contraintes Sudoku

- **Ligne** : Chaque chiffre de 1 à 9 doit apparaître une seule fois par ligne
- **Colonne** : Chaque chiffre de 1 à 9 doit apparaître une seule fois par colonne  
- **Carré 3x3** : Chaque chiffre de 1 à 9 doit apparaître une seule fois par carré

## 🏗️ Structure du code

### Fonctions principales

| Fonction | Description |
|----------|-------------|
| `main()` | Point d'entrée, initialise la grille et lance la résolution |
| `solveur()` | Fonction récursive implémentant l'algorithme de backtracking |
| `is_constraint()` | Vérifie si une valeur respecte les contraintes Sudoku |
| `print_board()` | Affiche la grille formatée avec bordures |
| `create_mask_board()` | Crée un masque pour identifier les cases fixes |

### Fonctions utilitaires

| Fonction | Description |
|----------|-------------|
| `is_fix()` | Vérifie si une case est fixe (donnée initiale) |
| `change_line()` | Gère le passage à la ligne suivante |
| `print_tiret()` | Affiche les bordures horizontales de la grille |
| `print_debug()` | Fonction de débogage (commentée par défaut) |

## 📊 Exemples

### Grille d'exemple (définie dans le code)

```
|---|---|---|
|089|000|040|
|000|708|069|
|000|004|301|
|---|---|---|
|010|940|003|
|000|000|000|
|400|067|010|
|---|---|---|
|801|400|000|
|640|302|000|
|090|000|130|
|---|---|---|
```

### Sortie du programme

```bash
$ ./sudoku_solver
|---|---|---|
|589|123|647|
|123|758|469|
|674|694|381|
|---|---|---|
|817|945|263|
|395|281|754|
|426|367|918|
|---|---|---|
|851|479|632|
|647|312|895|
|298|536|174|
|---|---|---|
Nombre de valeurs changé dans ce sudoku: 1234
```

## 🔨 Compilation

### Makefile

Le projet inclut un Makefile complet avec les cibles suivantes :

| Cible | Description |
|-------|-------------|
| `all` | Compilation standard (défaut) |
| `debug` | Compilation avec flags de debug et AddressSanitizer |
| `optimized` | Compilation avec optimisations (-O2) |
| `run` | Compilation et exécution |
| `clean` | Suppression des fichiers objets |
| `fclean` | Nettoyage complet |
| `re` | Recompilation complète |
| `valgrind` | Exécution avec Valgrind |
| `install` | Installation dans /usr/local/bin |
| `uninstall` | Désinstallation |
| `help` | Affichage de l'aide |

### Flags de compilation

- **Standard** : `-Wall -Wextra -Werror -std=c99`
- **Debug** : `-g -fsanitize=address`
- **Optimisé** : `-O2`

## 🧪 Tests et débogage

### Valgrind

```bash
make valgrind
```

Détecte les fuites mémoire et erreurs d'accès.

### AddressSanitizer

```bash
make debug
```

Détection d'erreurs mémoire en temps réel.

### Debug personnalisé

Décommentez la ligne dans `solveur()` pour activer l'affichage de debug :

```c
// print_debug(board, mask_board, line, index);
```

## 🤝 Contribution

Les contributions sont les bienvenues ! Pour contribuer :

1. **Fork** le projet
2. Créez une **branche** pour votre fonctionnalité (`git checkout -b feature/AmazingFeature`)
3. **Committez** vos changements (`git commit -m 'Add some AmazingFeature'`)
4. **Push** vers la branche (`git push origin feature/AmazingFeature`)
5. Ouvrez une **Pull Request**

### Guidelines

- Respecter le style de code existant
- Ajouter des commentaires pour les nouvelles fonctionnalités
- Tester les modifications avant de soumettre
- Mettre à jour la documentation si nécessaire

## 📈 Améliorations possibles

- [ ] Support de grilles de tailles variables (4x4, 16x16)
- [ ] Interface graphique
- [ ] Lecture de grilles depuis un fichier
- [ ] Génération aléatoire de grilles
- [ ] Optimisations algorithmiques (heuristiques)
- [ ] Mode interactif pour saisir une grille
- [ ] Export des solutions vers un fichier

## 📝 Licence

Ce projet est sous licence MIT. Voir le fichier `LICENSE` pour plus de détails.

## 👨‍💻 Auteur

**Etienne** - [edesaint@student.42.fr](mailto:edesaint@student.42.fr)

---

⭐ N'hésitez pas à donner une étoile si ce projet vous a été utile !
