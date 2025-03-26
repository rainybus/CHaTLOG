#pragma once
using namespace std;


class Bad_range : public exception // ¬ã¬à¬Ù¬Õ¬Ñ¬Ö¬Þ ¬Ü¬Ý¬Ñ¬ã¬ã ¬à¬ê¬Ú¬Ò¬à¬Ü, ¬ß¬Ñ¬ã¬Ý¬Ö¬Õ¬å¬ñ¬ã¬î ¬à¬ä ¬Ó¬ã¬ä¬â¬à¬Ö¬ß¬ß¬à¬Ô¬à ¬Ü¬Ý¬Ñ¬ã¬ã¬Ñ exception
{
public:
	virtual const char* what() const noexcept override
	{
		return "ERROR: bad range array"; // ¬à¬ä¬à¬Ò¬â¬Ñ¬Ø¬Ñ¬Ö¬ä¬ã¬ñ ¬ß¬Ñ ¬ï¬Ü¬â¬Ñ¬ß¬Ö ¬á¬â¬Ú ¬á¬à¬Ý¬å¬é¬Ö¬ß¬Ú¬Ú ¬Ú¬ã¬Ü¬Ý¬ð¬é¬Ö¬ß¬Ú¬ñ
	}
};
