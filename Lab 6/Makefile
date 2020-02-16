
compRecMS: main.o merge.o mergesortRec.o
  main.o mergesortRec.o merge.o -o recursiveMerge

compIterMS: main.o merge.o mergesortIter.o
  gcc main.o mergesortIter.o merge.o -o iterativeMerge 

runRecMS : compRecMS
  ./recursiveMerge

runIterMS : compIterMS
  ./iterativeMerge

main.o : main.c
  gcc -c main.c

mergeRec.o : mergesortRec.c merge.h
  gcc -c mergesortRec.c

mergeIter.o : mergesortIter.c merge.h
  gcc -c mergesortIter.c

merge.o : merge.c
  gcc -c merge.c

comparing.o : comparing.c
  gcc -c comparing.c

compare : comparing.o merge.o mergesortRec.o mergesortIter.o
  gcc comparing.o mergesortRec.o mergesortIter.o merge.o -o compareMerge
