typedef struct {
    int x, y, z;
    char c;
} bunch_t;



//This function uses pass-by-reference
void increaseBunch_p(bunch_t *inputBunch_p)
{
    inputBunch_p->x = inputBunch_p->x + 1;
    inputBunch_p->y = inputBunch_p->y + 1;
    inputBunch_p->z = inputBunch_p->z + 1;
    inputBunch_p->c = inputBunch_p->c + 1;
}

// This function uses pass-by-value
bunch_t increaseBunch(bunch_t inputBunch)
{
    bunch_t outputBunch;
    outputBunch.x = inputBunch.x+1;
    outputBunch.y = inputBunch.y+1;
    outputBunch.z = inputBunch.z+1;
    outputBunch.c = inputBunch.c+1;

    return outputBunch;
}

int main(void)
{

    bunch_t myBunch = {1, 2, 3, '7'};
    bunch_t newBunch = increaseBunch(myBunch);

    newBunch.c = 5;
    newBunch.x = 10;

    bunch_t *newBunch_p = &newBunch;
    (*newBunch_p).x = 5; // This line and the one below it are exactly the same.
    newBunch_p->x = 5;  // They both modify the member x of the struct that the pointer is pointing to.

    increaseBunch_p(&newBunch);


    while (1);
}
