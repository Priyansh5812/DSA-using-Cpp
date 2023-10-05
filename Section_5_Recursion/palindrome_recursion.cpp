#include <iostream>
using namespace std;
int isPalindrome(int);
int oneDigit(int);
bool isPalUtil(int, int*);

int oneDigit(int num)
{
    return (num >= 0 && num < 10);
}
bool isPalUtil(int num, int* dupNum)
{
    if (oneDigit(num))
        return (num == (*dupNum) % 10);
    if (!isPalUtil(num / 10, dupNum))
        return false;
    *dupNum /= 10;
    return (num % 10 == (*dupNum) % 10);
}
int isPalindrome(int num)
{
    if (num < 0)
        num = -num;
    int* dupNum = new int(num);
    return isPalUtil(num, dupNum);
}

int main()
{
    int n;
    //n = 12321;
    cout<<"Enter a number to check for Palindrome : ";
    cin>>n;
    if(isPalindrome(n))
    {
        cout <<"Yes"<<endl;
        return 0;
    }
    cout <<"No" << endl;
    return 0;
}
