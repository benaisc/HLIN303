Vous trouvez ici le code source d'un Compresseur de Huffman.

le fichier huf.c est notre code à jour

dans Archive vous trouverez la dernière version fonctionnelle de huf.c qu'il faut compiler avec arbre.c et fonction.c de leurs dossiers respectifs

et l'executer avec un fichier texte quelconque (ok fichiers textes fonctionnels, pas encore..)

La partie decompresseur n'est pas encore codée.. une formalitée me diriez vous ?


Algorithme suivi : 
Etape 0 :
	Compter le nombre d'occurences des char d'un fichier texte
	Construire un arbre
	Associer à chaque occurrences un code binaire en fonction de l'arbre

Etape 1 :
	Lire char par char le fichier
	Lire le code associé au char
	Pour chaque char :
		Concaténer le code à un tableau de 8bits
	Pour chaque tableau :
		Remplir un fichier2 avec la conversion en un entier des 8bits

Etape 2 :
	Lire entier par entier le fichier
	Convertir l'entier en son code binaire
	Remplir un fichier3 des codes binaires concaténés
	Lire bit à bit le fichier
		Avancer dans l'arbre en conséquence
			Arrivé à une feuille
				Ecrire dans un fichier4 la valeur de la feuille
				Repartir de la racine
