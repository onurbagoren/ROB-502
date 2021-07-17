#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

int main()
{
    // char *message = malloc(1024); // 1 kB of memory allocated
    // message[0] = 'H';
    // message[1] = 'e';
    // printf("%s, %ld\n", message, sizeof(message));
    // message[2] = '\0';
    // printf("%s, %ld\n", message, sizeof(message));

    // free(message);

    // message = NULL; // setting to null to remind that the pointer is not being used


    // int width = 1024;
    // int height = 1024;
    // uint8_t *image = malloc( width * height * 3 );  // 4 MB
    //                                                 // *3 is for the 3 channels of the image
    //                                                 // images are typically defined as an array and
    //                                                 // each pixel is at the %3 position

    // for( int y = 0; y < height; y++ )
    // {
    //     for( int x = 0; x <width; x++ )
    //     {
    //         uint8_t *pixel = &image[ (y * width + x) * 3 ]; // y * width gets to the correct row + x gets to the pixel.
    //                                                         // * 3 for the number of channels
    //         image[0] = 0x40;    // R
    //         image[1] = 0xe0;    // G
    //         image[2] = 0xd0;    // B
    //     }
    // }
    // free(image);
    // image = NULL;

    size_t buffer_size = sizeof(char) * 16;
    char *text_buffer = malloc(buffer_size);
    printf("text_buffer: %s", text_buffer);
    free(text_buffer);

    char *message_ = "hello world";
    strncpy( text_buffer, message_, buffer_size);
    free(message_);

    printf("text buffer: %s", text_buffer);
    free(text_buffer);

}
