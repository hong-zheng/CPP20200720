#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <deque>
#include <vector>
using namespace std;

/*
// �º��������� priority_queue �ĵ������������������Ƚ϶���
template<class T>
struct Less
{
	bool operator()(const T& val1, const T& val2)
	{
		return val1 < val2;
	}
};

template<class T>
struct Greater
{
	bool operator()(const T& val1, const T& val2)
	{
		return val1 > val2;
	}
};
 
// ����������ʵ�����ȼ�����
// 1��Ĭ������Ϊ vector
//	�� vector ��ΪĬ�����������ɣ�
//		1�����ȼ���ʵ���Ƕѽṹ�������Ҫ������ʣ������˫�˶��ж��ԣ�vector���������Ч�ʸ��ߣ���deque����Ȼ֧��������ʣ������ڲ�ͬ�Ļ�������Ҫ���л��㣻
//		2������ list ʵ�֣���Ϊ list ��֧���������
//
//2������������ Compare �º���
//ʵ�ֶԶѵĴ�С�Ŀ��ƣ������˴���������
// 
template<class T,class Container = vector<T>,class Compare = Less<T>>
class Priority_Queue
{
public:
	void push(const T& val)
	{
		_c.push_back(val);
		shiftUp(_c.size() - 1);
	}

	void pop()
	{
		swap(_c[0], _c[_c.size() - 1]);
		_c.pop_back();
		shiftDown(0);
	}

	T& front()
	{
		return _c.front();
	}

	T& back()
	{
		return _c.back();
	}

	size_t size() const
	{
		return _c.size();
	}

	bool empty() const
	{
		return _c.empty();
	}
private:
	// ���µ������������������Ƚ�
	void shiftDown(int parent)
	{
		int child = 2 * parent + 1;

		while (child < _c.size())
		{
			if (child + 1 < _c.size() && _cmp(_c[child],_c[child + 1]))
				child++;
			if (_cmp(_c[parent],_c[child]))
			{
				swap(_c[child], _c[parent]);
				parent = child;
				child = 2 * parent + 1;
			}
			else
			{
				break;
			}
		}
	}

	// ���ϵ������͸�������Ƚ�
	void shiftUp(int child)
	{
		int   parent = (child - 1) >> 1;

		// �����ڵ�Ϊ 0 ��ʱ��Ҳ�ǿ��Ե����ģ���Ϊ��ʱ���ӽ����Ȼ����
		while (parent >= 0)
		{
			if (_cmp(_c[parent],_c[child]))
			{
				swap(_c[parent], _c[child]);
				child = parent;
				parent = (child - 1) >> 1;
			}
			else
			{
				break;
			}
		}
	}
private:
	Container _c;
	Compare _cmp;
};
void testpriorityqueueu()
{
	Priority_Queue<int, vector<int>, Greater<int>> pq;
	//Priority_Queue<int, vector<int>, Less<int>> pq;
	pq.push(1);
	pq.push(10);
	pq.push(13);
	pq.push(61);
	pq.push(41);
	pq.push(421);
	pq.push(410);
	pq.push(141);
	pq.push(12);
	pq.push(11);
	 // 1 12 13 41 61 11 10
   	 // 1 13 12 41 11 61 10
	while(!pq.empty())
	{
		cout << pq.front() << " ";
		pq.pop();
	}
	cout << endl;
}

struct Date
{
	Date(int y = 2020,int m = 8,int d = 2)
		:_y(y)
		, _m(m)
		, _d(d)
	{}

	bool operator<(const Date& d) const
	{
		if (_y < d._y)
		{
			return true;
		}
		else if (_y == d._y)
		{
			if (_m < d._m)
			{
				return true;
			}
			else if (_m == d._m)
			{
				if (_d < d._d)
					return true;
			}
		}
		return false;
	}

	bool operator>(const Date& d) const
	{
		if (_y > d._y)
		{
			return true;
		}
		else if (_y == d._y)
		{
			if (_m > d._m)
			{
				return true;
			}
			else if (_m == d._m)
			{
				if (_d > d._d)
					return true;
			}
		}
		return false;
	}
	int _y;
	int _m;
	int _d;
};

ostream& operator<<(ostream& cout, const Date& d)
{
	cout << d._y << "-" << d._m << "-" << d._d << endl;
	return  cout;
}
void testDate()
{
	// �Զ�������ʹ�����ȼ����У���ģ���б����ض���"<,>"�Ĺ��򣬷���º����ڵ��õ�ʱ�򲢲�֪������ʲô����ȥ���Ƚ�
	//Priority_Queue<Date, vector<Date>, Less<Date>> pq;
	Priority_Queue<Date, vector<Date>, Greater<Date>> pq;

	pq.push(Date(2020, 3, 23));
	pq.push(Date(2000, 9, 13));
	pq.push(Date(1990, 10, 30));
	pq.push(Date(3020, 3, 23));
	pq.push(Date(1020, 5, 13));
	pq.push(Date(2020, 4, 3));

	while (!pq.empty())
	{
		cout << pq.front();
		pq.pop();
	}
	cout << endl;
}

*/
//struct Greater
//{
//	bool operator()(const int& val1, const int& val2)
//	{
//		return val1 > val2;
//	}
//};
//
//struct Less
//{
//	bool operator()(const int& val1, const int& val2)
//	{
//		return val1 < val2;
//	}
//};
//
//template<class Compare>
//void selectsort(vector<int>& ret)
//{
////ѡ������ÿһ�ζ�ѡ��������δ�������Сֵ������
//	Compare _cmp;
//	_cmp= Less<int>:
//	for (int i = 0; i < ret.size(); ++i)
//	{
//		int min = ret[i];
//		int minidx = i;
//		for (int j = i + 1; j < ret.size(); ++j)
//		{
//			if (_cmp(ret[j], min))
//			{
//				min = ret[j];
//				minidx = j;
//			}
//		}
//		swap(ret[i], ret[minidx]);
//	}
//}
//void display(vector<int>& ret)
//{
//	for (int i = 0; i < ret.size(); ++i)
//	{
//		cout << ret[i] << " ";
//	}
//	cout << endl;
//}
//void testselect()
//{
//	vector<int> ret{ 3, 23, 35, 5, 6, 1, 46, 42, 6432 };
//	display(ret);
//	selectsort<Less<int>>(ret);
//	display(ret);
//}
int main()
{

	//testselect();
	//testDate();
	//testpriorityqueueu();
	system("pause");
	return 0;
}