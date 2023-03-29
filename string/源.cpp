#include<iostream>

using namespace std;
class MyString
{
public:
	char* ch;
	MyString(string str);
	~MyString();
	int getLength()
	{
		return length;
	}

	bool SubString(MyString& ms, int pos, int len)
	{
		if (pos > length || pos < 1 || pos + len - 1 > length)
			return false;
		for (size_t i = pos; i <= pos + len - 1; i++)
		{
			ms.ch[i - pos + 1] = ch[i];
		}
		ms.length = len;
		return true;
	}

	int StrCompare(MyString &str1,MyString &str2)
	{
		for (size_t i = 1; i <= str1.length || i <= str2.length; i++)
		{
			if (str1.ch[i] != str2.ch[i])
			{
				char a1 = str1.ch[i];
				char a2 = str2.ch[i];
				return a1 - a2;
			}
		}
		return str1.length - str2.length;
	}

	/*int index(MyString &str)
	{
		if (str.length > length)
			return 0;
		int count = 1;
		rsize_t i = 0;
		while (count <= length - str.length + 1)
		{
			for ( i = 1; i <= str.length; i++)
			{
				if (ch[count + i - 1] != str.ch[i])
				{
					break;
				}
			}
			if (i > str.length)
			{
				break;
			}
			else
			{
				count++;
			}	
		}
		if (i > str.length)
		{
			return count;
		}
		return 0;

	}*/

	int index(MyString& str)
	{
		int k = 1;
		int i = k;
		int j = 1;
		while (i <= length && j <= str.length )
		{
			if (ch[i] == str.ch[j])
			{
				i++;
				j++;
			}
			else
			{
				k++;
				i = k;
				j = 1;
			}
		}
		if (j > str.length)
		{
			return k;
		}
		else
		{
			return 0;
		}
	}

	void get_next(MyString &str,int* next)
	{
		int i = 1, j = 0;
		next[1] = 0;
		while (i < str.length)
		{
			if (j == 0 || str.ch[i] == str.ch[j])
			{
				i++;
				j++;
				next[i] = j;
			}
			else
			{
				j = next[j];
			}
		}

	}

	int indexKmp(MyString& str)
	{
		int i = 1, j = 1;
		int* next = new int[str.length + 1]();
		get_next(str, next);
		while (i <= length && j <= str.length)
		{
			if (ch[i] == str.ch[j] || j == 0)
			{
				i++;
				j++;
			}
			else
			{
				j = next[j];
			}
		}
		if (j > str.length)
		{
			return i - str.length;
		}
		else
		{
			return 0;
		}
	
	}

	void printString()
	{
		for (size_t i = 1; i <= length; i++)
		{
			cout << ch[i];
		}
		cout << "\n";
	}

private:
	
	int length;
	int MAXLEN = 255;
};

MyString::MyString(string str)
{
	length = 0;
	ch = new char[MAXLEN]();
	for (size_t i = 0; i < str.size(); i++)
	{
		ch[i + 1] = str[i];
		length++;
	}
}

MyString::~MyString()
{
	delete ch;
}

int main()
{
	MyString str1 = MyString("dfaklhkljahevklhernithneruiwvthmupqhgt4qui4vmrtyq8mtviuqe8qv");
	MyString str2 = MyString("uiw");

	//str1.SubString(str2, 5, 5);
	//str2.printString();

	//cout<<str1.StrCompare(str1, str2);
	
	cout << str1.indexKmp(str2);
	return 0;
}
