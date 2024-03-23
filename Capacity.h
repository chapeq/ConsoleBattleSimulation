#pragma once
class Capacity {
public:
    // Constructeur initialisant successRate et chargeTurns
    Capacity(int successRate, int chargeTurns);

    // Fonction pour utiliser la capacité spéciale
    // Renvoie true si la capacité a été utilisée avec succès, sinon false
    bool useAbility();

    // Fonction pour réinitialiser la capacité spéciale
    // Renvoie true si la capacité a été utilisée précédemment, sinon false
    bool resetAbility();

    // Fonction pour diminuer le nombre de tours de charge restants
    void decreaseChargeTurns();

private:
    int mSuccessRate;       // Taux de réussite de la capacité spéciale
    int mChargeTurns;       // Nombre de tours avant que la capacité puisse être utilisée à nouveau
    int mInitChargeTurns;   // Nombre de tours initial avant de pouvoir réutiliser la capacité
    bool hasBeenUsed;       // Indique si la capacité a été utilisée lors du tour actuel
};



