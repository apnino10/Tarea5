Results_hw5.pdf : Resultados_hw5.txt Plots.py
	python Plots.py

Resultados_hw5.txt : curva.x
	./curva.x

curva.x : CurvaRotacion.c
	cc CurvaRotacion.c -o curva.x 
