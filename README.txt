Vous trouvez ici le code source du Compresseur de Huffman de Charles et Victor,

huf.c est notre code à jour qu'il faut compiler avec arbre.c et fonction.c :
$gcc huf.c arbre/arbre.c fonction/fonction.c -o huf

dehuf.c ne remplit pour l'instant qu'un tableau avec l'en-tête : 
$gcc dehuf.c arbre/arbre.c fonction/fonction.c -o dehuf

parcoursRepertoire.py execute huf mais huf ne reconnait pas son argv[1].

Executer avec un fichier texte quelconque (/ok contient des fichiers tests) syntaxe :
$python parcoursRepertoire.py REP
$./huf nom_fichier nom_fichier_compresser
$./dehuf nom_fichier_compresser nom_fichier_decompresser


Algorithme suivi : 
Etape 0 : COMPRESSEUR
	Lire char par char le fichier
		Compter le nombre d'occurences des char
	Construire un arbre
		Associer à chaque occurrences un code binaire en fonction de l'arbre
	Remplir l'en-tête de fichierhuf des codes associés aux char
	Lire char par char le fichier
		Pour chaque char :
			Concaténer le code associé au char à un tableau de 8bits
		Pour chaque tableau :
			Remplir fichierhuf avec la conversion en un char des 8bits

Etape 2 : DECOMPRESSEUR
	Lire l'en-tete et remplir en conséquence un tableau avec le le char et son code
	Lire char par char le fichierhuf
		Convertir le char en son code binaire
			Lire 'bit à bit' le code
				Regarder dans les codes
					Arrivé à une feuille
					Ecrire dans un fichier4 la valeur de la feuille

Etape 3 : Script python qui compresse chaque fichiers d'un repertoire
