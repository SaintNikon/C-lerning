set title '������������� ������ � �����'
set xlabel '����� (�������)'
set ylabel '���������'
plot 'signal_data.txt' using 1:2 with lines title '������ ������', \
     'signal_data.txt' using 1:3 with lines title '���������� ������', \
     'signal_data.txt' using 1:4 with lines title '��������������� ������'
pause -1
