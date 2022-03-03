
# filename and n=number of lines of your data 
filedata = 'Output/Earth/e_object3.dat'
n = system(sprintf('cat %s | wc -l', filedata))

do for [j=3500:n] {
    set title 'time '.j
    plot  'Output/Earth/e_object3.dat' u 2:3 every ::1::j w l lw 2, \
          'Output/Earth/e_object3.dat' u 2:3 every ::j::j w p pt 7 ps 2, \
          'Output/Earth/e_object4.dat' u 2:3 every ::1::j w l lw 2, \
          'Output/Earth/e_object4.dat' u 2:3 every ::j::j w p pt 7 ps 2, \
          'Output/Earth/e_object11.dat' u 2:3 every ::1::j w l lw 2, \
          'Output/Earth/e_object11.dat' u 2:3 every ::j::j w p pt 7 ps 2, \
          'Dati_veri_nasa/sonda.txt' u 2:3 every ::1::j w l lw 2,\
          'Dati_veri_nasa/sonda.txt' u 2:3 every ::j::j w p pt 7 ps 2,\
          'Dati_veri_nasa/luna.txt'  u 2:3 every ::1::j w l lw 2,\
          'Dati_veri_nasa/luna.txt'  u 2:3 every ::j::j w p pt 7 ps 2
    pause 0.01
}

