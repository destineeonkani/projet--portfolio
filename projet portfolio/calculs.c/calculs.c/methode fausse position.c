#include <stdio.h>

// Définition de la fonction f(x)
double f(double x) {
    return x*x*x - x - 2; // ta fonction exacte
}

int main() {
    double a = 1.0, b = 2.0, c;
    int i, max_iter;

    printf("Entrer le nombre d'iterations : ");
    scanf("%d", &max_iter);

    printf("\nIteration\tc\t\tf(c)\n");
    printf("-------------------------------------\n");

    for(i = 0; i < max_iter; i++) {
        // Calcul de la fausse position
        c = (a*f(b) - b*f(a)) / (f(b) - f(a));

        printf("%d\t\t%.4f\t%.4f\n", i, c, f(c));

        // Mise à jour des bornes selon le signe
        if(f(a)*f(c) < 0)
            b = c;
        else
            a = c;
    }

    printf("\nApproximation finale de la racine : %.4f\n", c);

    return 0;
}
