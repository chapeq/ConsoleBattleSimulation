#pragma once
class Capacity {
public:
    // Constructeur initialisant successRate et chargeTurns
    Capacity(int successRate, int chargeTurns);

    // Fonction pour utiliser la capacit� sp�ciale
    // Renvoie true si la capacit� a �t� utilis�e avec succ�s, sinon false
    bool useAbility();

    // Fonction pour r�initialiser la capacit� sp�ciale
    // Renvoie true si la capacit� a �t� utilis�e pr�c�demment, sinon false
    bool resetAbility();

    // Fonction pour diminuer le nombre de tours de charge restants
    void decreaseChargeTurns();

private:
    int mSuccessRate;       // Taux de r�ussite de la capacit� sp�ciale
    int mChargeTurns;       // Nombre de tours avant que la capacit� puisse �tre utilis�e � nouveau
    int mInitChargeTurns;   // Nombre de tours initial avant de pouvoir r�utiliser la capacit�
    bool hasBeenUsed;       // Indique si la capacit� a �t� utilis�e lors du tour actuel
};



