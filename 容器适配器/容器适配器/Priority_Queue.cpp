#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <deque>
#include <vector>
using namespace std;

/*
// 仿函数：用作 priority_queue 的第三个参数，用来做比较定义
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
 
// 容器适配器实现优先级队列
// 1、默认容器为 vector
//	用 vector 作为默认容器的理由：
//		1、优先级的实现是堆结构，因此需要随机访问，相对于双端队列而言，vector的随机访问效率更高，而deque的虽然支持随机访问，但是在不同的缓冲区需要进行换算；
//		2、不用 list 实现，因为 list 不支持随机访问
//
//2、第三个参数 Compare 仿函数
//实现对堆的大小的控制，增加了代码的灵活性
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
	// 向下调整：和两个孩子作比较
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

	// 向上调整：和父结点作比较
	void shiftUp(int child)
	{
		int   parent = (child - 1) >> 1;

		// 当父节点为 0 的时候也是可以调整的，因为此时孩子结点依然存在
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
	// 自定义类型使用优先级队列，类模板中必须重定义"<,>"的规则，否则仿函数在调用的时候并不知道调用什么规则去做比较
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
////选择排序，每一次都选择数组中未排序的最小值来排序
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