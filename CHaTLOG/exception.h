#pragma once
using namespace std;


class Bad_range : public exception // ���٬լѬ֬� �ܬݬѬ�� ���ڬҬ��, �߬Ѭ�ݬ֬լ���� ��� �Ӭ����֬߬߬�Ԭ� �ܬݬѬ��� exception
{
public:
	virtual const char* what() const noexcept override
	{
		return "ERROR: bad range array"; // ����Ҭ�ѬجѬ֬��� �߬� ��ܬ�Ѭ߬� ���� ���ݬ��֬߬ڬ� �ڬ�ܬݬ��֬߬ڬ�
	}
};
