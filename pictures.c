#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <unistd.h>
#include <time.h>
#include <png.h>

#include "pictures.h"
#include "map.h"

<<<<<<< HEAD
void readInputPng(){
#include <png.h>

#include "pictures.h"
#include "map.h"

=======
>>>>>>> pngFiles
#define PNG_DEBUG 3
#define ALL_TO_ALIVE_RATIO 10 // value for initial map creation: 3 means 1 in 3 is alive

void abort_(const char * s, ...)
{
        va_list args;
        va_start(args, s);
        vfprintf(stderr, s, args);
        fprintf(stderr, "\n");
        va_end(args);
        abort();
}

int x, y;

int width, height;
png_byte color_type;
png_byte bit_depth;

png_structp png_ptr;
png_infop info_ptr;
int number_of_passes;
png_bytep * row_pointers;

void readPngFile(char* file_name){
         char header[8];    // 8 is the maximum size that can be checked

        /* open file and test for it being a png */
        FILE *fp = fopen(file_name, "rb");
        if (!fp)
                abort_("[read_png_file] File %s could not be opened for reading", file_name);
        fread(header, 1, 8, fp);
        if (png_sig_cmp(header, 0, 8))
                abort_("[read_png_file] File %s is not recognized as a PNG file", file_name);


        /* initialize stuff */
        png_ptr = png_create_read_struct(PNG_LIBPNG_VER_STRING, NULL, NULL, NULL);

        if (!png_ptr)
                abort_("[read_png_file] png_create_read_struct failed");

        info_ptr = png_create_info_struct(png_ptr);
        if (!info_ptr)
                abort_("[read_png_file] png_create_info_struct failed");

        if (setjmp(png_jmpbuf(png_ptr)))
                abort_("[read_png_file] Error during init_io");

        png_init_io(png_ptr, fp);
        png_set_sig_bytes(png_ptr, 8);

        png_read_info(png_ptr, info_ptr);

        width = png_get_image_width(png_ptr, info_ptr);
        height = png_get_image_height(png_ptr, info_ptr);
        color_type = png_get_color_type(png_ptr, info_ptr);
        bit_depth = png_get_bit_depth(png_ptr, info_ptr);

        number_of_passes = png_set_interlace_handling(png_ptr);
        png_read_update_info(png_ptr, info_ptr);


        /* read file */
        if (setjmp(png_jmpbuf(png_ptr)))
                abort_("[read_png_file] Error during read_image");

        row_pointers = (png_bytep*) malloc(sizeof(png_bytep) * height);
        for (y=0; y<height; y++)
                row_pointers[y] = (png_byte*) malloc(png_get_rowbytes(png_ptr,info_ptr));

        png_read_image(png_ptr, row_pointers);

        fclose(fp);
  
}

void savePngFile(char* file_name){
          /* create file */
        FILE *fp = fopen(file_name, "wb");
        if (!fp)
                abort_("[write_png_file] File %s could not be opened for writing", file_name);


        /* initialize stuff */
        png_ptr = png_create_write_struct(PNG_LIBPNG_VER_STRING, NULL, NULL, NULL);

        if (!png_ptr)
                abort_("[write_png_file] png_create_write_struct failed");

        info_ptr = png_create_info_struct(png_ptr);
        if (!info_ptr)
                abort_("[write_png_file] png_create_info_struct failed");

        if (setjmp(png_jmpbuf(png_ptr)))
                abort_("[write_png_file] Error during init_io");

        png_init_io(png_ptr, fp);


        /* write header */
        if (setjmp(png_jmpbuf(png_ptr)))
                abort_("[write_png_file] Error during writing header");

        png_set_IHDR(png_ptr, info_ptr, width, height,
                     bit_depth, color_type, PNG_INTERLACE_NONE,
                     PNG_COMPRESSION_TYPE_BASE, PNG_FILTER_TYPE_BASE);

        png_write_info(png_ptr, info_ptr);


        /* write bytes */
        if (setjmp(png_jmpbuf(png_ptr)))
                abort_("[write_png_file] Error during writing bytes");

        png_write_image(png_ptr, row_pointers);


        /* end write */
        if (setjmp(png_jmpbuf(png_ptr)))
                abort_("[write_png_file] Error during end of write");

        png_write_end(png_ptr, NULL);

        /* cleanup heap allocation */
        for (y=0; y<height; y++)
                free(row_pointers[y]);
        free(row_pointers);

        fclose(fp);
  
}


void processPngFile(void){

//        if (png_get_color_type(png_ptr, info_ptr) == PNG_COLOR_TYPE_RGB)
//               abort_("[process_file] input file is PNG_COLOR_TYPE_RGB but must be PNG_COLOR_TYPE_RGBA "
//                       "(lacks the alpha channel)");

//        if (png_get_color_type(png_ptr, info_ptr) != PNG_COLOR_TYPE_RGBA)
//                abort_("[process_file] color_type of input file must be PNG_COLOR_TYPE_RGBA (%d) (is %d)",
//                       PNG_COLOR_TYPE_RGBA, png_get_color_type(png_ptr, info_ptr));

        int theSameRandValue;
        srand(time(NULL));
        for (y=0; y<height; y++) {
                png_byte* row = row_pointers[y];
                for (x=0; x<width; x++) {
                        png_byte* ptr = &(row[x*4]);
                        printf("Pixel at position [ %d - %d ] has RGBA values: %d - %d - %d - %d\n",
                               x, y, ptr[0], ptr[1], ptr[2], ptr[3]);

                      
                      theSameRandValue = ((rand()%(ALL_TO_ALIVE_RATIO)) / (ALL_TO_ALIVE_RATIO-1) ); // one in ALL_TO_ALIVE_RATIO shall be black (alive)
                      theSameRandValue = (theSameRandValue + 1 ) % 2; // 0 and 1 substituted
                      theSameRandValue *= 255; // 0 is black, 255 is white;
                      printf("theSameRandValue: %d\n", theSameRandValue);
                      ptr[0] = theSameRandValue;
                      ptr[1] = theSameRandValue;
                      ptr[2] = theSameRandValue;
                      ptr[3] = 255;
                     
                     
                     // ptr[0] = 255; ptr[1] = 255; ptr[2] = 255; ptr[3] = 255;  // full white untransparent canvas
                }
        }

}



void makeBinaryPicture(void){
  int i,j;
  
  
  //TEMPORARY SOLUTIONS FOR INITIALIZING AN ARRAY
  // srand(time(NULL));
  srand(0);
  for(i=1;i<PIXELS-1;i++){
    for(j=1;j<PIXELS-1;j++){
      point[i][j].x = i;
      point[i][j].y = j;
      point[i][j].prevState=rand()%2;
    }
  }

  for(i = 0; i <= PIXELS - 1; i++){
      point[i][0].x = i; 
      point[i][0].y = 0; 
      point[i][0].prevState = 0; 

      point[i][PIXELS-1].x = i;
      point[i][PIXELS-1].y = PIXELS-1;
      point[i][PIXELS-1].prevState = 0;

      point[0][i].x = 0; 
      point[0][i].y = i; 
      point[0][i].prevState = 0; 
  
      point[PIXELS-1][i].x = PIXELS-1; 
      point[PIXELS-1][i].y = i; 
      point[PIXELS-1][i].prevState = 0; 
  }
  
}

void printBinaryPicture(void){
  int i,j;
  for(i = 0; i < PIXELS; i++){
    for(j = 0; j < PIXELS; j++){
      printf("%d",point[i][j].prevState);
    }
    printf("\n");
  }

}
}


