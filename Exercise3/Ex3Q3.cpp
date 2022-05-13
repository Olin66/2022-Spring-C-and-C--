#include <cstdio>
#include <cstring>

#define CLEAR_BUF {int ch; \
while ((ch = getchar()) != EOF && ch != '\n'){;}}


struct CandyBar {
    char *name;
    double weight;
    int calorie;
};

int main(){
    CandyBar* cbs = new CandyBar[3];
    char* maxName;
    double max = 0;
    printf("please input three CandyBar's information\n");
    for (int i = 0; i < 3; i++)
    {
        char* name = new char[20];
        double weight;
        int calorie;
        printf("Enter the brand name of candy bar: ");
        fgets(name, 20, stdin);
        char* find = strchr(name, '\n');
        if(find) *find = '\0';
        printf("Enter the weight: ");
        scanf("%lf", &weight);
        printf("Enter the calories: ");
        scanf("%d", &calorie);
        cbs[i] = {name, weight, calorie};
        if ((calorie/weight) > max)
        {
            maxName = name;
            max = calorie/weight;
        }
        CLEAR_BUF
    }
    printf("Displaying the CandyBar array contents: \n");
    for (int i = 0; i < 3; i++)
    {
        printf("Brand name: %s\n", cbs[i].name);
        printf("Weight: %.1lf\n", cbs[i].weight);
        printf("Calories: %d\n", cbs[i].calorie);
    }
    printf("the greatest calories per weight is: \n");
    printf("Brand name: %s\n", maxName);
    printf("Calories per weight: %.4lf\n", max);
}