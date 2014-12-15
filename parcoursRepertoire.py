#!/usr/bin/env python

import os, re, sys
import ctypes

Fichiers={"":0}

def parcours(rep):
    print "je suis dans : ",rep
    liste=os.listdir(rep)
    for fichier in liste:
        if os.path.isdir(rep+"/"+fichier):
            parcours(rep+'/'+fichier)
        else:
            


parcours(sys.argv[1])
total=0
for fic in Fichiers:
        print fic, ":", Fichiers[fic]
        total+=Fichiers[fic]
print "total :", total
