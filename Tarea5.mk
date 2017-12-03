image_targets = Results_hw5.pdf

Results_hw5.pdf : Resultados_hw5.tex Plots.py
	pdflatex $< && python Plots.py

Resultados_hw5.txt : curva.x
	./curva.x

curva.x : CurvaRotacion.c
	cc CurvaRotacion.c -o curva.x 
