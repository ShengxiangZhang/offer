# C++输入读取方式总结

## cin

用cin读取时，遇到空格，制表符，回车会终止输入，并在末尾自动添加空字符。下面举两个例子

```C++
#include<iostream>

using namespace std;
int main() {
	int a, b;
	cin >> a >> b;
	cout << a << endl;
	cout << b;
	return 0;
}

Input: 
10 11(可以是空格，回车，制表符都会终止输入)
Output: 
10
11
```

```C++
#include<iostream>
#include<string>
using namespace std;

int main() {
	string s;
    cin >> s;
    cout << s << endl;
    return 0;
}

Input:
zhangsheng xiang(输入空格后，还可以继续输入，但是后面输入不存入向量中，输入回车则直接中断输入)
Output:
zhangsheng

```

```c++
//0是空字符NULL的ASCII码值，自动添加了空字符
int main() {
    //char s[10];
    string s;
    cin >> s;
    cout << s << endl;
    cout << int(s[5]);
    return 0;
}
Input:
zhang shengxiang
Output:
zhang
0
```

## getline()

getline()读取一行字符串，用回车来确定输入的结尾。值得注意的是，getline()并不会保存换行符，而是用空字符来代替换行符

```c++
#include <iostream>
#include <string>
using namespace std;
 
int main()
{
    //string类型
    string s;
    getline(cin,s);
    cout << s << endl;
    cout << int(s[5]);
    
    //字符数组类型输入
    //char name[50];
    //cin.getline(name,50)
    return 0;
}
Input:
zhang\n
Output:
zhang
0
```

## get

get读取到换行不，不会丢弃，而是把它放在输入队列里面

```c++
#include <iostream>
#include <string>
using namespace std;

int main()
{
    char name1[50];
    char name2[50]
    char a;
    //可以读取换行符，有些场景下可以用它，将换行符吞下，如果是cin>>a;不能读取换行符
    cin.get(a);
    cout << int(a);
    
    //连续读取以换行符分割的两个字符串时
    cin.get(name1,50);
    //需要cin.get()将输入中的换行吞下
    cin.get(name2,50)
    return 0;
}
```

## gets()

 接收一串字符，可以读取空格，但是，gets()函数在读取字符串时，可以超过字符数组的容量

## C/C++中字符串和数组的差别

在C语言中，把一个字符串存入一个数组时，也把结束符 '\0'存入数组，并以此作为该字符串是否结束的标志。

```c++
char a[5] = "asd";
for (int i = 0; a[i] != '\0'; i++) {
}
```

在C++中，提供一个string类，string类会提供 size接口，可以用来判断string类字符串是否结束，就不用'\0'来判断是否结束。

```c++
string a = "asd";
for (int i = 0; i < a.size(); i++) {
}
```