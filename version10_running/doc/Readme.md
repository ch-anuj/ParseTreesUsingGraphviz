
TO MAKE & RUN TEST CASES ON LEXER
=================================
    $ make
    $ ./out   <   <file-path/input-file-name>   >   output.dot
    $ dot -Tps output.dot -o g1.ps
// Now go to the main folder and open the graph g1.ps
----------------------
TO CLEAN
----------------------
    $ make clean


--------------------------
INSTRUCTIONS IN MAKE FILE
--------------------------
   $ make:
   $	lex lexer.l
   $	yacc -d parser.y
   $	g++ lex.yy.c y.tab.c -o out

   $ clean:
   $	rm out y.tab.c y.tab.h lex.yy.c output.dot g1.ps


---------
AUTHORS:
---------
1) Anuj Chauhan -- 150119
2) Vipin Chhillar -- 150805

