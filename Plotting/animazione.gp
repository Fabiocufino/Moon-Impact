
# filename and n=number of lines of your data 
filedata = 'Output/All/object0.dat'
n = system(sprintf('cat %s | wc -l', filedata))

do for [j=1:n] {
    set title 'time '.j
    plot  'Output/All/object0.dat'  u 2:3 every ::1::j w l lw 2, \
          'Output/All/object0.dat' u 2:3 every ::j::j w p pt 7 ps 2, \
          'Output/All/object1.dat' u 2:3 every ::1::j w l lw 2, \
          'Output/All/object1.dat' u 2:3 every ::j::j w p pt 7 ps 2, \
          'Output/All/object2.dat' u 2:3 every ::1::j w l lw 2, \
          'Output/All/object2.dat' u 2:3 every ::j::j w p pt 7 ps 2, \
          'Output/All/object3.dat' u 2:3 every ::1::j w l lw 2, \
          'Output/All/object3.dat' u 2:3 every ::j::j w p pt 7 ps 2, \
          'Output/All/object4.dat' u 2:3 every ::1::j w l lw 2, \
          'Output/All/object4.dat' u 2:3 every ::j::j w p pt 7 ps 2, \
          'Output/All/object5.dat' u 2:3 every ::1::j w l lw 2, \
          'Output/All/object5.dat' u 2:3 every ::j::j w p pt 7 ps 2, \
          'Output/All/object6.dat' u 2:3 every ::1::j w l lw 2, \
          'Output/All/object6.dat' u 2:3 every ::j::j w p pt 7 ps 2, \
          'Output/All/object7.dat' u 2:3 every ::1::j w l lw 2, \
          'Output/All/object7.dat' u 2:3 every ::j::j w p pt 7 ps 2, \
          'Output/All/object8.dat' u 2:3 every ::1::j w l lw 2, \
          'Output/All/object8.dat' u 2:3 every ::j::j w p pt 7 ps 2, \
          'Output/All/object9.dat' u 2:3 every ::1::j w l lw 2, \
          'Output/All/object9.dat' u 2:3 every ::j::j w p pt 7 ps 2, \
          'Output/All/object10.dat' u 2:3 every ::1::j w l lw 2, \
          'Output/All/object10.dat' u 2:3 every ::j::j w p pt 7 ps 2, \
          'Output/All/object11.dat' u 2:3 every ::1::j w l lw 2, \
          'Output/All/object11.dat' u 2:3 every ::j::j w p pt 7 ps 2, \

    pause 0.01
}

