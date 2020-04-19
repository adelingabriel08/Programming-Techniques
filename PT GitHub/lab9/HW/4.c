#include <stdio.h>
#include <stdlib.h>

int x = 200;
int y = 100;

void movedisks(int ndisks, char FromPeg, char toPeg, char auxPeg)
{
    
    printf("<text x=\"%d\" y=\"%d\" font-size=\"20\">ndisks %d</text>\n", x, y,ndisks);
    y += 50;
    if(ndisks == 1) {
		printf("");
    } else {
        movedisks(ndisks - 1, FromPeg, auxPeg, toPeg);
        movedisks(ndisks - 1, auxPeg, toPeg, FromPeg);
    }
}

int main()
{
    printf("<svg xmlns=\"http://www.w3.org/2000/svg\" version=\"1.1\" width=\"%d\" height=\"%d\" >\n", 2000, 5000);
    movedisks(5, 'A', 'C', 'B');
    printf("</svg>");
}
