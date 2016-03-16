#include<iostream>
#include<string>
#include<fstream>
const int WORD_LENGTH=365;
const int FREQUENCY_COUNT=3;
using namespace std;

struct WordNode            //���嵥�ʽṹ��
{
    char word[WORD_LENGTH];//��ŵ��ʵ�����
    int times;             //���ʳ��ִ���
	WordNode *pNext;       //�ṹ���ָ��
};

WordNode *pHead=NULL;      //�����ͷָ��

void CountWord(char *current);//ͳ�ƺ���
WordNode * SearchWord(char *current);//���Һ���
void PrintResult();//�������
void Release();//�ͷ��ڴ�

int main()
{
    
    char temp[WORD_LENGTH];//��ʱ��ŵ��ʵĴ���
    FILE *fp; 
    if(NULL==(fp=fopen("English.txt", "r")))    
	{
        printf("Open file failed!!\n");
        exit(1);
    }
    while( EOF != (fscanf(fp,"%s",temp)) )//��ȡ�ļ�
    {
        CountWord(temp);
    }
    fclose(fp);

    PrintResult();
    Release();
    return 0;
}

void CountWord(char *current)//ͳ�Ƶ���
{
    WordNode *pNode = NULL;
    pNode = SearchWord(current);
    if(NULL == pNode)
    {
        return;
    }
    else 
	{ 
	   pNode->times++;
    }
	
}


WordNode * SearchWord(char *current)//���ҵ������ڽڵ�
{
   if( NULL == pHead) //������Ϊ�յ�ʱ��Ҳ��ͳ�Ƶ�һ������ʱ
    {
        pHead = new WordNode;
        strcpy(pHead->word, current);
        pHead->times= 0;
        pHead->pNext = NULL;
        return pHead;
    }
    WordNode *pCurr = pHead;//�������е�����
    WordNode *pPre = NULL;
    while( (NULL != pCurr) && (0 != strcmp(pCurr->word, current)) )
    {
        pPre = pCurr;
        pCurr = pCurr->pNext;
    }

    //�õ��ʲ�����
    if(NULL == pCurr)
    {
        pCurr = new WordNode;
        strcpy(pCurr->word, current);
        pCurr->times= 0;
        pCurr->pNext = NULL;
        pPre->pNext = pCurr;
    }
    return pCurr;
}

//������
void PrintResult()
{
	FILE* fp1=fopen("out_all_word_frequency.txt", "w");
	FILE* fp2=fopen("out_high_frequency.txt","w");
    if(NULL == pHead)
    {
        printf("No Word!!\n");
    }
    else
    {
        WordNode *pCurr = pHead;

        while(NULL != pCurr)
        {
			
			 
            fprintf(fp1,"%s\t%d\n", pCurr->word, pCurr->times);
            printf("%s\t%d\n", pCurr->word, pCurr->times);

			if(pCurr->times >= FREQUENCY_COUNT)
				fprintf(fp2,"%s\t%d\n", pCurr->word, pCurr->times);

			pCurr = pCurr->pNext;
		}
		 fclose(fp1);
		 fclose(fp2);
    }
}

void Release()
{
    if(NULL == pHead)
    {
        return;
    }
    WordNode *pCurr = pHead;
    while(NULL != pCurr)
    {
        pHead = pCurr->pNext;
        delete pCurr;
        pCurr = pHead;
    }
}