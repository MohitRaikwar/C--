#include<iostream>
#include<string.h>
using namespace std;
int compute_score(string);
int main()
{
    
    int score1,score2;
    string word1,word2;
    cout<<"Player 1 \n Enter any word:";
    cin>>word1;
    cout<<"Player 2 \n Enter any word:";
    cin>>word2;
    score1=compute_score(word1);
    score2=compute_score(word2);
    cout<<"Score 1:"<<score1;
    cout<<"\nScore 2:"<<score2;
    if(score1>score2)
    cout<<"\nPlayer 1 wins !\n";
    else if(score1<score2)
    cout<<"\nPlayer 2 wins !\n";
    else cout<<"\nTie\n"; 
    return 0;
}
int compute_score(string s)
{
    int score=0,length;
    int  POINTS[7]={1,2,3,4,5,8,10};
    char type1[20]={'a','A','E','e','I','i','L','l','N','n','O','o','R','r','S','s','T','t','U','u'};
    char type2[8]={'B','b','C','c','M','m','P','p'};
    char type3[4]={'D','d','G','g'};
    char type4[8]={'F','f','H','h','V','v','W','w'};
    char type5[4]={'J','j','X','x'};
    char type6[4]={'Q','q','Z','z'};
    length=s.length();
    for(int i=0;i<length;i++)
    {
        for(int j=0;j<20;j++)
        {
            if(s[i]==type1[j])
            score+=POINTS[0];
        }
         for(int j=0;j<8;j++)
        {
            if(s[i]==type2[j])
            score+=POINTS[2];
        }
         for(int j=0;j<4;j++)
        {
            if(s[i]==type3[j])
            score+=POINTS[1];
        }
         for(int j=0;j<8;j++)
        {
            if(s[i]==type4[j])
            score+=POINTS[3];
        }
        for(int j=0;j<4;j++)
        {
            if(s[i]==type5[j])
            score+=POINTS[5];
        }
        for(int j=0;j<4;j++)
        {
            if(s[i]==type6[j])
            score+=POINTS[6];
        }

        if(s[i]=='K'||s[i]=='k')
        score+=POINTS[4];
    
        else
        score+=0;
    } 
    return score;

}