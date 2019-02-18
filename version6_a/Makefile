make:
	lex a_6.l
	yacc -d b_6.y
	g++ lex.yy.c y.tab.c -o out
	./out < input.txt > output.dot


clean:
	rm out y.tab.c y.tab.h lex.yy.c output.dot g1.ps
