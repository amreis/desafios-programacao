#include <iostream>
#include <string>
#include <vector>

using namespace std;

enum ABO { A, B, AB, O };
enum WhatToGuess { FATHER, MOTHER, SON };
struct BloodType {
    ABO abo;
    bool rhPositive;
};
ostream& operator<< (ostream& os, const BloodType& t)
{
    switch(t.abo)
    {
    case A:
        os << 'A';
        break;
    case B:
        os << 'B';
        break;
    case AB:
        os << "AB";
        break;
    case O:
        os << "O";
        break;
    }
    if (t.rhPositive)
        os << '+';
    else os << '-';
    return os;
}

ostream& operator<< (ostream& os, const vector<BloodType>& v)
{
    if (v.empty()) return os;
    if (v.size() == 1)
    {
        os << v[0];
        return os;
    }
    os << "{";
    for (size_t i = 0; i < v.size() - 1; ++i)
    {
        os << v[i] << ", ";
    }
    os << v[v.size()-1] << "}";
    return os;
}

void parseBloodType(string raw, BloodType& out)
{
    if (raw.length() == 3)
    {
        out.abo = AB;
        out.rhPositive = raw[2] == '+';
        return;
    }
    else if (raw[0] == 'A')
        out.abo = A;
    else if (raw[0] == 'B')
        out.abo = B;
    else
        out.abo = O;
    out.rhPositive = raw[1] == '+';
}

void guessMomType(BloodType father, BloodType son, vector<BloodType>& res)
{
    bool otherMustBePositive = son.rhPositive && ! father.rhPositive;
    ABO possibilities[] = { A, B, AB, O };
    vector<ABO> tmp;
    ABO fAbo = father.abo, mAbo;
    for (int i = 0; i < 4; ++i)
    {
        mAbo = possibilities[i];
    
        bool a_possible = fAbo == AB || mAbo == AB ||
                          fAbo == A  || mAbo == A;
                          
        bool b_possible = fAbo == AB || mAbo == AB || 
                          fAbo == B  || mAbo == B;
        bool ab_possible = (fAbo == AB && mAbo == AB) || 
            ((fAbo != mAbo) && (fAbo != O) && (mAbo != O));
            
        bool o_possible = 
            (fAbo != AB && mAbo != AB);
        if ((son.abo == A && a_possible) ||
            (son.abo == B && b_possible) ||
            (son.abo == AB && ab_possible) ||
            (son.abo == O && o_possible) )
        {
            tmp.push_back(mAbo);
        }
    }
    if (tmp.empty()) return;
    for (size_t i = 0; i < tmp.size(); ++i)
    {
        res.push_back( {tmp[i], true} );
        if (! otherMustBePositive ) {
            res.push_back( {tmp[i], false } );
        }
    }
}

void guessSonType(BloodType father, BloodType mother, vector<BloodType>& res)
{
    ABO fAbo, mAbo;
    bool fRh, mRh;
    fAbo = father.abo, fRh = father.rhPositive;
    mAbo = mother.abo, mRh = mother.rhPositive;
    bool canProducePositives = fRh || mRh;
    
    bool a_possible = fAbo == AB || mAbo == AB ||
                      fAbo == A  || mAbo == A;
                      
    bool b_possible = fAbo == AB || mAbo == AB || 
                      fAbo == B  || mAbo == B;
    bool ab_possible = (fAbo == AB && mAbo == AB) || 
        ((fAbo != mAbo) && (fAbo != O) && (mAbo != O));
        
    bool o_possible = 
        (fAbo != AB && mAbo != AB);
        
    if (a_possible)
    {
        res.push_back( {A, false} );
    }
    if (b_possible)
    {
        res.push_back( {B, false} );
    }
    if (ab_possible)
    {
        res.push_back( {AB, false} );
    }
    if (o_possible)
    {
        res.push_back( {O, false} );
    }
    if (canProducePositives)
    {
        if (res.empty()) return;
        const size_t size = res.size();
        for (size_t i = 0; i < size; ++i)
        {
            BloodType b = res[i];
            b.rhPositive = true;
            res.push_back(b);
        }
    }
}

int main()
{
    int nCase = 0;
    while (cin)
    {
        WhatToGuess what;
        BloodType father, mother, son;
        vector<BloodType> res;
        string helper;
        cin >> helper;
        if (helper == "E")
            return 0;
        if (helper == "?")
            what = FATHER;
        else
        {
            parseBloodType(helper, father);
        }
        cin >> helper;
        if (helper == "?")
            what = MOTHER;
        else
        {
            parseBloodType(helper, mother);
        }
        cin >> helper;
        if (helper == "?")
            what = SON;
        else
        {
            parseBloodType(helper, son);
        }
        ++nCase;
        switch (what)
        {
        case FATHER:
            guessMomType(mother,son,res);
            cout << "Case " << nCase << ": ";
            if (res.empty())
                cout << "IMPOSSIBLE " << mother << " " << son << endl;
            
            else 
            {
                cout << res << " " << mother << " " << son << endl;
            }
            break;
        case MOTHER:
            guessMomType(father, son, res);
            cout << "Case " << nCase << ": " << father << " ";
            if (res.empty())
                cout << "IMPOSSIBLE " << son << endl;
            
            else {
                cout << res << " " << son << endl;
            }
            break;
        case SON:
            guessSonType(father,mother,res);
            
            cout << "Case " << nCase << ": " << father << " " << mother << " ";
            cout << res << endl;
        }
        
    }
}
