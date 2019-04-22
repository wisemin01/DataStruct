// LinkedList.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include "list.h"
#include "vector.h"

using namespace MyStl;
using namespace std;

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	list<int> li = { 1,2,3,4,5,6,7,8,9,10 };

	for (auto iter = li.begin(); iter != li.end();)
	{
		int num = *iter;

		if (num % 2 == 0) {
			cout << num << endl;
			iter++;
		}
		else
		{
			iter = li.erase(iter);
		}
	}
}

