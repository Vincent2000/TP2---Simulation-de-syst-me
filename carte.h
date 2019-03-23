#include <cstdio>
#include <vector>
using namespace std;

class carte
{
  private:
  public:
    vector<vector<int>> tab_;
    carte(/*int const taille*/);
    ~carte();
    void afficherCarte();
};

carte::carte(/*int const taille*/)
{
    // tab_[0]= vector<bool> new vector(false, 20);
    tab_ = vector<vector<int>>(20, vector<int>(20, 0));
}

carte::~carte()
{
}

void carte::afficherCarte()
{
    for (int i = 0; i < tab_.size(); i++)
    {
        for (int j = 0; j < tab_[0].size(); j++)
        {
            if (tab_[i][j] > 0)
                printf("%.2d", tab_[i][j]);
            else
                printf("  ");
            printf("|");
        }
        printf("\n");
    }
}