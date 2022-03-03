
# filename and n=number of lines of your data 
filedata = 'luna.txt'
n = system(sprintf('cat %s | wc -l', filedata))

do for [j=3600:n] {
    set title 'time '.j
    plot  'sonda.txt' u 2:3 every ::1::j w l lw 2,\
          'sonda.txt' u 2:3 every ::j::j w p pt 7 ps 2,\
          'luna.txt' u 2:3 every ::1::j w l lw 2,\
          'luna.txt' u 2:3 every ::j::j w p pt 7 ps 2
    pause 0.001
}
