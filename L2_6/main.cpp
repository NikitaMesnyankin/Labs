#include "operations.h"

static inline const std::string target_path = "C:\\Tools\\target_file.txt";
static inline const std::string receipt_path = "C:\\Tools\\receipt.txt";

int main()
{
	mesnyankin::RobotEditor::RobotEditor(target_path, receipt_path).processQueue();
	return 0;
}