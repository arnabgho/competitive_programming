#include <stdio.h>
#include <string.h>

char x[1000], y[1000];
int c, r, d, i;
/******** Dynaimc function*******/
int dp(int xi, int yi)
{
    int c1;
    int a=xi+1;
    int b=yi+1;
    int p,q;
    int cost[a][b];
    char step[a][b];
    char ch[a][b];
    for(p=0;p<a;p++){
        cost[p][0]=d*p;
    }
    for(q=0;q<b;q++){
        cost[0][q]=i*q;
    }
    for(p=1;p<a;p++){
        for(q=1;q<b;q++){
            if(x[p]==y[q]){
                cost[p][q] = cost[p-1][q-1] + c;
                step[p][q] = 'C';
                ch[p][q] = '\t';
            }else{
                cost[p][q] = cost[p-1][q-1] + r;
                step[p][q] = 'R';
                ch[p][q] = y[q];
            }
            c1 = cost[p-1][q] + d;
            if(cost[p][q]>=c1){
                cost[p][q] = c1;
                step[p][q] = 'D';
                ch[p][q] = '\t';
            }
            c1 = cost[p][q-1] + i;
            if(cost[p][q]>=c1){
                cost[p][q] = c1;
                step[p][q] = 'I';
                ch[p][q] = y[q];
            }
        }
    }
    return cost[xi][yi];
}

/*********MAIN*********/
int main()
{
    int xi, yi, cost, n;
    scanf("%d", &n);
    while(n>0)
    {
        scanf("%s", x);
        scanf("%s", y);
        scanf("%d %d %d %d", &c, &r, &i, &d);
        xi = strlen(x);
        yi = strlen(y);
        cost = dp(xi, yi);
        printf("%d\n", cost);
        n--;
    }
    return 0;
}
