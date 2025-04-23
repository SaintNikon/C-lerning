set title 'Гармонический сигнал с шумом'
set xlabel 'Время (отсчёты)'
set ylabel 'Амплитуда'
plot 'signal_data.txt' using 1:2 with lines title 'Чистый сигнал', \
     'signal_data.txt' using 1:3 with lines title 'Зашумлённый сигнал', \
     'signal_data.txt' using 1:4 with lines title 'Отфильтрованный сигнал'
pause -1
