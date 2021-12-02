#include "operations.h"

mesnyankin::sVector mesnyankin::parseCommand(const std::string& content)
{
	std::istringstream iss(content);
	return mesnyankin::sVector((std::istream_iterator<std::string>(iss)), std::istream_iterator<std::string>());
}

mesnyankin::sVector mesnyankin::readFileLines(const std::string& filename, std::ifstream& is)
{
	mesnyankin::sVector tmp;
	is.open(filename, std::ifstream::in);

	if (is.fail())
	{
		std::cout << "Error opening file!" << std::endl;
		return tmp;
	}

	//std::cout << "ALL RD STATES: " << std::bitset<3>(is.rdstate()) << std::endl;
	if (is.bad())
	{
		std::cout << "BAD IOSTATE FLAG IS SET" << std::endl;
		return tmp; 	// skip when bad
	}

	std::istream::iostate state_backup = is.rdstate(); 	// save state
	is.clear(); 	// clear state
	std::streampos pos_backup = is.tellg();

	is.seekg(0, std::ios_base::end);
	auto length = is.tellg();
	if (length == 0)
	{
		std::cout << "EOF FILE IS REACHED" << std::endl;
		return tmp;
	}
	is.seekg(0);

	for (std::string line; std::getline(is, line);)
	{
		tmp.push_back(line);
	}

	is.unget();

	is.clear(); // recover state, previous reading may set eofbit
	is.seekg(pos_backup);
	is.setstate(state_backup);

	is.close();
	return tmp;
}

void mesnyankin::refillSVector(const std::string& content, mesnyankin::sVector& container)
{
	std::stringstream sstr;
	sstr << content;

	for (std::string line; std::getline(sstr, line);)
	{
		container.push_back(line);
	}
	return;
}


mesnyankin::RobotEditor::RobotEditor(
		const std::string& target_path,
				const std::string& receipt_path)
{
	std::ifstream ifstr;
	currentContent_ = mesnyankin::readFileLines(target_path, ifstr);
	linesCount_ = currentContent_.size();
	commandLines_ = transferToQueue(mesnyankin::readFileLines(receipt_path, ifstr));
	targetPath_ = target_path;

	if (commandLines_.empty())
	{
		throw std::invalid_argument("Receipt file must be non-empty!");
	}
}

void mesnyankin::RobotEditor::undo()
{
	if (previousStates_.empty())
	{
		std::cout << "Previous states stack is empty!" << std::endl;
		return;
	}

	currentContent_ = previousStates_.top();
	previousStates_.pop();
	linesCount_ = currentContent_.size();
}

void mesnyankin::RobotEditor::deleteAllLines()
{
	currentContent_.clear();
	linesCount_ = 0;
}

void mesnyankin::RobotEditor::replaceSelectedLines(__int64& low, __int64& high, const std::string& searchSS, const std::string& inpSS)
{
	if ((low <= 0) || (high <= 0))
	{
		std::cout << "Negative or zero indexes detected (bad request)!" << std::endl;
		return;
	}

	__int64 tmp = low;
	low = std::min(low, high);
	high = std::max(tmp, high);
	std::cout << "Low: " << low << " | High: " << high << " | Lines count: " << linesCount_ << std::endl;
	if ((low > linesCount_) || (high > linesCount_))
	{
		std::cout << "Out-of-bounds (indexes are too big)!" << std::endl;
		return;
	}

	if (low == linesCount_)
	{
		//previousStates_.push(currentContent_);
		*(currentContent_.begin() + low - 1) = std::regex_replace(*(currentContent_.begin() + low - 1), std::regex(searchSS), inpSS);
	}
	else {
		if (low == 1)
		{
			if (high == linesCount_)
			{
				replaceAllLines(searchSS, inpSS);
			}
			else
			{
				//previousStates_.push(currentContent_);
				for (auto it = currentContent_.begin(); it != currentContent_.begin() + high; it++)
				{
					*(it) = std::regex_replace(*(it), std::regex(searchSS), inpSS);
				}
			}
		}
		else
		{
			//previousStates_.push(currentContent_);
			if (high == linesCount_)
			{
				std::cout << "LOW: " << low << " | HIGH: " << high << std::endl;
				for (auto it = currentContent_.begin() + low - 1; it != currentContent_.end(); it++)
				{
					*(it) = std::regex_replace(*(it), std::regex(searchSS), inpSS);
				}
			}
			else
			{
				for (auto it = currentContent_.begin() + low - 1; it != currentContent_.begin() + high; it++)
				{
					*(it) = std::regex_replace(*(it), std::regex(searchSS), inpSS);
				}
			}
		}
	}
}

void mesnyankin::RobotEditor::deleteSelectedLines(__int64& low, __int64& high)
{
	if ((low <= 0) || (high <= 0))
	{
		std::cout << "Negative or zero indexes detected (bad request)!" << std::endl;
		return;
	}

	__int64 tmp = low;
	low = std::min(low, high);
	high = std::max(tmp, high);
	std::cout << "Low: " << low << " | High: " << high << " | Lines count: " << linesCount_ << std::endl;
	if ((low > linesCount_) || (high > linesCount_))
	{
		std::cout << "Out-of-bounds (indexes are too big)!" << std::endl;
		return;
	}

	if (low == linesCount_)
	{
		//previousStates_.push(currentContent_);
		currentContent_.resize(currentContent_.size() - 1);
		linesCount_ = currentContent_.size();
	}
	else {
		if (low == 1)
		{
			if (high == linesCount_)
			{
				deleteAllLines();
			}
			else
			{
				//previousStates_.push(currentContent_);
				currentContent_.erase(currentContent_.begin(), currentContent_.begin() + high);
				linesCount_ = currentContent_.size();
			}
		}
		else 
		{
			//previousStates_.push(currentContent_);
			if (high == linesCount_)
			{
				currentContent_.resize(currentContent_.size() - (high - low + 1));
			}
			else
			{
				if (low != high)
				{
					//std::cout << "Low: " << *(currentContent_.begin() + low - 1) << " | High: " << *(currentContent_.begin() + high - 1) << std::endl;
					currentContent_.erase(currentContent_.begin() + low - 1, currentContent_.begin() + high);
				}
				else
				{
					currentContent_.erase(currentContent_.begin() + low - 1, currentContent_.begin() + high);
				}
			}
			linesCount_ = currentContent_.size();
		}
	}
}

void mesnyankin::RobotEditor::changeAllLines(const std::string& content)
{
	//previousStates_.push(currentContent_);
	currentContent_.clear();
	
	refillSVector(content, currentContent_);

	linesCount_ = currentContent_.size();
}

void mesnyankin::RobotEditor::replaceAllLines(const std::string& searchSS, const std::string& inpSS)
{
	for (auto& item : currentContent_)
	{
		item = std::regex_replace(item, std::regex(searchSS), inpSS);
	}

	/*std::string accumulated;
	for (const auto& piece : currentContent_)
	{
		accumulated += (piece + '\n');
	}
	
	refillSVector(accumulated, currentContent_);*/ //do we need accumulation?

	linesCount_ = currentContent_.size();
}

void mesnyankin::RobotEditor::insert(__int64 idx, const std::string& content)
{
	mesnyankin::sVector tmp;
	mesnyankin::refillSVector(content, tmp);
	if ((idx > linesCount_) || (idx <= 0))
	{
		std::cout << "Index is negative, zero-equal or out-of-bounds!" << std::endl;
		return;
	}

	//previousStates_.push(currentContent_);
	currentContent_.insert(currentContent_.begin() + idx, tmp.begin(), tmp.end());
	linesCount_ = currentContent_.size();
}

void mesnyankin::RobotEditor::changeSelectedLines(__int64 low, __int64 high, const std::string& content)
{
	if ((low <= 0) || (high <= 0))
	{
		std::cout << "Negative or zero indexes detected (bad request)!" << std::endl;
		return;
	}

	if ((low > linesCount_) || (high > linesCount_))
	{
		std::cout << "Out-of-bounds (indexes are too big)!" << std::endl;
		return;
	}

	mesnyankin::sVector tmp;
	mesnyankin::refillSVector(content, tmp);

	if (low == linesCount_) //low == high == end
	{
		//previousStates_.push(currentContent_);
		currentContent_.resize(currentContent_.size() - 1);
		currentContent_.insert(currentContent_.end(), tmp.begin(), tmp.end()); //check validity
		linesCount_ = currentContent_.size();
	}
	else {
		//previousStates_.push(currentContent_);

		if (low == 1) //low == 1
		{
			if (high == linesCount_) //low == 1 high == end
			{
				for (auto& item : currentContent_)
				{
					item = content;
				}
				//currentContent_.insert(currentContent_.begin(), tmp.begin(), tmp.end());
			}
			else //low == 1 high != end
			{
				currentContent_.erase(currentContent_.begin(), currentContent_.begin() + high);
				for (unsigned int i = 0; i < (high - low + 1); i++)
				{
					currentContent_.insert(currentContent_.begin(), tmp.begin(), tmp.end()); //check if correct
				}
			}
		}
		else //low != 1
		{
			if (high == linesCount_) //low != 1 high == end
			{
				currentContent_.resize(currentContent_.size() - (high - low + 1));
				for (unsigned int i = 0; i < (high - low + 1); i++)
				{
					currentContent_.insert(currentContent_.end(), tmp.begin(), tmp.end()); //check validity
				}
			}
			else //low != 1 high != end
			{
				if (low != high) //low != 1 high != end
				{
					//std::cout << "Low: " << *(currentContent_.begin() + low - 1) << " | High: " << *(currentContent_.begin() + high - 1) << std::endl;
					//currentContent_.erase(currentContent_.begin() + low - 1, currentContent_.begin() + high), tmp.begin(), tmp.end()); //check validity
					for (auto it = (currentContent_.begin() + low - 1); it != currentContent_.begin() + high; it++)
					{
						*(it) = content;
					}
				}
				else //low != 1 high == low (1 elem)
				{
					currentContent_.insert(currentContent_.erase(currentContent_.begin() + low - 1, currentContent_.begin() + high), tmp.begin(), tmp.end()); //check validity
				}
			}
		}
		linesCount_ = currentContent_.size();
	}
}

void mesnyankin::RobotEditor::outputData()
{
	std::cout << "Lines count: " << linesCount_ << std::endl;
	if (currentContent_.empty())
	{
		std::cout << "Content is empty!" << std::endl;
		return;
	}

	mesnyankin::outputContainer(currentContent_);
}

void mesnyankin::RobotEditor::processQueue()
{
	while (!(commandLines_.empty()))
	{
		auto strCommand = commandLines_.front();
		std::cout << "PROCESSING COMMAND: " << strCommand << std::endl;
		auto tmpCommand = parseCommand(strCommand);
		previousStates_.push(currentContent_);

		if (std::regex_match(strCommand, UNDO))
		{
			std::cout << "COMMAND FOUND!" << std::endl;
			undo();
		}
		if (std::regex_match(strCommand, INSERT))
		{
			std::cout << "COMMAND FOUND!" << std::endl;
			__int64 ARG = std::stoll(tmpCommand[2]);
			std::string TEXTARG = tmpCommand[3];
			TEXTARG.erase(std::remove(TEXTARG.begin(), TEXTARG.end(), '\"'), TEXTARG.end());
			insert(ARG, TEXTARG);
		}

		if (std::regex_match(strCommand, DELETE_ALL))
		{
			std::cout << "COMMAND FOUND!" << std::endl;
			deleteAllLines();
		}

		if (std::regex_match(strCommand, DELETE_FROM))
		{
			std::cout << "COMMAND FOUND!" << std::endl;
			__int64 ARG1 = std::stoll(tmpCommand[2]), ARG2 = std::stoll(tmpCommand[4]);
			deleteSelectedLines(ARG1, ARG2);
		}

		if (std::regex_match(strCommand, CHANGE_ALL))
		{
			std::cout << "COMMAND FOUND!" << std::endl;
			std::string TEXTARG = tmpCommand[2];
			TEXTARG.erase(std::remove(TEXTARG.begin(), TEXTARG.end(), '\"'), TEXTARG.end());
			changeAllLines(TEXTARG);
		}

		if (std::regex_match(strCommand, CHANGE_FROM))
		{
			std::cout << "COMMAND FOUND!" << std::endl;
			__int64 ARG1 = std::stoll(tmpCommand[2]), ARG2 = std::stoll(tmpCommand[4]);
			std::string TEXTARG = tmpCommand[6];
			TEXTARG.erase(std::remove(TEXTARG.begin(), TEXTARG.end(), '\"'), TEXTARG.end());
			changeSelectedLines(ARG1, ARG2, TEXTARG);
		}

		if (std::regex_match(strCommand, REPLACE_ALL))
		{
			std::cout << "COMMAND FOUND!" << std::endl;
			std::string TEXTARG1 = tmpCommand[1], TEXTARG2 = tmpCommand[3];
			TEXTARG1.erase(std::remove(TEXTARG1.begin(), TEXTARG1.end(), '\"'), TEXTARG1.end());
			TEXTARG2.erase(std::remove(TEXTARG2.begin(), TEXTARG2.end(), '\"'), TEXTARG2.end());
			replaceAllLines(TEXTARG1, TEXTARG2);
		}

		if (std::regex_match(strCommand, REPLACE_FROM))
		{
			std::cout << "COMMAND FOUND!" << std::endl;
			__int64 ARG1 = std::stoll(tmpCommand[2]), ARG2 = std::stoll(tmpCommand[4]);
			std::string TEXTARG1 = tmpCommand[5], TEXTARG2 = tmpCommand[7];
			TEXTARG1.erase(std::remove(TEXTARG1.begin(), TEXTARG1.end(), '\"'), TEXTARG1.end());
			TEXTARG2.erase(std::remove(TEXTARG2.begin(), TEXTARG2.end(), '\"'), TEXTARG2.end());
			replaceSelectedLines(ARG1, ARG2, TEXTARG1, TEXTARG2);
		}

		std::cout << "COMMAND DONE, PROCESSING TO NEXT..." << std::endl;
		commandLines_.pop();
	}

	return;
}

mesnyankin::RobotEditor::~RobotEditor()
{
	if (!(commandLines_.empty()))
	{
		processQueue();
	}

	std::ofstream ofstr;
	ofstr.open(targetPath_);
	ofstr << "LOGGING: " << "\n";

	if (!(previousStates_.empty()))
	{
		while (!(previousStates_.empty()))
		{
			ofstr << "PREVIOUS STATE: ";
			if (!(previousStates_.top().empty()))
			{
				for (const auto& item : previousStates_.top())
				{
					ofstr << item << " ";
				}
				ofstr << "\n";
			}
			previousStates_.pop();
		}
	}
	else
	{
		ofstr << "PREVIOUS STATES DELETED OR WERE EXECUTED\n";
	}

	if (!(currentContent_.empty()))
	{
		for (const auto& item : currentContent_)
		{
			ofstr << item << " ";
		}
		ofstr << "\n";
	}
	else
	{
		ofstr << "Current content is empty or was deleted!\n";
	}
	ofstr.close();
}
