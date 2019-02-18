make:
	lex a_4.l
	yacc -d b_4.y
	g++ lex.yy.c y.tab.c -o out
	./out < input.txt > output.dot
	

clean:
	rm out y.tab.c y.tab.h lex.yy.c output.dot g1.ps
