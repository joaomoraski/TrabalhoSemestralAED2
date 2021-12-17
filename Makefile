run:
	gcc -g -c FuncoesArquivo.c TAD_BufferEntrada.c TAD_BufferSaida.c Ordenacao.c big_file.c main.c
	gcc -g *.o -o main -lm
	./main


clean:
	rm -rfd *.o *.exe main *.dat *.out
	clear