#include "utilits.h"

bool mesnyankin::verificateSArray(const mesnyankin::sArray& arr)
{
	unsigned int counter = 0;
	for (const auto& item : arr)
	{
		if (item.empty())
		{
			counter++;
		}
	}
	return (counter == 3) ? false : true;
}

bool mesnyankin::verificateETuple(const mesnyankin::eTuple& tupleData)
{
	mesnyankin::sArray sArr;
	mesnyankin::tie(tupleData, sArr);
	return ((!(mesnyankin::verificateSArray(sArr))) || ((std::get<3>(tupleData)) <= 0)) ? false : true;
}

bool mesnyankin::verificateETVector(const mesnyankin::eTVector& vector_data)
{
	if (vector_data.empty())
	{
		return false;
	}

	for (const auto& item : vector_data)
	{
		if (!(mesnyankin::verificateETuple(item)))
		{
			return false;
		}
	}
	return true;
}

void mesnyankin::erase_from_eTVector(mesnyankin::eTVector& etv, const mesnyankin::sArray& sArr)
{
	if (!(etv.empty()))
	{
		for (auto it = etv.begin(); it != etv.end();) {
			if (mesnyankin::compareData(*it, sArr)) {
				it = etv.erase(it);
			}
			else {
				++it;
			}
		}
	}
}

void mesnyankin::outputETVector(const mesnyankin::eTVector& etv)
{
	if (!(etv.empty()))
	{
		for (const auto& item : etv)
		{
			mesnyankin::outputTuple(item);
		}
	}
}