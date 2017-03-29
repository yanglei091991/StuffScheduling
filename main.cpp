#include <iostream>
#include <cmath>
#include <cstring>

using namespace std;

#define STUFF_NUM 20 //stuff number
#define SCHEDULING_DAYS 30 //total days to schedule


#define SHIFT_NUM 10 //shift type number
string shiftName[SHIFT_NUM] = {"夜班", "白班", "", "", "", "", "", "", "", ""};

int arrangeTable[STUFF_NUM][SCHEDULING_DAYS] = {0};

bool judgeADay();
bool judgeAStuff();
bool judgeShift();

static int scaleTrans = 0;
void fn(int n, int to, char *buf);
//a N-scale number to generate table
char scaleTransBuf[SCHEDULING_DAYS * STUFF_NUM + 1];
int generateTable(int table[], int id, int length, int possibleNum);



int main()
{

    int table[SCHEDULING_DAYS * STUFF_NUM + 1];

    int length = 4, N = 3;
    for(int i = 0; i < pow(N, length); i++) {
        generateTable(table, i, length, N);
        scaleTrans = 0;
        for(int j = 0; j < length; j++)
            cout<<table[j]<<" ";
        cout<<endl;
    }

    return 0;
}

bool judgeADay()
{
    return true;
}
bool judgeAStuff()
{
    return true;
}
bool judgeShift()
{
    return true;
}



//////////////////////////////////////////////////////////
void RightShift(int *arr, int N, int K){
    while(K--) {
        int t = arr[N-1];
        for(int i = N-1;i>0;i--)
            arr[i]=arr[i-1];
        arr[0]=t;
    }

 }


int generateTable(int table[], int id, int length, int possibleNum)
{
    fn(id, possibleNum, scaleTransBuf);

    for(int i = 0; i < length; i++) {
        if(scaleTransBuf[i] == 0)
            table[i] = 0;
        else
            table[i] = (scaleTransBuf[i] - '0');
    }
    //shift table
    int strLen = strlen(scaleTransBuf);
    if(strLen != length) {
        RightShift(table, length, length - strLen);
    }
    return 1;
}


///////////////////////////////
//n:原数(10进制)  to:将转换成的进制  buf:保存转换后的进制数
void fn(int n, int to, char *buf)
{
    //特殊情况0，独立出来处理
    if (n == 0)
    {
        buf[scaleTrans] = '0';
        return;
    }

    //对于负数的预处理
    if (n < 0)
    {
        buf[scaleTrans] = '-';
        ++scaleTrans;
        n = -n;
    }

    //正整数递归，进行进制转换.
    if (n != 0)
    {
        //递归入栈
        fn(n/to,to,buf);
        //递归弹栈
        switch(n%to)
        {
        case 15: buf[scaleTrans] = 'F'; break;
        case 14: buf[scaleTrans] = 'E'; break;
        case 13: buf[scaleTrans] = 'D'; break;
        case 12: buf[scaleTrans] = 'C'; break;
        case 11: buf[scaleTrans] = 'B'; break;
        case 10: buf[scaleTrans] = 'A'; break;
        default: buf[scaleTrans] = (n%to+'0'); break;
        }
        ++scaleTrans;
    }
}
