#include <stdio.h>


int main(void)
{

    /*
     * Pointer is a variable, whose value is the address of another variable.
        One procedure to create pointers is to:
            Define variables of correct type
            Initialize variables
            Define pointers of correct type
            Assign pointers to addresses of associated variables
            Access contents of pointers through * operator
     *
     */

    // Example 1: the basics
    int x = 5;
    int *x_p = 0;  //x_p is a pointer to the type int. I assign 0 to it to make it a null pointer which means it is pointing to nowhere.

    x_p = &x; //& operator is the reference operator. x_p is going to point to x

    x = 7; //directly write to the variable.

    *x_p = 8; // using the pointer to write to the variable. * is dereferencing the pointer.


    // Example 2: pointers to different types

    unsigned int a = 0x00112233;
    unsigned short b = 0x4455;
    printf("%x\n",a);
    printf("%x\n",sizeof(a));
    printf("%x\n",&a);

    printf("%x\n",b);
    printf("%x\n",sizeof(b));
    printf("%x\n",&b);


    unsigned int *aptr = NULL;
    unsigned short *bptr = NULL;

    aptr = &a;
    bptr = &b;

    printf("%x\n",*aptr);
    printf("%x\n",sizeof(*aptr));
    printf("%x\n",aptr);

    printf("%x\n",*bptr);
    printf("%x\n",sizeof(*bptr));
    printf("%x\n",bptr);


    // Example 3: arrays and pointers, arithmetic operations on pointers

    /*
     * Note that when we define an array:
            We are actually defining an address
            Where array[i] is computed by C as (address of array + i * size_of_each_element)
     *
     * Some arithmetic operators are defined on pointers ++, --, +, -
            This is helpful for stepping through arrays, which could be defined using different sizes for elements.
     *
     */
    unsigned short array[10] = {0x0, 0x1111, 0x2222, 0x3333,
                            0x4444, 0x5555, 0x6666, 0x7777, 0x8888, 0x9999};
    unsigned short *arrayptr = array; //notice we don't use &array as array is already an address (a pointer)

    int i;
    for (i = 0; i < 10; i++){
        printf("i = %x ",i);
        printf("arrayptr = %x ",arrayptr + i);
        printf("array[i] = %04x\n",*(arrayptr + i));
        printf("\n");
    }

    // Example 4: having fun with pointers and arithmetic operations on them
    // You can also learn about Big-endian little-endian. Read about it here: https://en.wikipedia.org/wiki/Endianness Which one is MSP432? Big or little endian?
    unsigned int N = 0x11223344;
    unsigned char *Nptr = &N;  //There will be a warning here. Why?
    printf("%02x\n",*Nptr);

    for (i = 0; i<4; i++)
       printf("%02x\n",*(Nptr+i));


    while (1);
}
