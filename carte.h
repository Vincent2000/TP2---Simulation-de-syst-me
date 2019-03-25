#include <cstdio>
#include <vector>
using namespace std;

class carte
{
  private:
  public:
    vector<vector<int>> tab_;
    carte();
    void afficherCarte();
};

carte::carte()
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