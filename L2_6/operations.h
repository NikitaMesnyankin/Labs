#ifndef OPERATIONS_H
#define OPERATIONS_H

#include <algorithm>
#include <fstream>
#include <functional>
#include <iterator>
#include <iostream>
#include <queue>
#include <regex>
#include <string>
#include <sstream>
#include <stack>
#include <type_traits>
#include <vector>

static const std::regex UNDO("undo");
static const std::regex INSERT("insert after [1-9]+ \"[a-zA-Z\n\\\"]*\"");
static const std::regex DELETE_ALL("delete");
static const std::regex DELETE_FROM("delete (from [1-9]+ to [1-9]+)*");
static const std::regex CHANGE_ALL("change with \"[a-zA-Z\n\\\"]+\"");
static const std::regex CHANGE_FROM("change( from [1-9]+ to [1-9]+)* with \"[a-zA-Z\n\\\"]+\"");
static const std::regex REPLACE_ALL("replace \"[a-zA-Z\n\\\"]+\" with \"[a-zA-Z\n\\\"]+\"");
static const std::regex REPLACE_FROM("replace( from [1-9]+ to [1-9]+)+ \"[a-zA-Z\n\\\"]+\" with \"[a-zA-Z\n\\\"]+\"");

namespace mesnyankin
{
	typedef std::vector<std::string> sVector;

	template<typename T>
	void outputContainer(const T& container)
	{
		for (const auto& item : container)
		{
			std::cout << item << " ";
		}
		std::cout << std::endl;
	}
	
	template<typename T>
	std::queue<T> transferToQueue(const std::vector<T>& container)
	{
		std::queue<T> tmp;
		if (!(container.empty()))
		{
			for (const auto& item : container)
			{
				tmp.push(item);
			}
		}
		return tmp;
	};

	sVector readFileLines(const std::string&, std::ifstream&);

	void refillSVector(const std::string&, sVector&);

	sVector parseCommand(const std::string&);

	class RobotEditor
	{
	public:
		RobotEditor(const std::string&, const std::string&); //done //testED
		void deleteAllLines(); //done //testED
		void deleteSelectedLines(__int64&, __int64&); //done //testED
		void changeAllLines(const std::string&); //done //testED
		void changeSelectedLines(__int64, __int64, const std::string&);
		void insert(__int64, const std::string&); //done //testED
		void replaceAllLines(const std::string&, const std::string&); //done //testED
		void replaceSelectedLines(__int64&, __int64&, const std::string&, const std::string&); //done //testED
		void undo(); //done //testED //add outofbounds and empty conditions //added //testED
		void outputData();
		void processQueue();
		~RobotEditor();
	//private: //must be private next time
		sVector currentContent_;
		std::stack<sVector> previousStates_;
		std::queue<std::string> commandLines_;//implement queue algorithms
		__int64 linesCount_;
		std::string targetPath_;
	};
}


#endif
