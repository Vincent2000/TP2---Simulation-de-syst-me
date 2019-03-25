#include <cstdio>
#include <vector>
using namespace std;

struct Position
{
    int unsigned j_; //Position X
    int unsigned i_; //Position Y
};

comparePosition(Position a, Position b)
{
    return a.j_ == b.j_ && a.i_ == b.i_;
}

class Personnage
{
  public:
    Position position_;
    vector<Position> historique_;
    Personnage(int i, int j);
    void move(Position nouvellePosition);
    bool estAutorise(Position nouvellePosition, char configuration, int taille_carte);
    void afficherHistorique();
};

Personnage::Personnage(int i, int j)
{
    position_.i_ = i;
    position_.j_ = j;
    historique_ = vector<Position>();
}

void Personnage::move(Position nouvellePosition)
{
    historique_.push_back(position_);
    position_ = nouvellePosition;
}

bool Personnage::estAutorise(Position nouvellePosition, char configuration, int taille_carte)
{
    int k = 0;
    if (0 <= nouvellePosition.j_ && nouvellePosition.j_ < taille_carte && 0 <= nouvellePosition.i_ && nouvellePosition.i_ < taille_carte)
    {
        if (historique_.size() == 0)
            return true;
        switch (configuration)
        {
        case 'C':
            return true;
            break;

        case 'S':
            return !comparePosition(historique_[historique_.size() - 1], nouvellePosition);
            break;

        case 'U':
            while (k < historique_.size() && !comparePosition(historique_[k], nouvellePosition))
            {
                k++;
            }
            return !comparePosition(historique_[k], nouvellePosition);
            break;

        default:
            printf("Erreur");
            return false;
            break;
        }
    }
    return false;
}

void Personnage::afficherHistorique()
{
    for (int k = 0; k < historique_.size(); k++)
    {
        printf("[%u; %u]\n", historique_[k].i_, historique_[k].j_);
    }
}
