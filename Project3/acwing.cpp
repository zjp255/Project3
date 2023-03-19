#include<iostream>
using namespace std;
#define N 10
int n;//nΪ��װ��ĸ���
int c1;//��1��װ������
int c2;//��2��װ������ 
int x[N];//����Щ�ڵ���������1����Щ�ڵ�û�д��ȥ 0
int w[N];//ÿ����װ�������
int bestx[N];
int cw;//�����Ѿ���������ļ�װ��ĺ�
int bestcw = 0;//���Ž� 
void backtrack(int t, int c) {
	if (t > n) {
		if (cw > bestcw) {
			bestcw = cw;
			for (int i = 1; i <= n; i++) {
				bestx[i] = x[i];
			}
		}
		else return;
	}
	else {
		if (cw + w[t] <= c) {//���������� 
			cw += w[t];
			x[t] = 1;
			backtrack(t + 1, c);
			cw -= w[t]; //��ԭ
			x[t] = 0;//������һ������������ԭ 
		}
		else {
			x[t] = 0;
			backtrack(t + 1, c);//����������
		}
	}
}
int main() {
	memset(x, 0, sizeof(x));
	memset(bestx, 0, sizeof(bestx));
	cout << "�����뼯װ��ĸ�����" << endl;
	cin >> n;
	cout << "�������һ�Ҵ��������������" << endl;
	cin >> c1;
	cout << "������ڶ��Ҵ��������������" << endl;
	cin >> c2;
	cout << "������ÿ����װ���������" << endl;
	for (int i = 1; i <= n; i++)
		cin >> w[i];
	cout << "��һ�Ҵ���װ�ļ�װ���ǣ�" << endl;
	backtrack(1, c1);
	for (int i = 1; i <= n; i++)
		if (bestx[i])
			cout << i << " ";
	cout << endl;
	cout << "��һ�Ҵ��������������ǣ�";
	cout << bestcw << endl;

	bestcw = 0;
	for (int i = 1; i <= n; i++) {
		if (!bestx[i])
			bestcw += w[i];
	}
	if (bestcw > c2) {
		cout << "���Ҵ�����װ��ʣ�µ����м�װ�䣡" << endl;
	}
	else {
		cout << "�ڶ��Ҵ���װ�ļ�װ���ǣ�";
		for (int i = 1; i <= n; i++)
			if (!bestx[i])
				cout << i << " ";
		cout << endl;
		cout << "�ڶ��Ҵ��������������ǣ�";
		cout << bestcw << endl;
	}
	return 0;
}















//#include <stdio.h>
//#include <conio.h>
//
//int n;//��Ʒ����
//double c;//��������
//double v[100];//������Ʒ�ļ�ֵ
//double w[100];//������Ʒ������
//double cw = 0.0;//��ǰ��������
//double cp = 0.0;//��ǰ��������Ʒ��ֵ
//double bestp = 0.0;//��ǰ���ż�ֵ
//double perp[100];//��λ��Ʒ��ֵ�����
//int order[100];//��Ʒ���
//int put[100];//�����Ƿ�װ��
//
////����λ��ֵ����
//void knapsack()
//{
//    int i, j;
//    int temporder = 0;
//    double temp = 0.0;
//
//    for (i = 1; i <= n; i++)
//        perp[i] = v[i] / w[i];
//    for (i = 1; i <= n - 1; i++)
//    {
//        for (j = i + 1; j <= n; j++)
//            if (perp[i] < perp[j])//ð������perp[],order[],sortv[],sortw[]
//            {
//                temp = perp[i];
//                perp[i] = perp[i];
//                perp[j] = temp;
//
//                temporder = order[i];
//                order[i] = order[j];
//                order[j] = temporder;
//                temp = v[i];
//                v[i] = v[j];
//                v[j] = temp;
//
//                temp = w[i];
//                w[i] = w[j];
//                w[j] = temp;
//            }
//    }
//}
//
////���ݺ���
//void backtrack(int i)
//{
//    double bound(int i);
//    if (i > n)
//    {
//        bestp = cp;
//        return;
//    }
//    if (cw + w[i] <= c)
//    {
//        cw += w[i];
//        cp += v[i];
//        put[i] = 1;
//        backtrack(i + 1);
//        cw -= w[i];
//        cp -= v[i];
//    }
//    if (bound(i + 1) > bestp)//������������������
//        backtrack(i + 1);
//}
//
////�����Ͻ纯��
//double bound(int i)
//{
//    double leftw = c - cw;
//    double b = cp;
//    while (i <= n && w[i] <= leftw)
//    {
//        leftw -= w[i];
//        b += v[i];
//        i++;
//    }
//    if (i <= n)
//        b += v[i] / w[i] * leftw;
//    return b;
//
//}
//
//
//int main()
//{
//    int i;
//    printf("��������Ʒ��������������");
//    scanf_s("%d%lf", &n, &c);
//
//
//    printf("��������Ʒ�������ͼ�ֵ��");
//    for (i = 1; i <= n; i++)
//    {
//        printf("��%d����Ʒ��������", i);
//        scanf_s("%lf", &w[i]);
//        printf("��ֵ�ǣ�");
//        scanf_s("%lf", &v[i]);
//        order[i] = i;
//    }
//    knapsack();
//    backtrack(1);
//
//    printf("��Ҫװ�����Ʒ����ǣ�");
//    for (i = 1; i <= n; i++)
//    {
//        if (put[i] == 1)
//            printf("%d ", order[i]);
//    }
//    return 0;
//}

//#include<iostream>
//using namespace std;
//const int N = 20;
//int n = 0;
//char g[N][N];
//bool col[N], dg[N], udg[N], row[N];
//
//void dfs(int x, int y, int s)
//{
//	if (y == n)
//	{
//		y = 0;
//		x++;
//	}
//	if (x == n)
//	{
//		if (s == n)
//		{
//			for (int i = 0; i < n; i++)
//				puts(g[i]);
//			puts(" ");
//		}
//		return;
//	}
//	//���Żʺ�
//	dfs(x, y + 1, s);
//	//�Żʺ�
//	if (!row[x] && !col[y] && !dg[x + y] && !udg[x - y + n])
//	{
//		g[x][y] = 'Q';
//		row[x] = col[y] = dg[x + y] = udg[x - y + n] = true;
//		dfs(x, y + 1, s + 1);
//		row[x] = col[y] = dg[x + y] = udg[x - y + n] = false;
//		g[x][y] = '.';
//
//	}
//}
//int main()
//{
//	cin >> n;
//	for (int i = 0; i < n; i++)
//		for (int j = 0; j < n; j++)
//			g[i][j] = '.';
//	dfs(0, 0, 0);
//	return 0;
//}



//#include <iostream>
//#include <iomanip>
//#include <string.h>
//#include <cmath>
//#include <algorithm>//�㷨ͷ�ļ�
//using namespace std;
//
//void load_problem2(double arrs[], int num, double c) {//��װ�����������顢��װ�������������� 
//	//Ϊ���鸳ֵ
//	cout << "��ÿ����װ���������ֵ��" << endl;
//	for (int i = 0; i < num; i++) {
//		cin >> arrs[i];
//	}
//	//����
//	sort(arrs, arrs + num);
//	int temp = 0;
//	double currentSpace = c; //����ʣ��ռ�
//
//	for (int i = 0; i < num; i++) {
//		if (currentSpace < arrs[i]) { //ʣ��ռ�С�ڵ�ǰ���� 
//			break;
//		}
//		currentSpace -= arrs[i];
//		temp++;
//	}
//
//	cout << "����װ�£�" << temp << endl;
//}
//
//int main() {
//
//	double c;//������ 
//	int num;//��װ������ 
//	cout << "�������������ͼ�װ��������" << endl;
//	cin >> c >> num;
//	double* arrs = new double[num];
//
//
//	load_problem2(arrs, num, c);
//
//	return 0;
//}
//#include <stdio.h>
//#include <conio.h>
//
//int n;//��Ʒ����
//double c;//��������
//double v[100];//������Ʒ�ļ�ֵ
//double w[100];//������Ʒ������
//double cw = 0.0;//��ǰ��������
//double cp = 0.0;//��ǰ��������Ʒ��ֵ
//double bestp = 0.0;//��ǰ���ż�ֵ
//double perp[100];//��λ��Ʒ��ֵ�����
//int order[100];//��Ʒ���
//int put[100];//�����Ƿ�װ��
//
////����λ��ֵ����
//void knapsack()
//{
//    int i, j;
//    int temporder = 0;
//    double temp = 0.0;
//
//    for (i = 1; i <= n; i++)
//        perp[i] = v[i] / w[i];
//    for (i = 1; i <= n - 1; i++)
//    {
//        for (j = i + 1; j <= n; j++)
//            if (perp[i] < perp[j])//ð������perp[],order[],sortv[],sortw[]
//            {
//                temp = perp[i];
//                perp[i] = perp[i];
//                perp[j] = temp;
//
//                temporder = order[i];
//                order[i] = order[j];
//                order[j] = temporder;
//                temp = v[i];
//                v[i] = v[j];
//                v[j] = temp;
//
//                temp = w[i];
//                w[i] = w[j];
//                w[j] = temp;
//            }
//    }
//}
//
////���ݺ���
//void backtrack(int i)
//{
//    double bound(int i);
//    if (i > n)
//    {
//        bestp = cp;
//        return;
//    }
//    if (cw + w[i] <= c)
//    {
//        cw += w[i];
//        cp += v[i];
//        put[i] = 1;
//        backtrack(i + 1);
//        cw -= w[i];
//        cp -= v[i];
//    }
//    if (bound(i + 1) > bestp)//������������������
//        backtrack(i + 1);
//}
//
////�����Ͻ纯��
//double bound(int i)
//{
//    double leftw = c - cw;
//    double b = cp;
//    while (i <= n && w[i] <= leftw)
//    {
//        leftw -= w[i];
//        b += v[i];
//        i++;
//    }
//    if (i <= n)
//        b += v[i] / w[i] * leftw;
//    return b;
//
//}
//
//
//int main()
//{
//    int i;
//    printf("��������Ʒ��������������");
//    scanf_s("%d%lf", &n, &c);
//
//
//    printf("��������Ʒ�������ͼ�ֵ��");
//    for (i = 1; i <= n; i++)
//    {
//        printf("��%d����Ʒ��������", i);
//        scanf_s("%lf", &w[i]);
//        printf("��ֵ�ǣ�");
//        scanf_s("%lf", &v[i]);
//        order[i] = i;
//    }
//    knapsack();
//    backtrack(1);
//
//    printf("��Ҫװ�����Ʒ����ǣ�");
//    for (i = 1; i <= n; i++)
//    {
//        if (put[i] == 1)
//            printf("%d ", order[i]);
//    }
//    return 0;
//}









//#include <iostream>
//#include<stdio.h>
//#include<stdlib.h>
//using namespace std;
//typedef struct {
//    int s;
//    int f;
//    int index;
//}action;
//
//void sort_action(action a[], int n)
//{
//    int i, j;
//    action temp;
//    for (i = 1; i <= n; i++)
//        for (j = 1; j <= n - i; j++)
//        {
//            if (a[j].f > a[j + 1].f)
//            {
//                temp = a[j];
//                a[j] = a[j + 1];
//                a[j + 1] = temp;
//            }
//        }
//}
//
//int main()
//{
//    int n = 0;
//    cin >> n;
//    action a[100];
//    for (int i = 1; i <= n; i++) {
//        cin >> a[i].s >> a[i].f;
//        a[i].index = i;
//    }
//    sort_action(a, n);
//    bool b[100];
//    int num = 1;
//    b[1] = true;
//    int pretime = a[1].f;
//    for (int i = 2; i <= n; i++) {
//        if (a[i].s >= pretime) {
//            b[i] = true;
//            num++;
//            pretime = a[i].f;
//        }
//        else {
//            b[i] = false;
//        }
//    }
//    
//    cout << num << endl;
//   
//    for (int i = 1; i <= n; i++) {
//        if (b[i]) cout << a[i].index << " ";
//    }
//    return 0;
//}

//#include <stdio.h>
//
//int m[100][100][100];
//
//int max(int a, int b)
//{
//	if (a > b) {
//		return a;
//	}
//	else
//		return b;
//}
//
//int min(int a, int b)
//{
//	if (a > b) {
//		return b;
//	}
//	else
//		return a;
//}
//
//void knapsack(int v[], int w[], int b[], int c, int n, int t)
///*�������ܣ�v[]��w[]�����±��һ��ʼ��ʵ������ĺ������ʽ*/
//{
//	int i, j, k;
//	int jMax = min(w[n] - 1, c);			//�˾����Ҳ���Ի���jMax = w[n]-1��������ܻ�Խ�磬��������
//	int kMax = min(b[n] - 1, t);
//	for (j = 0; j <= jMax; j++)
//		for (k = 0; k <= kMax; k++)
//			m[n][j][k] = 0;
//	for (j = w[n]; j <= c; j++)
//		for (k = b[n]; k <= t; k++)
//			m[n][j][k] = v[n];
//
//	for (i = n - 1; i > 1; i--) {
//		jMax = min(w[n] - 1, c);
//		for (j = 0; j <= jMax; j++)
//			for (k = 0; k <= kMax; k++)
//				m[i][j][k] = m[i + 1][j][k];
//		for (j = w[i]; j <= c; j++)
//			for (k = b[n]; k <= t; k++)
//				m[i][j][k] = max(m[i + 1][j][k], m[i + 1][j - w[i]][k - b[i]] + v[i]);
//	}
//
//	m[1][c][t] = m[2][c][t];
//	if (c >= w[1] && t >= b[1]) {
//		m[1][c][t] = max(m[1][c][t], m[2][c - w[1]][t - b[1]] + v[1]);
//	}
//}
//
//void Traceback(int w[], int b[], int c, int n, int t, int x[])
///*������Ʒ�Ĵ�����0��ʾ���棬1��ʾ��*/
//{
//	int i;
//	for (i = 0; i < n; i++) {
//		if (m[i][c][t] == m[i + 1][c][t])
//			x[i] = 0;
//		else {
//			x[i] = 1;
//			c -= w[i];
//			t -= b[i];
//		}
//	}
//	x[n] = (m[n][c][t]) ? 1 : 0;
//}
//
//int main()
//{
//	int v[100];
//	int w[100];
//	int x[100];
//	int b[100];
//
//	int n, c, i, t;
//
//	printf("��������Ʒ������");
//	scanf_s("%d", &n);
//	printf("�����뱳��������");
//	scanf_s("%d", &c);
//
//	t = 100;
//
//	printf("���������Ʒ��������");
//	for (i = 1; i <= n; i++) scanf_s("%d", &w[i]);
//
//	for (i = 1; i <= n; i++)
//	{
//		b[i] = 1;
//	}
//
//	printf("���������Ʒ�ļ�ֵ��");
//	for (i = 1; i <= n; i++) scanf_s("%d", &v[i]);
//
//	knapsack(v, w, b, c, n, t);
//
//	printf("%d\n", m[1][c][t]);
//
//	return 0;
//}


//#include<iostream>
//using namespace std;
//
//int main()
//{
//    int t = 0;
//    char X[500], Y[500];
//    int a[500][500];
//    cin >> X >> Y;
//
//    int m = strlen(X);
//    int n = strlen(Y);
//    for (int i = 1; i <= m; i++)
//        a[i][0] = 0;
//    for (int j = 1; j <= n; j++)
//        a[0][j] = 0;
//    for (int i = 1; i <= m; i++)
//    {
//        for (int j = 1; j <= n; j++)
//        {
//            if (X[i - 1] == Y[j - 1])
//                a[i][j] = a[i - 1][j - 1] + 1;
//            else
//                a[i][j] = max(a[i - 1][j], a[i][j - 1]);
//        }
//    }
//
//    t = a[m][n];
//    int u = 0;
//    int r = 0;
//    int z = 0;
//    for (int x = 0; x < m; x++)
//    {
//        z = x;
//        for (int y = 0; y < n; y++) {
//            if (X[z] == Y[y]) {
//                u++;
//                z++;
//                if (u == t)
//                {
//                    break;
//
//                }
//
//
//            }
//            else {
//                u = 0;
//            }
//
//        }
//
//
//        if (u == t)
//        {
//
//
//            r = x;
//
//            break;
//
//        }
//
//    }
//    for (int w = r; w < r + t; w++)
//    {
//        cout << X[w] << "  ";
//    }
//
//    return 0;
//}


//#include <iostream>
//#include <string.h>
//using namespace std;
//struct SIGN {
//	int num;
//}l[100 + 5], r[100 + 5]; 
//int n;
//int p[200 + 5];
//int m[100 + 5][100 + 5]; 
//int s[100 + 5][100 + 5];
//
//void MatrixChain()
//{
//	memset(m, 0, sizeof(m));
//	
//	for (int r = 2; r <= n; r++)
//	{
//		
//		for (int i = 1; i <= n - r + 1; i++)
//		{
//			 
//			int j = i + r - 1;
//			if (i > n || j > n) continue;
//			
//			m[i][j] = m[i + 1][j] + p[2 * i] * p[2 * i + 1] * p[2 * j + 1];
//			
//			s[i][j] = i;
//			 
//			for (int k = i + 1; k < j; k++)
//			{
//				int t = m[i][k] + m[k + 1][j] + p[i * 2] * p[k * 2 + 1] * p[j * 2 + 1];
//				if (t < m[i][j])
//				{
//					
//					m[i][j] = t;
//					
//					s[i][j] = k;
//				}
//			}
//			
//		}
//	}
//}
//
//void Traceback(int i, int j)
//{
//	if (i == j) return;
//	Traceback(i, s[i][j]);
//	Traceback(s[i][j] + 1, j);
//	cout << "Multiply A(" << i << "," << s[i][j];
//	cout << ")and A(" << (s[i][j] + 1) << "," << j << ")" << endl;
//	l[i].num++;
//	r[j].num++;
//}
//
//void dealSign()
//{
//	cout << "�������";
//	
//	for (int i = 1; i <= n; i++)
//	{
//		int leftCount = l[i].num;
//		int rightCount = r[i].num;
//		 
//		for (int j = 0; j < leftCount; j++)
//		{
//			cout << "(";
//		}
//		cout << i;
//		for (int j = 0; j < rightCount; j++)
//		{
//			cout << ")";
//		}
//	}
//
//}
//int main()
//{
//	cout << "���������ĸ�����";
//	cin >> n;
//	cout << "������������ά�����ո�ֿ�" << endl;
//	for (int i = 1; i <= n; i++)
//	{
//		cin >> p[i * 2];
//		cin >> p[i * 2 + 1];
//	}
//	MatrixChain();
//	
//	cout << "��С�������Ϊ��" << m[1][n] << endl;
//	memset(l, 0, sizeof(l));
//	memset(r, 0, sizeof(r));
//	Traceback(1, n);
//	dealSign();
//	return 0;
//}


//#include<iostream> 
//using namespace std;
//const int MAXN = 1005;
//int v[MAXN];
//int w[MAXN];
//int f[MAXN][MAXN];
//int main()
//{
//	int n, m;
//	cin >> n >> m;
//	for (int i = 1; i < n; i++)
//		cin >> v[i] >> w[i];
//	for (int i = 1; i < n; i++)
//	{
//		
//		for (int j = 1; j < m; j++)
//		{
//			if (j < v[i])
//			{
//				f[i][j] = f[i - 1][j];
//			}
//			else
//			{
//				f[i][j] = max(f[i-1][j],f[i-1][j-v[i]] + w[i]);
//			}
//		}
//	}
//
//}




















//01��������
/*�� N ����Ʒ��һ�������� V �ı�����ÿ����Ʒֻ��ʹ��һ�Ρ�

�� i ����Ʒ������� vi����ֵ�� wi��

��⽫��Щ��Ʒװ�뱳������ʹ��Щ��Ʒ��������������������������ܼ�ֵ���
�������ֵ��

�����ʽ
��һ������������N��V���ÿո�������ֱ��ʾ��Ʒ�����ͱ����ݻ���

�������� N �У�ÿ���������� vi, wi���ÿո�������ֱ��ʾ�� i ����Ʒ������ͼ�ֵ��

�����ʽ
���һ����������ʾ����ֵ��

���ݷ�Χ
0 < N, V��1000
	0 < vi, wi��1000
	��������
	4 5
	1 2
	2 4
	3 4
	4 5
	���������
	8
	*/
//�ȼ��������Ǯ��
  






//typedef struct Node
//{
//    int elem[2];
//     Node* preNode;
//     Node* next;
//}Node;
//class Llist
//{
//public:
//    Node* headNode;
//    Node* tail;
//    int length;
//    int v;
//    int m;
//
//    void Add(int v, int m)
//    {
//        tail->next = new Node();
//        tail->next->preNode = tail;
//        tail = tail->next;
//        tail->elem[0] = v;
//        tail->elem[1] = m;
//        length++;
//        this->v += v;
//        this->m += m;
//
//    }
//
//    void Clear()
//    {
//        for (int i = length; i > 0; i--)
//        {
//            Node* temp;
//            temp = tail->preNode;
//            delete(tail);
//            tail = temp;
//           
//        }
//        length = 0;
//        v = 0;
//        m = 0;
//    }
//
//    Llist()
//    {
//        length = 0;
//        v = 0;
//        m = 0;
//        headNode = new Node();
//        tail = headNode;
//    }
//};
//
//void Sort(int** num, int n)
//{
//    int temp[3];
//    for (int x = 0; x < n; x++)
//    {
//
//        for (int i = n - 1; i > x; i--)
//        {
//            if (num[i][2] > num[i - 1][2])
//            {
//                temp[0] = num[i - 1][0];
//                temp[1] = num[i - 1][1];
//                temp[2] = num[i - 1][2];
//                num[i - 1][0] = num[i][0];
//                num[i - 1][1] = num[i][1];
//                num[i - 1][2] = num[i][2];
//                num[i][0] = temp[0];
//                num[i][1] = temp[1];
//                num[i][2] = temp[2];
//            }          
//        }
//    }
//    for (int i = 0; i < n - 1; i++)
//    {
//        if (num[i][3] == num[i + 1][3])
//        {
//            if (num[i][1] < num[i + 1][1])
//            {
//                int a = 0;
//                a = num[i][1];
//                num[i][1] = num[i + 1][1];
//                num[i + 1][1] = a;
//            }
//        }
//    }
//}
//int main()
//{
//    int n, v, max;
//    int** num;
//    max = 0;
//    cin >> n >> v;
//    num = new int* [n];
//    for (int i = 0; i < n; i++)
//    {
//        num[i] = new int[3];
//    }
//    for (int i = 0; i < n; i++)
//    {
//        cin >> num[i][0] >> num[i][1];
//        num[i][2] = num[i][1] / num[i][0];
//    }
//    Sort(num, n);
//    Llist* llist = new Llist();
//    int shenyu = v % num[0][0];
//    int count = v / num[0][0];
//    for (int i = 0; i < n; i++)
//    {
//        
//    }
//    
//    cout << max;
//    cin >> max;
//}
    




//ʧ�ܵĳ��ԣ���ٷ�
//#include<iostream>
//using namespace std;
//typedef struct Node
//{
//    int elem[2];
//     Node* preNode;
//     Node* next;
//}Node;
//class Llist
//{
//public:
//    Node* headNode;
//    Node* tail;
//    int length;
//    int v;
//    int m;
//
//    void Add(int v, int m)
//    {
//        tail->next = new Node();
//        tail->next->preNode = tail;
//        tail = tail->next;
//        tail->elem[0] = v;
//        tail->elem[1] = m;
//        length++;
//        this->v += v;
//        this->m += m;
//
//    }
//
//    void Clear()
//    {
//        for (int i = length; i > 0; i--)
//        {
//            Node* temp;
//            temp = tail->preNode;
//            delete(tail);
//            tail = temp;
//           
//        }
//        length = 0;
//        v = 0;
//        m = 0;
//    }
//
//    Llist()
//    {
//        length = 0;
//        v = 0;
//        m = 0;
//        headNode = new Node();
//        tail = headNode;
//    }
//};
//void sort(int** num,int n)
//{
//    int temp[2];
//    for (int x = 0; x < n; x++)
//    {
//
//        for (int i = n - 1; i > x; i--)
//        {
//            if (num[i][0] < num[i - 1][0])
//            {
//                temp[0] = num[i - 1][0];
//                temp[1] = num[i - 1][1];
//                num[i - 1][0] = num[i][0];
//                num[i - 1][1] = num[i][1];
//                num[i][0] = temp[0];
//                num[i][1] = temp[1];
//            }          
//        }
//    }
//    for (int i = 0; i < n - 1; i++)
//    {
//        if (num[i][0] == num[i + 1][0])
//        {
//            if (num[i][1] < num[i + 1][1])
//            {
//                int a = 0;
//                a = num[i][1];
//                num[i][1] = num[i + 1][1];
//                num[i + 1][1] = a;
//            }
//        }
//    }
//}
//int main()
//{
//    int n, v,max;
//    int** num;
//    max = 0;
//    cin >> n >> v;
//    num = new int* [n];
//    for (int i = 0; i < n; i++)
//    {
//        num[i] = new int[2];
//    }
//    for (int i = 0; i < n; i++)
//    {
//        cin >> num[i][0] >> num[i][1];
//    }
//    sort(num,n);
//    for (int i = 0;i < n; i++)
//    {
//        cout << num[i][0] << " ";
//    }
//    cout << endl;
//    for (int i = 0; i < n; i++)
//    {
//        cout << num[i][1] << " ";
//    }
//    Llist* llist = new Llist();
//    for (int i = 0; i < n; i++)
//    {
//
//        for (int x = 0; x < n; x++)
//        {
//            llist->Add(num[i][0], num[i][1]);
//            for (int s = x; s < n; s++)
//            {
//                if (s == i)
//                {
//                    continue;
//                }
//                else if (llist->v + num[s][0] <= v)
//                {
//                    llist->Add(num[s][0], num[s][1]);
//                }
//            }
//            if (llist->v == v)
//            {
//                if (llist->m > max)
//                {
//                    max = llist->m;
//                }
//            }
//            else
//            {
//                llist->Clear();
//            }
//        }
//    }
//    cout << max;
//    cin >> max;
//    return 0;
//}
