#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <utility>
#include <algorithm> // pour std::sort

#define OFFSET_DE_UN    1

using namespace std;

bool trierAscendant(const pair<int,int> &p1, const pair<int,int> &p2) { return (p2.second < p1.second); }

void afficherAmisDesAmisv1(int id, const vector<list<int> > &amis, const vector<string> &utilisateurs)
{
    cout << "Les amis des amis de id=" << id << " : " << utilisateurs[id] << " -> ";

    for (list<int>::const_iterator it = amis[id].begin(); it != amis[id].end(); ++it)
    {
        for (list<int>::const_iterator jt = amis[*it].begin(); jt != amis[*it].end(); ++jt)
        {
            cout << " " << *jt;
        }
    }

    cout << endl;
}

void afficherAmisDesAmisv2(int id, const vector<list<int> > &amis, const vector<string> &utilisateurs)
{
    cout << "Les amis des amis de id=" << id << " : " << utilisateurs[id] << " -> ";

    for (list<int>::const_iterator it = amis[id].begin(); it != amis[id].end(); ++it)
    {
        for (list<int>::const_iterator jt = amis[*it].begin(); jt != amis[*it].end(); ++jt)
        {
            if (*jt != id)
            {
                cout << " " << *jt;
            }
        }
    }

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

void afficherAmisDesAmisv3(int id, const vector<list<int> > &amis, const vector<string> &utilisateurs)
{
    cout << "Les amis des amis de id=" << id << " : " << utilisateurs[id] << " -> ";

    for (list<int>::const_iterator it = amis[id].begin(); it != amis[id].end(); ++it)
    {
        for (list<int>::const_iterator jt = amis[*it].begin(); jt != amis[*it].end(); ++jt)
        {
            if (*jt != id && !estAmi(*jt, amis[id]))
            {
                cout << " " << *jt;
            }
        }

    }
    cout << endl;
}

void amisEnCommuns(int id, const vector<list<int> > &amis, map<int,int> &communs)
{
    int cpt = 0;

    for (int i = 0; i < amis.size(); i++)
    {
        cpt = 0;
        if (i != id)
        {
            for (list<int>::const_iterator it = amis[i].begin(); it != amis[i].end(); ++it)
            {
                if (estAmi(*it, amis[id]) && !estAmi(i, amis[id]))
                {
                    cpt++;
                }
            }
        }

        if (cpt != 0)
        {
            communs[i] = cpt;
        }
    }
}

void afficherAmisInterets(string interet, const list<pair<int,string> > &interets)
{
    cout << "Utilisateur(s) partageant un intérêt pour \"" << interet << "\" : " << endl;
    
    for (list<pair<int,string> >::const_iterator it = interets.begin(); it != interets.end(); ++it)
    {
        if (it->second == interet)
        {
            cout << " " << it->first;
        }
    }
    cout << endl;
}

void afficherInteretsUtilisateurs(const map<string,list<int> > &interetsUtilisateurs)
{
    cout << "Liste des utilisateurs pour chaque intérêt : " << endl;
    
    for (map<string,list<int> >::const_iterator it = interetsUtilisateurs.begin(); it != interetsUtilisateurs.end(); ++it)
    {
        cout << it->first << " : ";

        for (list<int>::const_iterator jt = it->second.begin(); jt != it->second.end(); ++jt)
        {
            cout << *jt << " ";
        }

        cout << endl;
    }
}

void afficherUtilisateursInterets(const map<int,list<string> > &utilisateursInterets)
{
    cout << "Liste d'intérêts pour chaque utilisateur : " << endl;
    
    for (map<int,list<string> >::const_iterator it = utilisateursInterets.begin(); it != utilisateursInterets.end(); ++it)
    {
        cout << it->first << " : ";

        for (list<string>::const_iterator jt = it->second.begin(); jt != it->second.end(); ++jt)
        {
            cout << *jt << " ";
        }

        cout << endl;
    }
}

void afficherInteretsCommuns(int id, const list<string> &listeInterets, const list<pair<int,string> > &interets)
{
    for (list<string>::const_iterator it = listeInterets.begin(); it != listeInterets.end(); ++it)
    {
        cout << *it << " : ";
        for (list<pair<int,string> >::const_iterator jt = interets.begin(); jt != interets.end(); ++jt)
        {
            if (*it == jt->second && jt->first != id)
            {
                cout << jt->first << " ";
            }
        }

        cout << endl;
    }
}

void afficherPlusInteretsCommuns(int id, const list<string> &listeInterets, const list<pair<int,string> > &interets, const vector<string> &utilisateurs)
{
    vector<map<int,int> > nbInteretsCommuns;

    for(list<string>::const_iterator it = listeInterets.begin(); it != listeInterets.end(); ++it)
    {
        for (list<pair<int,string> >::const_iterator jt = interets.begin(); jt != interets.end(); ++jt)
        {
            if (*it == jt->second && jt->first != id)
            {
                nbInteretsCommuns[jt->first][jt->first] += 1;
            }
        }
    }

    for (int i = 0; i < nbInteretsCommuns.size(); i++)
    {
        cout << nbInteretsCommuns[i][i] << endl;
    }
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
    cout << "Nb utilisateurs: " << nbUtilisateurs << endl;
    
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
    
    for(int i = 0; i < relations.size(); i++)
    {
        listeAmis[relations[i].first].push_back(relations[i].second);
        listeAmis[relations[i].second].push_back(relations[i].first);
    }

    // Question 4 : afficher la liste des identifiants amis de chaque utilisateur
    for(int i = 0; i < nbUtilisateurs; i++)
    {
        cout << "id=" << i << " : " << utilisateurs[i] << " -> ";

        for (list<int>::const_iterator it = listeAmis[i].begin(); it != listeAmis[i].end(); ++it)
        {
            cout << *it << " ";
        }

        cout << endl;
    }
    
    cout << endl;
    
    // Question 5 : calculer et afficher le nombre total d'amis pour chaque utilisateur
    int somme = 0;
    float moyenne;
    cout << "Nb total d'amis" << endl;

    for(int i = 0; i < nbUtilisateurs; i++)
    {
        cout << "id=" << i << " : " << utilisateurs[i] << " -> " << listeAmis[i].size() << endl;
        somme += listeAmis[i].size();
    }
    
    cout << endl;
    
    // Question 6 : calculer et afficher le nombre moyen de connexions entre utilisateurs
    moyenne = (float)somme / nbUtilisateurs;

    cout << "Nb moyens de connexions : " << moyenne << endl;

    cout << endl;
    
    // Question 7 : générer un vector contenant le nombre total d'amis pour chaque utilisateur
    vector<pair<int,int> > listeNbAmis(nbUtilisateurs);
    for (int i = 0; i < nbUtilisateurs; i++)
    {
        listeNbAmis[i].first = i;
        listeNbAmis[i].second = listeAmis[i].size();
    }
    
    // Question 8 : trier ce vector et afficher les utilisateur ayant le plus d'amis
    sort(listeNbAmis.begin(), listeNbAmis.end(), trierAscendant);

    for (int i = 0; i < nbUtilisateurs; i++)
    {
        cout << "id=" << listeNbAmis[i].first << " : " << utilisateurs[listeNbAmis[i].first] << " -> " << listeNbAmis[i].second << endl;
    }

    cout << endl;
    
    // Question 9 : afficher les amis des amis d'un utilisateur
    afficherAmisDesAmisv1(0, listeAmis, utilisateurs);
    
    // Question 10 : afficher les amis des amis d'un utilisateur sans que l'utilisateur apparaisse dans la liste
    afficherAmisDesAmisv2(0, listeAmis, utilisateurs);
    
    // Question 11 : afficher les amis des amis d'un utilisateur en excluant les personnes déjà connues de l'utilisateur
    afficherAmisDesAmisv3(0, listeAmis, utilisateurs);
    afficherAmisDesAmisv3(3, listeAmis, utilisateurs);

    cout << endl;
    
    // Question 12 : générer une liste d'amis communs et l'afficher
    map<int,int> amisCommuns;
    
    amisEnCommuns(3, listeAmis, amisCommuns);

    for (map<int,int>::const_iterator it = amisCommuns.begin(); it != amisCommuns.end(); ++it)
    {
        cout << "id=" << it->first << " : " << utilisateurs[it->first] << " -> " << it->second << endl;
    }

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
    
    for (list<pair<int,string> >::const_iterator it = interets.begin(); it != interets.end(); ++it)
    {
        interetsUtilisateurs[it->second].push_back(it->first);
    }
    
    // Question 15 : afficher cette liste
    afficherInteretsUtilisateurs(interetsUtilisateurs);
    cout << endl;
    
    // Question 16 : générer une liste d'intérêts pour chaque utilisateur
    map<int,list<string> > utilisateursInterets;
    
    for (list<pair<int,string> >::const_iterator it = interets.begin(); it !=interets.end(); ++it)
    {
        utilisateursInterets[it->first].push_back(it->second);
    }

    // Question 17 : afficher cette liste
    afficherUtilisateursInterets(utilisateursInterets);
    cout << endl;
    
    // Question 18 : afficher les utilisateurs partageant les intérêts d'un utilisateur
    int id;

    cout << "Entrez l'id de l'utilisateurs: ";
    cin >> id;
    
    cout << "Centre d'intérêts communs : id=" << id << " : " << utilisateurs[id] << endl;

    afficherInteretsCommuns(id, utilisateursInterets[id], interets);
    
    cout << endl;
    
    // Question 19 : afficher les utilisateurs ayant le plus d'intérêts communs avec un utilisateur
    cout << "Utilisateurs ayant le plus d'intérêts en commun : id=" << id << " : " << utilisateurs[id] << endl;

    afficherPlusInteretsCommuns(id, utilisateursInterets[id], interets, utilisateurs);

    cout << endl;

    return 0;
}
