

# filename and n=number of lines of your data 
filedata = 'object1.dat'
n = system(sprintf('cat %s | wc -l', filedata))

do for [j=1:n] {
    set title 'time '.j
    splot 'object0.dat' u 2:3:4 every ::1::j w l lw 2, \
          'object0.dat' u 2:3:4 every ::j::j w p pt 7 ps 2, \
          'object1.dat' u 2:3:4 every ::1::j w l lw 2, \
          'object1.dat' u 2:3:4 every ::j::j w p pt 7 ps 2, \
          'object2.dat' u 2:3:4 every ::1::j w l lw 2, \
          'object2.dat' u 2:3:4 every ::j::j w p pt 7 ps 2, \
          'object3.dat' u 2:3:4 every ::1::j w l lw 2, \
          'object3.dat' u 2:3:4 every ::j::j w p pt 7 ps 2, \
          'object4.dat' u 2:3:4 every ::1::j w l lw 2, \
          'object4.dat' u 2:3:4 every ::j::j w p pt 7 ps 2, \
          'object5.dat' u 2:3:4 every ::1::j w l lw 2, \
          'object5.dat' u 2:3:4 every ::j::j w p pt 7 ps 2, \
          'object6.dat' u 2:3:4 every ::1::j w l lw 2, \
          'object6.dat' u 2:3:4 every ::j::j w p pt 7 ps 2, \
          'object7.dat' u 2:3:4 every ::1::j w l lw 2, \
          'object7.dat' u 2:3:4 every ::j::j w p pt 7 ps 2, \
          'object8.dat' u 2:3:4 every ::1::j w l lw 2, \
          'object8.dat' u 2:3:4 every ::j::j w p pt 7 ps 2, \
          'object9.dat' u 2:3:4 every ::1::j w l lw 2, \
          'object9.dat' u 2:3:4 every ::j::j w p pt 7 ps 2, \
          'object10.dat' u 2:3:4 every ::1::j w l lw 2, \
          'object10.dat' u 2:3:4 every ::j::j w p pt 7 ps 2, \
          'object11.dat' u 2:3:4 every ::1::j w l lw 2, \
          'object11.dat' u 2:3:4 every ::j::j w p pt 7 ps 2, \


    pause 0.1
}

