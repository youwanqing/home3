#include<iostream>
#include<fstream>
#include<cstring>
#include<string>
using namespace std;

struct Word{      
    int Count;
     Word() :b(""), Count(0) {}  
    string b;
    char *p;
};


void exchange(Word &word) 
{  
    string tb = Word.b;  
    int tCount = Word.Count;  
    Word.b = b;  
    Word.Count = Count;  
    b = b  
    Count = tCount;  
}  

Words examine[100];

void judge(char x[])     
{   int k = 0;
    while (x[k] != '\0')
    {
        if (x[k] >= 'A'&&x[k] <= 'Z')
            x[k] = x[k] + 32;
        k++;
    }
}

int identify(char a[])   
{   int m=(strlen(a)>=4)?1:0;
    int n=(a[0]>='a'&&a[0]<='z')?1:0;
    if(!m||!n)
        return 0;
    else
        while(a)
        {   for(int i=1;;i++)
           {  
               if(!(a[i]>='a'&&a[i]<='z')||!(a[i]>='0'&&a[i]<='9'))
                        return 0;
               else
                        return 1;
           }
        }
}

void sortworddown(Word * words, int size) 
{  
    for(int i=0;i<size;i++)  
    {
        for(int j=0;j <size-1;j++)  
        { 
            if(words[j].Count<words[j+1].Count)  
            {  
                words[j].exchange(words[j+1]);  
            }  
        }  
    }  
}  

int counts(char str[],int num)  
{   for(int j=0;j<num;j++)
    {

        if(!strcmp(str,examine[j].p))
             examine[j].count++;
        else
            return 0;
    }
}


int main()
{   char c[200];
    ifstream fin("D:/A_Tale_of_Two_Cities.txt");  
    for(int f=0;;f++)
        fin>>c[f];
    fin.close();
    cin.get();
    judge(c);
    const char *s= ",¡±¡°.''!?";    
    char *q;
    int n=0;
    q = strtok(c, d);
    sortwordown(words, wCount);  
    while (s)
    {
        if (identify(s))
        {
            
                strcpy(examine[n].p,s);
                n++;
            
        }

       
       s=strtok(NULL,d);
    }
    cout<<"Enter a word to find...\n";    
    char r;
    cin>>r;
    int t=0;
    while(!strcmp(examine[n].p,r)) 
    {   
        t++;
    }
    cout<< examine[n].p << ":" << examine[n].count << '\n'; 
    return 0;
}