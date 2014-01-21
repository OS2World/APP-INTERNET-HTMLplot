/*********************
   Source: Dennis Peterson
   dpeterso@halcyon.com
   Free to the world. Your problems are not my problems.

   This program generates a graphic bar for Web pages. It is assumed the
   data is normalized to the range of 0 to 100. The default is to present
   a bar with a red/green line representing percentages of 0% to 100% as
   might be applied to disk usage. Red is used space, green is unused space.
   Use your imagination for other uses. That is why this file is here.

   Code for this was derived from Analog. Analog is a very nice Web server
   log analyzer. Want to know more? Contact Stephen or www.altavista.com.

   NOTICE:
   Analog is copyright (C) Stephen R. E. Turner 1995 - 1997, except those
   parts written by other people.
   .
   .
   .
   Stephen R. E. Turner
   Statistical Laboratory,
   University of Cambridge
   sret1@cam.ac.uk
**********************/

#include <stdio.h>

int plotBar(int, int, char *);
int round(float);

int main(int argc, char **argv)
{
   int in, plot;

   if (argc != 3) {
      fprintf(stderr,"Usage:\thtmlplot n image_dir\n\twhere n is between 0 and 100\n\timage_dir = location of images used by web server (/images/)");
      exit(1);
   }

   in = atoi(argv[1]);

   switch (in)
   {
      case 0:
         plotBar(50, 1, argv[2]);
         return;
         break;

      case 100:
         plotBar(50, 0, argv[2]);
         return;
         break;

      default:
         if (in > 100) {
            fprintf(stderr,"Usage: htmlplot n where n is between 0 and 100\n");
            exit(1);
         }
        if (in < 0) {
            fprintf(stderr,"Usage: htmlplot n where n is between 0 and 100\n");
            exit(1);
         }
         /* Scale the data so line does not exceed 50 total */
         plot = round(in / 2.0);
         plotBar(plot, 0, argv[2]);   /* plot red line */
         plotBar(50 - plot, 1, argv[2]); /* plot green line */
         break;
   }
}

/* 0 = red, 1 = green */
int plotBar(int lineLen, int color, char *image_dir)
{
   int i, k, first = 1;
   char markchar;

   if (color == 0)
      markchar = '-';
   else
      markchar = '+';

   for (k = 32; k >= 1; k /= 2) {
      while (lineLen >= k) {
         printf("<img src=\"");
         printf("%s",image_dir);
         if (color == 0)
            printf("redbar%d.gif\" alt=\"", k);
         else
            printf("greenbar%d.gif\" alt=\"", k);

         if (first) {
            for (i = lineLen; i > 0; i--)
               printf("%c",markchar);
            first = 0;
         }
      printf("\">");
      lineLen -= k;
      }
   }
   return(0);
}

/* return rounded int from float */
int round(float num) {
   if (num - num + 0.5 < 0.0)
      return ((int) num + 1.0);
   else
      return ((int) num);   
}
