/* REXX -
   create red/green 25%, 50% and 80% plots. Images are in /images/.

   Usage: makebars >demo.html

   Source: Dennis Peterson
   Free to the world. You assume all risk. Don't make me come looking for you.
   The whole thing could easily have been written in REXX but I need to
   use C from time to time so I don't lose it completely.
*/

say "<HTML>"
say "   <HEAD>"
say "      <TITLE> Bar Graph Demo </TITLE>"
say "   </HEAD>"
say '   <BODY BGCOLOR="#000000" TEXT="#FFFFFF" LINK="#FFFF00" VLINK="#0FFDDD">'
say "      <H3>This is a demonstration of a bar graph for the values of 25%,"
say "      50%, and 80%</H3>"
say "      It's free. Enjoy."
say "      <HR>"
say "      <P>"

'@htmlplot 25 images/'
say "<P>"
'@htmlplot 50 images/'
say "<P>"
'@htmlplot 80 images/'
say "<P>"

say "   </BODY>"
say "</HTML>"
exit
