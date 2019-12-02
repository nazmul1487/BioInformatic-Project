/*
Team Members:
1. Milon Mahato 171-15-1472
2. Md. Nazmul Hassan 171-15-1487
3. Habibur Rahman 171-15-1471
4. Md. Sabiqul Islam 171-15-1476
*/

#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
#include<vector>
#include<map>

using namespace std;

string right_rotataion(string str)
{
    int len = str.length();
    string temp = "";
    temp.push_back(str[len-1]);
    for(int i = 1; i < len; i++)
        temp.push_back(str[i-1]);
    return temp;
}

void firstlook()
{
    printf("\n\n-->Press 1 for Suffix Array.\n");
    printf("-->Press 2 for Burrows Wheeler Transform Matrix & Text.\n");
    printf("-->Press 3 for Inverse Burrows Wheeler Transform.\n");
    printf("-->Press 4 for Exit.\n\n");
}

void suffix_array()
{
    string text, txt;
    printf("Enter Your Text for Suffix Array: ");
    cin >> text; txt = text; txt += '$';
    int len = txt.length();
    vector <string> sfxTxt;
    for(int i = 0; i < len; i++)
    {

        string sfx = txt.substr(i, len);
        sfxTxt.push_back(sfx);
    }
    printf("Suffixes of ""%s"" are:\n\n", text.c_str());
    for(int i = 0; i < sfxTxt.size(); i++)
    {
        printf("\t     ");
        for(int j = 0; j < i; j++)
            cout << ' ';
        cout << sfxTxt[i] << endl;;
    }
    sort(sfxTxt.begin(), sfxTxt.end());
    printf("\nSuffix Array: \n");
    for(int i = 0; i < sfxTxt.size(); i++)
    {
        printf("\t     ");
        cout << sfxTxt[i] <<endl;
    }
    printf("\n\n");
}

void bwt()
{
    printf("Enter your Text for BWT Matrix & Text: ");
    string txt, txt1 = "";
    cin >> txt; txt1 = txt; txt1 += "$";
    int len = txt1.length();
    vector <string> allRotation;
    string str = txt1;
    for(int i = 0; i < len; i++)
    {
        allRotation.push_back(str);
        str = right_rotataion(str);
    }
    sort(allRotation.begin(), allRotation.end());
    printf("\nBurrows Wheeler Transform Matrix: \n");
    for(int i = 0; i < len; i++)
    {
        printf("\t\t\t\t ");
        cout << allRotation[i] << endl;
    }

    cout << endl;
    printf("Burrows Wheeler Transform Text: ");
    for(int i = 0; i < len; i++)
        cout << allRotation[i][len-1];
    printf("\n\n\n");

}

void LFalgo()
{
    string bwt_txt, tmp;
    printf("Enter Burrows - Wheeler Transformed Text: ");

    cin >> bwt_txt;
    int len = bwt_txt.length();
    tmp = bwt_txt;

    vector< pair<char, int> > bwt, rec;

    for(int i = 0; i < len; i++)
    {
        bwt.push_back(make_pair(bwt_txt[i], i));
        rec.push_back(make_pair(bwt_txt[i], i));
    }
    sort(rec.begin(), rec.end());

    int index[len], st;
    for(int i = 0; i < len; i++)
    {
        if(bwt_txt[i] == '$')
        {
            st = i;
            break;
        }
    }
    for(int i = 0; i < len; i++)
    {
        index[i] = rec[st].second;
        st = rec[st].second;
    }
    printf("Your Original Text is: ");
    for(int i = 0; i < len; i++)
        cout << bwt_txt[index[i]];
    cout << endl;
}

int main()
{
    printf("\n***Implementation of Suffix Array, Burrows Wheeler Transform (BWT) Matrix & Text and Inverse BWT Text using C/C++.***\n");
    while(1)
    {
        firstlook();
        int a;
        printf("\nEnter Your Choice: ");
        scanf("%d", &a);
        if(a == 1)
            suffix_array();
        else if(a == 2)
            bwt();
        else if(a == 3)
            LFalgo();
        else if(a == 4)
            return 0;
        else
            printf("\nInvalid Choice. Please Press Anyone from (1/2/3/4).\nThank You.\n\n\n");
    }

    return 0;
}
