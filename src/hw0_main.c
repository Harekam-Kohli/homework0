#include <stdio.h>
#include <stdbool.h>


void update(int a, int x, int array[]) {
    array[a-1] = 0;
    for(int i=0; i<x; i++) {
        array[(a+i)%5] += 1;
    }
}

void lastlanded(int a, int x, int array[]) {
    while(true) {
        int y = 0;
        int z = (a+x)%5;
        if(z==1 || z==2 || z==3 || z==4 ) {
            printf("%d %d %d %d | %d\n", array[0], array[1], array[2], array[3], array[4]);
            printf("Last piece landed in section %d. Continue sowing seeds!\n", (a+x)%5);
            if(a+x>5) {
                a=(a+x)%5;
            }
            else {
                a=a+x;
            }
            x= array[a-1];
            if(array[((a+x)-1)%5]==0 && (a+x)%5 != 0) {
                update(a, x, array);
                printf("%d %d %d %d | %d\n", array[0], array[1], array[2], array[3], array[4]);
                printf("You lost because the last counter fell into section %d.\n", (a+x)%5);
                y++;
                break;
            }
            update(a, x, array);
        }
        else {
            break;
        }
    }
}

int main() {
    
int y = 0;
int a;
int x;
    int array[] = {2, 2, 2, 2, 0};
    while (true) {
        if(array[0]==0 && array[1]==0 && array[2]==0 && array[3]==0 ) 
        {
            printf("You won!\n");
            break;
        }

        printf("%d %d %d %d | %d\n", array[0], array[1], array[2], array[3], array[4]);
        printf("Choose a section (1-4): ");
        scanf("%d", &a);
        x = array[a-1];

        if(a!= 1 && a!=2 && a!=3 && a!=4 ) {
            printf("Invalid choice. Choose a section (1-4): ");
            scanf("%d", &a);
        }
        if(x==0) {
            printf("Invalid choice. Choose a section (1-4): ");
            scanf("%d", &a);
        }
        else if(array[((a+x)-1)%5]==0 && (a+x)%5 != 0) {
            update(a, x, array);
            printf("%d %d %d %d | %d\n", array[0], array[1], array[2], array[3], array[4]);
            printf("You lost because the last counter fell into section %d.\n", (a+x)%5);
            break;
        }
        else if(a+x >5 || a+x==4 || a+x==3) {
            if(array[(((a+x)%5)-1)]!=0 || (a+x)%5 == 0)  {
                update(a, x, array);
                if(array[((a+x)%5)-1]!=0 && (a+x)%5 != 0) {
                    lastlanded(a, x, array);
                    if(y==1) {
                        break;
                    }
                }
                else if(array[((a+x)-1)%5]==0 && (a+x)%5 != 0) {
                    printf("You lost because the last counter fell into section %d.\n", (a+x)%5);
                    break;
                }
            }
        }
        else if(a+x<=5) {
            if(array[((a+x)%5)]!=0 || (a+x)%5 == 0)  {
                update(a, x, array);
                if(array[(a+x)%5]!=0 && (a+x)%5 != 0) {
                    lastlanded(a, x, array);
                    break;
                }
                else if(array[((a+x)-1)%5]==0 && (a+x)%5 != 0) {
                    printf("You lost because the last counter fell into section %d.\n", (a+x)%5);
                    break;
                }
            }
        }
    }
    return 0;
}


