#include <iostream>
#include <fstream>

using namespace std;
int
main ()
{
ofstream ofs ("Moto.dat", ios::out);

if (!ofs)
  {
    cerr << "Ouverture du fichier impossible" << endl;
    return 1;
  }

    ofs << 2 << endl;
    ofs << "Honda shadow " << endl;
    ofs << 1986 << endl;
    ofs << "Honda Valkyrie Rune" << endl;
    ofs << 2004 << endl;
    

    ofs.close();
    {
      ifstream ifs ("Moto.data", ios :: in);
      if (!ifs )
        {
          cerr << "Ouverture du fichier impossible" << endl;
          return 1;
        }
      int n_moto ; 
      ifs >> n_moto;
      ifs.ignore();
      
      char ligne[256];
      for (int i = 0; i < n_moto; i ++)
        {
          ifs.getline(ligne,256);
          cout << "Modèle ; " << ligne << endl;
          int annee ;
          ifs >> annee;
          cout << "Annee ; " << annee << endl;
          ifs.ignore();
        }
    }
    return 0;
}