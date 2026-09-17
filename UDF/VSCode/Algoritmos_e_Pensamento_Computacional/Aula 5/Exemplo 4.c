#include <stdio.h>
#include <string.h>

int main() {
    char s1[50], s2[50];
    printf("Digite a primeira string: ");
    scanf("%s", s1);
    printf("Digite a segunda string: ");
    scanf("%s", s2);
    
    if (strcmp(s1, s2) == 0) {
        printf("As strings são iguais!\n");
    } else if (strcmp(s1, s2) < 0) {
        printf("A primeira string é menor!\n");
    } else if (strcmp(s1, s2) > 0) {
        printf("A segunda string é menor!\n");
    }
    
    return 0;
}