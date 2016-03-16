#include<iostream>
#include<string>
#include<fstream>
const int WORD_LENGTH=365;
const int FREQUENCY_COUNT=3;
using namespace std;

struct WordNode            //定义单词结构体
{
    char word[WORD_LENGTH];//存放单词的数组
    int times;             //单词出现次数
	WordNode *pNext;       //结构体的指针
};

WordNode *pHead=NULL;      //链表的头指针

void CountWord(char *current);//统计函数
WordNode * SearchWord(char *current);//查找函数
void PrintResult();//输出函数
void Release();//释放内存

int main()
{
    
    char temp[WORD_LENGTH];//临时存放单词的词组
    FILE *fp; 
    if(NULL==(fp=fopen("English.txt", "r")))    
	{
        printf("Open file failed!!\n");
        exit(1);
    }
    while( EOF != (fscanf(fp,"%s",temp)) )//读取文件
    {
        CountWord(temp);
    }
    fclose(fp);

    PrintResult();
    Release();
    return 0;
}

void CountWord(char *current)//统计单词
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


WordNode * SearchWord(char *current)//查找单词所在节点
{
   if( NULL == pHead) //当链表为空的时候，也就统计第一个单词时
    {
        pHead = new WordNode;
        strcpy(pHead->word, current);
        pHead->times= 0;
        pHead->pNext = NULL;
        return pHead;
    }
    WordNode *pCurr = pHead;//搜索现有的链表
    WordNode *pPre = NULL;
    while( (NULL != pCurr) && (0 != strcmp(pCurr->word, current)) )
    {
        pPre = pCurr;
        pCurr = pCurr->pNext;
    }

    //该单词不存在
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

//输出结果
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