#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <utility>
#include <algorithm> // pour std::sort

using namespace std;

bool trierAscendant(const pair<int,int> &p1, const pair<int,int> &p2) { return (p2.second < p1.second); }

void afficherAmisDesAmisv1(int id, const vector<list<int> > &amis)
{
    
    cout << endl;
}

void afficherAmisDesAmisv2(int id, const vector<list<int> > &amis)
{
    
    cout << endl;
}

bool estAmi(int id, const list<int> &a)
{
    for(list<int>::const_iterator it=a.begin();it!=a.end();it++)
    {
        if(id == *it)
            return true;
    }
    return false;
}

void afficherAmisDesAmisv3(int id, const vector<list<int> > &amis)
{
    
    cout << endl;
}

void afficherAmisInterets(string interet, const list<pair<int,string> > &interets)
{
    cout << "Utilisateur(s) partageant un intérêt pour \"" << interet << "\" : " << endl;
    
    // TODO
    
    cout << endl;
}

void afficherInteretsUtilisateurs(const map<string,list<int> > &interetsUtilisateurs)
{
    cout << "Liste des utilisateurs pour chaque intérêt : " << endl;
    
    // TODO
    
}

void afficherUtilisateursInterets(const map<int,list<string> > &utilisateursInterets)
{
    cout << "Liste d'intérêts pour chaque utilisateur : " << endl;
    
    // TODO
    
}

int main()
{
    const int nbUtilisateurs = 10;
    
    vector<string> utilisateurs;
    utilisateurs.reserve(nbUtilisateurs);
    utilisateurs.push_back("Hero");
    utilisateurs.push_back("Dun");
    utilisateurs.push_back("Sue");
    utilisateurs.push_back("Chi");
    utilisateurs.push_back("Thor");
    utilisateurs.push_back("Clive");
    utilisateurs.push_back("Hicks");
    utilisateurs.push_back("Devin");
    utilisateurs.push_back("Kate");
    utilisateurs.push_back("Klein");
    
    // Question 1 : afficher la liste des utilisateurs et leurs identifiants
    cout << "Utilisateurs : " << endl;
    
    for (int i = 0; i < nbUtilisateurs; i++)
    {
        cout << "id=" << i << " : " << utilisateurs[i] << endl;
    }
    
    cout << endl;
    
    // Question 2 : afficher le nombre d'utilisateurs
    
    // TODO
    
    cout << endl;
    
    vector<pair<int,int> > relations;
    relations.push_back(make_pair(0, 1));
    relations.push_back(make_pair(0, 2));
    relations.push_back(make_pair(1, 2));
    relations.push_back(make_pair(1, 3));
    relations.push_back(make_pair(2, 3));
    relations.push_back(make_pair(3, 4));
    relations.push_back(make_pair(4, 5));
    relations.push_back(make_pair(5, 6));
    relations.push_back(make_pair(5, 7));
    relations.push_back(make_pair(6, 8));
    relations.push_back(make_pair(7, 8));
    relations.push_back(make_pair(8, 9));
    
    // Question 3 : générer la liste des identifiants amis pour chaque utilisateur
    vector<list<int> > listeAmis(nbUtilisateurs);
    
    // TODO
    
    // Question 4 : afficher la liste des identifiants amis de chaque utilisateur
    
    // TODO
    
    cout << endl;
    
    // Question 5 : calculer et afficher le nombre total d'amis pour chaque utilisateur
    
    // TODO
    
    cout << endl;
    
    // Question 6 : calculer et afficher le nombre moyen de connexions entre utilisateurs
    
    // TODO
    
    cout << endl;
    
    // Question 7 : générer un vector contenant le nombre total d'amis pour chaque utilisateur
    vector<pair<int,int> > listeNbAmis(nbUtilisateurs);
    
    // TODO
    
    // Question 8 : trier ce vector et afficher les utilisateur ayant le plus d'amis
    
    // TODO
    
    cout << endl;
    
    // Question 9 : afficher les amis des amis d'un utilisateur
    
    // TODO
        
    afficherAmisDesAmisv1(0, listeAmis);
    
    // Question 10 : afficher les amis des amis d'un utilisateur sans que l'utilisateur apparaisse dans la liste
    
    // TODO
    
    afficherAmisDesAmisv2(0, listeAmis);
    
    // Question 11 : afficher les amis des amis d'un utilisateur en excluant les personnes déjà connues de l'utilisateur
    
    // TODO
    
    afficherAmisDesAmisv3(0, listeAmis);
    
    // TODO
    
    afficherAmisDesAmisv3(3, listeAmis);
    cout << endl;
    
    // Question 12 : générer une liste d'amis communs et l'afficher
    map<int,int> amisCommuns;
    
    // TODO
    
    cout << endl;
    
    list<pair<int,string> > interets;
    interets.push_back(make_pair(0, "programmation objet"));
    interets.push_back(make_pair(0, "c++"));
    interets.push_back(make_pair(0, "java"));
    interets.push_back(make_pair(1, "programmation objet"));
    interets.push_back(make_pair(1, "java"));
    interets.push_back(make_pair(1, "python"));
    interets.push_back(make_pair(2, "réseaux"));
    interets.push_back(make_pair(2, "socket"));
    interets.push_back(make_pair(2, "java"));
    interets.push_back(make_pair(2, "python"));
    interets.push_back(make_pair(3, "programmation"));
    interets.push_back(make_pair(3, "c"));
    interets.push_back(make_pair(3, "c++"));
    interets.push_back(make_pair(3, "qt"));
    interets.push_back(make_pair(4, "iot"));
    interets.push_back(make_pair(4, "c++"));
    interets.push_back(make_pair(4, "java"));
    interets.push_back(make_pair(4, "programmation objet"));
    interets.push_back(make_pair(5, "réseaux"));
    interets.push_back(make_pair(5, "qt"));
    interets.push_back(make_pair(6, "réseaux"));
    interets.push_back(make_pair(6, "socket"));
    interets.push_back(make_pair(6, "qt"));
    interets.push_back(make_pair(7, "data science"));
    interets.push_back(make_pair(7, "python"));
    interets.push_back(make_pair(7, "hadoop"));
    interets.push_back(make_pair(8, "data science"));
    interets.push_back(make_pair(8, "python"));
    interets.push_back(make_pair(8, "statistiques"));
    interets.push_back(make_pair(8, "mathématiques"));
    interets.push_back(make_pair(9, "data science"));
    interets.push_back(make_pair(9, "hadoop"));
    interets.push_back(make_pair(9, "mongodb"));
    interets.push_back(make_pair(9, "statistiques"));
    interets.push_back(make_pair(9, "python"));
    
    // Question 13 : afficher les utilisateurs ayant un même intérêt
    afficherAmisInterets("programmation objet", interets);
    cout << endl;
    
    // Question 14 : générer une liste d'index d'utilisateurs pour chaque intérêt
    map<string,list<int> > interetsUtilisateurs;
    
    // TODO
    
    // Question 15 : afficher cette liste
    afficherInteretsUtilisateurs(interetsUtilisateurs);
    cout << endl;
    
    // Question 16 : générer une liste d'intérêts pour chaque utilisateur
    map<int,list<string> > utilisateursInterets;
    
    // TODO
    
    // Question 17 : afficher cette liste
    afficherUtilisateursInterets(utilisateursInterets);
    cout << endl;
    
    // Question 18 : afficher les utilisateurs partageant les intérêts d'un utilisateur
    
    // TODO
    
    cout << endl;
    
    // Question 19 : afficher les utilisateurs ayant le plus d'intérêts communs avec un utilisateur
    
    // TODO
    
    return 0;
}
