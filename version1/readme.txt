in this version, I will make all the parts for a simple grammar
given as (always use augmented grammar)

S: 	E
E:	E+T
	|T
T:	T*F
	|F
F:	( E )
	|d

commands for running lex & yacc files simultaneously:

lex calc.l
yacc -d calc.y
cc lex.yy.c y.tab.c -o calc


commands for running lex file seperately:

lex calc.l
gcc lex.yy.c -lfl


Note: if you get any error while compiling, the best strategy is to paste the error on google








